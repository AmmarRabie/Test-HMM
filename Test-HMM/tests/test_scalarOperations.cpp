/*
this file should cover the following functions in hmm.h
- float HMM_SinF(float Angle)
- float HMM_TanF(float Angle)
- float HMM_CosF(float Angle)
- float HMM_ExpF(float Float)
- float HMM_LogF(float Float)
- float HMM_ToRadians(float Degrees)
- float HMM_SquareRootF(float Float)
- float HMM_RSquareRootF(float Float)
- float HMM_Power(float Base, int Exponent)
- float HMM_PowerF(float Base, float Exponent)
- float HMM_Lerp(float A, float Time, float B)
- float HMM_Clamp(float Min, float Value, float Max)
*/
#include <boost/test/unit_test.hpp>
#include "HMM.h"
#include "cmath"
namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(HMM_Scalar)

BOOST_AUTO_TEST_CASE(SIN) {
    BOOST_TEST(HMM_SINF(0) == sin(0),tt::tolerance(0.00001));
    BOOST_TEST(HMM_SINF(10) == sin(10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_SINF(-10) == sin(-10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_SINF(100) == sin(100),tt::tolerance(0.00001));
    BOOST_TEST(HMM_SINF(+0.005) == sin(+0.005),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(COS) {
    BOOST_TEST(HMM_COSF(0) == cos(0),tt::tolerance(0.00001));
    BOOST_TEST(HMM_COSF(10) == cos(10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_COSF(-10) == cos(-10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_COSF(100) == cos(100),tt::tolerance(0.00001));
    BOOST_TEST(HMM_COSF(+0.005) == cos(+0.005),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(TAN) {
    BOOST_TEST(HMM_TANF(0) == tan(0),tt::tolerance(0.00001));
    BOOST_TEST(HMM_TANF(10) == tan(10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_TANF(-10) == tan(-10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_TANF(90) == tan(90),tt::tolerance(0.00001));
    BOOST_TEST(HMM_TANF(HMM_PI32) == tan(HMM_PI32),tt::tolerance(0.00001));
    BOOST_TEST(HMM_TANF(+0.005) == tan(+0.005),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(EXP) {
    BOOST_TEST(HMM_EXPF(0) == exp(0),tt::tolerance(0.00001));
    BOOST_TEST(HMM_EXPF(10) == exp(10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_EXPF(-10) == exp(-10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_EXPF(90) == exp(90),tt::tolerance(0.00001));
    BOOST_TEST(HMM_EXPF(+0.005) == exp(+0.005),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(LOGF) {
    BOOST_TEST(HMM_LOGF(0) == log(0),tt::tolerance(0.00001));
    BOOST_TEST(HMM_LOGF(1) == log(1),tt::tolerance(0.00001));
    BOOST_TEST(HMM_LOGF(10) == log(10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_LOGF(-10) == log(-10),tt::tolerance(0.00001));
    BOOST_TEST(HMM_LOGF(90) == log(90),tt::tolerance(0.00001));
    BOOST_TEST(HMM_LOGF(+0.005) == log(+0.005),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(ToRadians) {
    BOOST_TEST(HMM_ToRadians(0) == 0,tt::tolerance(0.00001));
    BOOST_TEST(HMM_ToRadians(90) == HMM_PI32 / 2,tt::tolerance(0.00001));
    BOOST_TEST(HMM_ToRadians(45) == HMM_PI32 / 4,tt::tolerance(0.00001));
    BOOST_TEST(HMM_ToRadians(405) == 9 * HMM_PI32 / 4,tt::tolerance(0.00001));
    BOOST_TEST(HMM_ToRadians(-30) == -1 * HMM_PI32 / 6,tt::tolerance(0.00001));
    BOOST_TEST(HMM_ToRadians(-90) == -1 * HMM_PI32 / 2,tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(SQUAREROOT) {
    BOOST_TEST(HMM_SquareRootF(0) == 0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_SquareRootF(90) == sqrt(90),tt::tolerance(0.00001));

    BOOST_TEST(HMM_SquareRootF(45) == sqrt(45),tt::tolerance(0.00001));

    BOOST_TEST(HMM_SquareRootF(405) == sqrt(405),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(Power) {
    BOOST_TEST(HMM_PowerF(0, 10) == 0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_PowerF(5, 2) == 25.0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_PowerF(2, -3) == (1.0 / 8),tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(LERP) {
    BOOST_TEST(HMM_Lerp(10, 0.5, 20) == 15.0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Lerp(-20, 0.5, 20) == 0.0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Lerp(-10, 0.5, -20) == -15.0,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Lerp(0, 0, 0) == 0,tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_CASE(Clammp) {
    BOOST_TEST(HMM_Clamp(-10, 5, 20) == 5,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Clamp(-10, 25, 20) == 20,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Clamp(-10, -11, 20) == -10,tt::tolerance(0.00001));

    BOOST_TEST(HMM_Clamp(0.0005, 0.0006, 0.0007) == 0.0006,tt::tolerance(0.00001));
}

BOOST_AUTO_TEST_SUITE_END()
