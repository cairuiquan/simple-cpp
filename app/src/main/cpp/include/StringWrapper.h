//
// Created by CaiRuiQin on 22/1/22.
//

#ifndef SIMPLE_CPP_STRINGWRAPPER_H
#define SIMPLE_CPP_STRINGWRAPPER_H
#include <jni.h>

namespace chn {
class StringWrapper {
public:
    StringWrapper(JNIEnv *env, jstring str)
        :mEnv(env), mStr(str) {
        if (mStr) {
            mStrUTFChars = env->GetStringUTFChars(mStr, nullptr);
        }
    }

    ~StringWrapper() {
        if (mStrUTFChars) {
            mEnv->ReleaseStringUTFChars(mStr, mStrUTFChars);
        }
    }

    const char* get() {
        if (mStrUTFChars) {
            return mStrUTFChars;
        }
    }

    operator const char *() {
        return get();
    }

    operator bool() {
        return mStrUTFChars != nullptr;
    }

private:
    JNIEnv *mEnv;
    jstring mStr;
    const char *mStrUTFChars{nullptr};
};

}
#endif //SIMPLE_CPP_STRINGWRAPPER_H
