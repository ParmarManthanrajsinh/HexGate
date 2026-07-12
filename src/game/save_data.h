#pragma once

#include <cstdint>

struct t_SaveData
{
    uint32_t magic = 0x48475854;
    uint32_t version = 1;
    bool tutorial_complete = false;
};

t_SaveData LoadSaveData();
void SaveSaveData(const t_SaveData& data);
