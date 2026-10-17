#include "contentManager.hpp"
#include "../error/fileError.hpp"

ContentManager::ContentManager(FileContentRepositoryInterface *fileRepo): fileRepo(fileRepo)
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
    return data[lineIndex];
}

void ContentManager::setLine(size_t lineIndex, const std::string &lineContent)
{
    data[lineIndex] = lineContent;    
}

void ContentManager::addLine(const std::string &content)
{
    data.push_back(content);
}

void ContentManager::saveData() const
{
    fileRepo->save(data);
}

void ContentManager::loadData()
{
    const auto& lines = fileRepo->readLines();
    if(!lines.has_value())
        throw FileError(fileRepo->getFileShortName(), FileError::FileErrorType::READ_ERROR);
    data = lines.value();
}
