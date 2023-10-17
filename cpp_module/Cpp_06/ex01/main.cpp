#include "Serialize.hpp"

int main()
{
    Data* dptr = new Data;
    dptr->str = "asdf123";
    dptr->c = 'a';
    dptr->x = 12;

    uintptr_t raw = Serialize::serialize(dptr);
    Data *ret = Serialize::deserialize(raw);
    if (dptr == ret)
        std::cout << "data pointer same" << std::endl;
    std::cout << ret->str << " | " << ret->c << " | " << ret->x << std::endl;

    delete dptr;
    return 0;
}
