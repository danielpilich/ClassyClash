#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    virtual void tick(float deltaTime);
    Vector2 getWorldPosition() { return worldPosition; }
    Vector2 getScreenPosition() { return screenPosition; }
    void undoMovement();
    Rectangle getCollisionRectangle();

protected:
    Vector2 worldPosition{};
    Vector2 screenPosition{};
    Vector2 worldPositionLastFrame{};
    Texture2D idle{};
    Texture2D run{};
    Texture2D texture{idle};
    float width{};
    float height{};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float scale{4.f};
};

#endif