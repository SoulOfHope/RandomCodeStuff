// Imports
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

// Namespace Declarations
namespace fs = std::filesystem;

//Declare Using Namespace STD
using namespace std;

std::vector<std::byte> readFileData(const std::string& name) {
    std::filesystem::path inputFilePath{name};
    auto length = std::filesystem::file_size(inputFilePath);
    if (length == 0) {
        return {};  // empty vector
    }
    std::vector<std::byte> buffer(length);
    std::ifstream inputFile(name, std::ios_base::binary);
    inputFile.read(reinterpret_cast<char*>(buffer.data()), length);
    inputFile.close();
    return buffer;
}

int main() {
    std::string name;
    int age = 0;
    bool saved;

    if (fs::exists("save.bin") && fs::is_empty("save.bin")!=true) {
        std::vector data = readFileData("save.bin");
    }
    else {
        std::cout << "What is your name? ";
        std::cin >> name;
        std::cout << "Hello " << name << "." << std::endl;
        std::cout << "Enter your age: ";
        std::cin >> age;
    }

    if (age < 12) {
        std::cout << "I'm afraid you're too young for this adventure. Try again later in life." << std::endl;
        return 0;
    }

    std::cout << "Excellent. Let's begin." << std::endl;

    // Open the binary file for writing
    std::ofstream outfile("save.bin", std::ios::binary);
    if (outfile.is_open()) {
        // Write the user's information to the file
        outfile.write(reinterpret_cast<const char*>(&name[0]), name.size());
        outfile.write(reinterpret_cast<const char*>(&age), sizeof(age));
        outfile.close();
        std::cout << "User information saved successfully." << std::endl;
        saved = true;
    } else {
        std::cout << "Failed to open file for writing." << std::endl;
    }

    return 0;
}