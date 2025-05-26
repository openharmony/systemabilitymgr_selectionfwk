/*
 * Copyright (C) 2023-2024 Huawei Device Co., Ltd.
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

#include "scene_board_judgement.h"

#include "selection_panel.h"
#include "selection_log.h"

#include "display_manager.h"

namespace OHOS {
namespace SelectionFwk {
using WMError = OHOS::Rosen::WMError;
using WindowGravity = OHOS::Rosen::WindowGravity;
using WindowState = OHOS::Rosen::WindowState;
std::atomic<uint32_t> SelectionPanel::sequenceId_ { 0 };

SelectionPanel::~SelectionPanel() = default;
int32_t SelectionPanel::CreatePanel(
    const std::shared_ptr<AbilityRuntime::Context> &context, const PanelInfo &panelInfo)
{
    SELECTION_HILOGI("SelectionPanel CreatePanel start.");
    SELECTION_HILOGD(
        "start, type/flag: %{public}d/%{public}d.", static_cast<int32_t>(panelType_), static_cast<int32_t>(panelFlag_));
    // panelType_ = panelInfo.panelType;
    // panelFlag_ = panelInfo.panelFlag;
    // winOption_ = new (std::nothrow) OHOS::Rosen::WindowOption();
    // if (winOption_ == nullptr) {
    //     return ErrorCode::ERROR_NULL_POINTER;
    // }
    // if (panelInfo.panelType == PanelType::STATUS_BAR) {//状态栏面板
    //     winOption_->SetWindowType(OHOS::Rosen::WindowType::WINDOW_TYPE_INPUT_METHOD_STATUS_BAR);//窗口类型需要添加WINDOW_TYPE_SELECTION_FLOAT
    // } else {
    //     winOption_->SetWindowType(OHOS::Rosen::WindowType::WINDOW_TYPE_INPUT_METHOD_FLOAT);//窗口类型需要添加WINDOW_TYPE_SELECTION_FLOAT
    // }
    // winOption_->SetWindowType(OHOS::Rosen::WindowType::WINDOW_TYPE_DIALOG);//窗口类型需要确认
    // winOption_->SetWindowRect(OHOS::Rosen::Rect{10, 10, 80, 50});
    // WMError wmError = WMError::WM_OK;
    // window_ = OHOS::Rosen::Window::Create(GeneratePanelName(), winOption_, context, wmError);
    // if (wmError == WMError::WM_ERROR_INVALID_PERMISSION || wmError == WMError::WM_ERROR_NOT_SYSTEM_APP) {
    //     SELECTION_HILOGE("create window failed, permission denied, %{public}d!", wmError);
    //     return ErrorCode::ERROR_NOT_IME;
    // }
    // if (window_ == nullptr || wmError != WMError::WM_OK) {
    //     SELECTION_HILOGE("create window failed: %{public}d!", wmError);
    //     return ErrorCode::ERROR_OPERATE_PANEL;
    // }
    // isScbEnable_ = Rosen::SceneBoardJudgement::IsSceneBoardEnabled();
    // if (SetPanelProperties() != ErrorCode::NO_ERROR) {
    //     wmError = window_->Destroy();
    //     SELECTION_HILOGI("destroy window end, wmError is %{public}d.", wmError);
    //     return ErrorCode::ERROR_OPERATE_PANEL;
    // }
    // windowId_ = window_->GetWindowId();
    // SELECTION_HILOGI("success, type/flag/windowId/isScbEnable_: %{public}d/%{public}d/%{public}u/%{public}d.",
    //     static_cast<int32_t>(panelType_), static_cast<int32_t>(panelFlag_), windowId_, isScbEnable_);
    // // if (panelInfo.panelType == SOFT_KEYBOARD && isScbEnable_) {//软键盘+可用
    // //     RegisterKeyboardPanelInfoChangeListener();
    // // }
    // window_->RaiseToAppTop();
    // SELECTION_HILOGI("selectionPanel RaiseToAppTop  2.");
    // window_->Resize(80, 50);
    // window_->SetBackgroundColor("green");
    // window_->Show();
    // window_->Resize(80, 50);
    // window_->SetBackgroundColor("green");
    // SELECTION_HILOGI("selectionPanel show.");
    OHOS::Rosen::Rect baseWindowRect = { 150, 150, 400, 600 };
    sptr<Rosen::WindowOption> baseOp = new Rosen::WindowOption();
    baseOp->SetWindowType(Rosen::WindowType::WINDOW_TYPE_DYNAMIC);
    baseOp->SetWindowMode(Rosen::WindowMode::WINDOW_MODE_FLOATING);
    baseOp->SetWindowRect(baseWindowRect);
    baseOp->SetZIndex(1980);
    auto displayId = Rosen::DisplayManager::GetInstance().GetDefaultDisplayId();
    baseOp->SetDisplayId(displayId);
    // baseOp->SetWindowZOrder(Rosen::WindowZOrder::TOP_MOST);
    // baseOp->SetVisible(true);
    SELECTION_HILOGE("After SetWindowRect");

    sptr<Rosen::Window> window = Rosen::Window::Create("Demo_SSW_BaseWindow", baseOp, nullptr);
    if (!window) {
        SELECTION_HILOGE("Window creation failed");
        return ErrorCode::NO_ERROR;
    }
    SELECTION_HILOGE("After Window::Create");
    auto error = window->Show();
    if (error != WMError::WM_OK) {
        SELECTION_HILOGE("After Window::Show, error=%{public}d, WM_ERROR_INVALID_PARAM=%d", error, WM_ERROR_INVALID_PARAM);
    }
    // window->SetWindowFocus();
    // window->RaiseToTop();
    SELECTION_HILOGE("After Window::Show");
    return ErrorCode::NO_ERROR;
}

std::string SelectionPanel::GeneratePanelName()
{
    uint32_t sequenceId = GenerateSequenceId();
    std::string windowName = panelType_ == SOFT_KEYBOARD ? "softKeyboard" + std::to_string(sequenceId) ://panelType类型：softKeyboard、statusBar
                                                           "statusBar" + std::to_string(sequenceId);
    SELECTION_HILOGD("SelectionPanel, windowName: %{public}s.", windowName.c_str());
    return windowName;
}

int32_t SelectionPanel::SetPanelProperties()//设置输入面板属性，根据面板类型和标志来配置窗口的位置属性
{
    if (window_ == nullptr) {
        SELECTION_HILOGE("window is nullptr!");
        return ErrorCode::ERROR_OPERATE_PANEL;
    }
    WindowGravity gravity = WindowGravity::WINDOW_GRAVITY_FLOAT;//浮动位置
    if (panelType_ == SOFT_KEYBOARD && panelFlag_ == FLG_FIXED) {//软键盘+固定
        gravity = WindowGravity::WINDOW_GRAVITY_BOTTOM;
    } else if (panelType_ == SOFT_KEYBOARD && panelFlag_ == FLG_FLOATING) {//软键盘+浮动
        auto surfaceNode = window_->GetSurfaceNode();
        if (surfaceNode == nullptr) {
            SELECTION_HILOGE("surfaceNode is nullptr!");
            return ErrorCode::ERROR_OPERATE_PANEL;
        }
        surfaceNode->SetFrameGravity(Rosen::Gravity::TOP_LEFT);
        Rosen::RSTransactionProxy::GetInstance()->FlushImplicitTransaction();
    } else if (panelType_ == STATUS_BAR) {//状态栏面板
        auto surfaceNo = window_->GetSurfaceNode();
        if (surfaceNo == nullptr) {
            SELECTION_HILOGE("surfaceNo is nullptr!");
            return ErrorCode::ERROR_OPERATE_PANEL;
        }
        surfaceNo->SetFrameGravity(Rosen::Gravity::TOP_LEFT);
        Rosen::RSTransactionProxy::GetInstance()->FlushImplicitTransaction();
        return ErrorCode::NO_ERROR;
    }
    if (!isScbEnable_) {//非场景模式的重力设置------是什么东西，划词需要吗
        WMError wmError = window_->SetWindowGravity(gravity, invalidGravityPercent);
        if (wmError != WMError::WM_OK) {
            SELECTION_HILOGE("failed to set window gravity, wmError is %{public}d, start destroy window!", wmError);
            return ErrorCode::ERROR_OPERATE_PANEL;
        }
        return ErrorCode::NO_ERROR;
    }
    keyboardLayoutParams_.gravity_ = gravity;//场景模式
    auto ret = window_->AdjustKeyboardLayout(keyboardLayoutParams_);
    if (ret != WMError::WM_OK) {
        SELECTION_HILOGE("SetWindowGravity failed, wmError is %{public}d, start destroy window!", ret);
        return ErrorCode::ERROR_OPERATE_PANEL;
    }
    return ErrorCode::NO_ERROR;
}

uint32_t SelectionPanel::GenerateSequenceId()
{
    uint32_t seqId = ++sequenceId_;
    if (seqId == std::numeric_limits<uint32_t>::max()) {
        return ++sequenceId_;
    }
    return seqId;
}

// void SelectionPanel::SetPanelHeightCallback(CallbackFunc heightCallback)
// {
//     panelHeightCallback_ = std::move(heightCallback);
// }

} // namespace SelectionFwk
} // namespace OHOS