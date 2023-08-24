
#include "averages/GenericMovingAverage.h"

template <class T>
GenericMovingAverage<T>::~GenericMovingAverage()
{
    _values.clear();
}

/// @brief Push a value to the buffer
/// @tparam T: The type of the values to be stored
/// @param T value: The value to be pushed

template <class T>
void GenericMovingAverage<T>::push(T value)
{
    if (_values.size() < _bufSize)
    {
        _values.push_back(value);
    }
    else
    {
        _values[_index] = value;
        _index = (_index + 1) % _bufSize;
    }
}

/// @brief Calculate the moving average
/// @tparam T: The type of the values to be stored
/// @return T: The moving average

template <class T>
T GenericMovingAverage<T>::getFilterOutput()
{
    T returnValue = 0;
    if (_values.size() > 0)
    {
        using sum_t = typename conditional<is_integral<T>::value, int, T>::type;
        sum_t _sum = 0;
        for (uint16_t i = 0; i < _index; i++) // Iterate up to _index
        {
            _sum += _values[i];
        }
        returnValue = _sum / (_index > 0 ? _index : 1); // Divide by _index if greater than 0, else divide by 1
    }
    return returnValue;
}


/// @brief Get the last value added to the buffer
/// @tparam T: The type of the values to be stored
/// @return T: The last value added to the buffer

template <class T>
T GenericMovingAverage<T>::getLastValue()
{
    if(_values.size() > 0)
    {
        return _values.at(_index);
    }
    return 0;
}

/// @brief  Get the buffer status
/// @tparam T: The type of the values to be stored
/// @return g_buf_status_t: The status of the buffer

template <class T>
g_buf_status_t GenericMovingAverage<T>::getBufferStatus()
{
    g_buf_status_t returnValue;
    if(_values.size() == _bufSize)
    {
        returnValue = g_buf_status_t::BUFFER_FULL;
    }
    else if(_values.empty())
    {
        returnValue = g_buf_status_t::BUFFER_EMPTY;
    }
    else
    {
        returnValue = g_buf_status_t::BUFFER_PARTIAL;
    }
    return returnValue;
}

/// @brief Clear the buffer
/// @tparam T: The type of the values to be stored
/// @details Clear the buffer and reset the index and count.

template <class T>
void GenericMovingAverage<T>::clear()
{
    _index = 0;
    _values.clear();
}
