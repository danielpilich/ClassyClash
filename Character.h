#include "raylib.h"

class Character
{
public:
    Character(int windowWidth, int windowHeight);
    Vector2 getWorldPosition() { return worldPosition; }
    void tick(float deltaTime);
    void undoMovement();

private:
    Texture2D idle{LoadTexture("assets/characters/hero_idle.png")};
    Texture2D run{LoadTexture("assets/characters/hero_run.png")};
    Texture2D texture{idle};
    Vector2 screenPosition{};
    Vector2 worldPosition{};
    Vector2 worldPositionLastFrame{};
    float width{};
    float height{};
    float textureDirection{1.f};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float scale{4.f};
};