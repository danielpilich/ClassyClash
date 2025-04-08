#include "raylib.h"

class Enemy
{
public:
    Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture);
    Vector2 getWorldPosition() { return worldPosition; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRectangle();

private:
    Texture2D idle{};
    Texture2D run{};
    Texture2D texture{idle};
    Vector2 screenPosition{};
    Vector2 worldPosition{};
    Vector2 worldPositionLastFrame{};
    float width{};
    float height{};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 24.f};
    float speed{4.f};
    float scale{4.f};
};