#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture) : worldPosition(position), idle(idleTexture), run(runTexture), texture(idleTexture)
{
    width = texture.width / maxFrames;
    height = texture.height;

    worldPositionLastFrame = worldPosition;
}

void Enemy::tick(float deltaTime)
{
    // Update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        if (frame > maxFrames)
            frame = 0;
    }

    // Draw the Enemy
    Rectangle heroSource{
        frame * width,
        0.f,
        width,
        height};
    Rectangle heroDest{
        screenPosition.x,
        screenPosition.y,
        scale * width,
        scale * height};

    DrawTexturePro(texture, heroSource, heroDest, Vector2{}, 0.f, WHITE);
}

void Enemy::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}

Rectangle Enemy::getCollisionRectangle()
{
    return Rectangle{
        screenPosition.x,
        screenPosition.y,
        width * scale,
        height * scale};
}