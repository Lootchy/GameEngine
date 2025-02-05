#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() 
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;

}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component 
{
public:
	Entity* mEntity;

	virtual void Init(){}
	virtual void Update(){}
	virtual void Draw(){}

	virtual ~Component() {}
};

class Entity {
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray mComponentArray;
	ComponentBitSet mComponentBitSet;

public:

	void Update();
	void Draw();

	bool IsActive() const { return active; }
	void Destroy() { active = false; }

	template <typename T> bool hasComponent()const {
		return mComponentBitSet[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		mComponentArray[getComponentTypeID<T>()] = c;
		mComponentBitSet[getComponentTypeID<T>()] = true;

		c->Init();
		return *c;
	}

	template <typename T> T& getComponent() const 
	{
		auto ptr(mComponentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class ECS
{
};

