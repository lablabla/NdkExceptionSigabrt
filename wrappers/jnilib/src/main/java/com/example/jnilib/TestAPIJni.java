package com.example.jnilib;

public class TestAPIJni {

    public static native long init();
    public static native void release(long nativeAddress);
}
