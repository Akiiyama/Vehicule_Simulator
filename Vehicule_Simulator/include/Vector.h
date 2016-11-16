#ifndef __MATHS_VECTOR_H_INCLUDED__
#define __MATHS_VECTOR_H_INCLUDED__

#include <ostream>

namespace maths {

class Vector3
{
public:
	Vector3();
	~Vector3()									= default;
	Vector3(Vector3 const&);
	auto operator=(Vector3 const&) -> Vector3&;

	Vector3(float);
	Vector3(float, float, float);

	auto dot(Vector3 const&)		const	-> float;
	auto cross(Vector3 const&)		const	-> Vector3;
	auto norm()						const	-> float;
	auto normalize()						-> Vector3&;

	auto operator*(float) 			const	-> Vector3;
	auto operator*=(float)					-> Vector3&;
	auto operator/(float)			const	-> Vector3;
	auto operator/=(float)					-> Vector3&;

	auto operator+(Vector3 const&)	const	-> Vector3;
	auto operator+=(Vector3 const&)			-> Vector3&;
	auto operator-(Vector3 const&)	const	-> Vector3;
	auto operator-=(Vector3 const&)			-> Vector3&;

	auto operator==(Vector3 const&)	const	-> bool;
	auto operator!=(Vector3 const&)	const	-> bool;

	static	Vector3 const null;

	float x, y, z;
};

class Vector2
{
public:
	Vector2();
	~Vector2()									= default;
	Vector2(Vector2 const&);
	auto operator=(Vector2 const&) -> Vector2&;

	Vector2(float);
	Vector2(float, float);

	auto operator*(float) 			const	-> Vector2;
	auto operator*=(float)					-> Vector2&;
	auto operator/(float)			const	-> Vector2;
	auto operator/=(float)					-> Vector2&;

	auto operator+(Vector2 const&)	const	-> Vector2;
	auto operator+=(Vector2 const&)			-> Vector2&;
	auto operator-(Vector2 const&)	const	-> Vector2;
	auto operator-=(Vector2 const&)			-> Vector2&;

	auto operator==(Vector2 const&)	const	-> bool;
	auto operator!=(Vector2 const&)	const	-> bool;

	static	Vector2 const null;

	float x, y;
};

} //namespace math

auto operator<<(std::ostream&, maths::Vector3 const&) -> std::ostream&;
auto operator<<(std::ostream&, maths::Vector2 const&) -> std::ostream&;

#endif //__MATHS_VECTOR_H_INCLUDED__
