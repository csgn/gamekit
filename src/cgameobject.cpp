#include <gamekit/igameobject.h>

class CGameObject final : public IGameObject
{
public:
	explicit CGameObject(std::string id) : m_Id(std::move(id)) {}
	const std::string& GetId() const override { return m_Id; }
private:
	std::string m_Id;
};

IGameObject* GamekitAPI_IGameObject_New(const char* id)
{
	return new CGameObject(static_cast<std::string>(id));
}

int GamekitAPI_IGameObject_Destroy(const IGameObject* gameObjectPtr)
{
	if (gameObjectPtr == nullptr) return 0;

	delete gameObjectPtr;
	return 1;
}

int GamekitAPI_IGameObject_GetId(const IGameObject* gameObjectPtr, char* buffer, const int bufferSize)
{
	if (const auto id = gameObjectPtr->GetId(); bufferSize > id.length())
	{
		strcpy_s(buffer, bufferSize, id.c_str());
		return static_cast<int>(id.length());
	}

	return 0;
}


