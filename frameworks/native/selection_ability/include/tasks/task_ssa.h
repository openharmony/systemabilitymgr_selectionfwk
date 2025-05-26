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

#ifndef FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_SSA_H
#define FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_SSA_H

#include "task.h"

#include "input_attribute.h"
#include "input_client_info.h"
#include "selection_ability.h"
#include "secelction_property.h"
#include "iremote_object.h"

namespace OHOS {
namespace SelectionFwk {

class TaskSsaStartInput : public Task {
public:
    TaskSsaStartInput(const InputClientInfo &client, bool fromClient) : Task(TASK_TYPE_IMSA_START_INPUT)
    {
        auto func = [client, fromClient]() {
            SelectionAbility::GetInstance()->StartInput(client, fromClient);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaStartInput() = default;
};

class TaskSsaStopInput : public Task {
public:
    explicit TaskSsaStopInput(sptr<IRemoteObject> channel, uint32_t sessionId) : Task(TASK_TYPE_IMSA_STOP_INPUT)
    {
        auto func = [channel, sessionId]() {
            SelectionAbility::GetInstance()->StopInput(channel, sessionId);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaStopInput() = default;
};

class TaskSsaShowKeyboard : public Task {
public:
    TaskSsaShowKeyboard(int32_t requestKeyboardReason = 0) : Task(TASK_TYPE_IMSA_SHOW_KEYBOARD)
    {
        auto func = [requestKeyboardReason]() {
            SelectionAbility::GetInstance()->ShowKeyboard(requestKeyboardReason);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaShowKeyboard() = default;
};

class TaskSsaHideKeyboard : public Task {
public:
    explicit TaskSsaHideKeyboard() : Task(TASK_TYPE_IMSA_HIDE_KEYBOARD)
    {
        auto func = []() {
            SelectionAbility::GetInstance()->HideKeyboard();
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaHideKeyboard() = default;
};

class TaskSsaOnClientInactive : public Task {
public:
    explicit TaskSsaOnClientInactive(sptr<IRemoteObject> channel) : Task(TASK_TYPE_IMSA_CLIENT_INACTIVE)
    {
        auto func = [channel]() {
            SelectionAbility::GetInstance()->OnClientInactive(channel);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaOnClientInactive() = default;
};

class TaskSsaInitInputCtrlChannel : public Task {
public:
    explicit TaskSsaInitInputCtrlChannel(sptr<IRemoteObject> channel) : Task(TASK_TYPE_IMSA_INIT_INPUT_CTRL_CHANNEL)
    {
        auto func = [channel]() {
            SelectionAbility::GetInstance()->OnInitInputControlChannel(channel);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaInitInputCtrlChannel() = default;
};

class TaskSsaOnCursorUpdate : public Task {
public:
    TaskSsaOnCursorUpdate(int32_t x, int32_t y, int32_t h) : Task(TASK_TYPE_IMSA_CURSOR_UPDATE)
    {
        auto func = [x, y, h]() {
            SelectionAbility::GetInstance()->OnCursorUpdate(x, y, h);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaOnCursorUpdate() = default;
};

class TaskSsaSendPrivateCommand : public Task {
public:
    TaskSsaSendPrivateCommand(std::unordered_map<std::string, PrivateDataValue> privateCommand)
        : Task(TASK_TYPE_IMSA_SEND_PRIVATE_COMMAND)
    {
        auto func = [privateCommand]() {
            SelectionAbility::GetInstance()->ReceivePrivateCommand(privateCommand);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaSendPrivateCommand() = default;
};

class TaskSsaOnSelectionChange : public Task {
public:
    TaskSsaOnSelectionChange(std::u16string text, int32_t oldBegin, int32_t oldEnd, int32_t newBegin, int32_t newEnd)
        : Task(TASK_TYPE_IMSA_SELECTION_CHANGE)
    {
        auto func = [text, oldBegin, oldEnd, newBegin, newEnd]() {
            SelectionAbility::GetInstance()->OnSelectionChange(text, oldBegin, oldEnd, newBegin, newEnd);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaOnSelectionChange() = default;
};

class TaskSsaAttributeChange : public Task {
public:
    explicit TaskSsaAttributeChange(InputAttribute attr) : Task(TASK_TYPE_IMSA_ATTRIBUTE_CHANGE)
    {
        auto func = [attr]() {
            SelectionAbility::GetInstance()->OnAttributeChange(attr);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaAttributeChange() = default;
};

class TaskSsaStopInputService : public Task {
public:
    explicit TaskSsaStopInputService(bool isTerminateIme) : Task(TASK_TYPE_IMSA_STOP_INPUT_SERVICE)
    {
        auto func = [isTerminateIme]() {
            SelectionAbility::GetInstance()->OnStopInputService(isTerminateIme);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaStopInputService() = default;
};

class TaskSsaOnSetSubProperty : public Task {
public:
    explicit TaskSsaOnSetSubProperty(SubProperty prop) : Task(TASK_TYPE_IMSA_SET_SUBPROPERTY)
    {
        auto func = [prop]() {
            SelectionAbility::GetInstance()->OnSetSubtype(prop);
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaOnSetSubProperty() = default;
};

class TaskSsaSetCoreAndAgent : public Task {
public:
    TaskSsaSetCoreAndAgent() : Task(TASK_TYPE_IMSA_SET_CORE_AND_AGENT)
    {
        auto func = []() {
            SelectionAbility::GetInstance()->SetCoreAndAgent();
        };
        actions_.emplace_back(std::make_unique<Action>(func));
    }
    ~TaskSsaSetCoreAndAgent() = default;
};
} // namespace SelectionFwk
} // namespace OHOS

#endif // FRAMEWORKS_SELECTION_ABILITY_INCLUDE_TASKS_TASK_SSA_H