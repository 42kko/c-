#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &c)
{
    *this = c;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &c)
{
    if (this == &c)
        return *this;
    type = c.type;
    _size = c._size;
    _solo = c._solo;
    _vec = c._vec;
    _sorted = c._sorted;
    _deq = c._deq;
    _sortedDeq = c._sortedDeq;
    _vecT = c._vecT;
    _deqT = c._deqT;
    return *this;
}

PmergeMe::~PmergeMe()
{

}

double getTime(struct timeval &begin, struct timeval &end)
{
    double x, y, diff;
    x = static_cast<double>(begin.tv_sec * 1000000 + begin.tv_usec);
    y = static_cast<double>(end.tv_sec * 1000000 + end.tv_usec);
    diff = y - x;
    return diff;
}

PmergeMe::PmergeMe(const int &ac, char **av) : _size(ac - 1), _solo(0), type(true)
{
    unsigned long *_p;
    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    if (_size % 2 == 0)
        _p = new unsigned long[_size];
    else
    {
        _p = new unsigned long[_size - 1];
        _size--;
    }
    char *endP;
    long j = 0;
    for (unsigned long i = 0; i < _size; i++)
    {
        endP = 0;
        j = strtol(av[i + 1], &endP, 10);
        if (*endP != 0 || j < 0)
            throw std::string("ERR1");
       _p[i] = static_cast<unsigned long>(j);
    }
    if (_size < static_cast<unsigned long>(ac - 1))
    {
        endP = 0;
        j = strtol(av[ac - 1], &endP, 10);
        if (*endP != 0 || j < 0)
            throw std::string("ERR1");
        _solo = static_cast<unsigned long>(j);
    }
    //주사슬, 부사슬 생성한다.
    for (size_t i = 1; i < _size; i = i + 2) 
        _p[i - 1] > _p[i] ? _vec.push_back(pair(_p[i - 1], _p[i])) : _vec.push_back(pair(_p[i], _p[i - 1]));

    //주사슬의 mergeSort로 정렬한다.
    mergeSort(_vec, 0, _vec.size() - 1); 

    //주사슬을 미리 준비된 컨테이너에 담아준다.
    for (size_t i = 0; i < _vec.size(); i++)
        _sorted.push_back(_vec[i].first);

    //이진삽입을 통해 부사슬의 숫자들을 정렬이된 컨테이너에 담아준다.
    binaryInsertSort();

    //홀수의 숫자라 남는숫자가 있다면 이진삽입을 따로해준다.
    if (_solo)
        soloSort();
    // for (std::vector<unsigned long>::iterator iter = _sorted.begin(); iter != _sorted.end(); iter++)
    //     std::cout << *iter << std::endl;
    gettimeofday(&end, NULL);
    _vecT = getTime(begin, end);
    delete [] _p;
}

size_t PmergeMe::getIndex(size_t i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return getIndex(i - 1) + 2 * getIndex(i - 2);
}

size_t PmergeMe::findInSorted(unsigned long i)
{
    size_t ret = 0;
    for (std::vector<unsigned long>::iterator iter = _sorted.begin(); iter != _sorted.end(); iter++)
    {
        if (i == *iter)
            break;
        ret++;
    }
    return ret;
}

