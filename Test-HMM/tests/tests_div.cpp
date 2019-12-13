/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_DivideVec2(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec2 HMM_DivideVec2f(hmm_vec2 Left, float Right);
- hmm_vec3 HMM_DivideVec3(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec3 HMM_DivideVec3f(hmm_vec3 Left, float Right);
- hmm_vec4 HMM_DivideVec4(hmm_vec4 Left, hmm_vec4 Right);
- hmm_vec4 HMM_DivideVec4f(hmm_vec4 Left, float Right);
- hmm_mat4 HMM_DivideMat4f(hmm_mat4 Matrix, float Scalar);
take care of operator overloading also for these functions:
- hmm_vec2 operator/(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec3 operator/(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec4 operator/(hmm_vec4 Left, hmm_vec4 Right);
- hmm_vec2 operator/(hmm_vec2 Left, float Right);
- hmm_vec3 operator/(hmm_vec3 Left, float Right);
- hmm_vec4 operator/(hmm_vec4 Left, float Right);
- hmm_mat4 operator/(hmm_mat4 Left, float Right);
- hmm_vec2 &operator/=(hmm_vec2 &Left, hmm_vec2 Right);
- hmm_vec3 &operator/=(hmm_vec3 &Left, hmm_vec3 Right);
- hmm_vec4 &operator/=(hmm_vec4 &Left, hmm_vec4 Right);
- hmm_vec2 &operator/=(hmm_vec2 &Left, float Right);
- hmm_vec3 &operator/=(hmm_vec3 &Left, float Right);
- hmm_vec4 &operator/=(hmm_vec4 &Left, float Right);
- hmm_mat4 &operator/=(hmm_mat4 &Left, float Right);
*/
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "../HMM.h"
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(scoring_test_suite)
BOOST_AUTO_TEST_SUITE_END()
