#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"
#include<iostream>
using namespace std;

#pragma region R_HMM_SubtractVec2_op2
BOOST_AUTO_TEST_SUITE(S_HMM_SubtractVec2_op2)

BOOST_AUTO_TEST_CASE(TC1_zeros, TOLERANCE)
{
	hmm_vec2 left = HMM_Vec2i(0, 0), right = HMM_Vec2i(0, 0);
	//auto original = left; memcpy(&original.Elements, left.Elements, 16 * sizeof(int));
	//cout << "Ammar Alsayed says: " << original.Elements[0];
	left -= right;
	BOOST_TEST(left.X == 0.0);
	BOOST_TEST(left.Y == 0.0);

	left = HMM_Vec2i(0, 0);  right = HMM_Vec2i(-5, 546);
	left -= right;
	BOOST_TEST(left.X == -1 * right.X);
	BOOST_TEST(left.Y == -1 * right.Y);

	left = HMM_Vec2i(274, -765);  right = HMM_Vec2i(0, 0);
	//original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	BOOST_TEST(left.X == 274);
	BOOST_TEST(left.Y == -765);
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_vec2 left = HMM_Vec2i(52, 14), right = HMM_Vec2i(174, 156);
	left -= right;
	BOOST_TEST(left.X == 52 - 174);
	BOOST_TEST(left.Y == 14 - 156);

	left = HMM_Vec2i(12, 21);  right = HMM_Vec2i(15, 72);
	left -= right;
	BOOST_TEST(left.X == 12 - 15);
	BOOST_TEST(left.Y == 21 - 72);
}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_vec2 left = HMM_Vec2i(-789, -452), right = HMM_Vec2i(-451, -5146);
	left -= right;
	BOOST_TEST(left.X == -1 * (789 - 451));
	BOOST_TEST(left.Y == -1 * (452 - 5146));

	left = HMM_Vec2i(-10, -11);  right = HMM_Vec2i(-11, -10);
	left -= right;
	BOOST_TEST(left.X == -1 * (10 - 11));
	BOOST_TEST(left.Y == -1 * (11 - 10));
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	hmm_vec2 left = HMM_Vec2i(-457, 155), right = HMM_Vec2i(235, -4654);
	left -= right;
	BOOST_TEST(left.X == -457 - 235);
	BOOST_TEST(left.Y == 155 + 4654);

	left = HMM_Vec2i(548, -654);  right = HMM_Vec2i(-7317, 1254);
	left -= right;
	BOOST_TEST(left.X == 548 + 7317);
	BOOST_TEST(left.Y == -654 - 1254);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	hmm_vec2 left = HMM_Vec2i(INT_MAX, INT_MAX), right = HMM_Vec2i(INT_MAX, -1 * INT_MAX);
	left -= right;
	BOOST_TEST(left.X == 0);
	BOOST_TEST(left.Y == 2.0 * INT_MAX);
}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_SubtractVec2



#pragma region R_HMM_SubtractVec3_op2
BOOST_AUTO_TEST_SUITE(S_HMM_SubtractVec3_op2)

