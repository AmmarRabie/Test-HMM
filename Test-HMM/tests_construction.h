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
#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"

#pragma region R_HMM_Vec2i
BOOST_AUTO_TEST_SUITE(S_HMM_Vec2i)

BOOST_AUTO_TEST_CASE(TC1_zeros)
{
	hmm_vec2 vec = HMM_Vec2i(0, 0);
	BOOST_TEST(vec.X == 0);
	BOOST_TEST(vec.Y == 0);
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_vec2 vec = HMM_Vec2i(564, 8931);
	BOOST_TEST(vec.X == 564);
	BOOST_TEST(vec.Y == 8931);

	vec = HMM_Vec2i(31318, 801);
	BOOST_TEST(vec.X == 31318);
	BOOST_TEST(vec.Y == 801);

}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_vec2 vec = HMM_Vec2i(-564, -8931);
	BOOST_TEST(vec.X == -564);
	BOOST_TEST(vec.Y == -8931);

	vec = HMM_Vec2i(-31318, -801);
	BOOST_TEST(vec.X == -31318);
	BOOST_TEST(vec.Y == -801);
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	auto vec = HMM_Vec2i(-457, 155);
	BOOST_TEST(vec.X == -457);
	BOOST_TEST(vec.Y == 155);

	vec = HMM_Vec2i(548, -654);
	BOOST_TEST(vec.X == 548);
	BOOST_TEST(vec.Y == -654);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	auto vec = HMM_Vec2i(INT_MAX, INT_MAX);
	BOOST_TEST(vec.X == INT_MAX);
	BOOST_TEST(vec.Y == INT_MAX);

	vec = HMM_Vec2i(2 * INT_MAX, -2 * INT_MAX);
	BOOST_TEST(vec.X == 2.0 * INT_MAX);
	BOOST_TEST(vec.Y == -2.0 * INT_MAX);
}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_AddVec2

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	auto vec = HMM_Vec2i(1.65 * INT_MAX, 1.1254 * INT_MAX);
	BOOST_TEST(vec.X == 1.65 * INT_MAX);
	BOOST_TEST(vec.Y == 1.1254 * INT_MAX);

	vec = HMM_Vec2i(0.253 * INT_MAX, -1.2 * INT_MAX);
	BOOST_TEST(vec.X == 0.253 * INT_MAX);
	BOOST_TEST(vec.Y == -1.2 * INT_MAX);
}

