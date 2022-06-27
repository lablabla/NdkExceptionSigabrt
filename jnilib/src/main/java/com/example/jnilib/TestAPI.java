package com.example.jnilib;

public class TestAPI {
    protected long nativeTestAPI;

    public TestAPI() {
        nativeTestAPI = TestAPIJni.init();
    }

    public void Release() {
        TestAPIJni.release(nativeTestAPI);
    }

}
