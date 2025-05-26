/*
 * Copyright (C) 2024-2024 Huawei Device Co., Ltd.
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

#ifndef FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_AMS_H
#define FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_AMS_H

#include "task.h"

#include "actions/action_wait.h"
#include "global.h"
#include "task_manager.h"

namespace OHOS {
namespace SelectionFwk {
const uint32_t AMS_INIT_TIMEOUT_MS = 5000;

class TaskAmsInit : public Task {
public:
    TaskAmsInit() : Task(TASK_TYPE_AMS_INIT)
    {
        auto action = std::make_unique<ActionWait>(seqId_, AMS_INIT_TIMEOUT_MS,
            std::bind(&TaskAmsInit::OnComplete, this), std::bind(&TaskAmsInit::OnTimeout, this));
        actions_.push_back(std::move(action));
    }
    ~TaskAmsInit() = default;

private:
    void OnComplete()
    {
        SELECTION_HILOGI("TaskAmsInit::OnComplete");
        TaskManager::GetInstance().SetInited(true);
    }
    void OnTimeout()
    {
        SELECTION_HILOGW("TaskAmsInit::OnTimeout");
    }
};
} // namespace SelectionFwk
} // namespace OHOS

#endif // FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_AMS_H