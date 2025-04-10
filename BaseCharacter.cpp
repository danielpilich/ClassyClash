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

    // Draw the Character
    Rectangle heroSource{
        frame * width,
        0.f,
        width, // * textureDirection
        height};
    Rectangle heroDest{
        screenPosition.x,
        screenPosition.y,
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
        screenPosition.x,
        screenPosition.y,
        width * scale,
        height * scale};
}