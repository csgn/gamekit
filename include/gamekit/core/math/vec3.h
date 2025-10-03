// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC3_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC3_H

#include <string>

#include "gamekit/copyright.h"

namespace gamekit::core::math
{

template<typename T>
struct Vec3T
{
	T x;
	T y;
	T z;

	explicit Vec3T() : x(0), y(0), z(0) {}
	explicit Vec3T(T a) : x(a), y(a), z(a) {}
	explicit Vec3T(T x, T y, T z) : x(x), y(y), z(z) {}

	[[nodiscard]] std::string
	ToString() const
	{
		return "Vec3(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
};

struct Vec3 : Vec3T<float>
{
	using Vec3T::Vec3T;
};

struct Vec3Int : Vec3T<int>
{
	using Vec3T::Vec3T;
};


} // namespace gamekit::core::math

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC3_H
