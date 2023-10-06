#include "classes.hpp"

Base * generate(void)
{
    std::srand(std::time(0));
    int i = rand() % 3;
    switch (i)
    {
    case 0:
        std::cout << "create A" << std::endl;
        return (new A);
        break;
    case 1:
        std::cout << "create B" << std::endl;
        return (new B);
        break;
    case 2:
        std::cout << "create C" << std::endl;
        return (new C);
        break;
    default:
        break;
    }
    return (0);
}

void identify(Base* p)
{
    A *aPtr = dynamic_cast<A*>(p);
    B *bPtr = dynamic_cast<B*>(p);
    C *cPtr = dynamic_cast<C*>(p);
    if (aPtr)
        std::cout << "A" << std::endl;
    else if (bPtr)
        std::cout << "B" << std::endl;    
    else if (cPtr)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(...)
    {
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(...)
    {
    }    
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(...)
    {
    }
}

int main()
{
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);
}