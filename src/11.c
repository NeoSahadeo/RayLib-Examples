#include <raylib.h>

int main(void) {
  const int width = 800;
  const int height = width * 0.5625;
  InitWindow(width, height, "Example 10");
  SetTargetFPS(30);

  while (!WindowShouldClose()) {
  }

  CloseWindow();
  return 0;
}
