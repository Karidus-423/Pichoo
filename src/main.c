#include "raytracer.h"

const float ASPECT_RATIO = 16.0 / 9.0;

ahu hey;

void FovTest(Camera3D *cam, float *fovDirection) {
  float *fov = &cam->fovy;
  float change = 0.5f;

  *fov += change * (*fovDirection);

  if (*fov <= 45.0f || *fov >= 90.0f) {
    *fovDirection *= -1;
  }
  DrawSphere((Vector3){cam->position.x, cam->position.y, 0.5f}, 0.01f, RED);
}

void DrawPixelGrid(int win_width, int win_height) {}

int main() {
  int width = 900;
  int height = (int)(width / ASPECT_RATIO);

  InitWindow(width, height, "Pichoo");

  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, 0.0f};
  camera.target = (Vector3){0.0f, 0.0f, 5.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  SetTargetFPS(60);
  Vector3 zpos = {0.0f, 0.0f, 10.0f};
  float fovDirection = 1.0f;

  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_FREE);
    if (IsKeyPressed('Z')) {
      camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    };

    BeginDrawing();
    ClearBackground(SKYBLUE);
    BeginMode3D(camera);

    DrawCube(zpos, 1.0f, 1.0f, 1.0f, GREEN);

    DrawGrid(20, 1.0f);

    // FovTest(&camera, &fovDirection);
    DrawPixelGrid(width, height);

    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
