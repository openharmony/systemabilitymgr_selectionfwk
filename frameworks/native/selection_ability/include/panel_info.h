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

#ifndef SELECTION_FWK_PANEL_INFO_H
#define SELECTION_FWK_PANEL_INFO_H

#include "parcel.h"

namespace OHOS {
namespace SelectionFwk {
enum PanelType {
    MENU_PANEL = 1,
    MAIN_PANEL = 2,
};

struct PanelInfo : public Parcelable {
    PanelType panelType = MAIN_PANEL;
    int32_t x = 0;
    int32_t y = 0;
    int32_t width = 0;
    int32_t height = 0;

    bool ReadFromParcel(Parcel &in)
    {
        int32_t panelTypeData = in.ReadInt32();
        panelType = static_cast<PanelType>(panelTypeData);
        x = in.ReadInt32();
        y = in.ReadInt32();
        width = in.ReadInt32();
        height = in.ReadInt32();
        return true;
    }
    bool Marshalling(Parcel &out) const
    {
        if (!out.WriteInt32(static_cast<int32_t>(panelType))) {
            return false;
        }
        if (!out.WriteInt32(x)) {
            return false;
        }
        if (!out.WriteInt32(y)) {
            return false;
        }
        if (!out.WriteInt32(width)) {
            return false;
        }
        if (!out.WriteInt32(height)) {
            return false;
        }
        return true;
    }
    static PanelInfo *Unmarshalling(Parcel &in)
    {
        PanelInfo *data = new (std::nothrow) PanelInfo();
        if (data && !data->ReadFromParcel(in)) {
            delete data;
            data = nullptr;
        }
        return data;
    }
};

enum class ImmersiveMode : int32_t {
    NONE_IMMERSIVE = 0,
    IMMERSIVE = 1,
    LIGHT_IMMERSIVE = 2,
    DARK_IMMERSIVE = 3,
    END,
};
} // namespace SelectionFwk
} // namespace OHOS

#endif // SELECTION_FWK_PANEL_INFO_H
