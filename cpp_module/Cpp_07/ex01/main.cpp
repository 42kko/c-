#include "inter.hpp"

int main()
{
    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    // iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);

    // char arr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    // iter(arr, sizeof(arr) / sizeof(arr[0]), print<char>);

    // float arr[7] = {1.2, 2.5, 3.1, 4.8, 5.6, 6.0, 7.3};
    // iter(arr, sizeof(arr) / sizeof(arr[0]), print<float>);

    std::string arr[3] = {"hello", "world", "cpp07"};
    iter(arr, sizeof(arr) / sizeof(arr[0]), print<std::string>);

    return 0;
}
