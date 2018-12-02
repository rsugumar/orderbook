#include <fstream>
#include "FileReader.hpp"

std::vector<std::string>
FileReader::getFileContentLines() {
    std::ifstream fileStream(mFileName);
    if (!fileStream.good()) {
        throw "File not accessible";
    }
    std::vector<std::string> lines;
    std::string line;
    while (!std::getline(fileStream, line).fail()) {
        if (!trimUnwantedChars(line).empty()) {
            lines.emplace_back(line);
        }
    }
    fileStream.close();
    return lines;
}

std::string
FileReader::trimUnwantedChars(std::string& line) const {
    // trim spaces and other unwanted chars
    if (line.find_first_of("/") != std::string::npos) {
        line.erase(line.find_first_of("/")); // trim comment char after
    }
    line.erase(0, line.find_first_not_of(" "));       // left trim
    line.erase(line.find_last_not_of(" \n\r\t") + 1); // right trim

    return line;
}
