//
// Created by cairq on 1/2/22.
//

#include <jni.h>
#include <MyLogger.h>

namespace {
    JavaVM *javaVm;
}

extern "C" {

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *p) {
    LOGD("");
    javaVm = vm;
    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM *jvm, void *p) {
    LOGD("");
}

}
