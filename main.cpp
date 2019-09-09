// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {
	vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
	vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
	std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
    std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;
}

void vec4ConstructorsTest()
{
    ///----------------------------------------------------------------------
    /// Constructors
    ///----------------------------------------------------------------------
    /// vec4() test.
    /// operator<< test.
    /// operator=  test
    vec4 test1 = vec4();
    std::cout << "vec4() && vec4= expected value: (0, 0, 0, 0)" << std::endl;
    std::cout << "vec4() && vec4= actual value: " << test1 << std::endl;

    /// vec4(float x, float y, float z, float w);
    vec4 test2 = vec4(1.f, 2.f, 3.f, 4.f);
    std::cout << "vec4() expected value: (1, 2, 3, 4)" << std::endl;
    std::cout << "vec4() actual value: " << test2 << std::endl;

    /// vec4(const vec4 &v2);
    vec4 test3 = vec4(test2);
    std::cout << "vec4() expected value: (1, 2, 3, 4)" << std::endl;
    std::cout << "vec4() actual value: " << test3 << std::endl;
}

void vec4OperatorTest(){
    /// operator== test
    vec4 test1 = vec4(1.f, 3.f, 5.f, 7.f);
    vec4 test2 = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 == expected value: flase" << std::endl;
    if(test1 == test2)
    {
        std::cout << "vec4 == actual value: true" << std::endl;
    } else {
        std::cout << "vec4 == actual value: false" << std::endl;
    }
    std::cout << std::endl;

    /// operator!= test
    std::cout << "vec4 != expected value: true" << std::endl;
    if(test1 != test2)
    {
        std::cout << "vec4 != actual value: true" << std::endl;
    } else {
        std::cout << "vec4 != actual value: false" << std::endl;
    }
    std::cout << std::endl;

    /// dot product test
    std::cout << "vec4 dot product expected value: 100" << std::endl;
    std::cout << "vec4 dot product actual value: " << dot(test1, test2) << std::endl;
    std::cout << std::endl;

    /// cross product test
    std::cout << "vec4 cross product expected value: (-2, 4, -2, 0)" << std::endl;
    std::cout << "vec4 cross product actual value: " << cross(test1, test2) << std::endl;
    std::cout << std::endl;

    /// normalize  test
    std::cout << "vec4 normalize expected value: (0.109109, 0.327327, 0.545545, 0.763763)" << std::endl;
    std::cout << "vec4 normalize actual value: " << normalize(test1) << std::endl;
    std::cout << std::endl;
}

void mat4ConstructorsTest()
{
    ///----------------------------------------------------------------------
    /// Constructors
    ///----------------------------------------------------------------------
    /// Default Constructor.  Initialize to identity matrix.
    /// mat4() test;
    /// mat4=  test;
    mat4 test1 = mat4();
    std::cout << "mat4() expected value: " << std::endl;
    std::cout << "(1, 0, 0, 0)" << std::endl;
    std::cout << "(0, 1, 0, 0)" << std::endl;
    std::cout << "(0, 0, 1, 0)" << std::endl;
    std::cout << "(0, 0, 0, 1)" << std::endl;
    std::cout << "mat4() actual value: " << std::endl;
    std::cout << test1 << std::endl;
    std::cout << std::endl;

    /// Initializes the diagonal values of the matrix to diag. All other values are 0.
    /// mat4(float diag);
    mat4 test2 = mat4(2.f);
    std::cout << "mat4(2.f) expected value: " << std::endl;
    std::cout << "(2, 0, 0, 0)" << std::endl;
    std::cout << "(0, 2, 0, 0)" << std::endl;
    std::cout << "(0, 0, 2, 0)" << std::endl;
    std::cout << "(0, 0, 0, 2)" << std::endl;
    std::cout << "mat4(2.f) actual value: " << std::endl;
    std::cout << test2 << std::endl;
    std::cout << std::endl;

    /// Initializes matrix with each vector representing a column in the matrix
    /// mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3);
    vec4 testCol1 = vec4(1.f, 3.f, 5.f, 7.f);
    vec4 testCol2 = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3) expected value: " << std::endl;
    std::cout << "(1, 2, 1, 2)" << std::endl;
    std::cout << "(3, 4, 3, 4)" << std::endl;
    std::cout << "(5, 6, 5, 6)" << std::endl;
    std::cout << "(7, 8, 7, 8)" << std::endl;
    std::cout << "mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3) actual value: " << std::endl;
    std::cout << mat4(testCol1, testCol2, testCol1, testCol2) << std::endl;
    std::cout << std::endl;

    /// mat4(const mat4 &m2); copy constructor
    mat4 test3 = mat4(test2);
    std::cout << "mat4(const mat4 &m2) expected value: " << std::endl;
    std::cout << "(2, 0, 0, 0)" << std::endl;
    std::cout << "(0, 2, 0, 0)" << std::endl;
    std::cout << "(0, 0, 2, 0)" << std::endl;
    std::cout << "(0, 0, 0, 2)" << std::endl;
    std::cout << "mat4(const mat4 &m2) actual value: " << std::endl;
    std::cout << test3 << std::endl;
    std::cout << std::endl;
}

