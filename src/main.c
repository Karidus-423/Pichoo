#include "raytracer.h"

const float ASPECT_RATIO = 16.0 / 9.0;

int main() {
  int width = 900;
  int height = (int)(width / ASPECT_RATIO);
  InitWindow(width, height, "Pichoo");
  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, -5.0f};
  camera.target = Vector3Zero();
  camera.projection = CAMERA_PERSPECTIVE;
  camera.fovy = 45.0f;
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};

  while (!WindowShouldClose()) {
    GetWindowScaleDPI();
    UpdateCamera(&camera, CAMERA_FREE);
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    BeginMode3D(camera);
    ClearBackground(SKYBLUE);

    DrawSphere(
        (Vector3){camera.position.x, camera.position.y, camera.position.z + 1},
        0.02f, RED);

    DrawCube((Vector3){0.0f, 0.0f, 10.0f}, 1, 1, 1, GREEN);
    DrawGrid(20, 1);

    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
