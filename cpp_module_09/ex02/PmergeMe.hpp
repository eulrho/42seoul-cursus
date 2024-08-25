#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>
# include <stdexcept>
# include <ctime>
# include <algorithm>

class PmergeMe {
	private:
		struct NumberPair {
			int number;
			std::vector<NumberPair> pair;
		};
		std::vector<int> vector;
		std::list<int> list;
		double timeOfVector;
		double timeOfList;
		void insertData(int argc, char **argv);
		double sortVector();
		double sortList();
		typedef std::vector<NumberPair>::iterator vectorPairIter;
		typedef std::list<int>::iterator listIter;
		void recursiveSortVector(std::vector<NumberPair> &);
		std::vector<NumberPair> topBottomSortVector(std::vector<NumberPair> &, std::vector<NumberPair> &);
		std::vector<int> extractVector(std::vector<NumberPair>&);
		void insertNewJacobsthalNumber(std::vector<int> &, int);
		static bool compare(const NumberPair&, const NumberPair&);
		template <typename Container>
		void printData(Container &container)
		{
			typename Container::iterator iter = container.begin();

			for (; iter != container.end(); iter++)
				std::cout << *iter << ' ';
			std::cout << std::endl;
		}
		template <typename ContainerIter, typename ValueType, typename Compare>
		ContainerIter searchPosition(ContainerIter left, ContainerIter right, const ValueType &target, Compare comp)
		{
			return std::upper_bound(left, right, target, comp);
		}
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		void fordJohnson(int argc, char **argv);
};

#endif