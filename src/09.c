#include <math.h>
#include <raylib.h>

#define MAX_BUILDINGS 100

int main(void) {
  const int width = 800;
  const int height = width * 0.5625;
  InitWindow(width, height, "Example 9");
  SetTargetFPS(60);

  int spacing = 0;
  Rectangle player = {(float)width / 2, (float)height / 2, 40, 40};
  Rectangle buildings[MAX_BUILDINGS] = {0};
  Color build_color[MAX_BUILDINGS] = {0};

  for (int x = 0; x < MAX_BUILDINGS; x++) {
    buildings[x].width = (float)GetRandomValue(50, 200);
    buildings[x].height = (float)GetRandomValue(100, 800);
    buildings[x].y = height - 130.0f - buildings[x].height;
    buildings[x].x = -6000.0f + spacing;

    spacing += (int)buildings[x].width;
    build_color[x] = (Color){(unsigned char)GetRandomValue(200, 240),
                             (unsigned char)GetRandomValue(200, 240),
                             (unsigned char)GetRandomValue(200, 250), 255};
  }
  Camera2D camera = {0};
  camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
  camera.offset = (Vector2){width / 2.0f, height / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      player.x += 40;
    else if (IsKeyDown(KEY_LEFT))
      player.x -= 40;

    camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
    if (IsKeyDown(KEY_A))
      camera.rotation--;
    else if (IsKeyDown(KEY_D))
      camera.rotation++;

    if (camera.rotation > 40)
      camera.rotation = 40;
    else if (camera.rotation < -40)
      camera.rotation = -40;

    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));
    // camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() *
    // 0.1f));
    if (IsKeyPressed(KEY_R)) {
      camera.zoom = 1.0f;
      camera.rotation = 0.0f;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < MAX_BUILDINGS; i++)
      DrawRectangleRec(buildings[i], build_color[i]);

    DrawRectangleRec(player, RED);

    DrawLine((int)camera.target.x, -height * 10, (int)camera.target.x,
             height * 10, GREEN);
    DrawLine(-width * 10, (int)camera.target.y, width * 10,
             (int)camera.target.y, GREEN);

    EndMode2D();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
