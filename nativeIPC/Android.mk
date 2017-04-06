LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	client.cpp	\
	server.cpp	\
	myServer.cpp

LOCAL_SHARED_LIBRARIES := libutils libbinder liblog

LOCAL_C_INCLUDES := $(LOCAL_PATH) $(LOCAL_PATH)/../include
LOCAL_C_INCLUDES += $(BINDERDEMO_C_INCLUDES)

LOCAL_LDLIBS += $(BINDERDEMO_LDLIBS)

LOCAL_STATIC_LIBRARIES := binderTC_Stub

LOCAL_MODULE:= nativeIBinder
#LOCAL_CFLAGS += -pie -fPIE
#LOCAL_LDFLAGS += -pie -fPIE

#include $(BUILD_EXECUTABLE)
include $(BUILD_SHARED_LIBRARY)
