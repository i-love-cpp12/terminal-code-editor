#include "editor.hpp"

Editor::Editor(const std::string &filePath): fileRepo(filePath), contentManager(&fileRepo)
{
}

void Editor::update(Key key)
{
}

const ContentManager &Editor::getContent() const
{
    return contentManager;
}
