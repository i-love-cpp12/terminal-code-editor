#pragma once
#include<cstdint>

enum class KeyModifier : uint8_t
{
    NONE = 0,
    SHIFT = 1 << 0,
    CTRL = 1 << 1,
    ALT = 1 << 2,
    SUPER = 1 << 3
};

constexpr KeyModifier operator|(KeyModifier m1, KeyModifier m2)
{
    return static_cast<KeyModifier>(static_cast<uint8_t>(m1) | static_cast<uint8_t>(m2));
}

struct Key
{
    char ch;
    KeyModifier modifier;
};