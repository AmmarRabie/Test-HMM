/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_MultiplyVec2(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec2 HMM_MultiplyVec2f(hmm_vec2 Left, float Right);
- hmm_vec3 HMM_MultiplyVec3(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec3 HMM_MultiplyVec3f(hmm_vec3 Left, float Right);
- hmm_vec4 HMM_MultiplyVec4(hmm_vec4 Left, hmm_vec4 Right);
- hmm_vec4 HMM_MultiplyVec4f(hmm_vec4 Left, float Right);
- hmm_mat4 HMM_MultiplyMat4(hmm_mat4 Left, hmm_mat4 Right);
- hmm_mat4 HMM_MultiplyMat4f(hmm_mat4 Matrix, float Scalar);
- hmm_vec4 HMM_MultiplyMat4ByVec4(hmm_mat4 Matrix, hmm_vec4 Vector);

take care of operator overloading also for these functions:
- hmm_vec2 operator*(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec3 operator*(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec4 operator*(hmm_vec4 Left, hmm_vec4 Right);
- hmm_mat4 operator*(hmm_mat4 Left, hmm_mat4 Right);
- hmm_vec2 operator*(hmm_vec2 Left, float Right);
- hmm_vec3 operator*(hmm_vec3 Left, float Right);
- hmm_vec4 operator*(hmm_vec4 Left, float Right);
- hmm_mat4 operator*(hmm_mat4 Left, float Right);
- hmm_vec2 operator*(float Left, hmm_vec2 Right);
- hmm_vec3 operator*(float Left, hmm_vec3 Right);
- hmm_vec4 operator*(float Left, hmm_vec4 Right);
- hmm_mat4 operator*(float Left, hmm_mat4 Right);
- hmm_vec4 operator*(hmm_mat4 Matrix, hmm_vec4 Vector);
- hmm_vec2 &operator*=(hmm_vec2 &Left, hmm_vec2 Right);
- hmm_vec3 &operator*=(hmm_vec3 &Left, hmm_vec3 Right);
- hmm_vec4 &operator*=(hmm_vec4 &Left, hmm_vec4 Right);
- hmm_vec2 &operator*=(hmm_vec2 &Left, float Right);
- hmm_vec3 &operator*=(hmm_vec3 &Left, float Right);
- hmm_vec4 &operator*=(hmm_vec4 &Left, float Right);
- hmm_mat4 &operator*=(hmm_mat4 &Left, float Right);
*/
#pragma once
#include <boost\test\included\unit_test.hpp>