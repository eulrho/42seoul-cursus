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
		struct NumberPairVector {
			int number;
			std::vector<NumberPairVector> pair;
		};
		struct NumberPairList {
			int number;
			std::list<NumberPairList> pair;
		};
		std::vector<NumberPairVector> vector;
		std::list<NumberPairList> list;
		double timeOfVector;
		double timeOfList;
		void insertData(int argc, char **argv);
		double sortVector();
		double sortList();
		typedef std::vector<NumberPairVector>::iterator vectorPairIter;
		typedef std::list<int>::iterator listIter;
		void recursiveSortVector(std::vector<NumberPairVector> &);
		std::vector<NumberPairVector> topBottomSortVector(std::vector<NumberPairVector> &, std::vector<NumberPairVector> &);
		void insertNewJacobsthalNumber(std::vector<int> &, int);
		static bool compare(const NumberPairVector&, const NumberPairVector&);
		vectorPairIter findVector(vectorPairIter, vectorPairIter, const NumberPairVector&);
		template <typename Container>
		void printData(Container &container)
		{
			typename Container::iterator iter = container.begin();

			for (; iter != container.end(); iter++)
				std::cout << iter->number << ' ';
			std::cout << std::endl;
		}
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		void fordJohnson(int argc, char **argv);
};

#endif