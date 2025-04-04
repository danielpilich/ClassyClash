#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Classy Clash!");

    Character hero{};
    hero.setScreenPosition(windowWidth, windowHeight);

    const Texture2D map{LoadTexture("assets/map/WorldMap.png")};
    Vector2 mapPosition{0.0, 0.0};
    const float mapScale{4.f};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const float deltaTime{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // Moving the map
        mapPosition = Vector2Scale(hero.getWorldPosition(), -1.f);

        // Draw the map
        DrawTextureEx(map, mapPosition, 0.f, mapScale, WHITE);

        hero.tick(deltaTime);

        // World bounds
        if (hero.getWorldPosition().x < 0.f ||
            hero.getWorldPosition().y < 0.f ||
            hero.getWorldPosition().x + windowWidth > map.width * mapScale ||
            hero.getWorldPosition().y + windowHeight > map.height * mapScale)
        {
            hero.undoMovement();
        }

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}