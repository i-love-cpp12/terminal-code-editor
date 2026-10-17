#pragma once

#include "../core/fileContentRepositoryInterface.hpp"
#include <filesystem>
#include <fstream>
#include<optional>

class FileContentRepository : public FileContentRepositoryInterface
{
    public:
        explicit FileContentRepository(const std::filesystem::path& path);
        ~FileContentRepository();
        virtual bool save(const std::vector<std::string>& lines) const override;
        virtual std::optional<std::vector<std::string>> readLines() const override;
        virtual std::string getFileShortName() const override;
    private:
        std::filesystem::path path;

};