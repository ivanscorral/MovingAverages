
#include "GenericMovingAverage.h"

template <class T>
GenericMovingAverage<T>::GenericMovingAverage(uint16_t size)
    : _bufSize(size), _index(0), _count(0)
{
    _values.reserve(size);
}

template <class T>
GenericMovingAverage<T>::~GenericMovingAverage()
{
    _values.clear();
}

template <class T>
void GenericMovingAverage<T>::push(T value)
{   
    if (_count < _bufSize)
    {
        _count++;
    }
    _values.push_back(value);
    if (++_index == _bufSize)
    {
        _index = 0;
    }
}

template <class T>
T GenericMovingAverage<T>::getFilterOutput()
{
        T returnValue = 0;
        if (_count > 0)
        {
            using sum_type = typename conditional<is_floating_point<T>::value, T, int>::type;
            sum_type sum = 0;
            for (auto item: _values)
            {
                sum += item;
            }
            returnValue = sum / _values.size();
        }
        return returnValue;
    }

template <class T>
T GenericMovingAverage<T>::getLastValue()
{
    return _values.at(_index);
}

template <class T>
g_buf_status_t GenericMovingAverage<T>::getBufferStatus()
{
    if (_count == _bufSize || initialized)
    {
        if (!initialized)
            initialized = true;
        return g_buf_status_t::BUFFER_FULL;
    }
    else if (_count == 0)
    {
        return g_buf_status_t::BUFFER_EMPTY;
    }
    else
    {
        return g_buf_status_t::BUFFER_PARTIAL;
    }
}

template <class T>
void GenericMovingAverage<T>::clear()
{
    _index = 0;
    _count = 0;
    _values.clear();
}
