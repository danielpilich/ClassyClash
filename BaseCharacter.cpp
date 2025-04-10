#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
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