package com.lufinkey;

public class IOCpp {
	static {
		loadLibraries();
	}

	public static void loadLibraries() {
		com.lufinkey.DataCpp.loadLibraries();
		com.lufinkey.AsyncCpp.loadLibraries();
		System.loadLibrary("IOCpp");
	}
}
