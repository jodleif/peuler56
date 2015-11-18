#pragma once
#include <boost/multiprecision/cpp_int.hpp>
namespace peuler55 {
	using boost::multiprecision::uint512_t;

	int digital_sum(const uint512_t& num);
	uint512_t iexp(uint_fast32_t x, unsigned n);
	int max_digital_sum();


#ifdef _DEBUG
	namespace test {
		void digital_sum_test();
		void iexp_test();
		void all_tests();
	}
#endif
}