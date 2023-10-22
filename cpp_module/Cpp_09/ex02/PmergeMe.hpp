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
        vec _vec;
        pair *_pair;
        unsigned long _solo;
        unsigned long _size;
    public:
        PmergeMe(const int &ac, char **av);
        // ~PmergeMe();
        // PmergeMe(const PmergeMe &c);
        // PmergeMe& operator=(const PmergeMe &c);
        void mergeSort(pair *_p, size_t left, size_t right);
        void merge(pair *_p, size_t left, size_t mid, size_t right);
};

#endif