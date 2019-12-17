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
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "HMM.h"
#include "test_helpers.h"
namespace utf = boost::unit_test;
namespace tt = boost::test_tools;
using namespace std;

BOOST_AUTO_TEST_SUITE(multiplication_test_suite)

BOOST_AUTO_TEST_SUITE(multiplication_vec2_by_int, *utf::label("trivial"))

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2_int_BothVecsZeros, *utf::tolerance(0.00001)) {
    //Arrange
    auto zeros = HMM_Vec2i(0, 0);
    //Act
    auto res = HMM_MultiplyVec2(zeros, zeros);
    //Assert
    float expectedRes[2] = {0, 0};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2_int_V1_zeros, *utf::tolerance(0.00001)) {
    //Arrange
    auto zeros = HMM_Vec2i(0, 0);
    auto right = HMM_Vec2i(5, -10);
    //Act
    auto res = HMM_MultiplyVec2(zeros, right);
    //Assert
    float expectedRes[2] = {0, 0};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2_int_postives, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2i(1, 5);
    auto right = HMM_Vec2i(3, 4);
    //Act
    auto res = HMM_MultiplyVec2(left, right);
    //Assert
    float expectedRes[2] = {left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2_int_pos_neg, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2i(1, 5);
    auto right = HMM_Vec2i(-3, -4);
    //Act
    auto res = HMM_MultiplyVec2(left, right);
    //Assert
    float expectedRes[2] = {left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]};
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]}));
}

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2_float_pos_neg, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    auto right = HMM_Vec2(-2, -10.);
    //Act
    auto res = HMM_MultiplyVec2(left, right);
    //Assert
    float expectedRes[2] = {left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_SUITE_END()
//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(multiplication_vec2_by_float)

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyVec2f_vec_x_posfloat, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = HMM_MultiplyVec2f(left, right);
    //Assert
    float expectedRes[2] = {left.Elements[0] * right, left.Elements[1] * right};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_SUITE_END()
//--------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(mul_vec2_using_operators)

BOOST_AUTO_TEST_CASE(test_mul_vec2_by_vec2_using_mul_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(10., 1.);
    auto right = HMM_Vec2(-2, -5.);
    //Act
    auto res = left * right;
    //Assert
    float expectedRes[2] = {left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_mul_vec2_by_float_using_mul_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = left * right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] * right, left.Elements[1] * right}));
}

BOOST_AUTO_TEST_CASE(test_mul_vec2_by_vec2_using_mul_equal_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    auto right = HMM_Vec2(-2, -5.);
    //Act
    auto res = left;
    res *= right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] * right.Elements[0], left.Elements[1] * right.Elements[1]}));
}

BOOST_AUTO_TEST_CASE(test_mul_vec2_by_float_using_mul_equal_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = left;
    res *= right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] * right, left.Elements[1] * right}));
}

BOOST_AUTO_TEST_SUITE_END()

//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(multiplication_mat4_by_mat4)

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyMat4, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    //Act
    hmm_mat4 res = HMM_MultiplyMat4(left, left);

    //Assert
    float expMat[4][4] = {{38, 80, 50, 56},
                          {38, 236, 50, 56},
                          {158, 248, 218, 248},
                          {75, -90, 105, 120}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_SUITE_END()

//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(multiplication_mat4_by_floatscalar)

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyMat4f, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    float right = .5;
    //Act
    hmm_mat4 res = HMM_MultiplyMat4f(left, right);

    //Assert
    float expMat[4][4] = {{arr[0][0] * right, arr[0][1] * right, arr[0][2] * right, arr[0][3] * right},
                          {arr[1][0] * right, arr[1][1] * right, arr[1][2] * right, arr[1][3] * right},
                          {arr[2][0] * right, arr[2][1] * right, arr[2][2] * right, arr[2][3] * right},
                          {arr[3][0] * right, arr[3][1] * right, arr[3][2] * right, arr[3][3] * right}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_SUITE_END()

//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(multiplication_mat4_by_vec4)

BOOST_AUTO_TEST_CASE(test_HMM_MultiplyMat4ByVec4, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    hmm_vec4 right = HMM_Vec4(.5, 1., 0., -3.);
    //Act
    hmm_vec4 res = HMM_MultiplyMat4ByVec4(left, right);
    //Assert
    float expRes[] = {5.5, -50, 8.5, 10};
    BOOST_TEST(res.Elements == expRes);
}

BOOST_AUTO_TEST_SUITE_END()
//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(multiplication_using_operators)

BOOST_AUTO_TEST_CASE(test_mul_mat4_by_mat4_using_mul_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    //Act
    hmm_mat4 res = left * left;

    //Assert
    float expMat[4][4] = {{38, 80, 50, 56},
                          {38, 236, 50, 56},
                          {158, 248, 218, 248},
                          {75, -90, 105, 120}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_CASE(test_mul_mat4_by_floatscalar_using_mul_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    float right = .5;
    //Act
    hmm_mat4 res = left * right;
    //Assert
    float expMat[4][4] = {{arr[0][0] * right, arr[0][1] * right, arr[0][2] * right, arr[0][3] * right},
                          {arr[1][0] * right, arr[1][1] * right, arr[1][2] * right, arr[1][3] * right},
                          {arr[2][0] * right, arr[2][1] * right, arr[2][2] * right, arr[2][3] * right},
                          {arr[3][0] * right, arr[3][1] * right, arr[3][2] * right, arr[3][3] * right}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_CASE(test_mul_mat4_by_vec4_using_mul_operator, *utf::tolerance(0.00001)) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    hmm_vec4 right = HMM_Vec4(.5, 1., 0., -3.);
    //Act
    hmm_vec4 res = left * right;
    //Assert
    float epxRes[] = {5.5, -50, 8.5, 10};
    BOOST_TEST(res.Elements == epxRes);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
