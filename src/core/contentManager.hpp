#pragma once
#include "fileContentRepositoryInterface.hpp"
#include<vector>
#include<string>

class ContentManager
{
    public:
        ContentManager(FileContentRepositoryInterface* fileRepo);
        const std::vector<std::string>& getLines() const;
        size_t linesCount() const;
        const std::string& getLine(size_t lineIndex) const;
        void setLine(size_t lineIndex, const std::string& lineContent);
        void addLine(const std::string& content = "");
        void saveData() const;
    private:
        std::vector<std::string> data;
        FileContentRepositoryInterface* fileRepo;

        void loadData();
};