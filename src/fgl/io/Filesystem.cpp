//
//  Filesystem.cpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#include "Filesystem.hpp"
#include <filesystem>

namespace fgl {
	using stdfs = std::filesystem;

	bool fs::exists(const String& path) {
		std::error_code error;
		return stdfs::exists(path, error);
	}

	Promise<bool> fs::existsAsync(const String& path) {
		return promiseThread([=]() {
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
		return promiseThread([=]() {
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
		return promiseThread([=]() {
			return fs::writeFile(path, data, options);
		});
	}



	void fs::createDirectory(const String& path) {
		stdfs::create_directory(path);
	}

	Promise<void> fs::createDirectoryAsync(const String& path) {
		return promiseThread([=]() {
			return createDirectory(path);
		});
	}

	void fs::createDirectories(const String& path) {
		stdfs::create_directories(path);
	}

	Promise<void> fs::createDirectoriesAsync(const String& path) {
		return promiseThread([=]() {
			return createDirectories(path);
		});
	}



	bool fs::remove(const String& path) {
		return stdfs::remove(path);
	}

	Promise<bool> fs::removeAsync(const String& path) {
		return promiseThread([=]() {
			return fs::remove(path);
		});
	}

	uintmax_t fs::removeAll(const String& path) {
		return stdfs::remove_all(path);
	}

	Promise<uintmax_t> fs::removeAllAsync(const String& path) {
		return promiseThread([=]() {
			return fs::removeAll(path);
		});
	}



	String fs::temporaryDirectory() {
		return stdfs::temp_directory_path().string();
	}
}
