package com.example.exceptioncrash;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.jnilib.TestAPI;

public class MainActivity extends AppCompatActivity {

    private TestAPI testAPI;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.loadLibrary("jnilib");
    }

    @Override
    protected void onResume() {
        super.onResume();
        testAPI = new TestAPI();
    }

    @Override
    protected void onPause() {
        testAPI.Release();
        super.onPause();
    }
}