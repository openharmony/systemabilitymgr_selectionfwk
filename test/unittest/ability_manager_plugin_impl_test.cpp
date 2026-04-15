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

#include "ability_manager_plugin_impl.h"

namespace OHOS {
namespace SelectionFwk {

using namespace testing::ext;

class AbilityManagerPluginImplTest : public testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp();
    void TearDown();

    AbilityManagerPluginImpl plugin_;
};

void AbilityManagerPluginImplTest::SetUpTestCase()
{
    std::cout << "AbilityManagerPluginImplTest SetUpTestCase" << std::endl;
}

void AbilityManagerPluginImplTest::TearDownTestCase()
{
    std::cout << "AbilityManagerPluginImplTest TearDownTestCase" << std::endl;
}

void AbilityManagerPluginImplTest::SetUp()
{
    std::cout << "AbilityManagerPluginImplTest SetUp" << std::endl;
}

void AbilityManagerPluginImplTest::TearDown()
{
    std::cout << "AbilityManagerPluginImplTest TearDown" << std::endl;
}

/**
 * @tc.name: AbilityManagerPluginImpl001
 * @tc.desc: test Initialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl001, TestSize.Level0)
{
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: AbilityManagerPluginImpl002
 * @tc.desc: test Initialize returns true when already initialized
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl002, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.Initialize());
}

/**
 * @tc.name: AbilityManagerPluginImpl003
 * @tc.desc: test GetModuleName
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl003, TestSize.Level0)
{
    const char* name = plugin_.GetModuleName();
    ASSERT_STREQ(name, "AbilityManager");
}

/**
 * @tc.name: AbilityManagerPluginImpl004
 * @tc.desc: test GetModuleVersion
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl004, TestSize.Level0)
{
    int version = plugin_.GetModuleVersion();
    ASSERT_EQ(version, 1);
}

/**
 * @tc.name: AbilityManagerPluginImpl005
 * @tc.desc: test Cleanup
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl005, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl006
 * @tc.desc: test IsAvailable after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl006, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl007
 * @tc.desc: test IsAvailable without Initialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl007, TestSize.Level0)
{
    AbilityManagerPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl008
 * @tc.desc: test HealthCheck returns true when initialized
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl008, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.HealthCheck());
}

/**
 * @tc.name: AbilityManagerPluginImpl009
 * @tc.desc: test HealthCheck returns false when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl009, TestSize.Level0)
{
    AbilityManagerPluginImpl newPlugin;
    ASSERT_FALSE(newPlugin.HealthCheck());
}

/**
 * @tc.name: AbilityManagerPluginImpl010
 * @tc.desc: test GetStatus returns "not_initialized" when not initialized
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl010, TestSize.Level0)
{
    AbilityManagerPluginImpl newPlugin;
    ASSERT_STREQ(newPlugin.GetStatus(), "not_initialized");
}

/**
 * @tc.name: AbilityManagerPluginImpl011
 * @tc.desc: test GetStatus returns "available" when initialized
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl011, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_STREQ(plugin_.GetStatus(), "available");
}

/**
 * @tc.name: AbilityManagerPluginImpl012
 * @tc.desc: test ConnectAbility without Initialize returns error
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl012, TestSize.Level0)
{
    AbilityManagerPluginImpl newPlugin;

    // nullptr callback should return error
    int32_t ret = newPlugin.ConnectAbility(AAFwk::Want(), nullptr, 100);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: AbilityManagerPluginImpl013
 * @tc.desc: test DisconnectAbility without Initialize returns error
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl013, TestSize.Level0)
{
    AbilityManagerPluginImpl newPlugin;

    int32_t ret = newPlugin.DisconnectAbility(nullptr);
    ASSERT_EQ(ret, -1);
}

/**
 * @tc.name: AbilityManagerPluginImpl014
 * @tc.desc: test ConnectAbility with null callback after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl014, TestSize.Level0)
{
    plugin_.Initialize();

    int32_t ret = plugin_.ConnectAbility(AAFwk::Want(), nullptr, 100);
    ASSERT_NE(ret, ERR_OK);
}

/**
 * @tc.name: AbilityManagerPluginImpl015
 * @tc.desc: test DisconnectAbility with null callback after Initialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl015, TestSize.Level0)
{
    plugin_.Initialize();

    int32_t ret = plugin_.DisconnectAbility(nullptr);
    ASSERT_NE(ret, ERR_OK);
}

/**
 * @tc.name: AbilityManagerPluginImpl016
 * @tc.desc: test Cleanup and reinitialize
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl016, TestSize.Level0)
{
    plugin_.Initialize();
    ASSERT_TRUE(plugin_.IsAvailable());

    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());

    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl017
 * @tc.desc: test multiple Initialize calls
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl017, TestSize.Level0)
{
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.Initialize());
    ASSERT_TRUE(plugin_.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl018
 * @tc.desc: test multiple Cleanup calls
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl018, TestSize.Level0)
{
    plugin_.Initialize();
    plugin_.Cleanup();
    plugin_.Cleanup();
    ASSERT_FALSE(plugin_.IsAvailable());
}

/**
 * @tc.name: AbilityManagerPluginImpl019
 * @tc.desc: test destructor calls Cleanup
 * @tc.type: FUNC
 */
HWTEST_F(AbilityManagerPluginImplTest, AbilityManagerPluginImpl019, TestSize.Level0)
{
    auto* plugin = new AbilityManagerPluginImpl();
    plugin->Initialize();
    ASSERT_TRUE(plugin->IsAvailable());

    delete plugin;
    // Destructor should call Cleanup, no crash expected
}

} // namespace SelectionFwk
} // namespace OHOS
