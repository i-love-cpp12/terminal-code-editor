#pragma once
#include <vector>
#include "../core/key.hpp"
class Input
{
    public:
        virtual ~Input() = default;
        virtual std::vector<Key> getCurrentKeys() const = 0;
};