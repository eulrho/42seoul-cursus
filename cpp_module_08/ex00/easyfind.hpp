#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &a, int b) {
	typename T::iterator iter = std::find(a.begin(), a.end(), b);

	if (iter == a.end())
		throw std::invalid_argument(std::string("not found"));
	return iter;
}

#endif