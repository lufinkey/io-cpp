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
	void console::log(const String& output) {
		writeLine(output);
	}

	void console::write(const String& output) {
		std::cout << output;
	}

	void console::writeLine(const String& output) {
		std::cout << output << std::endl;
	}

	void console::error(const String& output) {
		writeErrLine(output);
	}

	void console::writeErr(const String& output) {
		std::cerr << output;
	}

	void console::writeErrLine(const String& output) {
		std::cerr << output << std::endl;
	}
}
