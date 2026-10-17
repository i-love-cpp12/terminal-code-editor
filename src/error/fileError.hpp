#pragma once

#include<string>
#include<stdexcept>
#include<cstdint>

class FileError : public std::runtime_error
{
    public:
        enum class FileErrorType : uint8_t
        {
            READ_ERROR,
            WRITE_ERROR,
            UNKNOWN_ERROR
        };
        explicit FileError(const std::string& fileName, FileErrorType errorType);
    private:
        std::string fileName;
        FileErrorType errorType;
        static std::string errorTypeToString(const std::string& fileName, FileErrorType errorType);
};