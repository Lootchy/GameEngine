#pragma once
#include <vector>
#include <memory>

class Entity;

class TransformSystem
{
public:
	void Update(std::vector<std::unique_ptr<Entity>>& entities);
};

