/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_SubtractVec2(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec3 HMM_SubtractVec3(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec4 HMM_SubtractVec4(hmm_vec4 Left, hmm_vec4 Right);
- hmm_mat4 HMM_SubtractMat4(hmm_mat4 Left, hmm_mat4 Right);
take care of operator overloading also for these functions:
- hmm_vec2 operator-(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec3 operator-(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec4 operator-(hmm_vec4 Left, hmm_vec4 Right);
- hmm_mat4 operator-(hmm_mat4 Left, hmm_mat4 Right);
- hmm_vec2 &operator-=(hmm_vec2 &Left, hmm_vec2 Right);
- hmm_vec3 &operator-=(hmm_vec3 &Left, hmm_vec3 Right);
- hmm_vec4 &operator-=(hmm_vec4 &Left, hmm_vec4 Right);
- hmm_mat4 &operator-=(hmm_mat4 &Left, hmm_mat4 Right);
*/
#pragma once
#include <boost\test\included\unit_test.hpp>
