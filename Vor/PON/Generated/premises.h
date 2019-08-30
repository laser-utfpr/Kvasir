#pragma once
#include <string>
#include <iostream>
namespace premise {
	namespace main {
		namespace PrTest {
			extern bool state;
			extern bool cpy1st, cpy2nd;
			extern void compare();
			extern void notify_this_atStatus(bool newValue);
		}
	}
}
