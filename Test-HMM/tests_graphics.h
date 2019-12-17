/*
this file should cover the following functions in hmm.h
- hmm_mat4 HMM_Orthographic(float Left, float Right, float Bottom, float Top, float Near, float Far);
- hmm_mat4 HMM_Perspective(float FOV, float AspectRatio, float Near, float Far);
- hmm_mat4 HMM_LookAt(hmm_vec3 Eye, hmm_vec3 Center, hmm_vec3 Up);
*/

#pragma once
#include <boost\test\included\unit_test.hpp>
#include "HMM.h"


// my implementation of the projection function from http://learnwebgl.brown37.net/08_projections/projections_ortho.html

bool Mat4Equal(hmm_mat4 m1 ,hmm_mat4 m2) 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((m1.Elements[i][j] != m2.Elements[i][j]))
			{
				return false;
			}
		}
	}

	return true;

}

void printMatrix(hmm_mat4 m1)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m1.Elements[i][j] << " ";
		}

		std::cout << std::endl;
	}

}

hmm_mat4 constructOrhographic(float Left, float Right, float Bottom, float Top, float Near, float Far)
{
	hmm_mat4 Result = HMM_Mat4d(1.0f);

	Result.Elements[0][0] = 2.0f / (Right - Left);
	Result.Elements[1][1] = 2.0f / (Top - Bottom);
	Result.Elements[2][2] = -2.0f / (Far - Near);
	Result.Elements[3][0] = -1 * (Left + Right) / (Right - Left);
	Result.Elements[3][1] = -1 * (Bottom + Top) / (Top - Bottom);
	Result.Elements[3][2] = -1 * (Far + Near) / (Far - Near);

	return Result;
}








#pragma region HMM_Orthographic
BOOST_AUTO_TEST_SUITE(HMM_Orthographicc)

