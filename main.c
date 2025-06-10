#include "terrain.h"

/* #define MAX_ROCKS 80 */

/* typedef struct Rock { */
/*     Vector3 position; */
/*     Model model; */
/* } Rock; */

/* Rock rocks[MAX_ROCKS]; */

/* #define GRID_ROWS 4 */
/* #define GRID_COLS 4 */
/* #define CELL_SIZE (TERRAIN_SIZE / GRID_ROWS) */

/* float heights[GRID_ROWS][GRID_COLS] = { */
/*   { 0.2f, 0.2f, 0.2f, 0.2f }, */
/*   { 0.2f, 1.5f, 1.2f, 0.2f }, */
/*   { 0.2f, 1.5f, 1.2f, 0.2f }, */
/*   { 0.2f, 0.2f, 0.2f, 0.2f } */
/* }; */

/* Image GenerateBlendedHeightmap(void) { */
/*     // 1. Generate base seamless noise */
/*     Image base = GenImagePerlinNoise(TERRAIN_SIZE, TERRAIN_SIZE, 0, 0, 1.0f); */
/*     Color *basePixels = LoadImageColors(base); */

/*     // 2. Create grid-based distortion map */
/*     Color *distortionPixels = (Color *)RL_MALLOC(TERRAIN_SIZE * TERRAIN_SIZE * sizeof(Color)); */

/*     for (int gy = 0; gy < GRID_ROWS; gy++) { */
/*         for (int gx = 0; gx < GRID_COLS; gx++) { */

/*             for (int y = 0; y < CELL_SIZE; y++) { */
/*                 for (int x = 0; x < CELL_SIZE; x++) { */
/*                     int globalX = gx * CELL_SIZE + x; */
/*                     int globalY = gy * CELL_SIZE + y; */

                    
/*                     float hx0y0 = heights[gy][gx]; */
/*                     float hx1y0 = heights[gy][gx+1]; */
/*                     float hx0y1 = heights[gy+1][gx]; */
/*                     float hx1y1 = heights[gy+1][gx+1]; */

/*                     float tx = (x % CELL_SIZE) / (float)CELL_SIZE; */
/*                     float ty = (y % CELL_SIZE) / (float)CELL_SIZE; */

/*                     float factor = Lerp(Lerp(hx0y0, hx1y0, tx), */
/*                                         Lerp(hx0y1, hx1y1, tx), */
/*                                         ty); */

/*                     // Clamp to avoid going out of bounds due to integer rounding */
/*                     if (globalX >= TERRAIN_SIZE || globalY >= TERRAIN_SIZE) continue; */

/*                     unsigned char value = (unsigned char)(factor * 127.5f); // ~0.0–2.0 mapped to 0–255 */
/*                     distortionPixels[globalY * TERRAIN_SIZE + globalX] = (Color){ value, value, value, 255 }; */
/*                 } */
/*             } */
            
/*         } */
/*     } */

/*     // 3. Blend both maps */
/*     Color *finalPixels = (Color *)RL_MALLOC(TERRAIN_SIZE * TERRAIN_SIZE * sizeof(Color)); */

/*     for (int i = 0; i < TERRAIN_SIZE * TERRAIN_SIZE; i++) { */
/*         float baseHeight = basePixels[i].r / 255.0f; */
/*         float factor = distortionPixels[i].r / 127.5f; */

/*         float finalValue = baseHeight * factor; */
/*         finalValue = fminf(fmaxf(finalValue, 0.0f), 1.0f); // clamp [0,1] */

/*         unsigned char gray = (unsigned char)(finalValue * 255); */
/*         finalPixels[i] = (Color){ gray, gray, gray, 255 }; */
/*     } */

    

/*     // 4. Create final image */
/*     Image finalImage = { */
/*         .data = finalPixels, */
/*         .width = TERRAIN_SIZE, */
/*         .height = TERRAIN_SIZE, */
/*         .mipmaps = 1, */
/*         .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 */
/*     }; */

/*     // Cleanup */
/*     UnloadImageColors(basePixels); */
/*     UnloadImage(base); */
/*     RL_FREE(distortionPixels); */

/*     return finalImage; */
/* } */


