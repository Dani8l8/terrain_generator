#include "raylib.h"

int main(){
    // Initialize
    const int SCREEN_WDITH = 600;
    const int SCREEN_HEIGHT = 400;

    InitWindow(SCREEN_WDITH, SCREEN_HEIGHT, "Raylib Window!");

    // Gameloop
    while (!WindowShouldClose()){
        // Render
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    // Deinitialization
    CloseWindow();
    return 0;
}
