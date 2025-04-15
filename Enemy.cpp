#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture)
{
    worldPosition = position;
    idle = idleTexture;
    run = runTexture;
    texture = idleTexture;
    speed = 3.5f;

    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime)
{
    if (!getAlive())
        return;

    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());

    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->getCollisionRectangle(), getCollisionRectangle()))
        target->takeDamage(damagePerSecond * deltaTime);
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(worldPosition, target->getWorldPosition());
}