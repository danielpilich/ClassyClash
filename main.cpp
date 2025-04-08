#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Classy Clash!");

    Character hero{windowWidth, windowHeight};

    Prop rock{Vector2{0.f,0.f}, LoadTexture("assets/map/Rock.png")};

    const Texture2D map{LoadTexture("assets/map/WorldMap.png")};
    Vector2 mapPosition{0.0, 0.0};
    const float mapScale{3.5f};

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

        // Render props
        rock.Render(hero.getWorldPosition());

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