BOOST_AUTO_TEST_CASE(TC1_zeros)
{
	hmm_vec3 left = HMM_Vec3i(0, 0, 0), right = HMM_Vec3i(0, 0, 0);
	left -= right;
	BOOST_TEST(left.X == 0);
	BOOST_TEST(left.Y == 0);
	BOOST_TEST(left.Z == 0);

	left = HMM_Vec3i(0, 0, 0);  right = HMM_Vec3i(-5, 546, 6463);
	left -= right;
	BOOST_TEST(left.X == -1 * right.X);
	BOOST_TEST(left.Y == -1 * right.Y);
	BOOST_TEST(left.Z == -1 * right.Z);

	left = HMM_Vec3i(274, -765, -452369);  right = HMM_Vec3i(0, 0, 0);
	left -= right;
	BOOST_TEST(left.X == 274);
	BOOST_TEST(left.Y == -765);
	BOOST_TEST(left.Z == -452369);
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_vec3 left = HMM_Vec3i(52, 14, 1254), right = HMM_Vec3i(174, 156, 9452);
	left -= right;
	BOOST_TEST(left.X == 52 - 174);
	BOOST_TEST(left.Y == 14 - 156);
	BOOST_TEST(left.Z == 1254 - 9452);

	left = HMM_Vec3i(12, 21, 2);  right = HMM_Vec3i(15, 72, 1);
	left -= right;
	BOOST_TEST(left.X == 12 - 15);
	BOOST_TEST(left.Y == 21 - 72);
	BOOST_TEST(left.Z == 2 - 1);
}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_vec3 left = HMM_Vec3i(-789, -452, -88875), right = HMM_Vec3i(-451, -5146, -3654);
	left -= right;
	BOOST_TEST(left.X == -1 * (789 - 451));
	BOOST_TEST(left.Y == -1 * (452 - 5146));
	BOOST_TEST(left.Z == -1 * (88875 - 3654));

	left = HMM_Vec3i(-10, -11, -5);  right = HMM_Vec3i(-11, -10, -5);
	left -= right;
	BOOST_TEST(left.X == -1 * (10 - 11));
	BOOST_TEST(left.Y == -1 * (11 - 10));
	BOOST_TEST(left.Z == -1 * (5 - 5));
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	hmm_vec3 left = HMM_Vec3i(-457, 155, 254), right = HMM_Vec3i(235, -4654, -147258);
	left -= right;
	BOOST_TEST(left.X == -457 - 235);
	BOOST_TEST(left.Y == 155 + 4654);
	BOOST_TEST(left.Z == 254 + 147258);

	left = HMM_Vec3i(548, -654, -6841);  right = HMM_Vec3i(-7317, 1254, 1486);
	left -= right;
	BOOST_TEST(left.X == 548 + 7317);
	BOOST_TEST(left.Y == -654 - 1254);
	BOOST_TEST(left.Z == -6841 - 1486);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	hmm_vec3 left = HMM_Vec3i(INT_MAX, INT_MAX, -1 * INT_MAX), right = HMM_Vec3i(INT_MAX, -1 * INT_MAX, -1 * INT_MAX);
	left -= right;
	BOOST_TEST(left.X == 0);
	BOOST_TEST(left.Y == 2.0 * INT_MAX);
	BOOST_TEST(left.Z == 0);
}


BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_SubtractVec3



#pragma region R_HMM_SubtractVec4_op2
BOOST_AUTO_TEST_SUITE(S_HMM_SubtractVec4_op2)

BOOST_AUTO_TEST_CASE(TC1_zeros)
{
	hmm_vec4 left = HMM_Vec4i(0, 0, 0, 0), right = HMM_Vec4i(0, 0, 0, 0);
	left -= right;
	BOOST_TEST(left.X == 0);
	BOOST_TEST(left.Y == 0);
	BOOST_TEST(left.Z == 0);
	BOOST_TEST(left.W == 0);

	left = HMM_Vec4i(0, 0, 0, 0);  right = HMM_Vec4i(-5, 546, 6463, -654323);
	left -= right;
	BOOST_TEST(left.X == -1 * right.X);
	BOOST_TEST(left.Y == -1 * right.Y);
	BOOST_TEST(left.Z == -1 * right.Z);
	BOOST_TEST(left.W == -1 * right.W);

	left = HMM_Vec4i(274, -765, -452369, 5431);  right = HMM_Vec4i(0, 0, 0, 0);
	left -= right;
	BOOST_TEST(left.X == 274);
	BOOST_TEST(left.Y == -765);
	BOOST_TEST(left.Z == -452369);
	BOOST_TEST(left.W == 5431);
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_vec4 left = HMM_Vec4i(52, 14, 1254, 70), right = HMM_Vec4i(174, 156, 9452, 90);
	left -= right;
	BOOST_TEST(left.X == 52 - 174);
	BOOST_TEST(left.Y == 14 - 156);
	BOOST_TEST(left.Z == 1254 - 9452);
	BOOST_TEST(left.W == 70 - 90);

	left = HMM_Vec4i(12, 21, 2, 125);  right = HMM_Vec4i(15, 72, 1, 987);
	left -= right;
	BOOST_TEST(left.X == 12 - 15);
	BOOST_TEST(left.Y == 21 - 72);
	BOOST_TEST(left.Z == 2 - 1);
	BOOST_TEST(left.W == 125 - 987);
}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_vec4 left = HMM_Vec4i(-789, -452, -88875, -164), right = HMM_Vec4i(-451, -5146, -3654, -461);
	left -= right;
	BOOST_TEST(left.X == -1 * (789 - 451));
	BOOST_TEST(left.Y == -1 * (452 - 5146));
	BOOST_TEST(left.Z == -1 * (88875 - 3654));
	BOOST_TEST(left.W == -1 * (164 - 461));

	left = HMM_Vec4i(-10, -11, -5, -1);  right = HMM_Vec4i(-11, -10, -5, -2);
	left -= right;
	BOOST_TEST(left.X == -1 * (10 - 11));
	BOOST_TEST(left.Y == -1 * (11 - 10));
	BOOST_TEST(left.Z == -1 * (5 - 5));
	BOOST_TEST(left.W == -1 * (1 - 2));
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	hmm_vec4 left = HMM_Vec4i(-457, 155, 254, -379), right = HMM_Vec4i(235, -4654, -147258, 973);
	left -= right;
	BOOST_TEST(left.X == -457 - 235);
	BOOST_TEST(left.Y == 155 + 4654);
	BOOST_TEST(left.Z == 254 + 147258);
	BOOST_TEST(left.W == -379 - 973);

	left = HMM_Vec4i(548, -654, -6841, 528);  right = HMM_Vec4i(-7317, 1254, 1486, -825);
	left -= right;
	BOOST_TEST(left.X == 548 + 7317);
	BOOST_TEST(left.Y == -654 - 1254);
	BOOST_TEST(left.Z == -6841 - 1486);
	BOOST_TEST(left.W == 528 + 825);
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	hmm_vec4 left = HMM_Vec4i(INT_MAX, INT_MAX, -1 * INT_MAX, -1 * INT_MAX), right = HMM_Vec4i(INT_MAX, -1 * INT_MAX, -1 * INT_MAX, INT_MAX);
	left -= right;
	BOOST_TEST(left.X == 0);
	BOOST_TEST(left.Y == 2.0 * INT_MAX);
	BOOST_TEST(left.Z == 0);
	BOOST_TEST(left.W == -2.0 * INT_MAX);
}


BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_SubtractVec4



#pragma region R_HMM_SubtractMat4_op2
BOOST_AUTO_TEST_SUITE(S_HMM_SubtractMat4_op2)
BOOST_AUTO_TEST_CASE(TC1_zeros)
{
	hmm_mat4 left = HMM_Mat4(), right = HMM_Mat4();
	auto original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << "and j = " << j);
			BOOST_TEST(left.Elements[i][j] == 0);
		}
	}

	left = HMM_Mat4(); right = HMM_Mat4();
	right.Elements[0][0] = 637;		right.Elements[0][1] = 39862;	right.Elements[0][2] = 49175;	right.Elements[0][3] = 92691;
	right.Elements[1][0] = 98150;	right.Elements[1][1] = 65186;	right.Elements[1][2] = 69296;	right.Elements[1][3] = 34902;
	right.Elements[2][0] = 77198;	right.Elements[2][1] = 53326;	right.Elements[2][2] = 46488;	right.Elements[2][3] = 86270;
	right.Elements[3][0] = 54705;	right.Elements[3][1] = 69516;	right.Elements[3][2] = 28732;	right.Elements[3][3] = 41310;
	original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == -1 * right.Elements[i][j]);
		}
	}

	left = HMM_Mat4(); right = HMM_Mat4();
	left.Elements[0][0] = 637;		left.Elements[0][1] = 39862;	left.Elements[0][2] = 49175;	left.Elements[0][3] = 92691;
	left.Elements[1][0] = 98150;	left.Elements[1][1] = 65186;	left.Elements[1][2] = 69296;	left.Elements[1][3] = 34902;
	left.Elements[2][0] = 77198;	left.Elements[2][1] = 53326;	left.Elements[2][2] = 46488;	left.Elements[2][3] = 86270;
	left.Elements[3][0] = 54705;	left.Elements[3][1] = 69516;	left.Elements[3][2] = 28732;	left.Elements[3][3] = 41310;
	original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j]);
		}
	}
}

