//
//  Filesystem.cpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#include "Filesystem.hpp"
#ifdef __ANDROID__
	#include <ghc/filesystem.hpp>
	namespace stdfs = ghc::filesystem;
#else
	#include <filesystem>
	namespace stdfs = std::filesystem;
#endif

namespace fgl {
	bool fs::exists(const String& path) {
		std::error_code error;
		return stdfs::exists(path.storage, error);
	}

	Promise<bool> fs::existsAsync(const String& path) {
		return async<bool>([=]() {
			return fs::exists(path);
		});
	}



	String fs::readFile(const String& path, ReadFileOptions options) {
		std::ifstream file;
		String data;
		try {
			file.exceptions(std::ios::failbit | std::ios::badbit);
			file.open(path.c_str(), options.mode);
			data = String(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
			file.close();
		} catch(...) {
			if(file.is_open()) {
				file.close();
			}
			std::rethrow_exception(std::current_exception());
		}
		return data;
	}

	Promise<String> fs::readFileAsync(const String& path, ReadFileOptions options) {
		return async<String>([=]() {
			return fs::readFile(path, options);
		});
	}



	void fs::writeFile(const String& path, const String& data, WriteFileOptions options) {
		std::ofstream file;
		try {
			file.exceptions(std::ios::failbit | std::ios::badbit);
			file.open(path.c_str(), options.mode);
			file << data;
			file.close();
		} catch(...) {
			if(file.is_open()) {
				file.close();
			}
			std::rethrow_exception(std::current_exception());
		}
	}

	Promise<void> fs::writeFileAsync(const String& path, const String& data, WriteFileOptions options) {
		return async<void>([=]() {
			return fs::writeFile(path, data, options);
		});
	}



	void fs::createDirectory(const String& path) {
		stdfs::create_directory(path.storage);
	}

	Promise<void> fs::createDirectoryAsync(const String& path) {
		return async<void>([=]() {
			return createDirectory(path);
		});
	}

	void fs::createDirectories(const String& path) {
		stdfs::create_directories(path.storage);
	}

	Promise<void> fs::createDirectoriesAsync(const String& path) {
		return async<void>([=]() {
			return createDirectories(path);
		});
	}



	bool fs::remove(const String& path) {
		return stdfs::remove(path.storage);
	}

	Promise<bool> fs::removeAsync(const String& path) {
		return async<bool>([=]() {
			return fs::remove(path);
		});
	}

	uintmax_t fs::removeAll(const String& path) {
		return stdfs::remove_all(path.storage);
	}

	Promise<uintmax_t> fs::removeAllAsync(const String& path) {
		return async<uintmax_t>([=]() {
			return fs::removeAll(path);
		});
	}
}
