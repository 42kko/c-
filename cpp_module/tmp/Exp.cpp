#include "Exp.hpp"

int Exp::getValue()
{
	return (pow(this->one, this->two));
}

int Exp::getBase()
{
	return (this->one);
}

int Exp::getExp()
{
	return (this->two);
}

bool Exp::equals(Exp b)
{
	if (this->getValue() == b.getValue())
		return (true);
	else
		return (false);
}

int main()
{
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	std::cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << std::endl;
	std::cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << std::endl;

	if (a.equals(b))
		std::cout << "SAME" << std::endl;
	else
		std::cout << "not same" << std::endl;
}