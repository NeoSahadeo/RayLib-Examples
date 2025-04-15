#include <raylib.h>

int main(void) {

  const int width = 1280;
  const int height = 720;

  InitWindow(width, height, "01 Example");
  SetTargetFPS(0);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Hello world, First example", width / 2, height / 2, 20, PINK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
