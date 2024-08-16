#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>

class PmergeMe {
	private:

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
};

#endif