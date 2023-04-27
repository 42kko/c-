#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &c);
		Brain& operator=(const Brain &c);
		virtual ~Brain();
};

#endif