#include <iostream>
#include "ECS.h"
#include "Components.h"

int main()
{
    Manager manager;
    Entity& player(manager.addEntity());
    player.addComponent<TransformComponent>();
    std::cout << player.getComponent<TransformComponent>().mTransform.position.x << std::endl;

}
