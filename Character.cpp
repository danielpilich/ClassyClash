#include "Character.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{
    idle = LoadTexture("assets/characters/hero_idle.png");
    run = LoadTexture("assets/characters/hero_run.png");
    texture = idle;

    width = texture.width / maxFrames;
    height = texture.height;

    worldPositionLastFrame = worldPosition;

    screenPosition = {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
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
        worldPositionLastFrame = worldPosition;
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
        frame * width,
        0.f,
        textureDirection * width,
        height};
    Rectangle heroDest{
        screenPosition.x,
        screenPosition.y,
        scale * width,
        scale * height};

    DrawTexturePro(texture, heroSource, heroDest, Vector2{}, 0.f, WHITE);
}