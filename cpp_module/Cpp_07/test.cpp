#include <iostream>
#include <string>

int main()
{
    std::string *array = new std::string[5];
    array[0] = "hi";
    std::cout << array[0] << std::endl;
}