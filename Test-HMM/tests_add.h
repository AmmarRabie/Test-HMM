/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_AddVec2(hmm_vec2 Left, hmm_vec2 Right)
- hmm_vec3 HMM_AddVec3(hmm_vec3 Left, hmm_vec3 Right)
- hmm_vec4 HMM_AddVec4(hmm_vec4 Left, hmm_vec4 Right)
- hmm_mat4 HMM_AddMat4(hmm_mat4 Left, hmm_mat4 Right)
*/
#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"

#pragma region R_HMM_AddVec2
BOOST_AUTO_TEST_SUITE(S_HMM_AddVec2)

BOOST_AUTO_TEST_CASE(TC1_zeros)
{
	hmm_vec2 left = HMM_Vec2i(0, 0), right = HMM_Vec2i(0, 0);
	auto res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 0);
	BOOST_TEST(res.Y == 0);

	left = HMM_Vec2i(0, 0);  right = HMM_Vec2i(-5, 546);
	res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == right.X);
	BOOST_TEST(res.Y == right.Y);

	left = HMM_Vec2i(274, -765);  right = HMM_Vec2i(0, 0);
	res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == left.X);
	BOOST_TEST(res.Y == left.Y);
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_vec2 left = HMM_Vec2i(52, 14), right = HMM_Vec2i(174, 156);
	auto res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 52 + 174);
	BOOST_TEST(res.Y == 14 + 156);

	left = HMM_Vec2i(12, 21);  right = HMM_Vec2i(15, 72);
	res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 12 + 15);
	BOOST_TEST(res.Y == 21 + 72);
}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_vec2 left = HMM_Vec2i(-789, -452), right = HMM_Vec2i(-451, -5146);
	auto res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == -1*(789 + 451));
	BOOST_TEST(res.Y == -1 * (452 + 5146));

	left = HMM_Vec2i(-10, -11);  right = HMM_Vec2i(-11, -10);
	res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == -1 * (10 + 11));
	BOOST_TEST(res.Y == -1 * (11 + 10));
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	hmm_vec2 left = HMM_Vec2i(-457, 155), right = HMM_Vec2i(235, -4654);
	auto res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 235 - 457);
	BOOST_TEST(res.Y == 155 - 4654);

	left = HMM_Vec2i(548, -654);  right = HMM_Vec2i(-7317, 1254);
	res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 548 - 7317);
	BOOST_TEST(res.Y == 1254 - 654);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers)
{
	hmm_vec2 left = HMM_Vec2i(INT_MAX, INT_MAX), right = HMM_Vec2i(INT_MAX, -1 * INT_MAX);
	auto res = HMM_AddVec2(left, right);
	BOOST_TEST(res.X == 2.0 * INT_MAX);
	BOOST_TEST(res.Y == 0);

	//left = HMM_Vec2i(-10, -11);  right = HMM_Vec2i(-11, -10);
	//res = HMM_AddVec2(left, right);
	//BOOST_TEST(res.X == -1 * (10 + 11));
	//BOOST_TEST(res.Y == -1 * (11 + 10));
}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_AddVec2



#pragma region R_HMM_AddVec3
BOOST_AUTO_TEST_SUITE(S_HMM_AddVec3)

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_AddVec3



#pragma region R_HMM_AddVec4
BOOST_AUTO_TEST_SUITE(S_HMM_AddVec4)

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_AddVec4



#pragma region R_HMM_AddMat4
BOOST_AUTO_TEST_SUITE(S_HMM_AddMat4)

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_AddMat4