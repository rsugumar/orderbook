#ifndef __FILE_READER_HPP__
#define __FILE_READER_HPP__
#pragma once

#include <vector>
#include <string>

class FileReader {
    public:
        FileReader(std::string fName)
            : mFileName{fName} {}
        std::vector<std::string> getFileContentLines();

    private:
        std::string trimUnwantedChars(std::string& line) const;

    private:
        const std::string mFileName;
};

#endif