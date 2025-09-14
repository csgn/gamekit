#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once

#include <string>

#include "gamekit_api_common.h"

struct IGameObject
{
public:
	virtual ~IGameObject() = default;
	virtual const std::string& GetId() const = 0;
};

GAMEKIT_API IGameObject* CALL_TYPE GamekitAPI_IGameObject_New(const char* id);
GAMEKIT_API int CALL_TYPE GamekitAPI_IGameObject_Destroy(const IGameObject* gameObjectPtr);
GAMEKIT_API int CALL_TYPE GamekitAPI_IGameObject_GetId(const IGameObject* gameObjectPtr, char* buffer, int bufferSize);

#endif // GAMEOBJECT_H
