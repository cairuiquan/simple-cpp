package com.chn.simplecpp

import android.app.Application

/*
 * Description :
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/2
 */
class MyApp: Application() {
    override fun onCreate() {
        super.onCreate()
        System.loadLibrary("mylib")
    }
}