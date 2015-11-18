#include "maximum_digsum.h"
#include <string>
#include <boost/lexical_cast.hpp>

int peuler55::digital_sum(const uint512_t& num)
{
	auto num_str = num.convert_to<std::string>();
	auto end = num_str.data() + num_str.size();
	int digital_sum{ 0 };
	for (auto ptr = num_str.data();ptr < end;++ptr) {
		digital_sum += boost::lexical_cast<int, char>(*ptr);
	}
	return digital_sum;
}


// Hackers delight p288
boost::multiprecision::uint512_t peuler55::iexp(uint_fast32_t base, unsigned n)
{
	auto res = uint512_t{ 1u };
	auto x = uint512_t{ base };
	while(1) {
		if (n & 1) res = x * res;
		n = n >> 1; // Shift exponent
		if (n == 0) return res;
		x = x*x;
	}
}

int peuler55::max_digital_sum()
{
	int temp_max{ 0 };
	for (uint_fast32_t a = 1; a < 100;++a) {
		for (unsigned n = 1; n < 100u;++n) {
			auto res = iexp(a, n);
			auto new_sum = digital_sum(res);
			if (new_sum > temp_max) temp_max = new_sum;
		}
	}
	return temp_max;
}
#ifdef _DEBUG
#include <cassert>
void peuler55::test::digital_sum_test()
{
	uint512_t sum1{ "123456789" };
	uint512_t sum2{ 123u };
	assert(digital_sum(sum1) == 45);
	assert(digital_sum(sum2) == 6);
}

void peuler55::test::iexp_test()
{
	uint512_t res1{ 1000 };
	uint512_t res2{ 512 };
	assert(iexp(10, 3) == res1);
	assert(iexp(2, 9) == res2);
}

void peuler55::test::all_tests()
{
	digital_sum_test();
	iexp_test();
}
#endif
