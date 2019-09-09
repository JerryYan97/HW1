#include "mat4.h"
#include "math.h"

const float PI = 3.1415926f;

/// Default Constructor.  Initialize to identity matrix.
mat4::mat4()
{
    for (unsigned int i = 0; i < 4; i++) {
        data[i] = vec4(0.f, 0.f, 0.f, 0.f);
        data[i][i] = 1.f;
    }
}

/// Initializes the diagonal values of the matrix to diag. All other values are 0.
mat4::mat4(float diag)
{
    *this = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        data[i][i] = diag;
    }
}

/// Initializes matrix with each vector representing a column in the matrix
mat4::mat4(const vec4 &col0, const vec4 &col1, const vec4 &col2, const vec4& col3)
{
    data[0] = col0;
    data[1] = col1;
    data[2] = col2;
    data[3] = col3;
}

mat4::mat4(const mat4 &m2) // copy constructor
{
    data[0] = m2[0];
    data[1] = m2[1];
    data[2] = m2[2];
    data[3] = m2[3];
}

/// Returns the values of the column at the index
vec4 mat4::operator[](unsigned int index) const
{
    try {
        if(index > 3)
        {
            std::out_of_range exception("The Index of Mat4[] is out of range. The range should be [0,3].\n");
            throw exception;
        }
        return data[index];
    } catch (std::out_of_range outofrange) {
        std::cout << "EXCEPTION: OUT OF RANGE.\n" << outofrange.what();
        return vec4(0.f, 0.f, 0.f, 0.f);
    }
}

/// Returns a reference to the column at the index
vec4& mat4::operator[](unsigned int index)
{
    try {
        if(index > 3)
        {
            std::out_of_range exception("The Index of Mat4[] is out of range. The range should be [0,3].\n");
            throw exception;
        }
        return data[index];
    } catch (std::out_of_range outofrange) {
        std::cout << "EXCEPTION: OUT OF RANGE.\n" << outofrange.what();
        return data[0];
    }
}

/// Returns a row of the input matrix
vec4 row(const mat4 &m, unsigned int index)
{
    try {
        if(index > 3)
        {
            std::out_of_range exception("The Index of 'row(const mat4 &m, unsigned int index)' is out of range. The range should be [0,3].\n");
            throw exception;
        }
        return vec4(m[0][index], m[1][index], m[2][index], m[3][index]);
    } catch (std::out_of_range outofrange) {
        std::cout << "EXCEPTION: OUT OF RANGE.\n" << outofrange.what();
        return vec4(0.f, 0.f, 0.f, 0.f);
    }
}
/// Creates a 3-D rotation matrix.
/// Takes an angle in degrees and an axis represented by its xyz components, and outputs a 4x4 rotation matrix
/// Use Rodrigues' formula to implement this method
mat4 mat4::rotate(float angle, float x, float y, float z)
{
    float radian = angle * PI / 180.f;
    float mcos = cos(radian);
    float msin = sin(radian);
    mat4 rotationMatrix = mat4();

    rotationMatrix[0][0] = mcos + x * x * (1 - mcos);
    rotationMatrix[0][1] = z * msin + x * y * (1 - mcos);
    rotationMatrix[0][2] = -y * msin + x * z * (1 - mcos);
    rotationMatrix[0][3] = 0;

    rotationMatrix[1][0] = -z * msin + x * y * (1 - mcos);
    rotationMatrix[1][1] = mcos + y * y * (1 - mcos);
    rotationMatrix[1][2] = x * msin + y * z * (1 - mcos);
    rotationMatrix[1][3] = 0;

    rotationMatrix[2][0] = y * msin + x * z * (1 - mcos);
    rotationMatrix[2][1] = -x * msin + y * z * (1 - mcos);
    rotationMatrix[2][2] = mcos + z * z * (1 - mcos);
    rotationMatrix[2][3] = 0;

    return rotationMatrix;
}

