#pragma once
#include<cstdint>

enum class KeyModifier : uint8_t
{
    SHIFT = 1 << 0,
    CTRL = 1 << 1,
    ALT = 1 << 2,
    SUPER = 1 << 3
};

struct Key
{
    char ch;
    KeyModifier modifier;
};