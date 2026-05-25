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

#include "pasteboard_plugin_impl.h"

namespace OHOS {
namespace SelectionFwk {

using namespace testing::ext;

class PasteboardPluginImplTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();

    PasteboardPluginImpl plugin_;
};

void PasteboardPluginImplTest::SetUpTestCase()
{
    std::cout << "PasteboardPluginImplTest SetUpTestCase" << std::endl;
}

void PasteboardPluginImplTest::TearDownTestCase()
{
    std::cout << "PasteboardPluginImplTest TearDownTestCase" << std::endl;
}

void PasteboardPluginImplTest::SetUp()
{
    std::cout << "PasteboardPluginImplTest SetUp" << std::endl;
}

void PasteboardPluginImplTest::TearDown()
{
    std::cout << "PasteboardPluginImplTest TearDown" << std::endl;
}

/**
 * @tc.name: PasteboardPluginImpl001
 * @tc.desc: test Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl001, TestSize.Level0)
{
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: PasteboardPluginImpl002
 * @tc.desc: test Initialize returns true when already initialized
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl002, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: PasteboardPluginImpl003
 * @tc.desc: test GetModuleName
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl003, TestSize.Level0)
{
    const char* name = plugin_.GetModuleName();
    ASSERT_STREQ(name, "Pasteboard");
}

/**
 * @tc.name: PasteboardPluginImpl004
 * @tc.desc: test GetModuleVersion
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl004, TestSize.Level0)
{
    int version = plugin_.GetModuleVersion();
    ASSERT_EQ(version, 1);
}

/**
 * @tc.name: PasteboardPluginImpl005
 * @tc.desc: test Cleanup
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl005, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl006
 * @tc.desc: test IsAvailable after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl006, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl007
 * @tc.desc: test IsAvailable without Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl007, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl008
 * @tc.desc: test HealthCheck returns true when initialized
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl008, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.HealthCheck());
}

/**
 * @tc.name: PasteboardPluginImpl009
 * @tc.desc: test HealthCheck returns false when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl009, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.HealthCheck());
}

/**
 * @tc.name: PasteboardPluginImpl010
 * @tc.desc: test GetStatus returns "uninitialized" when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl010, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    ASSERT_STREQ(newPlugin.GetStatus(), "uninitialized");
}

/**
 * @tc.name: PasteboardPluginImpl011
 * @tc.desc: test GetStatus returns "available" when initialized
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl011, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_STREQ(plugin_.GetStatus(), "available");
}

/**
 * @tc.name: PasteboardPluginImpl012
 * @tc.desc: test InitPasteboard after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl012, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.InitPasteboard());
}

/**
 * @tc.name: PasteboardPluginImpl013
 * @tc.desc: test InitPasteboard without Initialize returns false
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl013, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.InitPasteboard());
}

/**
 * @tc.name: PasteboardPluginImpl014
 * @tc.desc: test GetSelectionContent without Initialize returns error
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl014, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;

    std::string content;
    int32_t ret = newPlugin.GetSelectionContent(content, 100);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: PasteboardPluginImpl015
 * @tc.desc: test CanGetSelectionContent without Initialize returns false
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl015, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.CanGetSelectionContent());
}

/**
 * @tc.name: PasteboardPluginImpl016
 * @tc.desc: test CanGetSelectionContent after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl016, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_FALSE(plugin_.CanGetSelectionContent());
}

/**
 * @tc.name: PasteboardPluginImpl017
 * @tc.desc: test SetCanGetSelectionContentFlag to true
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl017, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.SetCanGetSelectionContentFlag(true);
    ASSERT_TRUE(plugin_.CanGetSelectionContent());
}

/**
 * @tc.name: PasteboardPluginImpl018
 * @tc.desc: test SetCanGetSelectionContentFlag to false
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl018, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.SetCanGetSelectionContentFlag(true);
    ASSERT_TRUE(plugin_.CanGetSelectionContent());

    plugin_.SetCanGetSelectionContentFlag(false);
    ASSERT_FALSE(plugin_.CanGetSelectionContent());
}

/**
 * @tc.name: PasteboardPluginImpl019
 * @tc.desc: test SetCanGetSelectionContentFlag without Initialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl019, TestSize.Level0)
{
    PasteboardPluginImpl newPlugin;
    newPlugin.SetCanGetSelectionContentFlag(true);
    ASSERT_FALSE(newPlugin.CanGetSelectionContent());
}

/**
 * @tc.name: PasteboardPluginImpl021
 * @tc.desc: test Cleanup and reinitialize
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl021, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());

    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());

    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl022
 * @tc.desc: test multiple Initialize calls
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl022, TestSize.Level0)
{
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl023
 * @tc.desc: test multiple Cleanup calls
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl023, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.Cleanup();
    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());
}

/**
 * @tc.name: PasteboardPluginImpl024
 * @tc.desc: test flag persistence after multiple SetCanGetSelectionContentFlag calls
 * @tc.type: FUNC
 */
HWTEST_F(PasteboardPluginImplTest, PasteboardPluginImpl024, TestSize.Level0)
{
    plugin_.Initialize();

    plugin_.SetCanGetSelectionContentFlag(true);
    ASSERT_TRUE(plugin_.CanGetSelectionContent());

    plugin_.SetCanGetSelectionContentFlag(false);
    ASSERT_FALSE(plugin_.CanGetSelectionContent());

    plugin_.SetCanGetSelectionContentFlag(true);
    ASSERT_TRUE(plugin_.CanGetSelectionContent());

    plugin_.SetCanGetSelectionContentFlag(false);
    ASSERT_FALSE(plugin_.CanGetSelectionContent());
}

} // namespace SelectionFwk
} // namespace OHOS
