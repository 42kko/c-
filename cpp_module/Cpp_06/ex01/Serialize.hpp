#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
    int x;
    char c;
    std::string str;
};

class Serialize
{
    private:

    public:
    Serialize();
    ~Serialize();
    Serialize(const Serialize &c);
    Serialize& operator=(const Serialize &c);
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif