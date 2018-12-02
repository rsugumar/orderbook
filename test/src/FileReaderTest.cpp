#include <gtest/gtest.h>
#include "FileReader.hpp"

class FileReaderTest : public ::testing::Test {
    public:
        std::vector<std::string> contents;

    protected:
        virtual void SetUp() {
            contents.emplace_back("add 1 B 45.2 100");
            contents.emplace_back("modify 1 50");
            contents.emplace_back("get price B 1");
            contents.emplace_back("add 2 S 51.4 200");
            contents.emplace_back("add 3 B 45.1 100");
            contents.emplace_back("get size S 1");
            contents.emplace_back("add 4 S 51.2 300");
            contents.emplace_back("add 5 S 51.2 200");
            contents.emplace_back("remove 3");
            contents.emplace_back("get price B 1");
            contents.emplace_back("get size B 1");
            contents.emplace_back("get price S 1");
            contents.emplace_back("get size S 1");
        }

        virtual void TearDown() {
        }
};

TEST_F(FileReaderTest, fileContentsVerification) {
    FileReader fileReader("resources/inputFile1.txt");
    std::vector<std::string> allFileLines = fileReader.getFileContentLines();
    ASSERT_EQ(contents, allFileLines);
}

TEST(InvalidFileCheck, check_when_non_existing_file_is_supplied) {
    FileReader fileReader("junx.txt");
    EXPECT_THROW({
        try {
            std::vector<std::string> allFileLines = fileReader.getFileContentLines();
        } catch (const char* msg) {
            EXPECT_STREQ("File not accessible", msg);
            throw;
        }
    }, const char*);
}
