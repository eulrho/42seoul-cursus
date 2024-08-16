#ifndef RPN_HPP
# define RPN_HPP

# include <string>
#	include <stack>

class RPN {
	private:
		std::stack<float> stack;
		void add();
		void sub();
		void mult();
		void div();
	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN &operator=(const RPN&);
		void postfix(const std::string&);
};

#endif