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

#ifndef SELECTION_SERVICE_H
#define SELECTION_SERVICE_H

#include <mutex>
#include <string>

#include "callback_object.h"
#include "iselection_listener.h"
#include "selection_service_stub.h"
#include "refbase.h"
#include "system_ability.h"
#include <i_input_event_consumer.h>

namespace OHOS::SelectionFwk {
using namespace MMI;

constexpr const char *SYS_SELECTION_SWITCH_USERNAM = "persist.sys.selection.switch.username";
constexpr const char *SYS_SELECTION_TRIGGER_USERNAM = "persist.sys.selection.trigger.username";
constexpr const char *SYS_SELECTION_APP_USERNAM = "persist.sys.selection.app.username";
constexpr const char *SYS_SELECTION_TRIGGER_VAL = "ctrl";
constexpr const uint32_t DOUBLE_CLICK_TIME = 500;

typedef enum {
    SELECT_INPUT_INITIAL = 0,
    SELECT_INPUT_WORD_BEGIN = 1,
    SELECT_INPUT_WAIT_LEFT_MOVE = 2,
    SELECT_INPUT_LEFT_MOVE = 3,
    SELECT_INPUT_WAIT_DOUBLE_CLICK = 4,
    SELECT_INPUT_WAIT_TRIBLE_CLICK = 5,
    SELECT_INPUT_DOUBLE_CLICKED = 6,
    SELECT_INPUT_TRIPLE_CLICKED = 7,
} SelectInputState;

typedef enum {
    SUB_INITIAL = 0,
    SUB_WAIT_POINTER_ACTION_BUTTON_DOWN = 1,
    SUB_WAIT_POINTER_ACTION_BUTTON_UP   = 2,
    SUB_WAIT_KEY_CTRL_DOWN = 3,
    SUB_WAIT_KEY_CTRL_UP = 4,
} SelectInputSubState;

class SelectionService : public SystemAbility, public SelectionServiceStub {
    DECLARE_SYSTEM_ABILITY(SelectionService);

public:
    static sptr<SelectionService> GetInstance();
    SelectionService();
    SelectionService(int32_t saId, bool runOnCreate);
    ~SelectionService();

    ErrCode AddVolume(int32_t volume, int32_t& funcResult) override;
    ErrCode RegisterListener(const sptr<IRemoteObject> &listener) override;
    ErrCode UnregisterListener(const sptr<IRemoteObject> &listener) override;
    int32_t Dump(int32_t fd, const std::vector<std::u16string> &args) override;
    int32_t StartNewAbility(const std::string& bundleName, const std::string& abilityName);
    void StopCurrentAbility();
    sptr<ISelectionListener> GetListener();
protected:
    void OnStart() override;
    void OnStop() override;
    void HandleKeyEvent(int32_t keyCode);
    void HandlePointEvent(int32_t type);
private:
    void InputMonitorInit();
    void InputMonitorCancel();
    void WatchParams();

    int32_t inputMonitorId_ {-1};
    std::mutex abilityMutex_;
    std::string currentBundleName_ = "";
    std::string currentAbilityName_ = "";
    static sptr<SelectionService> instance_;
    static std::shared_mutex adminLock_;
    mutable std::mutex mutex_;
    sptr<ISelectionListener> listenerStub_ { nullptr };
};

class SelectionInputMonitor : public IInputEventConsumer {
public:
    virtual void OnInputEvent(std::shared_ptr<KeyEvent> keyEvent) const;
    virtual void OnInputEvent(std::shared_ptr<PointerEvent> pointerEvent) const;
    virtual void OnInputEvent(std::shared_ptr<AxisEvent> axisEvent) const;

public:
    static bool ctrlSelectFlag;
private:
    void InputInitialProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void InputWordBeginProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void InputWordWaitLeftMoveProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void InputWordWaitDoubleClickProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void InputWordJudgeTripleClickProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void InputWordWaitTripleClickProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void FinishedWordSelection() const;
    void InjectCtrlC() const;
    void ResetProcess(std::shared_ptr<PointerEvent> pointerEvent) const;
    void JudgeTripleClick() const;
    static uint32_t curSelectState;
    static uint32_t subSelectState;
    static int64_t lastClickTime;
};
}

#endif // SELECTION_SERVICE_H