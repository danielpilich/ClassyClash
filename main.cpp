#include "raylib.h";
#include "raymath.h";

int main(){
    const int windowDimensions[2]{
        384, // width
        384 // height
    };

    const float speed{4.0};

    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash!");

    Texture2D map = LoadTexture("assets/map/WorldMap.png");
    Vector2 mapPosition{0.0, 0.0};
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;
        if(Vector2Length(direction) != 0.0){
            Vector2 movement = Vector2Scale(Vector2Normalize(direction), speed);
            mapPosition = Vector2Subtract(mapPosition, movement); // mapPosition = mapPosition - movement
        }

        DrawTextureEx(map, mapPosition, 0.0, 4.0, WHITE);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}