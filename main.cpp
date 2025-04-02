#include "raylib.h";
#include "raymath.h";

int main()
{
    const int windowWidth = 384;
    const int windowHeight = 384;

    const float speed{4.0};

    InitWindow(windowWidth, windowHeight, "Classy Clash!");

    const Texture2D map{LoadTexture("assets/map/WorldMap.png")};
    Vector2 mapPosition{0.0, 0.0};

    const Texture2D heroIdle{LoadTexture("assets/characters/hero_idle.png")};
    const Texture2D heroRun{LoadTexture("assets/characters/hero_run.png")};
    Texture2D hero{heroIdle};
    Vector2 heroPosition{
        (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)hero.width / 6.0f),
        (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)hero.height)};
    float textureDirection{1.f};
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f / 12.f};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const float deltaTime{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A))
            direction.x -= 1.0;
        if (IsKeyDown(KEY_D))
            direction.x += 1.0;
        if (IsKeyDown(KEY_W))
            direction.y -= 1.0;
        if (IsKeyDown(KEY_S))
            direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            Vector2 movement = Vector2Scale(Vector2Normalize(direction), speed);
            mapPosition = Vector2Subtract(mapPosition, movement); // mapPosition = mapPosition - movement

            hero = heroRun;

            textureDirection = direction.x < 0.f ? -1.f : direction.x > 0.f ? 1.f : textureDirection;
        }
        else{
            hero = heroIdle;
        }

        // Draw the map
        DrawTextureEx(map, mapPosition, 0.0, 4.0, WHITE);

        // Update animation frame
        runningTime += deltaTime;
        if (runningTime >= updateTime)
        {
            runningTime = 0.f;
            frame++;
            if (frame > maxFrames)
                frame = 0;
        }

        // Draw the character
        Rectangle heroSource{
            frame * (float)hero.width / 6.f,
            0.f,
            textureDirection * (float)hero.width / 6.f,
            (float)hero.height};
        Rectangle heroDest{
            heroPosition.x,
            heroPosition.y,
            4.f * hero.width / 6.f,
            4.f * hero.height};

        DrawTexturePro(hero, heroSource, heroDest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}