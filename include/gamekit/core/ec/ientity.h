// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_IENTITY_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_IENTITY_H

#include <memory>
#include <typeindex>
#include <unordered_map>

#include "gamekit/copyright.h"
#include "gamekit/core/ec/icomponent.h" // IWYU pragma: export
#include "gamekit/core/ec/ibehaviour.h" // IWYU pragma: export

namespace gamekit::core::ec
{

class IEntity
{
public:
	virtual ~IEntity() = default;

	template<typename T>
	void
	AttachComponent(std::unique_ptr<T> component)
	{
		static_assert(std::is_base_of_v<IComponent, T>, "T must derive from IComponent");

		component->AttachRoot(this);
		m_components[std::type_index(typeid(T))] = std::move(component);
	}

	template<typename T>
	T*
	GetComponent() const
	{
		static_assert(std::is_base_of_v<IComponent, T>, "T must derive from IComponent");
		auto it = m_components.find(std::type_index(typeid(T)));
		if (it != m_components.end())
			return static_cast<T*>(it->second.get());

		return nullptr;
	}

	template<typename T>
	void
	AttachBehaviour(std::unique_ptr<T> behaviour)
	{
		static_assert(std::is_base_of_v<IBehaviour, T>, "T must derive from IBehaviour");

		behaviour->AttachRoot(this);
		m_behaviours[std::type_index(typeid(T))] = std::move(behaviour);
	}

	template<typename T>
	T*
	GetBehaviour() const
	{
		static_assert(std::is_base_of_v<IBehaviour, T>, "T must derive from IBehaviour");
		auto it = m_behaviours.find(std::type_index(typeid(T)));
		if (it != m_behaviours.end())
			return static_cast<T*>(it->second.get());

		return nullptr;
	}

private:
	std::unordered_map<std::type_index, std::unique_ptr<IComponent>> m_components;
	std::unordered_map<std::type_index, std::unique_ptr<IBehaviour>> m_behaviours;
};

} // namespace gamekit::core::ec

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_EC_IENTITY_H
