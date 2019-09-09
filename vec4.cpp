#include "vec4.h"
#include <exception>
#include <stdlib.h>
#include <math.h>

vec4::vec4()
    : data{0.f, 0.f, 0.f, 0.f}
{}

vec4::vec4(float x, float y, float z, float w)
    : data{x, y, z, w}
{}

vec4::vec4(const vec4 &v2)
    : data{v2.data[0], v2.data[1], v2.data[2], v2.data[3]}
{}

float vec4::operator[](unsigned int index) const
{
    try {
        if(index > 3)
        {
            std::out_of_range exception("The Index of Vec4[] is out of range. The range should be [0,3].\n");
            throw exception;
        }
        return data[index];
    } catch (std::out_of_range outofrange) {
        std::cout << "EXCEPTION: OUT OF RANGE.\n" << outofrange.what();
        return 0.f;
    }
}

float& vec4::operator[](unsigned int index)
{
    try {
        if(index > 3)
        {
            std::out_of_range exception("The Index of Vec4[] is out of range. The range should be [0,3].\n");
            throw exception;
        }
        return data[index];
    } catch (std::out_of_range outofrange) {
        std::cout << "EXCEPTION: OUT OF RANGE.\n" << outofrange.what();
        return data[0];
    }
}

vec4& vec4::operator=(const vec4 &v2)
{
    for (unsigned int i = 0; i < 4; i++) {
        data[i] = v2[i];
    }
    return *this;
}

bool vec4::operator==(const vec4 &v2) const
{
    for (unsigned int i = 0; i < 4; i++) {
        if(abs(data[i] - v2[i]) >= 1e-6f)
        {
            return false;
        }
    }
    return true;
}

bool vec4::operator!=(const vec4 &v2) const
{
    if(*this == v2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

vec4 vec4::operator+(const vec4 &v2) const
{
    vec4 temp = vec4(*this);
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] += v2[i];
    }
    return temp;
}

vec4 vec4::operator-(const vec4 &v2) const
{
    vec4 temp = vec4(*this);
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] -= v2[i];
    }
    return temp;
}

vec4 vec4::operator*(float c) const
{
    vec4 temp = vec4(*this);
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] *= c;
    }
    return temp;
}

vec4 vec4::operator/(float c) const
{
    vec4 temp = vec4(*this);
    for (unsigned int i = 0; i < 4; i++) {
        temp[i] /= c;
    }
    return temp;
}

vec4& vec4::operator+=(const vec4 &v2)
{
    *this = *this + v2;
    return *this;
}

vec4& vec4::operator-=(const vec4 &v2)
{
    *this = *this - v2;
    return *this;
}

vec4& vec4::operator*=(float c)
{
    *this = *this * c;
    return *this;
}

vec4& vec4::operator/=(float c)
{
    *this = *this / c;
    return *this;
}

std::ostream &operator<<(std::ostream &o, const vec4 &v)
{
    std::cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
    return o;
}

float dot(const vec4 &v1, const vec4 &v2)
{
    float temp = 0.f;
    for (unsigned int i = 0; i < 4; i++) {
        temp = temp + v1[i] * v2[i];
    }
    return temp;
}

vec4 cross(const vec4 &v1, const vec4 &v2)
{
    vec4 temp;
    temp[0] = v1[1] * v2[2] - v1[2] * v2[1];
    temp[1] = v1[2] * v2[0] - v1[0] * v2[2];
    temp[2] = v1[0] * v2[1] - v1[1] * v2[0];
    temp[3] = 0;
    return temp;
}

float length(const vec4 &v)
{
    float temp = 0.f;
    for (unsigned int i = 0; i < 4; i++) {
        temp = temp + v[i] * v[i];
    }
    return sqrt(temp);
}

vec4 operator*(float c, const vec4 &v)
{
    return v * c;
}

vec4 normalize(const vec4& v)
{
    return v / length(v);
}
