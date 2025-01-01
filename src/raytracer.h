#ifndef RAYTRACER
#define RAYTRACER

#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define OPEN 0
#define CLOSE 1

void DrawContents();
void SettingsWindow(uint mode, Camera *cam);

#endif
