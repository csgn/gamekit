// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_ICOMPONENT_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_ICOMPONENT_H

#include <type_traits>

#include "gamekit/copyright.h"

namespace gamekit::core::ec
{

class IEntity;

class IComponent
{
public:
	virtual ~IComponent() = default;

	void
	AttachRoot(IEntity const* entity)
	{
		m_root = entity;
	}

	template<typename T>
	T const*
	GetRoot() const
	{
		static_assert(std::is_base_of_v<IEntity, T>, "T must derive from IEntity");
		return dynamic_cast<T const*>(m_root);
	}

private:
	IEntity const* m_root = nullptr;
};

} // namespace gamekit::core::ec

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_ICOMPONENT_H
