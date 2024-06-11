#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string name;
    int age;
    bool saved;

    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Hello " << name << "." << std::endl;
    std::cout << "Enter your age: ";
    std::cin >> age;

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
    } else {
        std::cout << "Failed to open file for writing." << std::endl;
    }

    return 0;
}