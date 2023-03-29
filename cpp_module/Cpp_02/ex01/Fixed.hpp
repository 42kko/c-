#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(int i);
		Fixed(float i);
		Fixed(const Fixed& c);
		~Fixed();
		Fixed& operator=(const Fixed& c);
		std::ostream& operator<<(const Fixed& c);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

