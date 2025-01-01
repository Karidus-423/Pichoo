#include "raygui.h"
#include "raytracer.h"
#include <raylib.h>
#include <raymath.h>

const float ASPECT_RATIO = 16.0 / 9.0;
Vector2 hi = {0};

void DrawContents() {
  ClearBackground(GRAY);
  DrawGrid(21, 1.0f);
}

int main() {
  uint width = 1200;
  uint height = (int)(width / ASPECT_RATIO);
  InitWindow(width, height, "Raytracer");
  SetTargetFPS(165);

  Camera cam = {0};
  cam.projection = CAMERA_PERSPECTIVE;
  cam.position = Vector3Zero();
  cam.target = (Vector3){0.0f, 0.0f, 5.0f};
  cam.up = (Vector3){0.0f, 1.0f, 0.0f};
  cam.fovy = 45.0f;

  Vector3 corner_top_left = (Vector3){0.0f, 0.0f, 0.1f};

  uint show_settings = 1;

  while (WindowShouldClose() != true) {

    if (IsKeyPressed('Z') == true) {
      cam.target = Vector3Zero();
    }
    UpdateCamera(&cam, CAMERA_FREE);

    BeginDrawing();
    BeginMode3D(cam);

    DrawContents();

    EndMode3D();

    //~~~~~~~~~~~~~~~~GUI
    if (IsKeyPressed(KEY_TAB) == true) {
      show_settings++;
    }
    if (show_settings % 2 == 0) {
      SettingsWindow(OPEN, &cam);
    }
    //~~~~~~~~~~~~~~~~~~~

    EndDrawing();
  }

  CloseWindow();
}

void SettingsWindow(uint mode, Camera *cam) {
  Rectangle fov_slider = {74, 24, 95, 20};
  Rectangle info = {74, 50, 95, 50};

  switch (mode) {
  case OPEN:
    GuiSlider(fov_slider, "FOV Slider", "", &cam->fovy, 45.0f, 90.0f);
    GuiLabel(info, TextFormat("%d | %d", hi.x, hi.y));
  case CLOSE:
    return;
  }
}
