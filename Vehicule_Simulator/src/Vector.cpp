#include <cmath>

#include "Vector.h"

namespace maths {

Vector3 const Vector3::null { 0.f, 0.f, 0.f };

Vector3::Vector3()
:	x(0.f), y(0.f), z(0.f)
{}

Vector3::Vector3(Vector3 const& v)
:	x(v.x) , y(v.y), z(v.z)
{}

auto Vector3::operator=(Vector3 const& v) -> Vector3&
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	return *this;
}

Vector3::Vector3(float f)
:	x(f), y(f), z(f)
{}

Vector3::Vector3(float x, float y, float z)
:	x(x), y(y), z(z)
{}

auto Vector3::dot(Vector3 const& v)  const -> float
{
	return x * v.x + y * v.y + z * v.z;
}

auto Vector3::cross(Vector3 const& v) const -> Vector3
{
	return {
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	};
}

auto Vector3::norm() const -> float
{
	return sqrt(x * x + y * y + z * z);
}

auto Vector3::normalize() -> Vector3&
{
	float n = this->norm();

	x /= n; y /= n; z /= n;

	return *this;
}

auto Vector3::operator*(float f) const -> Vector3
{
	return {x * f, y * f, z * f};
}

auto Vector3::operator*=(float f) -> Vector3&
{
	x *= f;	y *= f;	z *= f;

	return *this;
}

auto Vector3::operator/(float f) const -> Vector3
{
	return { x / f, y / f, z / f};
}

auto Vector3::operator/=(float f) -> Vector3&
{
	x /= f; y /= f; z /= f;

	return *this;
}

auto Vector3::operator+(Vector3 const& v) const -> Vector3
{
	return {
		x + v.x,
		y + v.y,
		z + v.z
	};	
}

auto Vector3::operator+=(Vector3 const& v) -> Vector3&
{
	x += v.x; y += v.y; z += v.z;

	return *this;
}

auto Vector3::operator-(Vector3 const& v) const -> Vector3
{
	return {
		x - v.x,
		y - v.y,
		z - v.z
	};
}

auto Vector3::operator-=(Vector3 const& v) -> Vector3&
{
	x -= v.x; y -= v.y; z -= v.z;

	return *this;
}

auto Vector3::operator==(Vector3 const& v) const -> bool
{
	if (this->x != v.x || this->y != v.y || this->z != v.z)
		return false;

	return true;
}

auto Vector3::operator!=(Vector3 const& v) const -> bool
{
	return !(*this == v);
}


Vector2 const Vector2::null { 0.f, 0.f};

Vector2::Vector2()
:	x(0.f), y(0.f)
{}

Vector2::Vector2(Vector2 const& v)
:	x(v.x), y(v.y)
{}

auto Vector2::operator=(Vector2 const& v) -> Vector2&
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
	}

	return *this;
}

Vector2::Vector2(float f)
:	x(f), y(f)
{}

Vector2::Vector2(float x, float y)
:	x(x), y(y)
{}

auto Vector2::operator*(float f) const -> Vector2
{
	return {x * f, y * f};
}

auto Vector2::operator*=(float f) -> Vector2&
{
	x *= f;	y *= f;

	return *this;
}

auto Vector2::operator/(float f) const -> Vector2
{
	return { x / f, y / f};
}

auto Vector2::operator/=(float f) -> Vector2&
{
	x /= f; y /= f;

	return *this;
}

auto Vector2::operator+(Vector2 const& v) const -> Vector2
{
	return {
		x + v.x,
		y + v.y
	};	
}

auto Vector2::operator+=(Vector2 const& v) -> Vector2&
{
	x += v.x; y += v.y;

	return *this;
}

auto Vector2::operator-(Vector2 const& v) const -> Vector2
{
	return {
		x - v.x,
		y - v.y
	};
}

auto Vector2::operator-=(Vector2 const& v) -> Vector2&
{
	x -= v.x; y -= v.y;

	return *this;
}

auto Vector2::operator==(Vector2 const& v) const -> bool
{
	if (this->x != v.x || this->y != v.y)
		return false;

	return true;
}

auto Vector2::operator!=(Vector2 const& v) const -> bool
{
	return !(*this == v);
}

} //namespace math

auto operator<<(std::ostream& os, maths::Vector3 const& v) -> std::ostream&
{
	os << v.x << "\t" << v.y << "\t" << v.z;

	return os;
}

auto operator<<(std::ostream& os, maths::Vector2 const& v) -> std::ostream&
{
	os << v.x << "\t" << v.y;

	return os;
}
