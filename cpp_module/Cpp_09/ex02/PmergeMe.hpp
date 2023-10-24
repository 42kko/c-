#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <deque>
#include <time.h>
#include <sys/time.h>
#include <sstream>

class PmergeMe
{
    private:
        PmergeMe();
        unsigned long _size;
        unsigned long _solo;
        bool type;
        typedef std::pair<unsigned long, unsigned long> pair;
        //for vector
        typedef std::vector<pair> vec;
        vec _vec;
        std::vector<unsigned long> _sorted;
        void mergeSort(vec &p, size_t left, size_t right);
        void merge(vec &arr, size_t left, size_t mid, size_t right);
        void soloSort();
        void smallSort();
        void binaryInsertSort();
        size_t findInSorted(unsigned long i_);
        //for deque
        typedef std::deque<pair> deq;
        deq _deq;
        std::deque<unsigned long> _sortedDeq;
        void mergeSortDeq(deq &p, size_t left, size_t right);
        void mergeDeq(deq &arr, size_t left, size_t mid, size_t right);
        void soloSortDeq();
        void smallSortDeq();
        void binaryInsertSortDeq();
        size_t findInSortedDeq(unsigned long i_);
        size_t getIndex(size_t i);
        double _vecT;
        double _deqT;
    public:
        PmergeMe(const int &ac, char **av, int x);
        PmergeMe(const int &ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe &c);
        PmergeMe& operator=(const PmergeMe &c);
        double getTimeV() const;
        double getTimeD() const;
        std::deque<unsigned long> getDeq() const;
        std::vector<unsigned long> getVec() const;
};

#endif