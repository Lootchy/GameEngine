#include "ECS.h"

void Entity::Update()
{
	for (auto& c : components) {
		c->Update();
	}
}

void Entity::Draw()
{
	for (auto& c : components) {
		c->Draw();
	}
}

void Manager::Update()
{
	for (auto& e : entities) {
		e->Update();
	}
}

void Manager::Draw()
{
	for (auto& e : entities) {
		e->Draw();
	}
}

void Manager::Refresh()
{
	entities.erase(std::remove_if(
		std::begin(entities), std::end(entities),
		[this](const std::unique_ptr<Entity>& entity) { return IsInactive(entity); }
	), std::end(entities));
}




bool Manager::IsInactive(const std::unique_ptr<Entity>& lEntity)
{
	return !lEntity->IsActive();
}

Entity& Manager::addEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}
