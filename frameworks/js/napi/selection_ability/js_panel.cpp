/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#include "js_panel.h"

#include "napi/native_common.h"
#include "napi/native_node_api.h"
#include "selection_log.h"
#include "panel_listener_impl.h"
// #include "utils.h"
// #include "selectionmethod_trace.h"


#include "selection_ability.h"

namespace OHOS {
namespace SelectionFwk {
const std::string JsPanel::CLASS_NAME = "Panel";
thread_local napi_ref JsPanel::panelConstructorRef_ = nullptr;
std::mutex JsPanel::panelConstructorMutex_;

napi_value JsPanel::Init(napi_env env)
{
    SELECTION_HILOGI("JsPanel start.");
    napi_value constructor = nullptr;
    std::lock_guard<std::mutex> lock(panelConstructorMutex_);
    if (panelConstructorRef_ != nullptr) {
        napi_status status = napi_get_reference_value(env, panelConstructorRef_, &constructor);
        CHECK_RETURN(status == napi_ok, "failed to get jsPanel constructor.", nullptr);
        return constructor;
    }
    const napi_property_descriptor properties[] = {
        DECLARE_NAPI_FUNCTION("show", Show),

    };
    NAPI_CALL(env, napi_define_class(env, CLASS_NAME.c_str(), CLASS_NAME.size(), JsNew, nullptr,
                       sizeof(properties) / sizeof(napi_property_descriptor), properties, &constructor));
    CHECK_RETURN(constructor != nullptr, "failed to define class!", nullptr);
    NAPI_CALL(env, napi_create_reference(env, constructor, 1, &panelConstructorRef_));
    return constructor;
}

napi_value JsPanel::JsNew(napi_env env, napi_callback_info info)
{
    SELECTION_HILOGD("create panel instance start.");
    std::shared_ptr<PanelListenerImpl> panelImpl = PanelListenerImpl::GetInstance();
    if (panelImpl != nullptr) {
        SELECTION_HILOGD("set eventHandler.");
        panelImpl->SetEventHandler(AppExecFwk::EventHandler::Current());
    }
    JsPanel *panel = new (std::nothrow) JsPanel();
    CHECK_RETURN(panel != nullptr, "no memory for JsPanel!", nullptr);
    auto finalize = [](napi_env env, void *data, void *hint) {
        SELECTION_HILOGD("jsPanel finalize.");
        auto *jsPanel = reinterpret_cast<JsPanel *>(data);
        CHECK_RETURN_VOID(jsPanel != nullptr, "finalize nullptr!");
        jsPanel->GetNative() = nullptr;
        delete jsPanel;
    };
    napi_value thisVar = nullptr;
    napi_status status = napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
    if (status != napi_ok) {
        SELECTION_HILOGE("failed to get cb info: %{public}d!", status);
        delete panel;
        return nullptr;
    }
    status = napi_wrap(env, thisVar, panel, finalize, nullptr, nullptr);
    if (status != napi_ok) {
        SELECTION_HILOGE("failed to wrap: %{public}d!", status);
        delete panel;
        return nullptr;
    }
    return thisVar;
}

JsPanel::~JsPanel()
{
    selectionPanel_ = nullptr;
}

void JsPanel::SetNative(const std::shared_ptr<SelectionPanel> &panel)
{
    selectionPanel_ = panel;
}

napi_value JsPanel::Show(napi_env env, napi_callback_info info)
{
    SELECTION_HILOGI("cJsPanel---Show.");
    // SelectionMethodSyncTrace tracer("JsPanel_Show");
    // auto ctxt = std::make_shared<PanelContentContext>(env, info);
    // auto input = [ctxt](napi_env env, size_t argc, napi_value *argv, napi_value self) -> napi_status {
    //     ctxt->info = { std::chrono::system_clock::now(), JsEvent::SHOW };
    //     jsQueue_.Push(ctxt->info);
    //     return napi_ok;
    // };
    // auto exec = [ctxt](AsyncCall::Context *ctx) {
    //     jsQueue_.Wait(ctxt->info);
    //     if (ctxt->selectionPanel == nullptr) {
    //         SELECTION_HILOGE("selectionPanel is nullptr!");
    //         jsQueue_.Pop();
    //         return;
    //     }
    //     auto code = SelectionAbility::GetInstance()->ShowPanel(ctxt->selectionPanel);
    //     if (code == ErrorCode::NO_ERROR) {
    //         ctxt->SetState(napi_ok);
    //         jsQueue_.Pop();
    //         return;
    //     }
    //     jsQueue_.Pop();
    //     ctxt->SetErrorCode(code);
    // };
    // ctxt->SetAction(std::move(input));
    // // 1 means JsAPI:show has 1 param at most.
    // AsyncCall asyncCall(env, info, ctxt, 1);
    // return asyncCall.Call(env, exec, "show");
    return nullptr;
}

std::shared_ptr<SelectionPanel> JsPanel::GetNative()
{
    return selectionPanel_;
}
}
}