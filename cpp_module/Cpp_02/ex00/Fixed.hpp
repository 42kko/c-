#include <iostream>
#include <ostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(const Fixed& c);
		~Fixed();
		Fixed& operator=(const Fixed& c);
		int getRawBits() const;
		void setRawBits(int const raw);
};

