#include "rules.h"
#include "methods.h"
#include "instances.h"
#include <string>
#include <iostream>

        #include <iostream>
        using namespace std;
    
namespace rule {
	namespace main {
		namespace rlTeste {
			int count = 0;
			void inc() {
				count++;
				std::cout << "  [" << count << " of 1]" << std::endl;
				if (count >= 1) {
					std::cout << "* method::main::mtMove::mtMove()" << std::endl;
					method::main::mtMove::mtMove();
				}
			}
			void dec() {
				count--;
				std::cout << "  [" << count << " of 1]" << std::endl;
			}
		}
	}
}