// Genera una esfera deformada aplicando ruido simple a los vértices
/* Mesh GenerateDeformedSphere(float radius, int rings, int slices, float deformAmount) { */
/*     Mesh mesh = { 0 }; */
/*     int vertexCount = rings * slices; */
/*     Vector3 *vertices = (Vector3 *)malloc(vertexCount * sizeof(Vector3)); */
/*     Vector3 *normals = (Vector3 *)malloc(vertexCount * sizeof(Vector3)); */
/*     Vector2 *texcoords = (Vector2 *)malloc(vertexCount * sizeof(Vector2)); */
/*     unsigned short *indices = (unsigned short *)malloc((rings - 1) * (slices - 1) * 6 * sizeof(unsigned short)); */

/*     int index = 0; */
/*     for (int i = 0; i < rings; i++) { */
/*         float theta = (float)i / (rings - 1) * PI; */
/*         for (int j = 0; j < slices; j++) { */
/*             float phi = (float)j / (slices - 1) * 2.0f * PI; */

/*             float x = sinf(theta) * cosf(phi); */
/*             float y = cosf(theta); */
/*             float z = sinf(theta) * sinf(phi); */

/*             // Ruido simple para deformar el radio */
/*             float noise = ((float)GetRandomValue(-1000, 1000) / 1000.0f); */
/*             float r = radius + noise * deformAmount; */

/*             vertices[index] = (Vector3){ x * r, y * r, z * r }; */
/*             normals[index] = Vector3Normalize((Vector3){ x, y, z }); */
/*             texcoords[index] = (Vector2){ (float)j / (slices - 1), (float)i / (rings - 1) }; */

/*             index++; */
/*         } */
/*     } */

/*     int idx = 0; */
/*     for (int i = 0; i < rings - 1; i++) { */
/*         for (int j = 0; j < slices - 1; j++) { */
/*             int cur = i * slices + j; */
/*             indices[idx++] = cur; */
/*             indices[idx++] = cur + slices; */
/*             indices[idx++] = cur + slices + 1; */

/*             indices[idx++] = cur; */
/*             indices[idx++] = cur + slices + 1; */
/*             indices[idx++] = cur + 1; */
/*         } */
/*     } */

/*     mesh.vertexCount = vertexCount; */
/*     mesh.triangleCount = idx / 3; */
/*     mesh.vertices = (float *)vertices; */
/*     mesh.normals = (float *)normals; */
/*     mesh.texcoords = (float *)texcoords; */
/*     mesh.indices = (unsigned short *)indices; */

/*     UploadMesh(&mesh, false); */
/*     return mesh; */
/* } */

// Genera las rocas deformadas y las posiciona sobre el terreno
/* void GenerateDeformedRocks(Image heightmap, float terrainHeight) { */
/*     for (int i = 0; i < MAX_ROCKS; i++) { */
/*         float x = GetRandomValue(0, TERRAIN_SIZE - 1); */
/*         float z = GetRandomValue(0, TERRAIN_SIZE - 1); */
/*         float y = GetHeightAtPoint(heightmap, (int)x, (int)z, terrainHeight); */
/*         rocks[i].position = (Vector3){ x * TERRAIN_SCALE, y, z * TERRAIN_SCALE }; */

/*         float radius = GetRandomValue(3, 8) / 10.0f;  // 0.3 - 0.8 */
/*         float deformAmount = radius * 0.4f; */

/*         Mesh deformMesh = GenerateDeformedSphere(radius, 16, 16, deformAmount); */
/*         rocks[i].model = LoadModelFromMesh(deformMesh); */
/*     } */
/* } */

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

    /* GenerateDeformedRocks(heightmap, MAX_TERRAIN_HEIGHT); */
    UnloadImage(heightmap);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(camera);

        Matrix modelMat = MatrixIdentity();
        SetShaderValueMatrix(shader, GetShaderLocation(shader, "matModel"), modelMat);

        DrawModel(terrain, (Vector3){ 0, 0, 0 }, TERRAIN_SCALE, DARKGREEN);
        /* DrawModel(terrain, (Vector3){ 0, 0, TERRAIN_SIZE }, TERRAIN_SCALE, DARKGREEN); */

        /* for (int i = 0; i < MAX_ROCKS; i++) { */
        /*     DrawModel(rocks[i].model, rocks[i].position, 1.0f, GRAY); */
        /* } */

        DrawGrid(50, 5);
        EndMode3D();

        /* DrawText("Terreno con Rocas Deformadas", 10, 10, 20, DARKGRAY); */
        EndDrawing();
    }

    /* for (int i = 0; i < MAX_ROCKS; i++) { */
    /*     UnloadModel(rocks[i].model); */
    /* } */
    UnloadModel(terrain);
    UnloadShader(shader);
    CloseWindow();
    return 0;
}
