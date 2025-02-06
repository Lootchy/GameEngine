#include "TransformSystem.h"
#include "Components.h"

void TransformSystem::Update(std::vector<std::unique_ptr<Entity>>& entities)
{
	for (auto& entity : entities) {
		if (entity.get()->IsActive() && entity.get()->hasComponent<TransformComponent>()) {
			TransformComponent& transform = entity->getComponent<TransformComponent>();
			std::cout << "Entity has transform component\n";
		}
	}
}
