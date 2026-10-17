#include "contentManager.hpp"
#include "../error/fileError.hpp"
#include <utility>

ContentManager::ContentManager(FileContentRepositoryInterface &fileRepo): fileRepo(fileRepo)
{
    loadData();
}

const std::vector<std::string> &ContentManager::getLines() const
{
    return data;
}

size_t ContentManager::linesCount() const
{
    return data.size();
}

const std::string &ContentManager::getLine(size_t lineIndex) const
{
    return data.at(lineIndex);
}

void ContentManager::setLine(size_t lineIndex, const std::string &lineContent)
{
    data.at(lineIndex) = lineContent;    
}

void ContentManager::addLine(const std::string &content)
{
    data.push_back(content);
}
void ContentManager::addLine(std::string &&content)
{
    data.push_back(std::move(content));
}

void ContentManager::saveData() const
{
    if(!fileRepo.save(data))
        throw FileError(fileRepo.getFileShortName(), FileError::FileErrorType::WRITE_ERROR);
}

void ContentManager::loadData()
{
    auto lines = fileRepo.readLines();
    if(!lines)
        throw FileError(fileRepo.getFileShortName(), FileError::FileErrorType::READ_ERROR);
    data = std::move(*lines);
}
