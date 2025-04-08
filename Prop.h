#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 position, Texture2D texture);
    void Render(Vector2 heroPosition);
    Rectangle getCollisionRectangle(Vector2 heroPosition);

private:
    Texture2D texture{};
    Vector2 worldPosition{};
    float scale{4.f};
};