BOOST_AUTO_TEST_CASE(ALLEQUAL)
{
	hmm_mat4 expectedOutput = constructOrhographic(1,1,1,1,1,1);

	hmm_mat4 orthographic = HMM_Orthographic(1,1,1,1,1,1);

	//printMatrix(expectedOutput);
	std::cout << std::endl;
	//printMatrix(orthographic);



	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(ALLNotEQUAL)
{
	hmm_mat4 expectedOutput = constructOrhographic(1, 2, 3, 4, 5, 6);

	hmm_mat4 orthographic = HMM_Orthographic(1, 2, 3, 4, 5, 6);

	//printMatrix(expectedOutput);
	std::cout << std::endl;
	//printMatrix(orthographic);



	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(ALLZeors)
{
	hmm_mat4 expectedOutput = constructOrhographic(0, 0, 0, 0, 0, 0);

	hmm_mat4 orthographic = HMM_Orthographic(0,0, 0, 0, 0, 0);

	//printMatrix(expectedOutput);
	std::cout << std::endl;
	//printMatrix(orthographic);



	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}



BOOST_AUTO_TEST_CASE(BIGNumbers)
{
	std::cout << "before" << std::endl;
	hmm_mat4 expectedOutput = constructOrhographic(-FLT_MAX, FLT_MAX, 1000000, 0, 1000000, 0);

	hmm_mat4 orthographic = HMM_Orthographic(-FLT_MAX, FLT_MAX, 1000000, 0, 1000000, 0);

	//printMatrix(expectedOutput);
	std::cout << std::endl;
	//printMatrix(orthographic);



	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_Orthographicc


hmm_mat4 constructPersective(float FOV, float AspectRatio, float Near, float Far)
{
	hmm_mat4 Result = HMM_Mat4d(0.0f);

	Result.Elements[2][3] = -1.0f;
	Result.Elements[2][2] = (Near + Far) / (Near - Far);
	Result.Elements[3][2] = (2.0f * Near * Far) / (Near - Far);

	float angle = HMM_TanF(FOV * (HMM_PI32 / 360.0));

	Result.Elements[0][0] = 1.0f / angle;
	Result.Elements[1][1] = AspectRatio / angle;


	return Result;
}

#pragma region HMM_perectivee
BOOST_AUTO_TEST_SUITE(HMM_perectivee)

BOOST_AUTO_TEST_CASE(FAREQUALNEAR)
{
	hmm_mat4 expectedOutput = constructPersective(100, 10,10, 10);

	hmm_mat4 orthographic = HMM_Perspective(100, 10, 10, 10);

	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(FAREnotQUALNEAR)
{
	hmm_mat4 expectedOutput = constructPersective(100, 10, 34, 10);

	hmm_mat4 orthographic = HMM_Perspective(100, 10, 34, 10);





	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(ALLZeors)
{
	hmm_mat4 expectedOutput = constructPersective(0, 0, 0, 0);

	hmm_mat4 orthographic = HMM_Perspective(0,0,0,0);


	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}



BOOST_AUTO_TEST_CASE(BIGNEARANDFAR)
{
	hmm_mat4 expectedOutput = constructPersective(100, 1, -FLT_MAX, +FLT_MAX);

	//printMatrix(expectedOutput);

	hmm_mat4 orthographic = HMM_Perspective(100, 1, -FLT_MAX, +FLT_MAX);

	//printMatrix(orthographic);

	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(FOVNinty)
{
	hmm_mat4 expectedOutput = constructPersective(90, 1, -FLT_MAX, +FLT_MAX);

	//printMatrix(expectedOutput);

	hmm_mat4 orthographic = HMM_Perspective(90, 1, -FLT_MAX, +FLT_MAX);

	//printMatrix(orthographic);

	BOOST_CHECK_EQUAL(Mat4Equal(orthographic, expectedOutput), true);

}


BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_Orthographicc




hmm_mat4 constructLookAt(hmm_vec3 Eye, hmm_vec3 Center, hmm_vec3 Up)
{

	hmm_mat4 lookat = HMM_Mat4d(1.0f);
	hmm_vec3 f = HMM_NormalizeVec3(HMM_SubtractVec3(Center, Eye));
	hmm_vec3 s = HMM_NormalizeVec3(HMM_Cross(f, Up));
	hmm_vec3 u = HMM_Cross(s, f);

	lookat.Elements[3][0] = -HMM_DotVec3(s, Eye);
	lookat.Elements[3][1] = -HMM_DotVec3(u, Eye);
	lookat.Elements[3][2] = HMM_DotVec3(f, Eye);
	lookat.Elements[3][3] = 1.0f;

	lookat.Elements[0][0] = s.X;
	lookat.Elements[1][0] = s.Y;
	lookat.Elements[2][0] = s.Z;

	lookat.Elements[0][1] = u.X;
	lookat.Elements[1][1] = u.Y;
	lookat.Elements[2][1] = u.Z;

	lookat.Elements[0][2] = -f.X;
	lookat.Elements[1][2] = -f.Y;
	lookat.Elements[2][2] = -f.Z;

	return lookat;
}





#pragma region HMM_LOOKATT
BOOST_AUTO_TEST_SUITE(HMM_LOOKATT)

BOOST_AUTO_TEST_CASE(EYEEQZERO)
{
	hmm_vec3 Eye;
	Eye.X = 0;
	Eye.Y = 0;
	Eye.Z = 0;

	hmm_vec3 Center;
	Center.X = 1;
	Center.Y = 2;
	Center.Z = 3;

	hmm_vec3 Up;
	Up.X = 3;
	Up.Y = 4;
	Up.Z = 5;


	hmm_mat4 expectedOutput=constructLookAt(Eye, Center, Up);
	hmm_mat4 lookat = HMM_LookAt(Eye,Center,Up);

	BOOST_CHECK_EQUAL(Mat4Equal(lookat, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(CENTERQZERO)
{
	hmm_vec3 Eye;
	Eye.X = 10;
	Eye.Y = 30;
	Eye.Z = 40;

	hmm_vec3 Center;
	Center.X = 0;
	Center.Y = 0;
	Center.Z = 0;

	hmm_vec3 Up;
	Up.X = 3;
	Up.Y = 4;
	Up.Z = 5;


	hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
	hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

	BOOST_CHECK_EQUAL(Mat4Equal(lookat, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(CENTERQEYE)
{
	hmm_vec3 Eye;
	Eye.X = 10;
	Eye.Y = 30;
	Eye.Z = 40;


	hmm_vec3 Center;
	Center.X = 10;
	Center.Y = 30;
	Center.Z = 40;


	hmm_vec3 Up;
	Up.X = 3;
	Up.Y = 4;
	Up.Z = 5;


	hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
	hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

	BOOST_CHECK_EQUAL(Mat4Equal(lookat, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(allDifferent)
{
	hmm_vec3 Eye;
	Eye.X = 10;
	Eye.Y = 30;
	Eye.Z = 40;

	hmm_vec3 Center;
	Center.X = 100;
	Center.Y = 101;
	Center.Z = 102;

	hmm_vec3 Up;
	Up.X = 69;
	Up.Y = 23;
	Up.Z = 11;


	hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
	hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

	BOOST_CHECK_EQUAL(Mat4Equal(lookat, expectedOutput), true);

}

BOOST_AUTO_TEST_CASE(ALLZEROS)
{
	hmm_vec3 Eye;
	Eye.X = 0;
	Eye.Y = 0;
	Eye.Z = 0;

	hmm_vec3 Center;
	Center.X = 0;
	Center.Y = 0;
	Center.Z = 0;

	hmm_vec3 Up;
	Up.X = 0;
	Up.Y = 0;
	Up.Z = 0;


	hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
	hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

	BOOST_CHECK_EQUAL(Mat4Equal(lookat, expectedOutput), true);

}

BOOST_AUTO_TEST_SUITE_END()
#pragma endregion HMM_LOOKATT


