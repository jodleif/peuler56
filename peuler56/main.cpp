/*
	18.11.2015 - Jo �ivind Gjernes
	Project euler 56
	A googol (10^100) is a massive number: one followed by one-hundred zeros; 
	100^100 is almost unimaginably large: one followed by two-hundred zeros. 
	Despite their size, the sum of the digits in each number is only 1.

	Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
*/


#include <iostream>
#include "maximum_digsum.h"
#include "timer/bench_timer.h"

int main()
{
	std::cout << "Project euler 56 - \n";
#ifdef _DEBUG
	peuler56::test::all_tests();
	std::cout << "Tests ok!\n";
	std::cin.get();
#endif
	bench_timer bt;
	std::cout << "Max digital sum is: " << peuler56::threaded_max_digital_sum() << "\n";
	return 0;
}
