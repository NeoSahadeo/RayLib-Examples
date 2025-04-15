#include <raylib.h>

int main(void) {
  const int width = 1280;
  const int height = width * 0.5625;
  InitWindow(width, height, "Example 2");
  SetTargetFPS(60);

  Vector2 ball_position = {
      (float)width / 2,
      (float)height / 2,
  };

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      ball_position.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      ball_position.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
      ball_position.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      ball_position.y += 2.0f;

    BeginDrawing();

    ClearBackground(BLACK);

    DrawCircle(ball_position.x, ball_position.y, 30, RED);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
