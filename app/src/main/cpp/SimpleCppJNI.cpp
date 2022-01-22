//
// Created by cairq on 1/2/22.
//

#include <jni.h>
#include "MyLogger.h"
#include "JniUtils.h"
#include "StringWrapper.h"
#include <string>

JavaVM *gJavaVm;

namespace {
    template <class C>
    inline jlong toJPtr(C *demo) {
        return reinterpret_cast<intptr_t>(demo);
    }

    template <class C>
    inline C* toNative(jlong ptr) {
        return reinterpret_cast<C*>(ptr);
    }

    class Test{
    public:
        Test() {
        }

        void sayHello(const std::string &str) {
            LOG_D("Hello: %s", str.c_str());
        }
    };
}

extern "C" {

JNIEXPORT jlong JNICALL nativeCreateInstance(JNIEnv *env, jobject obj)
{
    LOG_D("");
    return toJPtr(new Test());
}

JNIEXPORT void JNICALL nativeHello(JNIEnv *env, jobject obj, jlong instance, jstring str)
{
    std::string s(chn::StringWrapper(env, str));
    LOG_D("env %p, this:%p", env, obj);
    Test *t = toNative<Test>(instance);
    t->sayHello(s);
}

JNIEXPORT void JNICALL nativeRelease(JNIEnv *env, jobject obj, jlong instance, jstring str)
{
    LOG_D("env %p, this:%p", env, obj);
    Test *t = toNative<Test>(instance);
    delete t;
}

}

namespace {
    static const char *gSimpleCppClassPathName = "com/chn/simplecpp/SimpleCpp";
    static JNINativeMethod gSimpleCppMethods[] = {
            {"nativeCreateInstance","()J", (void *)(nativeCreateInstance)},
            {"nativeHello","(JLjava/lang/String;)V", (void *)(nativeHello)},
            {"nativeRelease", "(J)V",(void *)(nativeRelease)}
    };

    static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *methods,
                                     int numMethods) {
        jclass clazz;
        clazz = env->FindClass(className);
        if (clazz == nullptr) {
            LOG_E("FindClass fail");
            return JNI_FALSE;
        }
        if (env->RegisterNatives(clazz, methods, numMethods) < 0) {
            JNI_HANDLE_EXCEPTION(env);
            LOG_E("RegisterNatives fail");
            return JNI_FALSE;
        }
        return JNI_TRUE;
    }

    static int registerNativeMethods(JNIEnv *env) {
//        //test thread env
//        JNIEnv *testThreadEnv = nullptr;
//        if (JNI_SetupThreadEnv(&testThreadEnv) != JNI_OK) {
//
//        }
        if (!registerNativeMethods(env, gSimpleCppClassPathName, gSimpleCppMethods,
                                   sizeof(gSimpleCppMethods) / sizeof(gSimpleCppMethods[0]))) {
            LOG_E("register SimpleCpp fail");
        }
        return JNI_TRUE;
    }

}

extern "C" {

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *p) {
    LOG_D("");
    gJavaVm = vm;
    JNIEnv *env = nullptr;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
        LOG_E("GetEnv fail");
        return -1;
    }
    registerNativeMethods(env);
    return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM *jvm, void *p) {
    LOG_D("");
}

}
