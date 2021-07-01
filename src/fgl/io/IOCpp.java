package com.lufinkey.libiocpp;

public class IOCpp {
	static {
		loadLibraries();
	}

	public static void loadLibraries() {
		com.lufinkey.libdatacpp.DataCpp.loadLibraries();
		com.lufinkey.libasynccpp.AsyncCpp.loadLibraries();
		System.loadLibrary("IOCpp");
	}
}
