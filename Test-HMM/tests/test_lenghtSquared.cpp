/*
this file should cover the following functions in hmm.h
- HMMDEF float HMM_LengthSquaredVec2(hmm_vec2 A)
- HMMDEF float HMM_LengthSquaredVec3(hmm_vec3 A)
- HMMDEF float HMM_LengthSquaredVec4(hmm_vec4 A)
*/
#include <boost/test/unit_test.hpp>
#include "HMM.h"
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(S_HMM_LengthSquaredVec2)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    auto vec = HMM_Vec2i(0, 0);
    auto res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == 0.0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(25.4, 30.0);
    auto res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == 1545.16);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(-25.4, -30.0);
    auto res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == 1545.16);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(25.4, -30.0);
    auto res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == 1545.16);

    vec = HMM_Vec2(-25.4, 30.0);
    res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == 1545.16);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(1.0 * INT_MAX, 1.0 * INT_MAX);
    auto res = HMM_LengthSquaredVec2(vec);
    BOOST_TEST(res == (INT_MAX * 2.0 * INT_MAX));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_LengthSquaredVec3)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    auto vec = HMM_Vec3i(0, 0, 0);
    auto res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 0.0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(25.4, 30.0, 164.84);
    auto res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 28717.3848005);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(-25.4, -30.0, -164.84);
    auto res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 28717.3848005);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(25.4, -30.0, 164.84);
    auto res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 28717.3848005);

    vec = HMM_Vec3(-25.4, 30.0, -164.84);
    res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 28717.3848005);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(1.0 * INT_MAX, 1.0 * INT_MAX, -1 * INT_MAX);
    auto res = HMM_LengthSquaredVec3(vec);
    BOOST_TEST(res == 3719550785.027308 * 3719550785.027308);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_LengthSquaredVec4)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    auto vec = HMM_Vec4i(0, 0, 0, 0);
    auto res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 0.0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(25.4, 30.0, 164.84, 583.125);
    auto res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 368752.125);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(-25.4, -30.0, -164.84, -583.125);
    auto res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 368752.125);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(25.4, -30.0, -164.84, 583.125);
    auto res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 368752.125);

    vec = HMM_Vec4(-25.4, 30.0, -164.84, -583.125);
    res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 368752.125);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(1.0 * INT_MAX, -1 * INT_MAX, 1.0 * INT_MAX, -1 * INT_MAX);
    auto res = HMM_LengthSquaredVec4(vec);
    BOOST_TEST(res == 4.0 * INT_MAX * INT_MAX);
}

BOOST_AUTO_TEST_SUITE_END()
