#pragma once

# include <list>
# include <vector>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>

typedef std::vector<int>::iterator	(*t_exe)(std::vector<int>::iterator, std::vector<int>::iterator, int);

class PmergeMe {

	private:
		static const int	jacobsthal[100];

		PmergeMe();
		PmergeMe(PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(PmergeMe& copy);

		static void	jacobsthalInsert(std::list<int>&, std::list<int>&);
		static void	binaryJacobsthalInsert(std::vector<int>&, std::vector<int>&);
		static std::list<int>::iterator	listIndex(std::list<int>& base, int index);
		static std::list<int>::iterator	listElement(std::list<int>& base, int index);

	public:
		static void	listFordJohnson(std::list<int>& list);
		static void	vectorFordJohnson(std::vector<int>& list);
} ;

