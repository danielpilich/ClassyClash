#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture)
{
    worldPosition = position;
    idle = idleTexture;
    run = runTexture;
    texture = idleTexture;

    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime)
{
    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());

    BaseCharacter::tick(deltaTime);
}