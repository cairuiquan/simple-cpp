//
// Created by CaiRuiQin on 22/1/22.
//

#ifndef SIMPLE_CPP_JNIUTILS_H
#define SIMPLE_CPP_JNIUTILS_H

#include <jni.h>

#define JNI_HANDLE_EXCEPTION(env)                    \
    if (env->ExceptionCheck()) {                     \
        env->ExceptionDescribe();                    \
        env->ExceptionClear();                       \
    }                                                \

void makeThreadKey();
jint JNI_SetupThreadEnv(JNIEnv **env);
void JNI_ThreadDestroy(void *value);

#endif //SIMPLE_CPP_JNIUTILS_H
