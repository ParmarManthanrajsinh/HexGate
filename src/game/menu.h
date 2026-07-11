#pragma once

enum class GameState
{
    TITLE_SCREEN,
    HOW_TO_PLAY,
    PLAYING
};

GameState UpdateTitleScreen(float anim_time);
GameState UpdateHowToPlay(float anim_time);
void DrawTitleScreen(float anim_time);
void DrawHowToPlay(float anim_time);