BOOST_AUTO_TEST_CASE(TC2_positives)
{
	hmm_mat4 left = HMM_Mat4(), right = HMM_Mat4();
	right.Elements[0][0] = 70824;	right.Elements[0][1] = 16505;	right.Elements[0][2] = 38823;	right.Elements[0][3] = 99502;
	right.Elements[1][0] = 91736;	right.Elements[1][1] = 43347;	right.Elements[1][2] = 53315;	right.Elements[1][3] = 37516;
	right.Elements[2][0] = 17629;	right.Elements[2][1] = 58691;	right.Elements[2][2] = 62767;	right.Elements[2][3] = 49954;
	right.Elements[3][0] = 79444;	right.Elements[3][1] = 93380;	right.Elements[3][2] = 82594;	right.Elements[3][3] = 29226;

	left.Elements[0][0] = 57258;	left.Elements[0][1] = 26652;	left.Elements[0][2] = 66972;	left.Elements[0][3] = 54865;
	left.Elements[1][0] = 62865;	left.Elements[1][1] = 63243;	left.Elements[1][2] = 68940;	left.Elements[1][3] = 6709;
	left.Elements[2][0] = 39968;	left.Elements[2][1] = 48773;	left.Elements[2][2] = 11260;	left.Elements[2][3] = 14758;

	left.Elements[3][0] = 88404;	left.Elements[3][1] = 7239;	left.Elements[3][2] = 15992;	left.Elements[3][3] = 14221;
	auto original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}

	left = HMM_Mat4(); right = HMM_Mat4();
	right.Elements[0][0] = 59848;	right.Elements[0][1] = 2713;	right.Elements[0][2] = 44642;	right.Elements[0][3] = 50806;
	right.Elements[1][0] = 14087;	right.Elements[1][1] = 71073;	right.Elements[1][2] = 4303;	right.Elements[1][3] = 91377;
	right.Elements[2][0] = 72664;	right.Elements[2][1] = 78052;	right.Elements[2][2] = 44143;	right.Elements[2][3] = 64906;
	right.Elements[3][0] = 47632;	right.Elements[3][1] = 60001;	right.Elements[3][2] = 11031;	right.Elements[3][3] = 50474;

	left.Elements[0][0] = 68378;	left.Elements[0][1] = 72835;	left.Elements[0][2] = 38240;	left.Elements[0][3] = 42124;
	left.Elements[1][0] = 83195;	left.Elements[1][1] = 67815;	left.Elements[1][2] = 43495;	left.Elements[1][3] = 73784;
	left.Elements[2][0] = 64833;	left.Elements[2][1] = 44326;	left.Elements[2][2] = 61627;	left.Elements[2][3] = 33390;
	left.Elements[3][0] = 65428;	left.Elements[3][1] = 95957;	left.Elements[3][2] = 83924;	left.Elements[3][3] = 658;

	original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}
}

BOOST_AUTO_TEST_CASE(TC3_negatives)
{
	hmm_mat4 left = HMM_Mat4(), right = HMM_Mat4();
	right.Elements[0][0] = -56710;	right.Elements[0][1] = -71014;	right.Elements[0][2] = -84992;	right.Elements[0][3] = -75348;
	right.Elements[1][0] = -87241;	right.Elements[1][1] = -93414;	right.Elements[1][2] = -19193;	right.Elements[1][3] = -20068;
	right.Elements[2][0] = -67166;	right.Elements[2][1] = -15830;	right.Elements[2][2] = -12413;	right.Elements[2][3] = -57087;

	right.Elements[3][0] = -19520;	right.Elements[3][1] = -23452;	right.Elements[3][2] = -56739;	right.Elements[3][3] = -27053;
	left.Elements[0][0] = -71645;	left.Elements[0][1] = -19524;	left.Elements[0][2] = -26228;	left.Elements[0][3] = -71157;
	left.Elements[1][0] = -31404;	left.Elements[1][1] = -53801;	left.Elements[1][2] = -63188;	left.Elements[1][3] = -30700;
	left.Elements[2][0] = -89972;	left.Elements[2][1] = -88742;	left.Elements[2][2] = -76691;	left.Elements[2][3] = -97167;
	left.Elements[3][0] = -41668;	left.Elements[3][1] = -89867;	left.Elements[3][2] = -29079;	left.Elements[3][3] = -47677;

	auto original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}

	left = HMM_Mat4(); right = HMM_Mat4();
	right.Elements[0][0] = -10234;	right.Elements[0][1] = -11179;	right.Elements[0][2] = -94765;	right.Elements[0][3] = -13894;
	right.Elements[1][0] = -11340;	right.Elements[1][1] = -7840;	right.Elements[1][2] = -22502;	right.Elements[1][3] = -42027;
	right.Elements[2][0] = -34452;	right.Elements[2][1] = -76601;	right.Elements[2][2] = -76847;	right.Elements[2][3] = -66517;
	right.Elements[3][0] = -45818;	right.Elements[3][1] = -89920;	right.Elements[3][2] = -5691;	right.Elements[3][3] = -68548;

	left.Elements[0][0] = -84344;	left.Elements[0][1] = -50730;	left.Elements[0][2] = -62411;	left.Elements[0][3] = -37186;
	left.Elements[1][0] = -7417;	left.Elements[1][1] = -56742;	left.Elements[1][2] = -73895;	left.Elements[1][3] = -59310;
	left.Elements[2][0] = -92782;	left.Elements[2][1] = -87977;	left.Elements[2][2] = -64911;	left.Elements[2][3] = -21998;
	left.Elements[3][0] = -62754;	left.Elements[3][1] = -97017;	left.Elements[3][2] = -35772;	left.Elements[3][3] = -55770;

	original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}
}

