#include "premises.h"
#include "rules.h"
#include <string>
#include <iostream>

        #include <iostream>
        using namespace std;
    
namespace premise {
	namespace main {
		namespace PrTest {
			bool state = (false);
			bool cpy1st = false;
			bool cpy2nd = true;
			void compare() {
				if (cpy1st == cpy2nd) {
					if (state == false) {
						state = true;
						std::cout << "+ rule::main::rlTeste::inc();";
						rule::main::rlTeste::inc();
					}
				} else {
					if (state == true) {
						state = false;
						std::cout << "- rule::main::rlTeste::dec();";
						rule::main::rlTeste::dec();
					}
				}
			}
			void notify_this_atStatus(bool newValue) {
				cpy1st = newValue;
				compare();
			}
		}
	}
}
