#pragma once
#include<string>
#include<vector>
#include<optional>

class FileContentRepositoryInterface
{
    public:
        virtual ~FileContentRepositoryInterface() = default;
        virtual bool save(const std::vector<std::string>& lines) const = 0;
        virtual std::optional<std::vector<std::string>> readLines() const = 0;
        virtual std::string getFileShortName() const = 0;
};