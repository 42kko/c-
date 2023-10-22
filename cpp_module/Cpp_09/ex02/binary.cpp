#include <iostream>
#include <vector>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<unsigned long> _sorted;
    std::vector<unsigned long> _vec;
    unsigned long _solo;
    unsigned long _size;
    void binaryInsertSort();
    void binary(int idx);
    void printSortedArray();
    size_t getIndex(int i)
public:
    PmergeMe(const int &ac, char **av);
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
};

PmergeMe::PmergeMe(const int &ac, char **av) : _size(ac - 1)
{
    _vec.reserve(_size);

    for (int i = 0; i < _size; ++i)
    {
        char *endP;
        unsigned long j = static_cast<unsigned long>(strtoul(av[i + 1], &endP, 10));
        if (*endP != 0)
        {
            std::cerr << "Error: Invalid input" << std::endl;
            exit(1);
        }
        _vec.push_back(j);
    }

    if (ac > _size + 1)
    {
        char *endP;
        _solo = static_cast<unsigned long>(strtoul(av[_size + 1], &endP, 10));
        if (*endP != 0)
        {
            std::cerr << "Error: Invalid input" << std::endl;
            exit(1);
        }
    }

    binaryInsertSort();
    mergeSort(0, _sorted.size() - 1);
    printSortedArray();
}

void PmergeMe::binary(int idx)
{
    if (idx < 2)
        return;

    int x = 0;
    int maxIdx = _sorted.size() - 1;
    int minIdx = 0;

    if (_solo)
    {
        x = 1;
        _vec.push_back(_solo);
    }

    minIdx = maxIdx - _vec.size() + 1 + x;

    for (int i = 0; i < maxIdx - minIdx + 1 + x; i++)
    {
        unsigned long key = _sorted[maxIdx - i];

        int left = 0;
        int right = maxIdx - x;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (_vec[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (right < 0)
            _vec.insert(_vec.begin(), key);
        else
            right < left ? _vec.insert(_vec.begin() + left, key) : _vec.insert(_vec.begin() + right, key);
    }

    binary(idx - 1);
}

void PmergeMe::binaryInsertSort()
{
    if (_vec.size() <= 2)
    {
        _sorted = _vec;
        return;
    }

    int max = 0;
    int size = _vec.size();

    if (_solo)
    {
        size += 1;
        _sorted.reserve(size);
    }
    else
    {
        _sorted.reserve(size);
    }

    for (int i = 0; i < size; i++)
    {
        if (size <= getIndex(i))
        {
            max = i;
            break;
        }
    }

    binary(max);
}

size_t PmergeMe::getIndex(int i)
{
    if (i == 0)
        return 1;
    if (i == 1)
        return 1;

    return (getIndex(i - 1) + 2 * (getIndex(i - 2)));
}

void PmergeMe::printSortedArray()
{
    std::cout << "정렬된 배열: ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<unsigned long> L(n1);
    std::vector<unsigned long> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = _vec[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = _vec[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            _vec[k] = L[i];
            i++;
        }
        else
        {
            _vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        _vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        _vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
        return 1;
    }

    PmergeMe pMergeMe(argc, argv);

    return 0;
}
