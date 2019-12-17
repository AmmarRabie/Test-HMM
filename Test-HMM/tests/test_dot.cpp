/*
this file should cover the following functions in hmm.h
- float HMM_DotVec2(hmm_vec2 VecOne, hmm_vec2 VecTwo);
- float HMM_DotVec3(hmm_vec3 VecOne, hmm_vec3 VecTwo);
- float HMM_DotVec4(hmm_vec4 VecOne, hmm_vec4 VecTwo);
*/
#include <boost/test/unit_test.hpp>
#include "HMM.h"
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(S_HMM_DotVec2)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    hmm_vec2 left = HMM_Vec2i(0, 0), right = HMM_Vec2i(0, 0);
    auto res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 0);
    left = HMM_Vec2i(0, 0);
    right = HMM_Vec2i(-5, 546);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 0);

    left = HMM_Vec2i(274, -765);
    right = HMM_Vec2i(0, 0);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_CASE(TC2_Positives) {
    hmm_vec2 left = HMM_Vec2i(3, 2), right = HMM_Vec2i(2, 3);
    auto res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 12);

    left = HMM_Vec2i(39, 31), right = HMM_Vec2i(97, 45);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 5178);
}

BOOST_AUTO_TEST_CASE(TC3_Negatives) {
    hmm_vec2 left = HMM_Vec2i(-23, -982), right = HMM_Vec2i(-32, -543);
    auto res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 533962);

    left = HMM_Vec2i(-39, -131), right = HMM_Vec2i(-397, -845);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 126178);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg) {
    hmm_vec2 left = HMM_Vec2i(-58, -9), right = HMM_Vec2i(32, 543);
    auto res = HMM_DotVec2(left, right);
    BOOST_TEST(res == -6743);

    left = HMM_Vec2i(-39, -131), right = HMM_Vec2i(397, 845);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == -126178);

    left = HMM_Vec2i(-12, 112), right = HMM_Vec2i(19, -62);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == -7172);

    left = HMM_Vec2i(82, -74), right = HMM_Vec2i(-33, 52);
    res = HMM_DotVec2(left, right);
    BOOST_TEST(res == -6554);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    hmm_vec2 left = HMM_Vec2i(INT_MAX, INT_MAX), right = HMM_Vec2i(INT_MAX, -1 * INT_MAX);
    auto res = HMM_DotVec2(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_DotVec3)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    hmm_vec3 left = HMM_Vec3i(0, 0, 0), right = HMM_Vec3i(0, 0, 0);
    auto res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 0);
    left = HMM_Vec3i(0, 0, 0);
    right = HMM_Vec3i(12, -5, 546);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 0);

    left = HMM_Vec3i(100, 274, -765);
    right = HMM_Vec3i(0, 0, 0);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_CASE(TC2_Positives) {
    hmm_vec3 left = HMM_Vec3i(10, 3, 2), right = HMM_Vec3i(15, 2, 3);
    auto res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 162);

    left = HMM_Vec3i(97, 39, 31), right = HMM_Vec3i(10, 97, 45);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 6148);
}

BOOST_AUTO_TEST_CASE(TC3_Negatives) {
    hmm_vec3 left = HMM_Vec3i(-3, -23, -982), right = HMM_Vec3i(-999, -32, -543);
    auto res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 536959);

    left = HMM_Vec3i(-12, -39, -131), right = HMM_Vec3i(-1, -397, -845);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 126190);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg) {
    hmm_vec3 left = HMM_Vec3i(-12, -58, -9), right = HMM_Vec3i(12, 32, 543);
    auto res = HMM_DotVec3(left, right);
    BOOST_TEST(res == -6887);

    left = HMM_Vec3i(-9, -39, -131), right = HMM_Vec3i(12, 397, 845);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == -126286);

    left = HMM_Vec3i(-3, -12, 112), right = HMM_Vec3i(221, 19, -62);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == -7835);

    left = HMM_Vec3i(12, 82, -74), right = HMM_Vec3i(-43, -33, 52);
    res = HMM_DotVec3(left, right);
    BOOST_TEST(res == -7070);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    hmm_vec3 left = HMM_Vec3i(INT_MAX, INT_MAX, INT_MAX), right = HMM_Vec3i(0, INT_MAX, -1 * INT_MAX);
    auto res = HMM_DotVec3(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_DotVec4)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    hmm_vec4 left = HMM_Vec4i(0, 0, 0, 0), right = HMM_Vec4i(0, 0, 0, 0);
    auto res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 0);
    left = HMM_Vec4i(0, 0, 0, 0);
    right = HMM_Vec4i(0, 12, -5, 546);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 0);

    left = HMM_Vec4i(-1, 100, 274, -765);
    right = HMM_Vec4i(0, 0, 0, 0);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_CASE(TC2_Positives) {
    hmm_vec4 left = HMM_Vec4i(11, 10, 3, 2), right = HMM_Vec4i(1, 15, 2, 3);
    auto res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 173);

    left = HMM_Vec4i(111, 97, 39, 31), right = HMM_Vec4i(42, 10, 97, 45);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 10810);
}

BOOST_AUTO_TEST_CASE(TC3_Negatives) {
    hmm_vec4 left = HMM_Vec4i(-99, -3, -23, -982), right = HMM_Vec4i(-12, -999, -32, -543);
    auto res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 538147);

    left = HMM_Vec4i(-4, -12, -39, -131), right = HMM_Vec4i(-3, -1, -397, -845);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 126202);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg) {
    hmm_vec4 left = HMM_Vec4i(-99, -12, -58, -9), right = HMM_Vec4i(1111, 12, 32, 543);
    auto res = HMM_DotVec4(left, right);
    BOOST_TEST(res == -116876);

    left = HMM_Vec4i(9, 39, 131, 47), right = HMM_Vec4i(-12, -397, -845, -12);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == -126850);

    left = HMM_Vec4i(12, -3, -12, 112), right = HMM_Vec4i(-99, 221, 19, -62);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == -9023);

    left = HMM_Vec4i(-97, 12, 82, -74), right = HMM_Vec4i(28, -43, -33, 52);
    res = HMM_DotVec4(left, right);
    BOOST_TEST(res == -9786);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    hmm_vec4 left = HMM_Vec4i(INT_MAX, INT_MAX, INT_MAX, INT_MAX), right = HMM_Vec4i(-1 * INT_MAX, INT_MAX, -1 * INT_MAX, INT_MAX);
    auto res = HMM_DotVec4(left, right);
    BOOST_TEST(res == 0);
}
BOOST_AUTO_TEST_SUITE_END()
