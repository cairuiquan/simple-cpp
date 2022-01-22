//
// Created by CaiRuiQin on 22/1/22.
//
#include "JniUtils.h"
#include <pthread.h>

extern JavaVM *gJavaVm;

static pthread_key_t g_thread_key;
static pthread_once_t g_key_once = PTHREAD_ONCE_INIT;

void makeThreadKey() {
    pthread_key_create(&g_thread_key, JNI_ThreadDestroy);
}

jint JNI_SetupThreadEnv(JNIEnv **pEnv) {
    JavaVM *jvm = gJavaVm;
    if (!jvm) {
        return JNI_ERR;
    }

    pthread_once(&g_key_once, makeThreadKey);
    JNIEnv *env = (JNIEnv*) pthread_getspecific(g_thread_key);
    if (env) {
        *pEnv = env;
        return JNI_OK;
    }

    if (jvm->AttachCurrentThread(&env, nullptr) == JNI_OK) {
        pthread_setspecific(g_thread_key, env);
        *pEnv = env;
        return JNI_OK;
    }

    return JNI_ERR;
}

void JNI_ThreadDestroy(void *value) {
    JNIEnv *env = (JNIEnv*) value;
    if (!env) {
        gJavaVm->DetachCurrentThread();
        pthread_setspecific(g_thread_key, nullptr);
    }
}
