//
//  Console.hpp
//  IOCpp-macOS
//
//  Created by Luis Finke on 2/26/20.
//  Copyright © 2020 Luis Finke. All rights reserved.
//

#pragma once

#include <fgl/io/Common.hpp>

namespace fgl {
	namespace console {
		void log(const String& output);
		void write(const String& output);
		void writeLine(const String& output);
		void error(const String& output);
		void writeErr(const String& output);
		void writeErrLine(const String& output);
	
		template<typename... T>
		void log(T... arg) {
			log(String::join({ stringify<T>(arg)... }, " "));
		}
	
		template<typename... T>
		void write(T... arg) {
			write(String::join({ stringify<T>(arg)... }));
		}
	
		template<typename... T>
		void writeLine(T... arg) {
			writeLine(String::join({ stringify<T>(arg)... }));
		}
	
		template<typename... T>
		void error(T... arg) {
			error(String::join({ stringify<T>(arg)... }, " "));
		}
	
		template<typename... T>
		void writeErr(T... arg) {
			writeErr(String::join({ stringify<T>(arg)... }));
		}
	
		template<typename... T>
		void writeErrLine(T... arg) {
			writeErrLine(String::join({ stringify<T>(arg)... }));
		}
	}
}
