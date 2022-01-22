package com.chn.simplecpp

/*
 * Description : 
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/22
 */
class SimpleCpp {
    private var mInstance: Long = 0
    init {
        mInstance = nativeCreateInstance()
    }

    fun sayHello(str: String) {
        nativeHello(mInstance, str)
    }

    fun release() {
        nativeRelease(mInstance)
    }

    external fun nativeCreateInstance(): Long
    external fun nativeHello(instance: Long, str: String)
    external fun nativeRelease(instance: Long)
}