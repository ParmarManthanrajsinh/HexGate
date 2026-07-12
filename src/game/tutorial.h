#pragma once
#include <raylib.h>
#include <vector>
#include "gates.h"

struct t_TutorialState
{
    int current_step = 0;
    float step_enter_time = 0.0f;
    int placed_gate_row = -1;
    int placed_gate_col = -1;
};

void DrawTutorialOverlay(const t_TutorialState& ts, float anim_time, const std::vector<t_Gate>& gates);
