#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture)
{
    worldPosition = position;
    idle = idleTexture;
    run = runTexture;
    texture = idleTexture;
    speed = 2.f;

    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime)
{
    if (!getAlive())
        return;

    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());
    if (Vector2Length(velocity) < radius)
        velocity = {};

    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->getCollisionRectangle(), getCollisionRectangle()))
        target->takeDamage(damagePerSecond * deltaTime);
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(worldPosition, target->getWorldPosition());
}