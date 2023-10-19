#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << " top" << std::endl;
    mstack.pop();
    std::cout << mstack.size() << " size" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << mstack.size()  << " size" << std::endl;
    ++it;
    --it;
    std::cout << "==========" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return 0;
}
