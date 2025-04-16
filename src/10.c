#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const int width = 800;
  const int height = width * 0.5625;
  InitWindow(width, height, "Example 10");
  SetTargetFPS(30);

  Camera2D camera = {0};
  camera.zoom = 1.0f;

  char *output = malloc(16);

  while (!WindowShouldClose()) {

    Vector2 mouse = GetMousePosition();
    sprintf(output, "%f", mouse.x);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(output, 20, 20, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
