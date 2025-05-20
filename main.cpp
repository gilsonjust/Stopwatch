#include <iostream>
#include <cassert>
#include "Stopwatch.hpp"

static void foo()
{
	volatile int x = 0; 
	x++;
}

int main()
{
	Stopwatch sw1(Stopwatch::Scale::millisec);
	Stopwatch sw2(Stopwatch::Scale::microsec);
	Stopwatch sw3(Stopwatch::Scale::nanosec);

	sw1.start(); 
	sw2.start(); 
	sw3.start();
	
	for (int i = 0; i < 999999; i++) 
		foo();
	
	sw1.stop(); 
	sw2.stop(); 
	sw3.stop();

	std::cout << "ms: " << sw1.getElapsedTimeAsStr() << "\n";
	std::cout << "us: " << sw2.getElapsedTimeAsStr() << "\n";
	std::cout << "ns: " << sw3.getElapsedTimeAsStr() << "\n";

	assert(sw1.getElapsedTime() > 0);
	assert(sw2.getElapsedTime() > 0);
	assert(sw3.getElapsedTime() > 0);

	return EXIT_SUCCESS;
}