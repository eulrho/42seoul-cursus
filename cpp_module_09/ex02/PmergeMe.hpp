#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>
# include <stdexcept>
# include <ctime>

class PmergeMe {
	private:
		std::vector<int> sortedVector;
		std::list<int> sortedList;
		double timeOfVector;
		double timeOfList;
		void insertData(int argc, char **argv);
		void printData();
		double sortVector();
		double sortList();
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		void fordJohnson(int argc, char **argv);
};

#endif