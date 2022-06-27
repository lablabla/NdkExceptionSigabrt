
#include "TestAPI.h"
#include "MyException.h"
#include <jni.h>
#include <android/log.h>

extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_jnilib_TestAPIJni_init(JNIEnv *env, jclass clazz) {
    try {
        auto *ptr = new test::Tester();
        return (long) ptr;
    }
    catch (test::exception::MyException& ex)
    {
        __android_log_print(ANDROID_LOG_ERROR, "ExceptionJNI", "Caught exception!!! (%s) (%d)", ex.what(), ex.status());
    }
    return 0;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jnilib_TestAPIJni_release(JNIEnv *env, jclass clazz, jlong nativeAddress) {
    auto *ptr = (test::Tester*)nativeAddress;
    if (ptr != nullptr)
    {
        delete ptr;
    }
}