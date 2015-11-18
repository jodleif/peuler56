#pragma once
#include <boost/multiprecision/cpp_int.hpp>
namespace peuler56 {
	using boost::multiprecision::uint1024_t;

	int digital_sum(const uint1024_t& num);
	int digital_sum2(const uint1024_t& num);
	uint1024_t iexp(uint_fast32_t x, unsigned n);
	int max_digital_sum();
	int max_digital_sum(uint_fast32_t from, uint_fast32_t to);
	int threaded_max_digital_sum();


#ifdef _DEBUG
	namespace test {
		void digital_sum_test();
		void digital_sum2_test();
		void iexp_test();
		void all_tests();
	}
#endif
}