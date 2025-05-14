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

#ifndef INTERFACE_KITS_JS_SELECTION_ABILITY_ENGINE_H
#define INTERFACE_KITS_JS_SELECTION_ABILITY_ENGINE_H
#include <map>
#include <memory>
#include <mutex>

#include "napi/native_api.h"
#include "util.h"
#include "callback_object.h"


namespace OHOS {
namespace SelectionFwk {
class JsSelectionAbilityEngine {
public:
    JsSelectionAbilityEngine() = default;
    ~JsSelectionAbilityEngine() = default;
    static napi_value Init(napi_env env, napi_value exports);
    static napi_value Subscribe(napi_env env, napi_callback_info info);
    static napi_value UnSubscribe(napi_env env, napi_callback_info info);

private:
    static napi_value JsConstructor(napi_env env, napi_callback_info cbinfo);
    static std::shared_ptr<JsSelectionAbilityEngine> GetSelectionAbilityEngine();
    void RegisterListener(napi_value callback, std::string type, std::shared_ptr<JSCallbackObject> callbackObj);
    void UnRegisterListener(napi_value callback, std::string type);

private:
    static const std::string KDS_CLASS_NAME;
    static thread_local napi_ref KDSRef_;
    std::map<std::string, std::vector<std::shared_ptr<JSCallbackObject>>> jsCbMap_;
    static std::mutex selectionMutex_;
    static std::shared_ptr<JsSelectionAbilityEngine> selectionDelegate_;
    std::recursive_mutex mutex_;
};
} // namespace SelectionFwk
} // namespace OHOS
#endif // INTERFACE_KITS_JS_SELECTION_ABILITY_ENGINE_H