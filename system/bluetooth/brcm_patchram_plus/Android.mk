#ifeq ($(BOARD_HAVE_BLUETOOTH_BCM),true)

LOCAL_PATH:= $(call my-dir)

#
# brcm_patchram_plus.c
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES := brcm_patchram_plus.c

LOCAL_MODULE := brcm_patchram_plus.dat

LOCAL_SHARED_LIBRARIES := libcutils

#Add by Taoyuan for BCM4330 bluetooth address 2011.5.3
ifeq ($(BOARD_HAVE_BLUETOOTH_BCM4330_BTADDR),true)
  LOCAL_CFLAGS += -DNEED_BTADDR
endif

#Add by Taoyuan for FirmWare copy and BCM4330 hcit mode
ifneq (, $(filter  P_01D msm7630_surf, $(TARGET_PRODUCT)))
PRODUCT_COPY_FILES += $(LOCAL_PATH)/BCM4330.hcd:system/etc/BCM4330.hcd
endif # check for TARGET_PRODUCT

ifneq (, $(filter  SH8288U, $(TARGET_PRODUCT)))
PRODUCT_COPY_FILES += $(LOCAL_PATH)/TEST_ONLY_Simcom_Bigbang_BCM4330B1_0087.hcd:system/etc/BCM4330.hcd
endif # check for TARGET_PRODUCT

PRODUCT_COPY_FILES += $(LOCAL_PATH)/init.qcom.btcit.sh:system/etc/init.qcom.btcit.sh
PRODUCT_COPY_FILES += $(LOCAL_PATH)/btparam.sh:system/etc/btparam.sh
PRODUCT_COPY_FILES += $(LOCAL_PATH)/TEST_ONLY_Ponyo_FixedAFHMap_384M_20110511.hcd:system/etc/TEST_ONLY_Ponyo_FixedAFHMap_384M_20110511.hcd

include $(BUILD_EXECUTABLE)

#endif
