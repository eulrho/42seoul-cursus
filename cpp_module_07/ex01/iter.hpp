#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *address, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i<length; i++) {
		f(address[i]);
	}
}

template <typename T>
void add(T &a)
{
	a++;
}

#endif