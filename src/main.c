#include "raylib.h"
#include "raytracer.h"

uint ASPECT_RATIO = 16 / 9;

int main() {
  uint width = 600;
  uint height = (int)(width / ASPECT_RATIO);
  InitWindow(width, height, "Raytracer");

  while (WindowShouldClose() != true) {
    BeginDrawing();
    ClearBackground(SKYBLUE);
    EndDrawing();
  }

  CloseWindow();
}
