/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_Vec2i(int X, int Y);
- hmm_vec2 HMM_Vec2(float X, float Y);
- hmm_vec3 HMM_Vec3(float X, float Y, float Z);
- hmm_vec3 HMM_Vec3i(int X, int Y, int Z);
- hmm_vec4 HMM_Vec4(float X, float Y, float Z, float W);
- hmm_vec4 HMM_Vec4i(int X, int Y, int Z, int W);
- hmm_vec4 HMM_Vec4v(hmm_vec3 Vector, float W);
- hmm_mat4 HMM_Mat4(void);
- hmm_mat4 HMM_Mat4d(float Diagonal);
*/
#include <boost/test/unit_test.hpp>
#include "HMM.h"
namespace utf = boost::unit_test;
BOOST_AUTO_TEST_SUITE(S_HMM_Vec2i)

BOOST_AUTO_TEST_CASE(TC1_zeros) {
    hmm_vec2 vec = HMM_Vec2i(0, 0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives) {
    hmm_vec2 vec = HMM_Vec2i(564, 8931);
    BOOST_TEST(vec.X == 564);
    BOOST_TEST(vec.Y == 8931);

    vec = HMM_Vec2i(31318, 801);
    BOOST_TEST(vec.X == 31318);
    BOOST_TEST(vec.Y == 801);
}

BOOST_AUTO_TEST_CASE(TC3_negatives) {
    hmm_vec2 vec = HMM_Vec2i(-564, -8931);
    BOOST_TEST(vec.X == -564);
    BOOST_TEST(vec.Y == -8931);

    vec = HMM_Vec2i(-31318, -801);
    BOOST_TEST(vec.X == -31318);
    BOOST_TEST(vec.Y == -801);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg) {
    auto vec = HMM_Vec2i(-457, 155);
    BOOST_TEST(vec.X == -457);
    BOOST_TEST(vec.Y == 155);

    vec = HMM_Vec2i(548, -654);
    BOOST_TEST(vec.X == 548);
    BOOST_TEST(vec.Y == -654);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2i(INT_MAX, INT_MAX);
    BOOST_TEST(vec.X == INT_MAX);
    BOOST_TEST(vec.Y == INT_MAX);

    vec = HMM_Vec2i(2.0 * INT_MAX, -2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
	auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
	BOOST_TEST(vec.X == 1.65 * INT_MAX);
	BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

	vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
	BOOST_TEST(vec.X == 0.253 * INT_MAX);
	BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec2)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec2 vec = HMM_Vec2i(0.0, 0.0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec2 vec = HMM_Vec2(564.3, 8931.1);
    BOOST_TEST(vec.X == 564.3);
    BOOST_TEST(vec.Y == 8931.1);

    vec = HMM_Vec2(31318.1, 801.3);
    BOOST_TEST(vec.X == 31318.1);
    BOOST_TEST(vec.Y == 801.3);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec2 vec = HMM_Vec2(-564.1, -8931.32);
    BOOST_TEST(vec.X == -564.1);
    BOOST_TEST(vec.Y == -8931.32);

    vec = HMM_Vec2(-31318.1, -801.9);
    BOOST_TEST(vec.X == -31318.1);
    BOOST_TEST(vec.Y == -801.9);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(-457.3, 155.7);
    BOOST_TEST(vec.X == -457.3);
    BOOST_TEST(vec.Y == 155.7);

    vec = HMM_Vec2(548.2, -654.4);
    BOOST_TEST(vec.X == 548.2);
    BOOST_TEST(vec.Y == -654.4);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec2(INT_MAX + 0.1, INT_MAX + 0.3);
    BOOST_TEST(vec.X == INT_MAX + 0.1);
    BOOST_TEST(vec.Y == INT_MAX + 0.3);

    vec = HMM_Vec2(2.0 * INT_MAX, -2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec3i)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3i(0, 0, 0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
    BOOST_TEST(vec.Z == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3i(564, 8931, 114);
    BOOST_TEST(vec.X == 564);
    BOOST_TEST(vec.Y == 8931);
    BOOST_TEST(vec.Z == 114);

    vec = HMM_Vec3i(31318, 801, 112);
    BOOST_TEST(vec.X == 31318);
    BOOST_TEST(vec.Y == 801);
    BOOST_TEST(vec.Z == 112);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3i(-564, -8931, -78);
    BOOST_TEST(vec.X == -564);
    BOOST_TEST(vec.Y == -8931);
    BOOST_TEST(vec.Z == -78);

    vec = HMM_Vec3i(-31318, -801, -336);
    BOOST_TEST(vec.X == -31318);
    BOOST_TEST(vec.Y == -801);
    BOOST_TEST(vec.Z == -336);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3i(-457, 155, -333);
    BOOST_TEST(vec.X == -457);
    BOOST_TEST(vec.Y == 155);
    BOOST_TEST(vec.Z == -333);

    vec = HMM_Vec3i(548, -654, 115);
    BOOST_TEST(vec.X == 548);
    BOOST_TEST(vec.Y == -654);
    BOOST_TEST(vec.Z == 115);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3i(INT_MAX, INT_MAX, INT_MAX);
    BOOST_TEST(vec.X == INT_MAX);
    BOOST_TEST(vec.Y == INT_MAX);
    BOOST_TEST(vec.Z == INT_MAX);

    vec = HMM_Vec3i(2.0 * INT_MAX, -2.0 * INT_MAX, 2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
    BOOST_TEST(vec.Z == 2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec3)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3(0.0, 0.0, 0.0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
    BOOST_TEST(vec.Z == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3(564.97, 8931.99, 114.33);
    BOOST_TEST(vec.X == 564.97);
    BOOST_TEST(vec.Y == 8931.99);
    BOOST_TEST(vec.Z == 114.33);

    vec = HMM_Vec3(31318.31, 801.22, 112.77);
    BOOST_TEST(vec.X == 31318.31);
    BOOST_TEST(vec.Y == 801.22);
    BOOST_TEST(vec.Z == 112.77);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec3 vec = HMM_Vec3(-564.19, -8931.93, -78.21);
    BOOST_TEST(vec.X == -564.19);
    BOOST_TEST(vec.Y == -8931.93);
    BOOST_TEST(vec.Z == -78.21);

    vec = HMM_Vec3(-31318.4, -801.14, -336.39);
    BOOST_TEST(vec.X == -31318.4);
    BOOST_TEST(vec.Y == -801.14);
    BOOST_TEST(vec.Z == -336.39);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(-457.36, 155.11, -333.02);
    BOOST_TEST(vec.X == -457.36);
    BOOST_TEST(vec.Y == 155.11);
    BOOST_TEST(vec.Z == -333.02);

    vec = HMM_Vec3(548.4, -654.22, 115.14);
    BOOST_TEST(vec.X == 548.4);
    BOOST_TEST(vec.Y == -654.22);
    BOOST_TEST(vec.Z == 115.14);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec3(INT_MAX + 0.1, INT_MAX + 0.2, INT_MAX - 0.1);
    BOOST_TEST(vec.X == INT_MAX + 0.1);
    BOOST_TEST(vec.Y == INT_MAX + 0.2);
    BOOST_TEST(vec.Z == INT_MAX - 0.1);

    vec = HMM_Vec3i(2.0 * INT_MAX, -2.0 * INT_MAX, 2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
    BOOST_TEST(vec.Z == 2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec4i)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4i(0, 0, 0, 0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
    BOOST_TEST(vec.Z == 0);
    BOOST_TEST(vec.W == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4i(564, 8931, 114, 32);
    BOOST_TEST(vec.X == 564);
    BOOST_TEST(vec.Y == 8931);
    BOOST_TEST(vec.Z == 114);
    BOOST_TEST(vec.W == 32);

    vec = HMM_Vec4i(31318, 801, 112, 98);
    BOOST_TEST(vec.X == 31318);
    BOOST_TEST(vec.Y == 801);
    BOOST_TEST(vec.Z == 112);
    BOOST_TEST(vec.W == 98);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4i(-564, -8931, -78, -66);
    BOOST_TEST(vec.X == -564);
    BOOST_TEST(vec.Y == -8931);
    BOOST_TEST(vec.Z == -78);
    BOOST_TEST(vec.W == -66);

    vec = HMM_Vec4i(-31318, -801, -336, -14);
    BOOST_TEST(vec.X == -31318);
    BOOST_TEST(vec.Y == -801);
    BOOST_TEST(vec.Z == -336);
    BOOST_TEST(vec.W == -14);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4i(-457, 155, -333, 22);
    BOOST_TEST(vec.X == -457);
    BOOST_TEST(vec.Y == 155);
    BOOST_TEST(vec.Z == -333);
    BOOST_TEST(vec.W == 22);

    vec = HMM_Vec4i(548, -654, 115, -412);
    BOOST_TEST(vec.X == 548);
    BOOST_TEST(vec.Y == -654);
    BOOST_TEST(vec.Z == 115);
    BOOST_TEST(vec.W == -412);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4i(INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    BOOST_TEST(vec.X == INT_MAX);
    BOOST_TEST(vec.Y == INT_MAX);
    BOOST_TEST(vec.Z == INT_MAX);
    BOOST_TEST(vec.W == INT_MAX);

    vec = HMM_Vec4i(2.0 * INT_MAX, -2.0 * INT_MAX, 2.0 * INT_MAX, -2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
    BOOST_TEST(vec.Z == 2.0 * INT_MAX);
    BOOST_TEST(vec.W == -2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec4)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4(0.0, 0.0, 0.0, 0.0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
    BOOST_TEST(vec.Z == 0);
    BOOST_TEST(vec.W == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4(564.97, 8931.99, 114.33, 21.3);
    BOOST_TEST(vec.X == 564.97);
    BOOST_TEST(vec.Y == 8931.99);
    BOOST_TEST(vec.Z == 114.33);
    BOOST_TEST(vec.W == 21.3);

    vec = HMM_Vec4(31318.31, 801.22, 112.77, 7.7);
    BOOST_TEST(vec.X == 31318.31);
    BOOST_TEST(vec.Y == 801.22);
    BOOST_TEST(vec.Z == 112.77);
    BOOST_TEST(vec.W == 7.7);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec4 vec = HMM_Vec4(-564.19, -8931.93, -78.21, -2.2);
    BOOST_TEST(vec.X == -564.19);
    BOOST_TEST(vec.Y == -8931.93);
    BOOST_TEST(vec.Z == -78.21);
    BOOST_TEST(vec.W == -2.2);

    vec = HMM_Vec4(-31318.4, -801.14, -336.39, -9.5);
    BOOST_TEST(vec.X == -31318.4);
    BOOST_TEST(vec.Y == -801.14);
    BOOST_TEST(vec.Z == -336.39);
    BOOST_TEST(vec.W == -9.5);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(-457.36, 155.11, -333.02, 18.3);
    BOOST_TEST(vec.X == -457.36);
    BOOST_TEST(vec.Y == 155.11);
    BOOST_TEST(vec.Z == -333.02);
    BOOST_TEST(vec.W == 18.3);

    vec = HMM_Vec4(548.4, -654.22, 115.14, -30.8);
    BOOST_TEST(vec.X == 548.4);
    BOOST_TEST(vec.Y == -654.22);
    BOOST_TEST(vec.Z == 115.14);
    BOOST_TEST(vec.W == -30.8);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    auto vec = HMM_Vec4(INT_MAX + 0.1, INT_MAX + 0.2, INT_MAX - 0.1, INT_MAX - 0.55);
    BOOST_TEST(vec.X == INT_MAX + 0.1);
    BOOST_TEST(vec.Y == INT_MAX + 0.2);
    BOOST_TEST(vec.Z == INT_MAX - 0.1);
    BOOST_TEST(vec.W == INT_MAX - 0.55);

    vec = HMM_Vec4(2.0 * INT_MAX, -2.0 * INT_MAX, 2.0 * INT_MAX, -2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
    BOOST_TEST(vec.Z == 2.0 * INT_MAX);
    BOOST_TEST(vec.W == -2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Vec4v)

BOOST_AUTO_TEST_CASE(TC1_zeros, *utf::tolerance(0.00001)) {
    hmm_vec3 v3 = HMM_Vec3i(0, 0, 0);
    hmm_vec4 vec = HMM_Vec4v(v3, 0);
    BOOST_TEST(vec.X == 0);
    BOOST_TEST(vec.Y == 0);
    BOOST_TEST(vec.Z == 0);
    BOOST_TEST(vec.W == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives, *utf::tolerance(0.00001)) {
    hmm_vec3 v3 = HMM_Vec3i(564, 8931, 114);
    hmm_vec4 vec = HMM_Vec4v(v3, 32);
    BOOST_TEST(vec.X == 564);
    BOOST_TEST(vec.Y == 8931);
    BOOST_TEST(vec.Z == 114);
    BOOST_TEST(vec.W == 32);

    v3 = HMM_Vec3i(31318, 801, 112);
    vec = HMM_Vec4v(v3, 98);
    BOOST_TEST(vec.X == 31318);
    BOOST_TEST(vec.Y == 801);
    BOOST_TEST(vec.Z == 112);
    BOOST_TEST(vec.W == 98);
}

BOOST_AUTO_TEST_CASE(TC3_negatives, *utf::tolerance(0.00001)) {
    hmm_vec3 v3 = HMM_Vec3i(-564, -8931, -78);
    hmm_vec4 vec = HMM_Vec4v(v3, -66);
    BOOST_TEST(vec.X == -564);
    BOOST_TEST(vec.Y == -8931);
    BOOST_TEST(vec.Z == -78);
    BOOST_TEST(vec.W == -66);

    v3 = HMM_Vec3i(-31318, -801, -336);
    vec = HMM_Vec4v(v3, -14);
    BOOST_TEST(vec.X == -31318);
    BOOST_TEST(vec.Y == -801);
    BOOST_TEST(vec.Z == -336);
    BOOST_TEST(vec.W == -14);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg, *utf::tolerance(0.00001)) {
    hmm_vec3 v3 = HMM_Vec3i(-457, 155, -333);
    auto vec = HMM_Vec4v(v3, 22);
    BOOST_TEST(vec.X == -457);
    BOOST_TEST(vec.Y == 155);
    BOOST_TEST(vec.Z == -333);
    BOOST_TEST(vec.W == 22);

    v3 = HMM_Vec3i(548, -654, 115);
    vec = HMM_Vec4v(v3, -412);
    BOOST_TEST(vec.X == 548);
    BOOST_TEST(vec.Y == -654);
    BOOST_TEST(vec.Z == 115);
    BOOST_TEST(vec.W == -412);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, *utf::tolerance(0.00001)) {
    hmm_vec3 v3 = HMM_Vec3i(INT_MAX, INT_MAX, INT_MAX);
    auto vec = HMM_Vec4v(v3, INT_MAX);
    BOOST_TEST(vec.X == INT_MAX);
    BOOST_TEST(vec.Y == INT_MAX);
    BOOST_TEST(vec.Z == INT_MAX);
    BOOST_TEST(vec.W == INT_MAX);

    v3 = HMM_Vec3i(2.0 * INT_MAX, -2.0 * INT_MAX, 2.0 * INT_MAX);
    vec = HMM_Vec4v(v3, -2.0 * INT_MAX);
    BOOST_TEST(vec.X == 2.0 * INT_MAX);
    BOOST_TEST(vec.Y == -2.0 * INT_MAX);
    BOOST_TEST(vec.Z == 2.0 * INT_MAX);
    BOOST_TEST(vec.W == -2.0 * INT_MAX);
}

/*BOOST_AUTO_TEST_CASE(TC6_largeNumbers,  *utf::tolerance(0.00001))
{
auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
BOOST_TEST(vec.X == 1.65 * INT_MAX);
BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
BOOST_TEST(vec.X == 0.253 * INT_MAX);
BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}*/
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Mat4)
BOOST_AUTO_TEST_CASE(TC1) {
    hmm_mat4 mat = HMM_Mat4();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            BOOST_TEST(mat.Elements[i][j] == 0);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(S_HMM_Mat4d)
BOOST_AUTO_TEST_CASE(TC1_Zeros) {
    hmm_mat4 mat = HMM_Mat4d(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            BOOST_TEST(mat.Elements[i][j] == 0);
        }
    }
}

BOOST_AUTO_TEST_CASE(TC2_Positive) {
    hmm_mat4 mat = HMM_Mat4d(2);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                BOOST_TEST(mat.Elements[i][j] == 2);
            else
                BOOST_TEST(mat.Elements[i][j] == 0);
        }
    }
}

BOOST_AUTO_TEST_CASE(TC3_Negative) {
    hmm_mat4 mat = HMM_Mat4d(-1);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                BOOST_TEST(mat.Elements[i][j] == -1);
            else
                BOOST_TEST(mat.Elements[i][j] == 0);
        }
    }
}

BOOST_AUTO_TEST_CASE(TC4_LargeNumber) {
    hmm_mat4 mat = HMM_Mat4d(INT_MAX);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                BOOST_TEST(mat.Elements[i][j] == INT_MAX);
            else
                BOOST_TEST(mat.Elements[i][j] == 0);
        }
    }
}
BOOST_AUTO_TEST_SUITE_END()
