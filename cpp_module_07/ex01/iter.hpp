#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename L>
void iter(T *address, L length, void (*f)(T&))
{
	for (L i = 0; i<length; i++) {
		f(address[i]);
	}
}

template <typename T, typename L>
void iter(T *address, L length, void (*f)(const T&))
{
	for (L i = 0; i<length; i++) {
		f(address[i]);
	}
}

template <typename T>
void print(T &a)
{
	std::cout << a << std::endl;
}

#endif