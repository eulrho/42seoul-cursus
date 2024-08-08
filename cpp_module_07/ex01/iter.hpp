#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename L, typename F, typename W>
void iter(T *address, L length, F (*f)(W))
{
	for (L i = 0; i<length; i++) {
		f(address[i]);
	}
}

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

#endif