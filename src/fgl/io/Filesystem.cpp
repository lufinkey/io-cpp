//
//  Filesystem.cpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#include "Filesystem.hpp"

namespace fgl {
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
		return fgl::async<String>([=]() {
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
		return fgl::async<void>([=]() {
			return fs::writeFile(path, data, options);
		});
	}


	bool fs::remove(const String& path) {
		return std::filesystem::remove(path.c_str());
	}

	Promise<bool> fs::removeAsync(const String& path) {
		return fgl::async<bool>([=]() {
			return fs::remove(path);
		});
	}

	uintmax_t fs::removeAll(const String& path) {
		return std::filesystem::remove_all(path.c_str());
	}

	Promise<uintmax_t> fs::removeAllAsync(const String& path) {
		return fgl::async<uintmax_t>([=]() {
			return fs::removeAll(path);
		});
	}
}
