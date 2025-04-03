#include "raylib.h"
#include "raymath.h"

class Character
{
public:
    Vector2 getWorldPosition() { return worldPosition; }
    void setScreenPosition(int windowWidth, int windowHeight);
    void tick(float deltaTime);

private:
    Texture2D idle{LoadTexture("assets/characters/hero_idle.png")};
    Texture2D run{LoadTexture("assets/characters/hero_run.png")};
    Texture2D texture{idle};
    Vector2 screenPosition{};
    Vector2 worldPosition{};
    float textureDirection{1.f};
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f / 12.f};
    const float speed{4.f};
};

void Character::setScreenPosition(int windowWidth, int windowHeight)
{
    screenPosition = {
        (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime)
{
    // Update character movement
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        Vector2 movement = Vector2Scale(Vector2Normalize(direction), speed);
        worldPosition = Vector2Add(worldPosition, movement); // worldPosition = worldPosition + movement

        texture = run;

        textureDirection = direction.x < 0.f ? -1.f : direction.x > 0.f ? 1.f
                                                                        : textureDirection;
    }
    else
    {
        texture = idle;
    }

    // Update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }

    // Draw the character
    Rectangle heroSource{
        frame * (float)texture.width / 6.f,
        0.f,
        textureDirection * (float)texture.width / 6.f,
        (float)texture.height};
    Rectangle heroDest{
        screenPosition.x,
        screenPosition.y,
        4.f * texture.width / 6.f,
        4.f * texture.height};

    DrawTexturePro(texture, heroSource, heroDest, Vector2{}, 0.f, WHITE);
}

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Classy Clash!");

    Character hero{};
    hero.setScreenPosition(windowWidth, windowHeight);

    const Texture2D map{LoadTexture("assets/map/WorldMap.png")};
    Vector2 mapPosition{0.0, 0.0};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const float deltaTime{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // Moving the map
        mapPosition = Vector2Scale(hero.getWorldPosition(), -1.f);

        // Draw the map
        DrawTextureEx(map, mapPosition, 0.0, 4.0, WHITE);

        hero.tick(deltaTime);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}