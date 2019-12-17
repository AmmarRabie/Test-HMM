/*
this file should cover the following functions in hmm.h
- hmm_vec3 HMM_Cross(hmm_vec3 VecOne, hmm_vec3 VecTwo);
*/
#include <boost/test/unit_test.hpp>
#include "HMM.h"
namespace utf = boost::unit_test;
BOOST_AUTO_TEST_SUITE(S_HMM_Cross)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    hmm_vec3 left = HMM_Vec3i(0, 0, 0), right = HMM_Vec3i(0, 0, 0);
    auto res = HMM_Cross(left, right);
    BOOST_TEST(res.X == 0);
    BOOST_TEST(res.Y == 0);
    BOOST_TEST(res.Z == 0);

    left = HMM_Vec3i(0, 0, 0);
    right = HMM_Vec3i(12, -5, 546);
    res = HMM_Cross(left, right);

    BOOST_TEST(res.X == 0);
    BOOST_TEST(res.Y == 0);
    BOOST_TEST(res.Z == 0);

    left = HMM_Vec3i(100, 274, -765);
    right = HMM_Vec3i(0, 0, 0);
    res = HMM_Cross(left, right);

    BOOST_TEST(res.X == 0);
    BOOST_TEST(res.Y == 0);
    BOOST_TEST(res.Z == 0);
}

BOOST_AUTO_TEST_CASE(TC2_Positive) {
    hmm_vec3 left = HMM_Vec3i(12, 23, 547), right = HMM_Vec3i(7, 87, 62);
    auto res = HMM_Cross(left, right);
    BOOST_TEST(res.X == -46163);
    BOOST_TEST(res.Y == 3085);
    BOOST_TEST(res.Z == 883);

    left = HMM_Vec3i(12, 21, 32);
    right = HMM_Vec3i(11, 31, 333);
    res = HMM_Cross(left, right);
    BOOST_TEST(res.X == 6001);
    BOOST_TEST(res.Y == -3644);
    BOOST_TEST(res.Z == 141);
}
BOOST_AUTO_TEST_CASE(TC3_Negative) {
    hmm_vec3 left = HMM_Vec3i(-31, -100, -34), right = HMM_Vec3i(-74, -69, -32);
    auto res = HMM_Cross(left, right);
    hmm_vec3 assertionResult = HMM_Vec3i(854, 1524, -5261);
    BOOST_TEST(res.X == 854);
    BOOST_TEST(res.Y == 1524);
    BOOST_TEST(res.Z == -5261);

    assertionResult = HMM_Vec3i(-3, 540, -254);
    left = HMM_Vec3i(-22, -10, -21);
    right = HMM_Vec3i(-32, -3, -6);
    res = HMM_Cross(left, right);

    BOOST_TEST(res.X == -3);
    BOOST_TEST(res.Y == 540);
    BOOST_TEST(res.Z == -254);
}

BOOST_AUTO_TEST_CASE(TC4_PosNeg) {
    hmm_vec3 left = HMM_Vec3i(-129, -213, -5847), right = HMM_Vec3i(7, 87, 62);
    auto res = HMM_Cross(left, right);
    hmm_vec3 assertionResult = HMM_Vec3i(495483, -32931, -9732);

    BOOST_TEST(res.X == 495483);
    BOOST_TEST(res.Y == -32931);
    BOOST_TEST(res.Z == -9732);

    assertionResult = HMM_Vec3i(-287, -4280, 1992);
    left = HMM_Vec3i(32, 43, 97);
    right = HMM_Vec3i(-56, -13, -36);
    res = HMM_Cross(left, right);

    BOOST_TEST(res.X == -287);
    BOOST_TEST(res.Y == -4280);
    BOOST_TEST(res.Z == 1992);

    assertionResult = HMM_Vec3i(16605, -2377, -4623);
    left = HMM_Vec3i(-153, -921, -76);
    right = HMM_Vec3i(-11, -36, -21);
    res = HMM_Cross(left, right);

    BOOST_TEST(res.X == 16605);
    BOOST_TEST(res.Y == -2377);
    BOOST_TEST(res.Z == -4623);
}

BOOST_AUTO_TEST_SUITE_END()
