#include "raylib.h";

int main(){
    const int windowDimensions[2]{
        384, // width
        384 // height
    };

    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash!");

    Texture2D map = LoadTexture("assets/map/WorldMap.png");
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPosition{0.0, 0.0};
        DrawTextureEx(map, mapPosition, 0.0, 2.0, WHITE);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}