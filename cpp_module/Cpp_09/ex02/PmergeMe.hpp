#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

class PmergeMe
{
    private:
        typedef std::pair<unsigned long, unsigned long> pair;
        typedef std::vector<std::pair<unsigned long, unsigned long> > vec;
        PmergeMe();
        std::vector<unsigned long> _sorted;
        vec _vec;
        unsigned long _solo;
        unsigned long _size;
        void binaryInsertSort();
        size_t getIndex(size_t i);
        void binary(int idx);
    public:
        PmergeMe(const int &ac, char **av);
        // ~PmergeMe();
        // PmergeMe(const PmergeMe &c);
        // PmergeMe& operator=(const PmergeMe &c);
        void mergeSort(vec &p, size_t left, size_t right);
        void merge(vec &arr, size_t left, size_t mid, size_t right);
};

#endif