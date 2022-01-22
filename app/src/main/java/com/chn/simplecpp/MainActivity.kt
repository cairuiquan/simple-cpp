package com.chn.simplecpp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

/*
 * Description :
 * Attention:
 *
 * Created by CaiRuiQin on 22/1/2
 */
class MainActivity : AppCompatActivity() {
    private lateinit var test: SimpleCpp

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        test = SimpleCpp()
        test.sayHello("SimpleCpp")
    }

    override fun onDestroy() {
        super.onDestroy()
        test.release()
    }
}