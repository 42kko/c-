#include "inter.hpp"

int main()
{
    // int arr1[7] = {1, 2, 3, 4, 5, 6, 7};
    // iter(arr1, sizeof(arr1) / sizeof(arr1[0]), print<int>);

    // char arr2[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    // iter(arr2, sizeof(arr2) / sizeof(arr2[0]), print<char>);

    // float arr3[7] = {1.2, 2.5, 3.1, 4.8, 5.6, 6.0, 7.3};
    // iter(arr3, sizeof(arr3) / sizeof(arr3[0]), print<float>);

    std::string arr4[3] = {"hello", "world", "cpp07"};
    iter(arr4, sizeof(arr4) / sizeof(arr4[0]), print<std::string>);

    return 0;
}
