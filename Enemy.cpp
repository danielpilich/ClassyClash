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
    Vector2 toTarget = Vector2Subtract(target->getScreenPosition(), screenPosition);
    
    toTarget = Vector2Normalize(toTarget);
    
    toTarget = Vector2Scale(toTarget, speed);
    
    worldPosition = Vector2Add(worldPosition, toTarget);

    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());

    BaseCharacter::tick(deltaTime);
}