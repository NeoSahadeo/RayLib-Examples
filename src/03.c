#include <raylib.h>
#include <stdbool.h>

int main(void) {
  const int width = 800;
  const int height = width * 0.5625;
  InitWindow(width, height, "Example 3");
  SetTargetFPS(60);

  Vector2 ball_pos;
  bool cursor_hidden = false;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_H)) {
      if (cursor_hidden == true) {
        ShowCursor();
        cursor_hidden = false;
      } else {
        HideCursor();
        cursor_hidden = true;
      }
    }
    ball_pos = GetMousePosition();

    BeginDrawing();

    ClearBackground(BLACK);
    DrawCircle(ball_pos.x, ball_pos.y, 30, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
