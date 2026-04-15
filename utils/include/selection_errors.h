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

#ifndef SELECTION_ERRORS_H
#define SELECTION_ERRORS_H

#include <errors.h>
#include <cstdint>
#include <string>

namespace OHOS {
namespace SelectionFwk {

enum SelectionConfigErrCode {
    SELECTION_CONFIG_OK = 0,
    SELECTION_CONFIG_FAILURE = -1,
    SELECTION_CONFIG_RDB_EXECUTE_FAILTURE = -2,
    SELECTION_CONFIG_RDB_NO_INIT = -3,
    SELECTION_CONFIG_RDB_EMPTY = -4,
    SELECTION_CONFIG_PERMISSION_DENIED = -5,
    SELECTION_CONFIG_NOP = -6,
    SELECTION_CONFIG_OVERFLOW = -7,
    SELECTION_CONFIG_NOT_FOUND = -8,
};

enum SelectionServiceError {
    INVALID_DATA = 1,
    UNAUTHENTICATED_ERROR,
    NOT_SYSTEM_APP_ERROR,
    INVALID_TIMING,
    CANNOT_GET_CONTENT,
    CONTENT_OUT_OF_RANGE,
    GET_CONTENT_TIMEOUT,
};

// 插件加载相关错误码
enum PluginLoaderError {
    PLUGIN_LOAD_OK = 0,
    PLUGIN_LOAD_FAILED_DLOPEN = -100,       // dlopen 失败
    PLUGIN_LOAD_FAILED_SYMBOL = -101,       // dlsym 查找符号失败
    PLUGIN_LOAD_FAILED_CREATE = -102,       // CreatePlugin 返回 nullptr
    PLUGIN_LOAD_FAILED_INIT = -103,         // 插件初始化失败
    PLUGIN_LOAD_FAILED_TYPE_MISMATCH = -104, // 类型不匹配
    PLUGIN_NOT_LOADED = -105,               // 插件未加载
    PLUGIN_UNLOAD_FAILED = -106,            // 插件卸载失败
    PLUGIN_SO_NOT_FOUND = -107,             // .so 文件不存在
};

} // namespace SelectionFwk
} // namespace OHOS
#endif // SELECTION_ERRORS_H
