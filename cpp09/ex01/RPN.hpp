#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
	private:
		std::stack<int> numbers;
		std::string str;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN(std::string str);

		RPN &operator=(const RPN &copy);

		~RPN();

		void calc();
};

#endif
