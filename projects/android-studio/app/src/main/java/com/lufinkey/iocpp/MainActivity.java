package com.lufinkey.iocpp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
	static {
		com.lufinkey.DataCpp.loadLibraries();
		com.lufinkey.AsyncCpp.loadLibraries();
		com.lufinkey.IOCpp.loadLibraries();
		System.loadLibrary("TestApp");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	native String stringFromJNI();
}
