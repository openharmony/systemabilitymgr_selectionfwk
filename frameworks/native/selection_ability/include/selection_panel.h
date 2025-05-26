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

#ifndef SELECTION_PANEL_H
#define SELECTION_PANEL_H

#include <cstdint>
#include <functional>
#include <map>
#include <string>

#include <atomic>

#include "panel_info.h"
#include "refbase.h"
#include "context.h"
#include "wm_common.h"
#include "window.h"
#include "ui/rs_surface_node.h"

namespace OHOS {
namespace SelectionFwk {
class SelectionPanel {
public:
    static constexpr uint32_t INVALID_WINDOW_ID = 0;
    // using CallbackFunc = std::function<void(uint32_t, PanelFlag)>;
    SelectionPanel() = default;
    ~SelectionPanel();
    int32_t CreatePanel(const std::shared_ptr<AbilityRuntime::Context> &context, const PanelInfo &panelInfo);
    // void SetPanelHeightCallback(CallbackFunc heightCallback);

    uint32_t windowId_ = INVALID_WINDOW_ID;

private:
    std::string GeneratePanelName();
    int32_t SetPanelProperties();
    static uint32_t GenerateSequenceId();
    PanelType panelType_ = PanelType::STATUS_BAR;//待修改
    PanelFlag panelFlag_ = PanelFlag::FLG_FIXED;//待修改

    sptr<OHOS::Rosen::Window> window_ = nullptr;
    sptr<OHOS::Rosen::WindowOption> winOption_ = nullptr;

    bool isScbEnable_ { false };

    Rosen::KeyboardLayoutParams keyboardLayoutParams_;
    static std::atomic<uint32_t> sequenceId_;
    uint32_t invalidGravityPercent = 0;

    // CallbackFunc panelHeightCallback_ = nullptr;
};
} // namespace SelectionFwk
} // namespace OHOS
#endif // SELECTION_PANEL_H