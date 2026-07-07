#pragma once

#include <raylib.h>
#include <vector>
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

constexpr int screen_width = 720;
constexpr int screen_height = 720;

enum class GameScreen { Logo, Title, Gameplay, Ending };
class Gates {
public:
  Gates(float x, float y, float size);
  ~Gates();
  void Draw();
  // public for now
  float posx;
  float posy;
  float size;
  bool hover;
  bool selected;
};
class Game {
public:
  Game();
  ~Game();

  void Update();
  void Draw();
  bool ShouldClose() const;

private:
  RenderTexture2D target{};
  int frame_counter{};
  Vector2 MousePosition;
  GameScreen current_screen{GameScreen::Logo};
  std::vector<Gates> gates;
};