void PmergeMe::soloSort()
{
    size_t left = 0;
    size_t right = _sorted.size() - 1;
    unsigned long key = _solo;
    if (key > _sorted.back()) 
    {
        _sorted.push_back(key);
        return ;
    }
    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (_sorted[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
    _sorted.insert(_sorted.begin() + left, key);
}

void PmergeMe::smallSort()
{
    for (size_t i = 0; i < _vec.size(); i++)
    {
        size_t left = 0;
        size_t right = _sorted.size() - 1;
        unsigned long key = _vec[i].second;
        while (left < right)
        {
            size_t mid = (left + right) / 2;
            if (_sorted[mid] > key)
                right = mid;
            else
                left = mid + 1;
        }
        _sorted.insert(_sorted.begin() + left, key);
    }
}

void PmergeMe::binaryInsertSort()
{
    if (_vec.size() < 3)
    {
        smallSort();
        return;
    }
    for (size_t i = 3; i <= _vec.size(); i ++)
    {
        size_t j = getIndex(i);
        size_t minIdx = 0;
        i == 3 ? minIdx = 1 : minIdx = getIndex(i - 1) + 1;
        size_t maxIdx = 0;
        j < _vec.size() ? maxIdx = j : maxIdx = _vec.size();
        for (; maxIdx >= minIdx; maxIdx--)
        {
            size_t left = 0;
            size_t right = findInSorted(_vec[maxIdx - 1].first);
            unsigned long key = _vec[maxIdx - 1].second;
            while (left < right)
            {
                size_t mid = (left + right) / 2;
                if (_sorted[mid] > key)
                    right = mid;
                else
                    left = mid + 1;
            }
            _sorted.insert(_sorted.begin() + left, key);
        }
        if (j >= _vec.size())
            break;
    }
}

void PmergeMe::merge(vec &arr, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    vec L(n1);
    vec R(n2);
    for (size_t i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (size_t i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    size_t i = 0, j = 0, k = left;
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

void PmergeMe::mergeSort(vec &p, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = (left + right) / 2;
        mergeSort(p, left, mid);
        mergeSort(p, mid + 1, right);
        merge(p, left, mid, right);
    }
}

/*
for deque
*/
PmergeMe::PmergeMe(const int &ac, char **av, int x) : _size(ac - 1), _solo(0), type(false)
{
    (void) x;
    unsigned long *_p;
    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    if (_size % 2 == 0)
        _p = new unsigned long[_size];
    else
    {
        _p = new unsigned long[_size - 1];
        _size--;
    }
    char *endP;
    long j = 0;
    for (unsigned long i = 0; i < _size; i++)
    {
        endP = 0;
        j = strtol(av[i + 1], &endP, 10);
        if (*endP != 0 || j < 0)
            throw std::string("ERR1");
       _p[i] = static_cast<unsigned long>(j);
    }
    if (_size < static_cast<unsigned long>(ac - 1))
    {
        endP = 0;
        j = strtol(av[ac - 1], &endP, 10);
        if (*endP != 0 || j < 0)
            throw std::string("ERR1");
        _solo = static_cast<unsigned long>(j);
    }
    for (size_t i = 1; i < _size; i = i + 2) 
        _p[i - 1] > _p[i] ? _deq.push_back(pair(_p[i - 1], _p[i])) : _deq.push_back(pair(_p[i], _p[i - 1]));
    mergeSortDeq(_deq, 0, _deq.size() - 1); 
    for (size_t i = 0; i < _deq.size(); i++)
        _sortedDeq.push_back(_deq[i].first);
    binaryInsertSortDeq();
    if (_solo)
        soloSortDeq();
    gettimeofday(&end, NULL);
    _deqT = getTime(begin, end);
    delete [] _p;
}

void PmergeMe::smallSortDeq()
{
    for (size_t i = 0; i < _vec.size(); i++)
    {
        size_t left = 0;
        size_t right = _sortedDeq.size() - 1;
        unsigned long key = _vec[i].second;
        while (left < right)
        {
            size_t mid = (left + right) / 2;
            if (_sortedDeq[mid] > key)
                right = mid;
            else
                left = mid + 1;
        }
        _sortedDeq.insert(_sortedDeq.begin() + left, key);
    }
}

void PmergeMe::soloSortDeq()
{
    size_t left = 0;
    size_t right = _sortedDeq.size() - 1;
    unsigned long key = _solo;
    if (key > _sortedDeq.back()) 
    {
        _sortedDeq.push_back(key);
        return ;
    }
    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (_sortedDeq[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
    _sortedDeq.insert(_sortedDeq.begin() + left, key);
}

size_t PmergeMe::findInSortedDeq(unsigned long i)
{
    size_t ret = 0;
    for (std::deque<unsigned long>::iterator iter = _sortedDeq.begin(); iter != _sortedDeq.end(); iter++)
    {
        if (i == *iter)
            break;
        ret++;
    }
    return ret;
}

void PmergeMe::binaryInsertSortDeq()
{
    if (_vec.size() < 3)
    {
        smallSortDeq();
        return;
    }
    for (size_t i = 3; i <= _vec.size(); i ++)
    {
        size_t j = getIndex(i);
        size_t minIdx = 0;
        i == 3 ? minIdx = 1 : minIdx = getIndex(i - 1) + 1;
        size_t maxIdx = 0;
        j < _vec.size() ? maxIdx = j : maxIdx = _vec.size();
        for (; maxIdx >= minIdx; maxIdx--)
        {
            size_t left = 0;
            size_t right = findInSortedDeq(_vec[maxIdx - 1].first);
            unsigned long key = _vec[maxIdx - 1].second;
            while (left < right)
            {
                size_t mid = (left + right) / 2;
                if (_sortedDeq[mid] > key)
                    right = mid;
                else
                    left = mid + 1;
            }
            _sortedDeq.insert(_sortedDeq.begin() + left, key);
        }
        if (j >= _vec.size())
            break;
    }
}

void PmergeMe::mergeDeq(deq &arr, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    deq L(n1);
    deq R(n2);
    for (size_t i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (size_t i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    size_t i = 0, j = 0, k = left;
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

void PmergeMe::mergeSortDeq(deq &p, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = (left + right) / 2;
        mergeSortDeq(p, left, mid);
        mergeSortDeq(p, mid + 1, right);
        mergeDeq(p, left, mid, right);
    }
}


double PmergeMe::getTimeV() const
{
    if (type)
        return _vecT;
    return 0;
}

double PmergeMe::getTimeD() const
{
    if (!type)
        return _deqT;
    return 0;
}

std::deque<unsigned long> PmergeMe::getDeq() const
{
    if (!type)
        return _sortedDeq;
    throw(std::string("err"));
}

std::vector<unsigned long> PmergeMe::getVec() const
{
    if (type)
        return _sorted;
    throw(std::string("err"));
}

