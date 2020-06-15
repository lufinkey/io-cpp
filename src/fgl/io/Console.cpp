//
//  Console.cpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#include "Console.hpp"
#include <iostream>

namespace fgl {
	namespace console {
		const char* TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S %z";
		
		String getLogPrefix() {
			char timestamp[255];
			time_t rawTime = time(NULL);
			struct tm* timeVal = localtime(&rawTime);
			strftime(timestamp, sizeof(timestamp), TIMESTAMP_FORMAT, timeVal);
			return timestamp;
		}
	}
	
	void console::log(const String& output) {
		writeLine("[", getLogPrefix(), "]: ", output);
	}

	void console::write(const String& output) {
		std::cout << output;
	}

	void console::writeLine(const String& output) {
		std::cout << output << std::endl;
	}

	void console::error(const String& output) {
		writeErrLine("[", getLogPrefix(), "]: ", output);
	}

	void console::writeErr(const String& output) {
		std::cerr << output;
	}

	void console::writeErrLine(const String& output) {
		std::cerr << output << std::endl;
	}
}
