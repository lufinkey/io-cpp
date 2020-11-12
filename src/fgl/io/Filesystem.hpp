//
//  Filesystem.hpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#pragma once

#include <fgl/io/Common.hpp>
#include <fstream>
#include <ios>

namespace fgl {
	namespace fs {
		namespace OpenMode {
			static const auto app = std::ios::app;
			static const auto ate = std::ios::ate;
			static const auto binary = std::ios::binary;
			static const auto in = std::ios::in;
			static const auto out = std::ios::out;
			static const auto trunc = std::ios::trunc;
		};

		bool exists(const String& path);
		Promise<bool> existsAsync(const String& path);
	
		struct ReadFileOptions {
			std::ios_base::openmode mode = OpenMode::in;
		};
		String readFile(const String& path, ReadFileOptions options = ReadFileOptions());
		Promise<String> readFileAsync(const String& path, ReadFileOptions options = ReadFileOptions());
	
		struct WriteFileOptions {
			std::ios_base::openmode mode = OpenMode::out;
		};
		void writeFile(const String& path, const String& data, WriteFileOptions options = WriteFileOptions());
		Promise<void> writeFileAsync(const String& path, const String& data, WriteFileOptions options = WriteFileOptions());
	
		void createDirectory(const String& path);
		Promise<void> createDirectoryAsync(const String& path);
		void createDirectories(const String& path);
		Promise<void> createDirectoriesAsync(const String& path);
		
		bool remove(const String& path);
		Promise<bool> removeAsync(const String& path);
		uintmax_t removeAll(const String& path);
		Promise<uintmax_t> removeAllAsync(const String& path);
	
		String temporaryDirectory();
	}
}
