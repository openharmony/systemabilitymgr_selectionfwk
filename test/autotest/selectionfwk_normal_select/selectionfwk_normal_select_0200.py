#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2026 Huawei Device Co., Ltd.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from devicetest.core.test_case import TestCase, Step
from devicetest.utils.file_util import get_resource_path
from hypium import *
from hypium.uiexplorer import *


class selectionfwk_normal_select_0200(TestCase):
    def __init__(self, configs):
        self.TAG = self.__class__.__name__
        TestCase.__init__(self, self.TAG, configs)

    def setup(self):
        Step("预置工作:初始化2in1开始................." + self.devices[0].device_sn)
        driver = UiDriver.create(self.device1)
        wake = driver.Screen.is_on()
        time.sleep(0.5)
        if wake:
            driver.ScreenLock.unlock()
        else:
            driver.Screen.wake_up()
            driver.ScreenLock.unlock()
        driver.shell("power-shell timeout -o 86400000")

    def process(self):
        Step("验证海泰浏览器是否能够正常划词")
        Step("执行操作")
        driver = UiDriver.create(self.device1)

        Step("步骤1:打开海泰浏览器")
        driver.start_app("com.haitai.htbrowser")

        Step("步骤2:点击同意隐私协议")
        component = driver.find_component(BY.text("同意"))
        if component:
            driver.touch(BY.text("同意"))

        Step("步骤3:点击以后再说")
        component = driver.find_component(BY.text("以后再说"))
        if component:
            driver.touch(BY.text("以后再说"))

        Step("步骤4:最大化窗口")
        display_width, display_height = driver.get_display_size()
        window_width, window_height = driver.get_window_size()
        if display_width != window_width:
            driver.touch(BY.key("EnhanceMaximizeBtn"))

        Step("步骤5:点击搜索框")
        driver.touch((1141, 829))

        Step("步骤6:输入文字")
        driver.input_text_by_keyboard("今日新闻")

        Step("步骤7:按下回车键")
        driver.press_key(key_code=2054)
        driver.wait(10)

        Step("步骤8:点击AI摘要")
        driver.touch((832, 974))
        driver.wait(10)

        Step("步骤9:尝试选中文字")
        driver.mouse_drag((1100, 477), (2486, 1176))

        Step("步骤10:按下ctrl")
        driver.press_key(key_code=2072)

        Step("步骤11:检查是否成功弹窗")
        driver.check_window_exist(WindowFilter().bundle_name("com.hxxxxi.xxos.vassistant"))

        Step("步骤12:关闭海泰浏览器")
        driver.stop_app("com.haitai.htbrowser")

    def teardown(self):
        Step("收尾工作")