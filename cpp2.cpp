#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    bool saved;
    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Hello " << name << "." << std::endl;
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (age<12) {
        std::cout << "I'm afraid you're too young for this adventure. Try again later in life." << std::endl;
        std::exit(0);
    };
    std::cout << "Excellent. Lets begin." << std::endl;
    return 0;
}