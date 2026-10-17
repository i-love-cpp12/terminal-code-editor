#pragma once

#include"../core/editor.hpp"

class EditorRenderer
{
    public:
        static void render(const Editor* editor);
    private:
        static void clear();
};
