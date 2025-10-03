// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC2_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC2_H

#include <string>
#include "gamekit/copyright.h"

namespace gamekit::core::math
{

template<typename T>
struct Vec2T
{
	T x;
	T y;

	explicit Vec2T() : x(0), y(0) {}
	explicit Vec2T(T a) : x(a), y(a) {}
	explicit Vec2T(T x, T y) : x(x), y(y) {}

	[[nodiscard]] std::string
	ToString() const
	{
		return "Vec2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
};

struct Vec2 : Vec2T<float>
{
	using Vec2T::Vec2T;
};

struct Vec2Int : Vec2T<int>
{
	using Vec2T::Vec2T;
};

} // namespace gamekit::core::math

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_MATH_VEC2_H
