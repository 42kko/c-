#include "Serialize.hpp"

Serialize::Serialize()
{

}

Serialize::~Serialize()
{

}

Serialize::Serialize(const Serialize &c)
{
    *this = c;
}

Serialize& Serialize::operator=(const Serialize &c)
{
    if (this == &c)
        return (*this);
    return(*this);
}

uintptr_t Serialize::serialize(Data *dptr)
{
    return reinterpret_cast<uintptr_t>(dptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
