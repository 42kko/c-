#include "PmergeMe.hpp"

std::string ft_trim(std::string c)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::string ret;
    size_t start = c.find_first_not_of(WHITESPACE);
    start == std::string::npos ? "" : ret = c.substr(start);
    size_t end = ret.find_last_not_of(WHITESPACE);
    end == std::string::npos ? "" : ret = ret.substr(0, end + 1);
    return ret;
}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const int &ac, char **av) : _size(ac - 1)
{
    unsigned long *_p;
    if (_size % 2 == 0)
        _p = new unsigned long[_size];
    else
        _p = new unsigned long[_size - 1];
    char *endP;
    unsigned long j = 0;
    for (unsigned long i = 0; i < _size; i++)
    {
        endP = 0;
        j = static_cast<unsigned long>(strtol(av[i + 1], &endP, 10));
        if (*endP != 0)
            throw std::string("ERR1");
       _p[i] = j;
    }
    if (_size < static_cast<unsigned long>(ac - 1))
    {
        endP = 0;
        _solo = strtol(av[ac], &endP, 10);
        if (*endP != 0)
            throw std::string("ERR1");
    }
    _pair = new pair[_size / 2];
    for (size_t i = 1; i < _size; i = i + 2)
    {
        _p[i - 1] > _p[i] ? _pair[i / 2] = pair(_p[i - 1], _p[i]) : _pair[i / 2] = pair(_p[i], _p[i - 1]);
    }
    mergeSort(_pair, 0, _size / 2 - 1);
    delete [] _pair;
    delete [] _p;
}

void PmergeMe::merge(pair *arr, size_t left, size_t mid, size_t right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    pair L[n1];
    pair R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(pair *p, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = (left + right) / 2;
        mergeSort(p, left, mid);
        mergeSort(p, mid + 1, right);
        merge(p, left, mid, right);
    }
}

