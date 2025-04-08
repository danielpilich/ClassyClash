#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 position, Texture2D tex) : worldPosition(position),
                                              texture(tex)
{
}

void Prop::Render(Vector2 heroPosition)
{
    Vector2 screenPosition{Vector2Subtract(worldPosition, heroPosition)};
    DrawTextureEx(texture, screenPosition, 0.f, 4.f, WHITE);
}

Rectangle Prop::getCollisionRectangle(Vector2 heroPosition)
{
    Vector2 screenPosition{Vector2Subtract(worldPosition, heroPosition)};
    return Rectangle{
        screenPosition.x,
        screenPosition.y,
        texture.width * scale,
        texture.height * scale};
}