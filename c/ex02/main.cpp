#include "PmergeMe.hpp"

int main(int argc, char **argv)
	{
	if (argc < 2)
		{
		std::cerr << "Error: No input provided." << std::endl;
		return 1;
		}
	for (int i = 1; i < argc; ++i)
		{
		for (int j = 0; argv[i][j]; j++)
			{
			if (!std::isdigit(argv[i][j]))
				{
				std::cerr << "Error: Invalid input." << std::endl;
				return 1;
				}
			}
		}
	PmergeMe sorter;
	sorter.sort(argc, argv);
	return 0;
	}
