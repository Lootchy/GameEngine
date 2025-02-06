#pragma once
#include "Components.h"

class TransformComponent : public Component
{
public:
    struct Transform {
        struct Position {
            float x, y, z;
            Position(float x = 0.0f, float y = 0.0f, float z = 0.0f)
                : x(x), y(y), z(z) {
            }
        };

        struct Scale {
            float x, y, z;
            Scale(float x = 1.0f, float y = 1.0f, float z = 1.0f)
                : x(x), y(y), z(z) {
            }
        };

        Position position;
        Scale scale;
        float rotation;

        Transform(float x = 0.0f, float y = 0.0f, float z = 0.0f,
            float sx = 1.0f, float sy = 1.0f, float sz = 1.0f,
            float rot = 0.0f)
            : position(x, y, z), scale(sx, sy, sz), rotation(rot) {
        }
    };

    Transform mTransform;

    TransformComponent() = default;

    TransformComponent(float x, float y, float z, float sx, float sy, float sz, float rot)
        : mTransform(x, y, z, sx, sy, sz, rot) {
    }
};
