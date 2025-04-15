#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    InitWindow(windowWidth, windowHeight, "Classy Clash!");

    Character hero{windowWidth, windowHeight};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("assets/map/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("assets/map/Log.png")}};

    Enemy goblin{
        Vector2{800.f, 300.f},
        LoadTexture("assets/characters/goblin_idle.png"),
        LoadTexture("assets/characters/goblin_run.png")};

    Enemy slime{
        Vector2{500.f, 700.f},
        LoadTexture("assets/characters/slime_idle.png"),
        LoadTexture("assets/characters/slime_run.png")};

    Enemy *enemies[]{
        &goblin,
        &slime};

    for (auto enemy : enemies)
    {
        enemy->setTarget(&hero);
    }

    goblin.setTarget(&hero);

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
        for (auto prop : props)
        {
            prop.Render(hero.getWorldPosition());
        }

        if (!hero.getAlive())
        { // Character IS NOT alive
            DrawText("Game Over!", 85.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else
        { // Character IS alive
            std::string healthInfo{"Health: "};
            healthInfo.append(std::to_string(hero.getHealth()), 0, 5);

            DrawText(healthInfo.c_str(), 65.f, 45.f, 40, RED);
        }

        // Draw the hero
        hero.tick(deltaTime);

        // Check world bounds
        if (hero.getWorldPosition().x < 0.f ||
            hero.getWorldPosition().y < 0.f ||
            hero.getWorldPosition().x + windowWidth > map.width * mapScale ||
            hero.getWorldPosition().y + windowHeight > map.height * mapScale)
        {
            hero.undoMovement();
        }

        // Check collision for props
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRectangle(hero.getWorldPosition()), hero.getCollisionRectangle()))
            {
                hero.undoMovement();
            }
        }

        // Check sword collision
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (auto enemy : enemies)
            {
                if (CheckCollisionRecs(enemy->getCollisionRectangle(), hero.getCollisionRectangle()))
                    enemy->setAlive(false);
            }
        }

        // Draw enemies
        for (auto enemy : enemies)
        {
            enemy->tick(deltaTime);
        }

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}