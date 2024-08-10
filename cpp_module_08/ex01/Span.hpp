#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		unsigned int n;
		std::vector<int> v;
	public:
		Span();
		~Span();
		Span(unsigned int);
		Span(const Span&);
		Span &operator=(const Span&);
		void addNumber(const int &);
		void addNumberRange(const unsigned int &);
		unsigned long shortestSpan();
		unsigned long longestSpan();
		class ExtraSpaceException : public std::exception {
			public:
				const char* what() const throw();
		};
		class TooFewException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif