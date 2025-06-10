#ifndef TERRAIN_H
#define TERRAIN_H

#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>
#include "config.h"

Image GenerateBlendedHeightmap(void);
float GetHeightAtPoint(Image heightmap, int x, int z, float maxHeight);
Model GenerateTerrain(Image* heightmapOut);

#endif // TERRAIN_H

