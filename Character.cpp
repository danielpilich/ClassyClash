#include "Character.h"
#include "raymath.h"

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