//
//  JNIIOCpp.cpp
//  IOCpp
//
//  Created by Luis Finke on 6/30/2021.
//  Copyright © 2021 Luis Finke. All rights reserved.
//

#ifdef __ANDROID__
#include <fgl/io/JNIIOCpp.hpp>
#include <android/log.h>

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	__android_log_print(ANDROID_LOG_DEBUG, "IOCpp", "JNI module loaded");
	return JNI_VERSION_1_6;
}

#endif