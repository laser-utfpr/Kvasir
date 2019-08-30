#include "instances.h"
#include "premises.h"
#include <string>
#include <iostream>

        #include <iostream>
        using namespace std;
    
namespace instance {
	namespace main {
		namespace at {
			namespace atStatus {
				bool value = false;
				void setValue(bool newValue) {
					if (value != newValue) {
						value = newValue;
						std::cout << "= premise::main::PrTest::notify_this_atStatus(" << newValue << ")" << std::endl;
						premise::main::PrTest::notify_this_atStatus(newValue);
					}
				}
			}
		}
	}
}
