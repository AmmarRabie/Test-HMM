/*
this file should cover the following functions in hmm.h
- hmm_mat4 HMM_Transpose(hmm_mat4 Matrix);
*/
#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"

#pragma region R_HMM_Transpose
BOOST_AUTO_TEST_SUITE(S_HMM_Transpose)

BOOST_AUTO_TEST_CASE(TC1_Zeros) {
	hmm_mat4 zeros;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			zeros.Elements[i][j] = 0;
		}
	}
	auto result = HMM_Transpose(zeros);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST(result.Elements[i][j] == 0);
		}
	}
}
BOOST_AUTO_TEST_CASE(TC2_Diagonal) {
	hmm_mat4 diagonal;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				diagonal.Elements[i][j] = 1;
			else
				diagonal.Elements[i][j] = 0;
		}
	}

	auto result = HMM_Transpose(diagonal);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i==j)
				BOOST_TEST(result.Elements[i][j] == 1);
			else
				BOOST_TEST(result.Elements[i][j] == 0);

		}
	}
}
BOOST_AUTO_TEST_CASE(TC3_Positive) {
	hmm_mat4 mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat.Elements[i][j] = i*j;
		}
	}
	auto result = HMM_Transpose(mat);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST(result.Elements[j][i] == i*j);
		}
	}
}
BOOST_AUTO_TEST_CASE(TC4_Negative) {
	hmm_mat4 mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat.Elements[i][j] = -1 * i*j;
		}
	}
	auto result = HMM_Transpose(mat);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			BOOST_TEST(result.Elements[j][i] == -1*i*j);
		}
	}
}
BOOST_AUTO_TEST_CASE(TC5_PosNeg) {
	hmm_mat4 mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j%2==0) {
				mat.Elements[i][j] = i*j;
			}
			else {
				mat.Elements[i][j] = -1 * i*j;
			}
		}
	}
	auto result = HMM_Transpose(mat);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j % 2 == 0) {
				BOOST_TEST(result.Elements[j][i] == i*j);
			}
			else {
				BOOST_TEST(result.Elements[j][i] == -1 * i*j);
			}
		}
	}
}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_Transpose