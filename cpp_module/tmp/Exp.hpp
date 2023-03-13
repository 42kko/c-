#ifndef EXP_H
#define EXP_H
#include <iostream>

class Exp
{
	private:
		int one;
		int two;
	public:
		Exp()
		{
			one = 1;
			two = 1;
		}
		Exp(int i, int j)
		{
			one = i;
			two = j;
		}
		Exp(int i)
		{
			one = i;
			two = 1;
		}
		int getValue();
		int getBase();
		int getExp();
		bool equals(Exp b);
};

#endif