#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int fixedPointNumber;
		static const int fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		Fixed &operator=(const Fixed &);
		bool operator>(const Fixed &);
		bool operator<(const Fixed &);
		bool operator>=(const Fixed &);
		bool operator<=(const Fixed &);
		bool operator==(const Fixed &);
		bool operator!=(const Fixed &);
		Fixed operator+(const Fixed &);
		Fixed operator-(const Fixed &);
		Fixed operator*(const Fixed &);
		Fixed operator/(const Fixed &);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &min(Fixed &, Fixed &);
		static Fixed &max(Fixed &, Fixed &);
};

std::ostream &operator<<(std::ostream&, const Fixed&);

#endif
