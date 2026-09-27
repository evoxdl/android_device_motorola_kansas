/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <aidl/android/hardware/power/BnPower.h>
#include <android-base/file.h>
#include <android-base/logging.h>

namespace aidl {
namespace google {
namespace hardware {
namespace power {
namespace impl {
namespace pixel {

using ::aidl::android::hardware::power::Mode;

const std::string TAP_TO_WAKE_NODE =
        "/sys/class/touchscreen/primary/gesture";

bool isDeviceSpecificModeSupported(Mode type, bool* _aidl_return) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE:
            *_aidl_return = true;
            return true;
        default:
            return false;
    }
}

bool setDeviceSpecificMode(Mode type, bool enabled) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE: {
            /*
             * Motorola/FocalTech gesture interface:
             *
             * 48 (0x30) = double tap disabled
             * 49 (0x31) = double tap enabled
             *
             * The kernel parses this sysfs input as decimal.
             */
            if (!::android::base::WriteStringToFile(
                        enabled ? "49" : "48",
                        TAP_TO_WAKE_NODE,
                        true)) {
                PLOG(ERROR) << "Failed to set double tap to wake";
            }

            return true;
        }
        default:
            return false;
    }
}

}  // namespace pixel
}  // namespace impl
}  // namespace power
}  // namespace hardware
}  // namespace google
}  // namespace aidl
