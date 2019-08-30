#include <stdio.h>
#include <sys/time.h>
#include <iostream>
#include "premises.h"
#include "instances.h"

using namespace std;

int main() {
	timeval time;
	double initial;
	double final;
	gettimeofday(&time,0);
	initial = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);

	instance::main::at::atStatus::setValue(true);
	gettimeofday(&time,0);
	final = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
	double resultado = final - initial;
	cout << resultado << endl;
	return 0;
}
