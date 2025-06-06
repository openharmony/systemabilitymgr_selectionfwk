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


#ifndef SELECTION_PANEL_MANGER_H
#define SELECTION_PANEL_MANGER_H
#include <unordered_map>
#include <memory>
#include <atomic>
#include <stdexcept>
#include <mutex>

#include "selection_panel.h"

namespace OHOS {
namespace SelectionFwk {
class SelectionPanelManger {
public:
    static SelectionPanelManger& GetInstance() {
        static SelectionPanelManger instance;
        return instance;
    }

    void AddSelectionPanel(int32_t id, std::shared_ptr<SelectionPanel> &obj) {
        std::lock_guard<std::mutex> lock(mutex_);
        storage_[id] = obj;
    }

    std::shared_ptr<SelectionPanel> GetSelectionPanel(int32_t id) const {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = storage_.find(id);
        return (it != storage_.end()) ? it->second : nullptr;
    }

    void RemoveSelectionPanel(int32_t id) {
        std::lock_guard<std::mutex> lock(mutex_);
        storage_.erase(id);
    }

    bool FindWindowID(uint32_t id) const {
        std::lock_guard<std::mutex> lock(mutex_);
        return storage_.find(id) != storage_.end();
    }

private:
    SelectionPanelManger() = default;
    ~SelectionPanelManger() = default;
    std::unordered_map<int32_t, std::shared_ptr<SelectionPanel>> storage_;
    mutable std::mutex mutex_;

};
} // namespace SelectionFwk
}  // namespace OHOS


#endif // SELECTION_PANEL_MANGER_H