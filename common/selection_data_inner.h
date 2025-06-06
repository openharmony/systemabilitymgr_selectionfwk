/*
 * Copyright (C) 2025 Huawei Device Co., Ltd.
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
#ifndef SELECTION_DATA_INNER
#define SELECTION_DATA_INNER

#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include "parcel.h"
#include "selection_interface.h"

namespace OHOS {
namespace SelectionFwk {

struct SelectionInfoData : public Parcelable {
    SelectionInfo data;

    bool ReadFromParcel(Parcel &in) {
        data.selectionType = static_cast<SelectionType>(in.ReadInt8());
        data.text = in.ReadString();
        data.startPosX = in.ReadInt32();
        data.startPosY = in.ReadInt32();
        data.endPosX = in.ReadInt32();
        data.endPosY = in.ReadInt32();
        data.displayId = in.ReadUint32();
        data.windowId = in.ReadUint32();
        data.bundleName = in.ReadString();
        return true;
    }

    bool Marshalling(Parcel &out) const {
        if (!out.WriteInt8(static_cast<int8_t>(data.selectionType))) {
            return false;
        }
        if (!out.WriteString(data.text)) {
            return false;
        }
        if (!out.WriteInt32(data.startPosX)) {
            return false;
        }
        if (!out.WriteInt32(data.startPosY)) {
            return false;
        }
        if (!out.WriteInt32(data.endPosX)) {
            return false;
        }
        if (!out.WriteInt32(data.endPosY)) {
            return false;
        }
        if (!out.WriteUint32(data.displayId)) {
            return false;
        }
        if (!out.WriteUint32(data.windowId)) {
            return false;
        }
        if (!out.WriteString(data.bundleName)) {
            return false;
        }
        return true;
    }

    static SelectionInfoData *Unmarshalling(Parcel &in) {
        SelectionInfoData *data = new (std::nothrow) SelectionInfoData();
        if (data && !data->ReadFromParcel(in)) {
            delete data;
            data = nullptr;
        }
        return data;
    }

    std::string ToString() const {
        std::ostringstream oss;
        oss << "SelectionInfo { selectionType: " << data.selectionType << ", text: \"" << data.text << "\" \
            startPosX: " << data.startPosX << ", startPosY: " << data.startPosY << ", endPosX: " << data.endPosX << ",\
            endPosY: " << data.endPosY << ", displayId: " << data.displayId << ", windowId: " << data.windowId <<
            ", bundleName: " << data.bundleName << "}";
        return oss.str();
    }
};

}
}

#endif