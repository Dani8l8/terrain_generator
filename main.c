#include "terrain.h"

int main(void) {
    InitWindow(1200, 800, "Terreno Procedural");
    SetTargetFPS(60);

    Image heightmap;
    Model terrain = GenerateTerrain(&heightmap);

    Shader shader = LoadShader("lighting.vs", "lighting.fs");
    terrain.materials[0].shader = shader;

    Vector3 lightDir = Vector3Normalize((Vector3){ -1.0f, -1.0f, -1.0f });
    SetShaderValue(shader, GetShaderLocation(shader, "lightDirection"), &lightDir, SHADER_UNIFORM_VEC3);

    Vector4 col = (Vector4){ 1.0f, 0.8f, 0.6f, 1.0f };
    SetShaderValue(shader, GetShaderLocation(shader, "colDiffuse"), &col, SHADER_UNIFORM_VEC4);

    Camera3D camera = { 0 };
    float worldSize = TERRAIN_SIZE * TERRAIN_SCALE ;
    Vector3 center = { worldSize / 2, 0, worldSize / 2 };
    camera.position = Vector3Add(center, (Vector3){ 80, 130, 150 });
    camera.target = center;
    camera.up = (Vector3){ 0, 1, 0 };
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    UnloadImage(heightmap);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(camera);

        Matrix modelMat = MatrixIdentity();
        SetShaderValueMatrix(shader, GetShaderLocation(shader, "matModel"), modelMat);

        DrawModel(terrain, (Vector3){ 0, 0, 0 }, TERRAIN_SCALE, DARKGREEN);

        DrawGrid(50, 5);
        EndMode3D();

        EndDrawing();
    }

    UnloadModel(terrain);
    UnloadShader(shader);
    CloseWindow();
    return 0;
}
