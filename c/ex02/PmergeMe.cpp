#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {}
    return *this;
}

size_t PmergeMe::jacobsthal(int k)
{
	return (pow(2, k + 1) + pow(-1, k)) / 3;
}

void PmergeMe::sort(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: No input provided." << std::endl;
        return;
    }

    std::vector<std::vector<int> > v_input;
    std::deque<std::deque<int> > d_input;

    for (int i = 1; i < argc; ++i)
    {
        char* endptr;
        long val = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || val < 0 || val > INT_MAX)
        {
            std::cerr << "Error: Invalid input '" << argv[i] << "'." << std::endl;
            return;
        }
        
        v_input.push_back(std::vector<int>(1, static_cast<int>(val)));
        d_input.push_back(std::deque<int>(1, static_cast<int>(val)));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v_input.size(); ++i)
        std::cout << v_input[i][0] << " ";
    std::cout << std::endl;

    clock_t v_start = clock();
    std::vector<std::vector<int> > v_result = sort(v_input);
    clock_t v_end = clock();
    double v_time = (v_end - v_start) * 1000.0 / CLOCKS_PER_SEC;

    clock_t d_start = clock();
    std::deque<std::deque<int> > d_result = sort(d_input);
    clock_t d_end = clock();
    double d_time = (d_end - d_start) * 1000.0 / CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (size_t i = 0; i < v_result.size(); ++i)
        std::cout << v_result[i][0] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << v_input.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << v_time << " us" << std::endl;
    std::cout << "Time to process a range of " << d_input.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) << d_time << " us" << std::endl;
}
