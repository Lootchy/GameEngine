#include <iostream>
#include "ECS.h"
#include "Components.h"

int main()
{
    Manager manager;
    Entity& player(manager.addEntity());
    player.addComponent<TransformComponent>();
    TransformComponent& transform = player.getComponent<TransformComponent>();
    std::cout << "Position: " << transform.mTransform.position.x << ", "
        << transform.mTransform.position.y << std::endl;

}
