#include <iostream>

int main(void)
{
    std::string name;
    std::cout << "Please input your name:";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << "!" << std::endl;
}
