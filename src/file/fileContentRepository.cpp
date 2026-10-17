#include "fileContentRepository.hpp"

FileContentRepository::FileContentRepository(const std::filesystem::path &path): path(path)
{
}

FileContentRepository::~FileContentRepository()
{
    
}

bool FileContentRepository::save(const std::vector<std::string> &lines) const
{
    std::ofstream file(path, std::ios::trunc);

    if(!file)
        return false;
    
    for(const auto& line : lines)
        file << line << '\n';

    return file.good();
}

std::optional<std::vector<std::string>> FileContentRepository::readLines() const
{
    std::ifstream file(path, std::ios::in);

    if(!file)
        return std::nullopt;

    std::vector<std::string> lines;
    std::string currentLine;

    while(std::getline(file, currentLine))
        lines.push_back(std::move(currentLine));

    if(file.bad())
        return std::nullopt;

    return lines;
}

std::string FileContentRepository::getFileShortName() const
{
    return path.filename().string();
}
