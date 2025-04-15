#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::tick(float deltaTime)
{
    worldPositionLastFrame = worldPosition;

    // Update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        Vector2 movement = Vector2Scale(Vector2Normalize(velocity), speed);
        worldPosition = Vector2Add(worldPosition, movement); // worldPosition = worldPosition + movement

        textureDirection = velocity.x < 0.f ? -1.f : velocity.x > 0.f ? 1.f
                                                                      : textureDirection;

        texture = run;
    }
    else
    {
        texture = idle;
    }

    velocity = {};

    // Draw the Character
    Rectangle heroSource{
        frame * width,
        0.f,
        width * textureDirection,
        height};
    Rectangle heroDest{
        getScreenPosition().x,
        getScreenPosition().y,
        scale * width,
        scale * height};

    DrawTexturePro(texture, heroSource, heroDest, Vector2{}, 0.f, WHITE);
}

void BaseCharacter::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}

Rectangle BaseCharacter::getCollisionRectangle()
{
    return Rectangle{
        getScreenPosition().x,
        getScreenPosition().y,
        width * scale,
        height * scale};
}