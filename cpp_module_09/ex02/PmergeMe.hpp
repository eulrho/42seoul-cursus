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
		void insertData(int argc, char **argv);
		template <typename Container>
		void printData(Container &container)
		{
			typename Container::iterator iter = container.begin();

			for (; iter != container.end(); iter++)
				std::cout << iter->number << ' ';
			std::cout << std::endl;
		}

		/**********
		 * vector *
		**********/
		double timeOfVector;
		double sortList();
		struct NumberPairVector {
			int number;
			std::vector<NumberPairVector> pair;
		};
		std::vector<NumberPairVector> vector;
		typedef std::vector<NumberPairVector>::iterator vectorPairIter;
		void recursiveSortVector(std::vector<NumberPairVector> &);
		std::vector<NumberPairVector> topBottomSortVector(std::vector<NumberPairVector> &, std::vector<NumberPairVector> &);
		void insertNewJacobsthalNumberIntoVector(std::vector<int> &, int);
		static bool compareVector(const NumberPairVector &a, const NumberPairVector &b);

		/**********
		 *  list  *
		**********/
		double timeOfList;
		double sortVector();
		struct NumberPairList {
			int number;
			std::list<NumberPairList> pair;
		};
		std::list<NumberPairList> list;
		typedef std::list<NumberPairList>::iterator listPairIter;
		void recursiveSortList(std::list<NumberPairList> &);
		std::list<NumberPairList> topBottomSortList(std::list<NumberPairList> &, std::list<NumberPairList> &);
		listPairIter listBack(std::list<NumberPairList> &);
		void insertNewJacobsthalNumberIntoList(std::list<int> &, int);
		static bool compareList(const NumberPairList &, const NumberPairList &);
		template <typename Container>
		typename Container::iterator getIteratorByIndex(Container &container, int idx)
		{
			typename Container::iterator res = container.begin();

			std::advance(res, idx);
			return res;
		}
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		void fordJohnson(int argc, char **argv);
};

#endif