ifeq ($(BOARD_HAVE_BLUETOOTH_BCM),true)

LOCAL_PATH:= $(call my-dir)

#
# brcm_cw_tx_test.c
#

include $(CLEAR_VARS)

LOCAL_SRC_FILES := brcm_cw_tx_test.c

LOCAL_MODULE := brcm_cw_tx_test

LOCAL_SHARED_LIBRARIES := libcutils

include $(BUILD_EXECUTABLE)

endif
