#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit_only.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from device makefile.
$(call inherit-product, device/motorola/kansas/device.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

PRODUCT_NAME := lineage_kansas
PRODUCT_DEVICE := kansas
PRODUCT_MANUFACTURER := motorola
PRODUCT_BRAND := motorola
PRODUCT_MODEL := Moto G 5G 2025

PRODUCT_GMS_CLIENTID_BASE := android-motorola

PRODUCT_BUILD_PROP_OVERRIDES += \
    DeviceName=kansas \
    BuildDesc="kansas_g_sys-user 16 W1VKS36M.9-12-9-8-3 6b8cf8 release-keys" \
    BuildFingerprint=motorola/kansas_g_sys/kansas:16/W1VKS36M.9-12-9-8-3/6b8cf8-4eab3:user/release-keys
