package com.example.httpclient;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;
import android.webkit.WebView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private static final String TAG = "MainActivity";

    private WebView webview;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_main);

        new Thread(new Runnable() {
            @Override
            public void run() {
                startServer();
            }
        }).start();

        Log.i("MyJniLog", "简直完美");

        // 1. webview如果通过loadurl直接访问输入的网址，那么就是走DNS服务器

        // 2. webview在loadurl之前先通过getHashRes(url) 进行处理得到serviceId + SR前缀的ip，通过此ip
        // 走的就是ServiceRouting路线
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public native String startServer();

    public native int getHashRes(String url);

}
