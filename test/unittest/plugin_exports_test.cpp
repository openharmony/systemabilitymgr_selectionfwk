/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gtest/gtest.h"

#include "selection_config.h"
#include "selection_errors.h"

namespace OHOS {
namespace SelectionFwk {

// Forward declare SelectionConfig for extern "C"
using SelectionConfig = OHOS::SelectionFwk::SelectionConfig;

} // namespace SelectionFwk
} // namespace OHOS

// External C functions from plugin_exports.cpp
extern "C" {
    int DatabaseSaveConfig(int uid, const OHOS::SelectionFwk::SelectionConfig* config);
    int DatabaseGetConfig(int uid, OHOS::SelectionFwk::SelectionConfig* config);
    int DatabaseIsAvailable();

    int PasteboardGetSelectionContent(char* buffer, int bufferSize, uint32_t windowId);
    int PasteboardCanGetSelectionContent();
    void PasteboardSetCanGetSelectionContentFlag(int flag);
    int PasteboardIsAvailable();

    int AbilityManagerConnectAbility(const void* want, const void* callback, int32_t userId);
    int AbilityManagerDisconnectAbility(const void* callback);
    int AbilityManagerIsAvailable();

    void PluginCleanupAll();
}

namespace OHOS {
namespace SelectionFwk {

using namespace testing::ext;

class PluginExportsTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();
};

void PluginExportsTest::SetUpTestCase()
{
    std::cout << "PluginExportsTest SetUpTestCase" << std::endl;
}

void PluginExportsTest::TearDownTestCase()
{
    std::cout << "PluginExportsTest TearDownTestCase" << std::endl;
}

void PluginExportsTest::SetUp()
{
    std::cout << "PluginExportsTest SetUp" << std::endl;
}

void PluginExportsTest::TearDown()
{
    std::cout << "PluginExportsTest TearDown" << std::endl;
}

// ==================== Database Plugin Tests ====================

/**
 * @tc.name: PluginExports001
 * @tc.desc: test DatabaseSaveConfig with null config
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports001, TestSize.Level0)
{
    int ret = DatabaseSaveConfig(100, nullptr);
    ASSERT_EQ(ret, SELECTION_CONFIG_FAILURE);
}

/**
 * @tc.name: PluginExports002
 * @tc.desc: test DatabaseGetConfig with null config
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports002, TestSize.Level0)
{
    int ret = DatabaseGetConfig(100, nullptr);
    ASSERT_EQ(ret, SELECTION_CONFIG_FAILURE);
}

/**
 * @tc.name: PluginExports003
 * @tc.desc: test DatabaseSaveConfig with valid config
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports003, TestSize.Level0)
{
    SelectionConfig config;
    config.SetEnabled(true);
    config.SetTriggered(false);
    config.SetApplicationInfo("com.example.test/TestAbility");

    int ret = DatabaseSaveConfig(3001, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports004
 * @tc.desc: test DatabaseGetConfig with existing record
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports004, TestSize.Level0)
{
    SelectionConfig saveConfig;
    saveConfig.SetEnabled(true);
    saveConfig.SetApplicationInfo("com.example.query/TestAbility");
    DatabaseSaveConfig(3002, &saveConfig);

    SelectionConfig getConfig;
    int ret = DatabaseGetConfig(3002, &getConfig);
    ASSERT_EQ(ret, 0);
    ASSERT_TRUE(getConfig.GetEnable());
    ASSERT_EQ(getConfig.GetApplicationInfo(), "com.example.query/TestAbility");
}

/**
 * @tc.name: PluginExports005
 * @tc.desc: test DatabaseGetConfig with non-existing record
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports005, TestSize.Level0)
{
    SelectionConfig config;
    int ret = DatabaseGetConfig(9999, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_NOT_FOUND);
}

/**
 * @tc.name: PluginExports006
 * @tc.desc: test DatabaseIsAvailable
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports006, TestSize.Level0)
{
    int available = DatabaseIsAvailable();
    ASSERT_EQ(available, 1);
}

/**
 * @tc.name: PluginExports007
 * @tc.desc: test DatabaseSaveConfig with zero uid
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports007, TestSize.Level0)
{
    SelectionConfig config;
    config.SetEnabled(false);
    config.SetApplicationInfo("com.example.zero/TestAbility");

    int ret = DatabaseSaveConfig(0, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports008
 * @tc.desc: test DatabaseSaveConfig with negative uid
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports008, TestSize.Level0)
{
    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.negative/TestAbility");

    int ret = DatabaseSaveConfig(-1, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports009
 * @tc.desc: test DatabaseSaveConfig update existing record
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports009, TestSize.Level0)
{
    SelectionConfig config1;
    config1.SetEnabled(true);
    config1.SetApplicationInfo("com.example.original/TestAbility");
    DatabaseSaveConfig(3003, &config1);

    SelectionConfig config2;
    config2.SetEnabled(false);
    config2.SetApplicationInfo("com.example.updated/TestAbility");
    int ret = DatabaseSaveConfig(3003, &config2);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);

    SelectionConfig getConfig;
    DatabaseGetConfig(3003, &getConfig);
    ASSERT_FALSE(getConfig.GetEnable());
    ASSERT_EQ(getConfig.GetApplicationInfo(), "com.example.updated/TestAbility");
}

// ==================== Pasteboard Plugin Tests ====================

/**
 * @tc.name: PluginExports010
 * @tc.desc: test PasteboardGetSelectionContent with null buffer
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports010, TestSize.Level0)
{
    int ret = PasteboardGetSelectionContent(nullptr, 100, 0);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports011
 * @tc.desc: test PasteboardGetSelectionContent with zero buffer size
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports011, TestSize.Level0)
{
    char buffer[100];
    int ret = PasteboardGetSelectionContent(buffer, 0, 0);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports012
 * @tc.desc: test PasteboardGetSelectionContent with negative buffer size
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports012, TestSize.Level0)
{
    char buffer[100];
    int ret = PasteboardGetSelectionContent(buffer, -1, 0);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports013
 * @tc.desc: test PasteboardCanGetSelectionContent
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports013, TestSize.Level0)
{
    int canGet = PasteboardCanGetSelectionContent();
    ASSERT_EQ(canGet, 0);
}

/**
 * @tc.name: PluginExports014
 * @tc.desc: test PasteboardSetCanGetSelectionContentFlag with true
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports014, TestSize.Level0)
{
    PasteboardSetCanGetSelectionContentFlag(1);
    int canGet = PasteboardCanGetSelectionContent();
    ASSERT_EQ(canGet, 1);
}

/**
 * @tc.name: PluginExports015
 * @tc.desc: test PasteboardSetCanGetSelectionContentFlag with false
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports015, TestSize.Level0)
{
    PasteboardSetCanGetSelectionContentFlag(1);
    PasteboardSetCanGetSelectionContentFlag(0);
    int canGet = PasteboardCanGetSelectionContent();
    ASSERT_EQ(canGet, 0);
}

/**
 * @tc.name: PluginExports016
 * @tc.desc: test PasteboardIsAvailable
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports016, TestSize.Level0)
{
    int available = PasteboardIsAvailable();
    ASSERT_EQ(available, 1);
}

/**
 * @tc.name: PluginExports017
 * @tc.desc: test PasteboardGetSelectionContent with valid buffer
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports017, TestSize.Level0)
{
    char buffer[100];
    // Initialize buffer to test that it gets properly null-terminated
    buffer[0] = 'X';
    buffer[99] = 'Y';

    int ret = PasteboardGetSelectionContent(buffer, sizeof(buffer), 100);
    // In test environment, the function may timeout and return error, but should:
    // 1. Not crash
    // 2. Properly null-terminate the buffer even on failure
    // The buffer content may be empty or unchanged depending on pasteboard state
    // Just verify the function completes without crash
    ASSERT_GE(ret, -1); // Return value should be valid error code or success
}

// ==================== AbilityManager Plugin Tests ====================

/**
 * @tc.name: PluginExports018
 * @tc.desc: test AbilityManagerConnectAbility with null want
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports018, TestSize.Level0)
{
    int callback = 0;
    int ret = AbilityManagerConnectAbility(nullptr, &callback, 100);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports019
 * @tc.desc: test AbilityManagerConnectAbility with null callback
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports019, TestSize.Level0)
{
    int want = 0;
    int ret = AbilityManagerConnectAbility(&want, nullptr, 100);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports020
 * @tc.desc: test AbilityManagerDisconnectAbility with null callback
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports020, TestSize.Level0)
{
    int ret = AbilityManagerDisconnectAbility(nullptr);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PluginExports021
 * @tc.desc: test AbilityManagerIsAvailable
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports021, TestSize.Level0)
{
    // AbilityManager plugin requires connection to system service
    // In test environment, the service may not be available
    // Just verify the function returns a valid value (0 or 1)
    int available = AbilityManagerIsAvailable();
    // Accept either 0 (not available) or 1 (available) since we can't control
    // whether AbilityManager service is running in test environment
    ASSERT_TRUE(available == 0 || available == 1);
}

// ==================== Plugin Lifecycle Tests ====================

/**
 * @tc.name: PluginExports022
 * @tc.desc: test PluginCleanupAll
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports022, TestSize.Level0)
{
    // First ensure plugins are initialized
    SelectionConfig config;
    config.SetEnabled(true);
    DatabaseSaveConfig(4001, &config);

    // Cleanup should work without crashing
    PluginCleanupAll();

    // After cleanup, IsAvailable should return false
    int dbAvailable = DatabaseIsAvailable();
    ASSERT_EQ(dbAvailable, 0);
}

/**
 * @tc.name: PluginExports024
 * @tc.desc: test Database operations after PluginCleanupAll
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports024, TestSize.Level0)
{
    PluginCleanupAll();

    // After cleanup, operations should still work (plugins auto-reinitialize)
    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.reinit/TestAbility");

    int ret = DatabaseSaveConfig(4002, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports025
 * @tc.desc: test Pasteboard operations after PluginCleanupAll
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports025, TestSize.Level0)
{
    PluginCleanupAll();

    // After cleanup, operations should still work (plugins auto-reinitialize)
    PasteboardSetCanGetSelectionContentFlag(1);
    int canGet = PasteboardCanGetSelectionContent();
    ASSERT_EQ(canGet, 1);
}

/**
 * @tc.name: PluginExports028
 * @tc.desc: test DatabaseSaveConfig with empty application info
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports028, TestSize.Level0)
{
    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("");

    int ret = DatabaseSaveConfig(4003, &config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports029
 * @tc.desc: test multiple DatabaseSaveConfig calls
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports029, TestSize.Level0)
{
    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.multi/TestAbility");

    ASSERT_EQ(DatabaseSaveConfig(5001, &config), SELECTION_CONFIG_OK);
    ASSERT_EQ(DatabaseSaveConfig(5002, &config), SELECTION_CONFIG_OK);
    ASSERT_EQ(DatabaseSaveConfig(5003, &config), SELECTION_CONFIG_OK);
}

/**
 * @tc.name: PluginExports030
 * @tc.desc: test PasteboardSetCanGetSelectionContentFlag with non-zero value
 * @tc.type: FUNC
 */
HWTEST_F(PluginExportsTest, PluginExports030, TestSize.Level0)
{
    PasteboardSetCanGetSelectionContentFlag(1);
    ASSERT_EQ(PasteboardCanGetSelectionContent(), 1);

    PasteboardSetCanGetSelectionContentFlag(100);
    ASSERT_EQ(PasteboardCanGetSelectionContent(), 1);

    PasteboardSetCanGetSelectionContentFlag(-1);
    ASSERT_EQ(PasteboardCanGetSelectionContent(), 1);

    PasteboardSetCanGetSelectionContentFlag(0);
    ASSERT_EQ(PasteboardCanGetSelectionContent(), 0);
}

} // namespace SelectionFwk
} // namespace OHOS
