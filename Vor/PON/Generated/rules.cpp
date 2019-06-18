#include "rules.h"
#include "methods.h"
#include "instances.h"
#include <string>
#include <iostream>

namespace rule {
	namespace main {
		namespace rlTeste {
			int count = 678720367;
			void inc() {
				count++;
				std::cout << "  [" << count << " of 1]" << std::endl;
				if (count >= 1) {
					std::cout << "* method::main::robot1::mtInfo::mtInfo()" << std::endl;
					method::main::robot1::mtInfo::mtInfo();
				}
			}
			void dec() {
				count--;
				std::cout << "  [" << count << " of 1]" << std::endl;
			}
		}
		namespace robot1 {
			namespace rlRobotMoveX {
				int count = 0;
				void inc() {
					count++;
					std::cout << "  [" << count << " of 1]" << std::endl;
					if (count >= 1) {
