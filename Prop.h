#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 position, Texture2D texture);
    void Render(Vector2 heroPosition);
    Rectangle getCollisionRectangle(Vector2 heroPosition);

private:
    Vector2 worldPosition{};
    Texture2D texture{};
    float scale{4.f};
};