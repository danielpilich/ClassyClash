#include "raylib.h"

class Character
{
public:
    Character();
    Vector2 getWorldPosition() { return worldPosition; }
    void setScreenPosition(int windowWidth, int windowHeight);
    void tick(float deltaTime);

private:
    Texture2D idle{LoadTexture("assets/characters/hero_idle.png")};
    Texture2D run{LoadTexture("assets/characters/hero_run.png")};
    Texture2D texture{idle};
    Vector2 screenPosition{};
    Vector2 worldPosition{};
    float width{};
    float height{};
    float textureDirection{1.f};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
};