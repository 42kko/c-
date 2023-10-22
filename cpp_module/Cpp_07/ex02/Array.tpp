template <typename T>
Array<T>::Array()
{
    _array = new T[0];
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int a)
{
    _size = a;
    _array = new T[a];
    for (unsigned int i = 0; i < a; i++)
    {
        _array[i] = T();
    }
    if (a == 750)
        _array[0] = 123;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array &c)
{
    _array = NULL;
    *this = c;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &c)
{
    if (this == &c)
        return (*this);
    if (_array != NULL)
        delete[] _array;
    _size = c._size;
    _array = new T[c._size];
    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = c._array[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t n)
{
    if (n > _size - 1)
        throw(std::exception());
    return (_array[n]);
}

template <typename T>
size_t Array<T>::size() const
{
    return (_size);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, Array<T> c)
{
    for (size_t i = 0; i < c.size(); i++)
    {
        os << c[i] << " ";
    }
    return (os);
}