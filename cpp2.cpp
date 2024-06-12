// Imports
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

// Namespace Declarations
namespace fs = std::filesystem;

//Declare Using Namespace STD
using namespace std;


struct UserData {
    std::string name;
    int age;
};

// Serialization function to write a string to a binary file
void writeString(std::ofstream& file, const std::string& str) {
    size_t len = str.length();
    file.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
    file.write(str.c_str(), len);
}

// Deserialization function to read a string from a binary file
std::string readString(std::ifstream& file) {
    size_t len;
    file.read(reinterpret_cast<char*>(&len), sizeof(size_t));
    std::string str(len, '\0');
    file.read(&str[0], len);
    return str;
}

void readSave(){
    // Reading data from the binary file
    std::ifstream infile("save.bin", std::ios::binary);
    if (infile.is_open()) {
        UserData readUser;
        readUser.name = readString(infile);
        infile.read(reinterpret_cast<char*>(&readUser.age), sizeof(int));
        std::cout << "Name: " << readUser.name << std::endl;
        std::cout << "Age: " << readUser.age << std::endl;
        infile.close();
    } else {
        std::cerr << "Failed to open file for reading." << std::endl;
        exit(1);
    }
}

int main() {
    bool saved = false;
    UserData user;

    if (fs::exists("save.bin") && fs::is_empty("save.bin") != true){
        
    } else {
    std::cout << "Enter your name: ";
    std::getline(std::cin, user.name);

    std::cout << "Enter your age: ";
    std::cin >> user.age;
    }

    if (user.age < 12) {
        std::cout << "I'm afraid you're too young for this adventure. Try again later in life." << std::endl;
        return 0;
    }

    std::cout << "Excellent. Let's begin." << std::endl;

    // Writing data to a binary file
    std::ofstream outfile("save.bin", std::ios::binary);
    if (outfile.is_open()) {
        writeString(outfile, user.name);
        outfile.write(reinterpret_cast<const char*>(&user.age), sizeof(int));
        std::cout << "User information saved successfully." << std::endl;
        saved = true;
        outfile.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    return 0;
}
