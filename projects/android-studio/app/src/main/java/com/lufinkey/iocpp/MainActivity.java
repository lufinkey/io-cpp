package com.lufinkey.iocpp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
	static {
		com.lufinkey.libdatacpp.DataCpp.loadLibraries();
		com.lufinkey.libasynccpp.AsyncCpp.loadLibraries();
		com.lufinkey.libiocpp.IOCpp.loadLibraries();
		System.loadLibrary("native-lib");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	native String stringFromJNI();
}
