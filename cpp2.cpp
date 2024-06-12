// Imports
#include <cstdlib>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

// Namespace Declarations
namespace fs = std::filesystem;

// Declare Using Namespace STD
using namespace std;


class UserData {
public:
    std::string name;
    int age;
};

void write_string(std::ofstream& file, const std::string& string) {
    uint64_t length = string.length();
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(string.c_str(), length);
}

std::string read_string(std::ifstream& file) {
    uint64_t length;
    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    std::string str(length, '\0');
    file.read(&str[0], length);
    return str;
}

void write_save(UserData& user) {
    try {
        std::ofstream outfile("save.bin", std::ios::binary);
        if (outfile) {
            write_string(outfile, user.name);
            outfile.write(reinterpret_cast<const char*>(&user.age), sizeof(user.age));
            std::cout << "User information saved successfully." << std::endl;
        } else {
            std::cerr << "Failed to open file for writing." << std::endl;
            std::exit(1);
        }
    } catch (const std::exception& e) {
        std::cerr << "Failed to save user information: " << e.what() << std::endl;
        std::exit(1);
    }
}

void read_save(UserData& user) {
    try {
        std::ifstream infile("save.bin", std::ios::binary);
        if (infile) {
            user.name = read_string(infile);
            infile.read(reinterpret_cast<char*>(&user.age), sizeof(user.age));
            std::cout << "Name: " << user.name << std::endl;
            std::cout << "Age: " << user.age << std::endl;
        } else {
            std::cerr << "Failed to open file for reading." << std::endl;
            std::exit(1);
        }
    } catch (const std::exception& e) {
        std::cerr << "Failed to read save file: " << e.what() << std::endl;
        std::exit(1);
    }
}

int main() {
    bool saved = false;
    UserData user;

    if (std::ifstream("save.bin", std::ios::binary).good() && fs::file_size("save.bin") > 0) {
        read_save(user);
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

    write_save(user);
    saved = true;

    return 0;
}

