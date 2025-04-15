#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    virtual void tick(float deltaTime);
    Vector2 getWorldPosition() { return worldPosition; }
    virtual Vector2 getScreenPosition() = 0;
    void undoMovement();
    Rectangle getCollisionRectangle();

protected:
    Vector2 worldPosition{};
    Vector2 worldPositionLastFrame{};
    Texture2D idle{};
    Texture2D run{};
    Texture2D texture{idle};
    float textureDirection{1.f};
    float width{};
    float height{};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float scale{4.f};
    Vector2 velocity{};
};

#endif