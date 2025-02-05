#include "ECS.h"


void Entity::Update()
{
	for (auto& c : components) {
		c->Update();
	}
	for (auto& c : components) {
		c->Draw();
	}
}
