#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
    int x;
    char c;
    std::string str;
};

uintptr_t serialize(Data *dptr)
{
    return reinterpret_cast<uintptr_t>(dptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data* dptr = new Data;
    dptr->str = "asdf123";
    dptr->c = 'a';
    dptr->x = 12;

    uintptr_t raw = serialize(dptr);
    Data *ret = deserialize(raw);
    std::cout << ret->str << " | " << ret->c << " | " << ret->x << std::endl;

    delete dptr;
    return 0;
}
