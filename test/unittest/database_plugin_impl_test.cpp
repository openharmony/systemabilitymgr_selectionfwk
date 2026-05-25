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

#include <optional>

#include "gtest/gtest.h"

#include "database_plugin_impl.h"
#include "selection_config_database.h"
#include "selection_errors.h"

namespace OHOS {
namespace SelectionFwk {

using namespace testing::ext;

class DatabasePluginImplTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();

    DatabasePluginImpl plugin_;
};

void DatabasePluginImplTest::SetUpTestCase()
{
    std::cout << "DatabasePluginImplTest SetUpTestCase" << std::endl;
}

void DatabasePluginImplTest::TearDownTestCase()
{
    std::cout << "DatabasePluginImplTest TearDownTestCase" << std::endl;
}

void DatabasePluginImplTest::SetUp()
{
    std::cout << "DatabasePluginImplTest SetUp" << std::endl;
}

void DatabasePluginImplTest::TearDown()
{
    std::cout << "DatabasePluginImplTest TearDown" << std::endl;
}

/**
 * @tc.name: DatabasePluginImpl001
 * @tc.desc: test Initialize with valid database
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl001, TestSize.Level0)
{
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: DatabasePluginImpl002
 * @tc.desc: test Initialize returns true when already initialized
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl002, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: DatabasePluginImpl003
 * @tc.desc: test GetModuleName
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl003, TestSize.Level0)
{
    const char* name = plugin_.GetModuleName();
    ASSERT_STREQ(name, "Database");
}

/**
 * @tc.name: DatabasePluginImpl004
 * @tc.desc: test GetModuleVersion
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl004, TestSize.Level0)
{
    int version = plugin_.GetModuleVersion();
    ASSERT_EQ(version, 1);
}

/**
 * @tc.name: DatabasePluginImpl005
 * @tc.desc: test Cleanup
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl005, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());
}

/**
 * @tc.name: DatabasePluginImpl006
 * @tc.desc: test IsAvailable after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl006, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: DatabasePluginImpl007
 * @tc.desc: test IsAvailable without Initialize
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl007, TestSize.Level0)
{
    DatabasePluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.IsAvailable());
}

/**
 * @tc.name: DatabasePluginImpl008
 * @tc.desc: test HealthCheck returns true when initialized
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl008, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.HealthCheck());
}

/**
 * @tc.name: DatabasePluginImpl009
 * @tc.desc: test HealthCheck returns false when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl009, TestSize.Level0)
{
    DatabasePluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.HealthCheck());
}

/**
 * @tc.name: DatabasePluginImpl010
 * @tc.desc: test GetStatus returns "uninitialized" when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl010, TestSize.Level0)
{
    DatabasePluginImpl newPlugin;
    ASSERT_STREQ(newPlugin.GetStatus(), "uninitialized");
}

/**
 * @tc.name: DatabasePluginImpl011
 * @tc.desc: test GetStatus returns "available" when initialized
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl011, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_STREQ(plugin_.GetStatus(), "available");
}

/**
 * @tc.name: DatabasePluginImpl012
 * @tc.desc: test Save with valid config
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl012, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetTriggered(true);
    config.SetApplicationInfo("com.example.test/TestAbility");

    int ret = plugin_.Save(1001, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: DatabasePluginImpl013
 * @tc.desc: test Save without Initialize returns error
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl013, TestSize.Level0)
{
    DatabasePluginImpl newPlugin;

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.test/TestAbility");

    int ret = newPlugin.Save(1002, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_RDB_NO_INIT);
}

/**
 * @tc.name: DatabasePluginImpl014
 * @tc.desc: test Save updates existing record
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl014, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config1;
    config1.SetEnabled(true);
    config1.SetApplicationInfo("com.example.test1/TestAbility");

    int ret = plugin_.Save(1003, config1);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);

    SelectionConfig config2;
    config2.SetEnabled(false);
    config2.SetApplicationInfo("com.example.test2/TestAbility");

    ret = plugin_.Save(1003, config2);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);

    auto result = plugin_.GetOneByUserId(1003);
    ASSERT_TRUE(result.has_value());
    ASSERT_FALSE(result.value().GetEnable());
    ASSERT_EQ(result.value().GetApplicationInfo(), "com.example.test2/TestAbility");
}

/**
 * @tc.name: DatabasePluginImpl015
 * @tc.desc: test GetOneByUserId with existing record
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl015, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetTriggered(false);
    config.SetApplicationInfo("com.example.query/TestAbility");

    plugin_.Save(1004, config);

    auto result = plugin_.GetOneByUserId(1004);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(result.value().GetEnable());
    ASSERT_FALSE(result.value().GetTriggered());
    ASSERT_EQ(result.value().GetApplicationInfo(), "com.example.query/TestAbility");
}

/**
 * @tc.name: DatabasePluginImpl016
 * @tc.desc: test GetOneByUserId with non-existing record
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl016, TestSize.Level0)
{
    plugin_.Initialize();

    auto result = plugin_.GetOneByUserId(9999);
    ASSERT_FALSE(result.has_value());
}

/**
 * @tc.name: DatabasePluginImpl017
 * @tc.desc: test GetOneByUserId without Initialize
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl017, TestSize.Level0)
{
    DatabasePluginImpl newPlugin;

    auto result = newPlugin.GetOneByUserId(1005);
    ASSERT_FALSE(result.has_value());
}

/**
 * @tc.name: DatabasePluginImpl018
 * @tc.desc: test Save with negative uid
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl018, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.negative/TestAbility");

    int ret = plugin_.Save(-1, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: DatabasePluginImpl019
 * @tc.desc: test Save with zero uid
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl019, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(false);
    config.SetApplicationInfo("com.example.zero/TestAbility");

    int ret = plugin_.Save(0, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: DatabasePluginImpl020
 * @tc.desc: test Save with empty application info
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl020, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("");

    int ret = plugin_.Save(1006, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);
}

/**
 * @tc.name: DatabasePluginImpl021
 * @tc.desc: test Save with all config fields set
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl021, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetTriggered(true);
    config.SetApplicationInfo("com.example.allfields/TestAbility");

    int ret = plugin_.Save(1007, config);
    ASSERT_EQ(ret, SELECTION_CONFIG_OK);

    auto result = plugin_.GetOneByUserId(1007);
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(result.value().GetEnable());
    ASSERT_TRUE(result.value().GetTriggered());
}

/**
 * @tc.name: DatabasePluginImpl022
 * @tc.desc: test Cleanup and reinitialize
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl022, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());

    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());

    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: DatabasePluginImpl023
 * @tc.desc: test multiple Save operations with different uids
 * @tc.type: FUNC
 */
HWTEST_F(DatabasePluginImplTest, DatabasePluginImpl023, TestSize.Level0)
{
    plugin_.Initialize();

    SelectionConfig config;
    config.SetEnabled(true);
    config.SetApplicationInfo("com.example.multi/TestAbility");

    ASSERT_EQ(plugin_.Save(2001, config), SELECTION_CONFIG_OK);
    ASSERT_EQ(plugin_.Save(2002, config), SELECTION_CONFIG_OK);
    ASSERT_EQ(plugin_.Save(2003, config), SELECTION_CONFIG_OK);

    ASSERT_TRUE(plugin_.GetOneByUserId(2001).has_value());
    ASSERT_TRUE(plugin_.GetOneByUserId(2002).has_value());
    ASSERT_TRUE(plugin_.GetOneByUserId(2003).has_value());
}

} // namespace SelectionFwk
} // namespace OHOS
