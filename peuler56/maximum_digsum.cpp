#include "maximum_digsum.h"
#include <string>
#include <boost/lexical_cast.hpp>
#include <thread>
#include <algorithm>

int peuler56::digital_sum(const uint1024_t& num)
{
	auto num_str = num.convert_to<std::string>();
	auto end = num_str.data() + num_str.size();
	int digital_sum{ 0 };
	for (auto ptr = num_str.data();ptr < end;++ptr) {
		digital_sum += boost::lexical_cast<int, char>(*ptr);
	}
	return digital_sum;
}

int peuler56::digital_sum2(const uint1024_t& num)
{
	auto workset{ num };
	int sum{ 0 };
	while(workset!=0) {
		sum += static_cast<int>(workset % 10);
		workset /= 10;
	}
	return sum;
}


// Hackers delight p288
boost::multiprecision::uint1024_t peuler56::iexp(uint_fast32_t base, unsigned n)
{
	auto res = uint1024_t{ 1u };
	auto x = uint1024_t{ base };
	while(1) {
		if (n & 1) res = x * res;
		n = n >> 1; // Shift exponent
		if (n == 0) return res;
		x = x*x;
	}
}

int peuler56::max_digital_sum()
{
	return max_digital_sum(1u, 100u);
}

int peuler56::max_digital_sum(uint_fast32_t from, uint_fast32_t to)
{

	int temp_max{ 0 };
	for (uint_fast32_t a = from; a < to;++a) {
		for (unsigned n = from; n < to;++n) {
			auto res = iexp(a, n);
			auto new_sum = digital_sum2(res);
			if (new_sum > temp_max) temp_max = new_sum;
		}
	}
	return temp_max;
}

int peuler56::threaded_max_digital_sum()
{
	int res1{ 0 };
	int res2{ 0 };
	int res3{ 0 };
	int res4{ 0 };
	auto t1 = std::thread([&res1]()
	{
		res1 = max_digital_sum(1u, 70u);
	});
	auto t2 = std::thread([&res2]()
	{
		res2 = max_digital_sum(70u, 90u);
	});
	auto t3 = std::thread([&res3]()
	{
		res3 = max_digital_sum(90u, 95u);
	});
	auto t4 = std::thread([&res4]()
	{
		res4 = max_digital_sum(95u, 100u);
	});
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return std::max({ res1,res2,res3,res4 });
}
#ifdef _DEBUG
#include <cassert>
void peuler56::test::digital_sum_test()
{
	uint1024_t sum1{ "123456789" };
	uint1024_t sum2{ 123u };
	assert(digital_sum(sum1) == 45);
	assert(digital_sum(sum2) == 6);
}

void peuler56::test::digital_sum2_test()
{
	uint1024_t sum1{ "123456789" };
	uint1024_t sum2{ 123u };
	assert(digital_sum2(sum1) == 45);
	assert(digital_sum2(sum2) == 6);
}

void peuler56::test::iexp_test()
{
	uint1024_t res1{ 1000 };
	uint1024_t res2{ 512 };
	assert(iexp(10, 3) == res1);
	assert(iexp(2, 9) == res2);
}

void peuler56::test::all_tests()
{
	digital_sum_test();
	digital_sum2_test();
	iexp_test();
}
#endif
