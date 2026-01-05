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

#ifndef SELECTION_TIMER_H
#define SELECTION_TIMER_H

#include <errors.h>
#include <cstdint>
#include <string>
#include <unordered_set>
#include "timer.h"

namespace OHOS {
namespace SelectionFwk {

class SelectionFwkTimer {
public:
    using TimerCallback = std::function<void ()>;
    static std::shared_ptr<SelectionFwkTimer> GetInstance();
    SelectionFwkTimer();
    ~SelectionFwkTimer();

    uint32_t Register(const TimerCallback& callback, uint32_t interval, bool once = false);
    void UnRegister(uint32_t timerId);
private:
    std::unique_ptr<Utils::Timer> selectionFwkTimer_ = nullptr;

    std::mutex timerSetMtx;
    std::unordered_set<uint32_t> timerRegSet_;
};
} // namespace SelectionFwk
} // namespace OHOS
#endif // SELECTION_TIMER_H