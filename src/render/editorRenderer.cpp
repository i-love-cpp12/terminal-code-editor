#include "editorRenderer.hpp"
#include <iostream>
#include <windows.h>

void EditorRenderer::render(const Editor *editor)
{
    clear();
}

void EditorRenderer::clear()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    if (console == INVALID_HANDLE_VALUE)
        return;

    CONSOLE_SCREEN_BUFFER_INFO info{};

    if (!GetConsoleScreenBufferInfo(console, &info))
        return;

    COORD home{0, 0};
    DWORD written = 0;

    DWORD size = static_cast<DWORD>(info.dwSize.X) *
                 static_cast<DWORD>(info.dwSize.Y);

    FillConsoleOutputCharacterA(console, ' ', size, home, &written);

    FillConsoleOutputAttribute(console, info.wAttributes, size, home, &written);

    SetConsoleCursorPosition(console, home);
}