BOOST_AUTO_TEST_CASE(TC4_posNeg)
{
	hmm_mat4 left = HMM_Mat4(), right = HMM_Mat4();
	right.Elements[0][0] = 537;	right.Elements[0][1] = 466;	right.Elements[0][2] = -804;	right.Elements[0][3] = 772;
	right.Elements[1][0] = -656;	right.Elements[1][1] = 485;	right.Elements[1][2] = 534;	right.Elements[1][3] = 807;
	right.Elements[2][0] = -585;	right.Elements[2][1] = -439;	right.Elements[2][2] = -243;	right.Elements[2][3] = 375;
	right.Elements[3][0] = 48;	right.Elements[3][1] = 615;	right.Elements[3][2] = -311;	right.Elements[3][3] = -269;

	left.Elements[0][0] = -28;	left.Elements[0][1] = -135;	left.Elements[0][2] = -179;	left.Elements[0][3] = 515;
	left.Elements[1][0] = -89;	left.Elements[1][1] = -98;	left.Elements[1][2] = -609;	left.Elements[1][3] = -73;
	left.Elements[2][0] = 301;	left.Elements[2][1] = -241;	left.Elements[2][2] = -440;	left.Elements[2][3] = 52;
	left.Elements[3][0] = 990;	left.Elements[3][1] = 309;	left.Elements[3][2] = 86;	left.Elements[3][3] = 508;

	auto original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}

	left = HMM_Mat4(); right = HMM_Mat4();
	right.Elements[0][0] = -419;	right.Elements[0][1] = -133;	right.Elements[0][2] = 79;	right.Elements[0][3] = 915;
	right.Elements[1][0] = -766;	right.Elements[1][1] = 507;	right.Elements[1][2] = 847;	right.Elements[1][3] = -828;
	right.Elements[2][0] = 878;	right.Elements[2][1] = -5;	right.Elements[2][2] = -226;	right.Elements[2][3] = -914;
	right.Elements[3][0] = -762;	right.Elements[3][1] = 514;	right.Elements[3][2] = 127;	right.Elements[3][3] = -468;

	left.Elements[0][0] = -272;	left.Elements[0][1] = -13;	left.Elements[0][2] = 156;	left.Elements[0][3] = 717;
	left.Elements[1][0] = -973;	left.Elements[1][1] = 489;	left.Elements[1][2] = -506;	left.Elements[1][3] = 26;
	left.Elements[2][0] = -874;	left.Elements[2][1] = 240;	left.Elements[2][2] = 10;	left.Elements[2][3] = -599;
	left.Elements[3][0] = -329;	left.Elements[3][1] = -32;	left.Elements[3][2] = 398;	left.Elements[3][3] = -77;

	original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}
}

BOOST_AUTO_TEST_CASE(TC5_largeNumbers, TOLERANCE)
{
	hmm_mat4 left = HMM_Mat4(), right = HMM_Mat4();
	right.Elements[0][0] = -INT_MAX;	right.Elements[0][1] = -INT_MAX;	right.Elements[0][2] = INT_MAX;	right.Elements[0][3] = INT_MAX;
	right.Elements[1][0] = -INT_MAX;	right.Elements[1][1] = INT_MAX;	right.Elements[1][2] = INT_MAX;	right.Elements[1][3] = -INT_MAX;
	right.Elements[2][0] = INT_MAX;	right.Elements[2][1] = -INT_MAX;	right.Elements[2][2] = -INT_MAX;	right.Elements[2][3] = -INT_MAX;
	right.Elements[3][0] = -INT_MAX;	right.Elements[3][1] = INT_MAX;	right.Elements[3][2] = INT_MAX;	right.Elements[3][3] = -INT_MAX;

	left.Elements[0][0] = -INT_MAX;	left.Elements[0][1] = -INT_MAX;	left.Elements[0][2] = INT_MAX;	left.Elements[0][3] = INT_MAX;
	left.Elements[1][0] = -INT_MAX;	left.Elements[1][1] = INT_MAX;	left.Elements[1][2] = -INT_MAX;	left.Elements[1][3] = INT_MAX;
	left.Elements[2][0] = -INT_MAX;	left.Elements[2][1] = INT_MAX;	left.Elements[2][2] = INT_MAX;	left.Elements[2][3] = -INT_MAX;
	left.Elements[3][0] = -INT_MAX;	left.Elements[3][1] = -INT_MAX;	left.Elements[3][2] = INT_MAX;	left.Elements[3][3] = -INT_MAX;

	auto original = left; memcpy(&original.Elements, &left.Elements, 16 * sizeof(int));
	left -= right;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST_INFO("i = " << i << " j = " << j);
			BOOST_TEST(left.Elements[i][j] == original.Elements[i][j] - right.Elements[i][j]);
		}
	}
}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_SubtractMat4