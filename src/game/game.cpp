#include "game.hpp"
#include "raylib.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

Gates::Gates(float x, float y, float gate_size) {
  posx = x;
  posy = y;
  size = gate_size;
  selected = false;
  hover = false;
}
Gates::~Gates() {}
void Gates::Draw() {

  float wireLen = 100;
  if (hover) {
    DrawRectangle(posx - 5, posy - 5, size + 10, size + 10, ORANGE);
  }
  DrawRectangle(posx, posy, size, size, GREEN);

  float t = 30.0;
  Vector2 v1 = {posx, posy + t};
  Vector2 v2 = {posx - wireLen, posy + t};
  DrawLineEx(v1, v2, 10, BLUE);
  DrawCircleV(v1, 5, RED);

  float t1 = 70.0;
  Vector2 v12 = {posx, posy + t1};
  Vector2 v22 = {posx - wireLen, posy + t1};
  DrawLineEx(v12, v22, 10, BLUE);

  DrawCircleV(v12, 5, RED);

  float t2 = 50.0;
  Vector2 v13 = {posx + size, posy + t2};
  Vector2 v23 = {posx + size + wireLen, posy + t2};
  DrawLineEx(v13, v23, 10, BLUE);

  DrawCircleV(v13, 5, RED);
}

Game::Game() {
  target = LoadRenderTexture(screen_width, screen_height);
  SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
  Vector2 MousePosition = {-100.0f, -100.0f};
  gates = std::vector<Gates>();
  gates.push_back(Gates(200, 200, 100));
  gates.push_back(Gates(500, 500, 100));
  gates.push_back(Gates(500, 100, 100));
}

Game::~Game() { UnloadRenderTexture(target); }

void Game::Update() {
  MousePosition = GetMousePosition();
  frame_counter++;
  for (Gates &g : gates) {
    bool hover = CheckCollisionPointRec(
        MousePosition, Rectangle{g.posx, g.posy, g.size, g.size});
    if (hover && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
      g.selected = !g.selected;
    }
    if (g.selected) {
      g.posx = MousePosition.x;
      g.posy = MousePosition.y;
    }
    if (hover) {
      g.hover = true;
    } else {
      g.hover = false;
    }
  }
}

void Game::Draw() {
  BeginDrawing();
  ClearBackground(WHITE);
  DrawCircle(4, 4, 2, RED);
  DrawCircle(6, 4, 2, RED);
  for (Gates g : gates) {
    g.Draw();
  }
  EndDrawing();
  // BeginTextureMode(target);
  // ClearBackground(RAYWHITE);
  //
  // DrawRectangle(70, 90, 200, 200, BLACK);
  // DrawRectangle(70 + 16, 90 + 16, 200 - 32, 200 - 32, RAYWHITE);
  // DrawText("raylib", 70 + 200 - MeasureText("raylib", 40) - 32,
  //          90 + 200 - 40 - 24, 40, BLACK);
  //
  // DrawText("6.x", 290, 90 - 26, 280, BLACK);
  // DrawText("GAMEJAM", 70, 90 + 210, 120, MAROON);
  //
  // if ((frame_counter / 20) % 2)
  // {
  //     DrawText("are you ready?", 160, 500, 50, BLACK);
  // }
  //
  // DrawRectangleLinesEx({0, 0, (float)screen_width, (float)screen_height}, 16,
  // BLACK);
  //
  // EndTextureMode();
  //
  // BeginDrawing();
  // ClearBackground(RAYWHITE);
  //
  // DrawTexturePro(target.texture,
  //                {0, 0, (float)target.texture.width,
  //                (float)-target.texture.height}, {0, 0,
  //                (float)target.texture.width, (float)target.texture.height},
  //                {0, 0}, 0.0f, WHITE);
  //
  // EndDrawing();
}

bool Game::ShouldClose() const { return WindowShouldClose(); }
