#include <jni.h>
#include <string>
#include <fgl/io.hpp>
#include <test/IOCppTests.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_lufinkey_iocpp_MainActivity_stringFromJNI(
		JNIEnv *env,
		jobject /* this */) {
	std::string hello = "Hello from C++";
	fgl_io_cpp_tests::runTests();
	return env->NewStringUTF(hello.c_str());
}
