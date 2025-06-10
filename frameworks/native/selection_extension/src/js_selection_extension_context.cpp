/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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

#include "js_selection_extension_context.h"
#include "js_error_utils.h"
#include "js_extension_context.h"
#include "js_runtime_utils.h"
#include "selection_js_utils.h"
#include "napi_common_want.h"
#include "selection_log.h"

namespace OHOS::AbilityRuntime {
using namespace OHOS::SelectionFwk;

namespace {

class JsSelectionExtensionContext final {
public:
    explicit JsSelectionExtensionContext(const std::shared_ptr<SelectionExtensionContext>& context) : context_(context)
    {
        SELECTION_HILOGI("JsSelectionExtensionContext::JsSelectionExtensionContext is called.");
    }
    JsSelectionExtensionContext() = default;
    ~JsSelectionExtensionContext() = default;

    static void Finalizer(napi_env env, void* data, void* hint)
    {
        SELECTION_HILOGI("JsSelectionExtensionContext::Finalizer is called.");
        std::unique_ptr<JsSelectionExtensionContext>(static_cast<JsSelectionExtensionContext*>(data));
    }

private:
    std::weak_ptr<SelectionExtensionContext> context_;
};
} // namespace

napi_value CreateJsSelectionExtensionContext(napi_env env, std::shared_ptr<SelectionExtensionContext> context)
{
    SELECTION_HILOGI("CreateJsSelectionExtensionContext begin");
    std::shared_ptr<OHOS::AppExecFwk::AbilityInfo> abilityInfo = nullptr;
    if (context) {
        abilityInfo = context->GetAbilityInfo();
    }

    napi_value objValue = CreateJsExtensionContext(env, context, abilityInfo);
    std::unique_ptr<JsSelectionExtensionContext> jsContext = std::make_unique<JsSelectionExtensionContext>(context);
    napi_wrap(env, objValue, jsContext.release(), JsSelectionExtensionContext::Finalizer, nullptr, nullptr);
    return objValue;
}
} // namespace OHOS::AbilityRuntime
