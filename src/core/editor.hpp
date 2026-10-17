#pragma once
#include "contentManager.hpp"
#include "../file/fileContentRepository.hpp"
#include "key.hpp"

class Editor
{
    public:
        explicit Editor(const std::string& filePath);
        void update(Key key);
        const ContentManager& getContent() const;
    private:
        FileContentRepository fileRepo;
        ContentManager contentManager;

};