void mat4OperatorTest()
{
    /// operator== test
    vec4 vecTest1 = vec4(1.f, 3.f, 5.f, 7.f);
    vec4 vecTest2 = vec4(2.f, 4.f, 6.f, 8.f);
    mat4 matTest1 = mat4(vecTest1, vecTest2, vecTest1, vecTest2);
    mat4 matTest2 = mat4(vecTest1, vecTest1, vecTest2, vecTest2);

    std::cout << "mat4 == expected value: flase" << std::endl;
    if(matTest1 == matTest2)
    {
        std::cout << "mat4 == actual value: true" << std::endl;
    } else {
        std::cout << "mat4 == actual value: false" << std::endl;
    }
    std::cout << std::endl;

    /// operator!= test
    std::cout << "mat4 != expected value: true" << std::endl;
    if(matTest1 != matTest2)
    {
        std::cout << "mat4 != actual value: true" << std::endl;
    } else {
        std::cout << "mat4 != actual value: false" << std::endl;
    }
    std::cout << std::endl;
}

/// Rotate, with at least two different angles tested
void mat4RotateTest()
{
    /// mat4 mat4::rotate(float angle, float x, float y, float z) test.
    /// First Angle:
    mat4 test1 = mat4();
    std::cout << "rotate expected value: " << std::endl;
    std::cout << "(1, 0, 0, 0)" << std::endl;
    std::cout << "(0, 0, -1, 0)" << std::endl;
    std::cout << "(0, 1, 0, 0)" << std::endl;
    std::cout << "(0, 0, 0, 1)" << std::endl;
    std::cout << "rotate actual value: " << std::endl;
    std::cout << test1.rotate(90.f, 1.f, 0.f, 0.f) << std::endl;

    ///Second Angle:
    vec4 axis = vec4(1, 1, 1, 0);
    axis = normalize(axis);
    std::cout << "rotate expected value: " << std::endl;
    std::cout << "( 0.910684, -0.244017, 0.333333, 0)" << std::endl;
    std::cout << "( 0.333333, 0.910684, -0.244017, 0)" << std::endl;
    std::cout << "(-0.244017, 0.333333,  0.910684, 0)" << std::endl;
    std::cout << "(        0,        0,         0, 1)" << std::endl;
    std::cout << "rotate actual value: " << std::endl;
    std::cout << test1.rotate(30.f, axis[0], axis[1], axis[2]) << std::endl;
}


void mat4MultiplicationTest()
{
    vec4 vecTest1 = vec4(1.f, 3.f, 5.f, 7.f);
    vec4 vecTest2 = vec4(2.f, 4.f, 6.f, 8.f);
    mat4 matTest1 = mat4(vecTest1, vecTest2, vecTest1, vecTest2);
    mat4 matTest2 = mat4(vecTest1, vecTest1, vecTest2, vecTest2);

    /// Matrix-matrix multiplication
    std::cout << "mat4 matrix-matrix multiplication expected value: " << std::endl;
    std::cout << "( 26,  26,  32,  32)" << std::endl;
    std::cout << "( 58,  58,  72,  72)" << std::endl;
    std::cout << "( 90,  90, 112, 112)" << std::endl;
    std::cout << "(122, 122, 152, 152)" << std::endl;
    std::cout << "mat4 matrix-matrix multiplication actual value: " << std::endl;
    std::cout << matTest1 * matTest2 << std::endl;

    /// Matrix-vector multiplication
    std::cout << "mat4 matrix-vector multiplication expected value: " << std::endl;
    std::cout << "(26, 64, 102, 140)" << std::endl;
    std::cout << "mat4 matrix-vector multiplication actual value: " << std::endl;
    std::cout << matTest1 * vec4(9, 6, 3, 1)<< std::endl;
    std::cout << std::endl;

    /// Vector-matrix multiplication
    std::cout << "mat4 vector-matrix multiplication expected value: " << std::endl;
    std::cout << "(49, 49, 68, 68)" << std::endl;
    std::cout << "mat4 vector-matrix multiplication actual value: " << std::endl;
    std::cout << vec4(9, 6, 3, 1) * matTest2<< std::endl;
    std::cout << std::endl;
}
int main() {
    vec4AddTest();
    std::cout << std::endl;
    vec4ConstructorsTest();
    std::cout << std::endl;
    vec4OperatorTest();
    std::cout << std::endl;

    mat4ConstructorsTest();
    std::cout << std::endl;
    mat4OperatorTest();
    std::cout << std::endl;
    mat4RotateTest();
    std::cout << std::endl;
    mat4MultiplicationTest();
    std::cout << std::endl;
}
