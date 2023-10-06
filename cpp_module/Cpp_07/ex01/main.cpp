#include <iostream>

template <typename T, typename Func>
void iter(T* arr, size_t length, Func f)
{
    for (size_t i = 0; i < length; ++i)
    {
        f(arr[i]);
    }
}

void print(int x)
{
    std::cout << x << std::endl;
}

void print(char c)
{
    std::cout << c << std::endl;
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    iter(arr, sizeof(arr) / sizeof(arr[0]), print);
    return 0;
}
