#include "fileError.hpp"

FileError::FileError(const std::string& fileName, FileErrorType errorType):
    fileName(fileName),
    errorType(errorType),
    std::runtime_error(FileError::errorTypeToString(fileName, errorType))
{
    
}

std::string FileError::errorTypeToString(const std::string& fileName, FileErrorType errorType)
{
    switch (errorType)
    {
        case FileErrorType::READ_ERROR:
            return "Failed to read to the " + fileName + " file.";    
        case FileErrorType::WRITE_ERROR:
            return "Failed to write to the " + fileName + " file.";
    };
    return "Unknown file error";
}
