/*
this file should cover the following functions in hmm.h
- hmm_mat4 HMM_Translate(hmm_vec3 Translation);
- hmm_mat4 HMM_Rotate(float Angle, hmm_vec3 Axis);
- hmm_mat4 HMM_Scale(hmm_vec3 Scale);
*/
#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"

#pragma region R_HMM_Translate
BOOST_AUTO_TEST_SUITE(S_HMM_Translate)

BOOST_AUTO_TEST_CASE(TC1_Zeros, TOLERANCE) {
	hmm_mat4 result;
	hmm_vec3 zeros=HMM_Vec3(0,0,0);
	result = HMM_Translate(zeros);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				BOOST_TEST(result.Elements[i][j] == 1.0);
			}
			else if (i == 3) {
				BOOST_TEST(result.Elements[i][j] == 0);
			}
			else {
				BOOST_TEST(result.Elements[i][j] == 0.0);
			}
		}
	}

}
BOOST_AUTO_TEST_CASE(TC2_Pos, TOLERANCE) {
	hmm_mat4 result;
	hmm_vec3 vec = HMM_Vec3(25, 32, 54);
	int expectedOutput[3] = {25, 32, 54};
	
	result = HMM_Translate(vec);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				BOOST_TEST(result.Elements[i][j] == 1.0);
			}
			else  if (i == 3) {
				BOOST_TEST(result.Elements[i][j] == expectedOutput[j]);
			}
			else {
				BOOST_TEST(result.Elements[i][j] == 0);
			}
		}
	}

}
BOOST_AUTO_TEST_CASE(TC3_Neg, TOLERANCE) {
	hmm_mat4 result;
	hmm_vec3 vec = HMM_Vec3(-12, -59, -99);
	int expectedOutput[3] = { -12, -59, -99 };
	result = HMM_Translate(vec);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				BOOST_TEST(result.Elements[i][j] == 1.0);
			}
			else  if (i == 3) {
				BOOST_TEST(result.Elements[i][j] == expectedOutput[j]);
			}
			else {
				BOOST_TEST(result.Elements[i][j] == 0);
			}
		}
	}

}

BOOST_AUTO_TEST_CASE(TC4_PosNeg, TOLERANCE) {
	hmm_mat4 result;
	hmm_vec3 vec = HMM_Vec3(-58, 12, -33);
	int expectedOutput[3] = { -58, 12, -33 };
	result = HMM_Translate(vec);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				BOOST_TEST(result.Elements[i][j] == 1.0);
			}
			else  if (i == 3) {
				BOOST_TEST(result.Elements[i][j] == expectedOutput[j]);
			}
			else {
				BOOST_TEST(result.Elements[i][j] == 0);
			}
		}
	}

}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_Translate
