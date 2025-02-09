#include "stdafx.h"
#define BOOST_TEST_MODULE HMM
#include <boost/test/included/unit_test.hpp>

#define HANDMADE_MATH_IMPLEMENTATION
#define HANDMADE_MATH_CPP_MODE
#include "HMM.h"

namespace utf = boost::unit_test;
namespace tt = boost::test_tools;
#define TOLERANCE *boost::unit_test::tolerance(0.00001)
#include "register_tests.h"



// if you use it, remove "#define BOOST_TEST_MODULE HMM" above
//test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
//{
//	int params[] = { 1, 2, 3, 4, 5 };
//	auto x = HMM_LogF(5.4);
//	cout << "x = " << x;
//	return 0;
//	framework::master_test_suite().
//		add(BOOST_PARAM_TEST_CASE(&free_test_function, params, params + 5));
//
//	return 0;
//}