/// Takes an xyz displacement and outputs a 4x4 translation matrix
mat4 mat4::translate(float x, float y, float z)
{
    mat4 temp = mat4();
    temp[3][0] = x;
    temp[3][1] = y;
    temp[3][2] = z;
    return temp;
}

/// Takes an xyz scale and outputs a 4x4 scale matrix
mat4 mat4::scale(float x, float y, float z)
{
    mat4 temp = mat4();
    temp[0][0] = x;
    temp[1][1] = y;
    temp[2][2] = z;
    return temp;
}

/// Generates a 4x4 identity matrix
mat4 mat4::identity()
{
    mat4 temp = mat4();
    return temp;
}

/// Assign m2 to this and return it
mat4& mat4::operator=(const mat4 &m2)
{
    for (unsigned int i = 0; i < 4; i++) {
        data[i] = m2[i];
    }
    return *this;
}

/// Test for equality
bool mat4::operator==(const mat4 &m2) const
{
    for (unsigned int i = 0; i < 4; i++) {
        if(data[i] != m2[i])
        {
            return false;
        }
    }
    return true;
}

/// Test for inequality
bool mat4::operator!=(const mat4 &m2) const
{
    if(*this == m2)
    {
        return false;
    }else {
        return true;
    }

}

mat4& mat4::operator+=(const mat4 &m2)
{
    *this = *this + m2;
    return *this;
}

mat4& mat4::operator-=(const mat4 &m2)
{
    *this = *this - m2;
    return *this;
}

mat4& mat4::operator*=(float c)
{
    *this = *this * c;
    return *this;
}

mat4& mat4::operator/=(float c)
{
    *this = *this / c;
    return *this;
}

mat4 mat4::operator+(const mat4 &m2) const
{
    mat4 temp = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = data[i] + m2[i];
    }
    return temp;
}

mat4 mat4::operator-(const mat4 &m2) const
{
    mat4 temp = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = data[i] - m2[i];
    }
    return temp;
}

mat4 mat4::operator*(float c) const
{
    mat4 temp = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = data[i] * c;
    }
    return temp;
}

mat4 mat4::operator/(float c) const
{
    mat4 temp = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = data[i] / c;
    }
    return temp;
}

/// Matrix multiplication (m1 * m2)
mat4 mat4::operator*(const mat4 &m2) const
{
    mat4 temp = mat4();
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            temp[i][j] = dot(row(*this, j), m2[i]);// The first number is the index of the column.
        }                                          // The second number is the index of the row.
    }
    return temp;
}

/// Matrix/vector multiplication (m * v)
/// Assume v is a column vector (ie. a 4x1 matrix)
vec4 mat4::operator*(const vec4 &v) const
{
    vec4 temp = vec4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = dot(row(*this, i), v);
    }
    return temp;
}

///----------------------------------------------------------------------
/// Matrix Operations
///----------------------------------------------------------------------
/// Returns the transpose of the input matrix (v_ij == v_ji)
mat4 transpose(const mat4 &m)
{
    mat4 tempMat4 = mat4(m);

    for (unsigned int i = 0; i < 4; i++) {              // i equals to the index of the row;
        for (unsigned int j = i + 1; j < 4; j++) {     // j equals to the index of the column;
             tempMat4[i][j] = m[j][i];
             tempMat4[j][i] = m[i][j];
        }
    }
    return tempMat4;
}

/// Scalar multiplication (c * m)
mat4 operator*(float c, const mat4 &m)
{
    mat4 temp = m * c;
    return temp;
}

/// Vector/matrix multiplication (v * m)
/// Assume v is a row vector (ie. a 1x4 matrix)
vec4 operator*(const vec4 &v, const mat4 &m)
{
    vec4 temp = vec4();
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] = dot(m[i], v);
    }
    return temp;
}

/// Prints the matrix to a stream in a nice format
std::ostream &operator<<(std::ostream &o, const mat4 &m)
{
    std::cout << row(m, 0) << std::endl;
    std::cout << row(m, 1) << std::endl;
    std::cout << row(m, 2) << std::endl;
    std::cout << row(m, 3) << std::endl;
    return o;
}
