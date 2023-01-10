
#include "GenericMovingAverage.h"

/// @brief Construct a new Generic Moving Average object With a given size
/// @tparam T: The type of the values to be stored
/// @param uint16_t size> The size of the buffer

template <class T>
GenericMovingAverage<T>::GenericMovingAverage(uint16_t size)
    : _bufSize(size), _index(0), _count(0)
{
    _values.reserve(size);
}


/// @brief  Destroy the Generic Moving Average object
/// @tparam T The type of the values to be stored

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

/// @brief Calculate the moving average
/// @tparam T: The type of the values to be stored
/// @return T: The moving average   

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

/// @brief Get the last value added to the buffer
/// @tparam T: The type of the values to be stored
/// @return T: The last value added to the buffer

template <class T>
T GenericMovingAverage<T>::getLastValue()
{
    return _values.at(_index);
}

/// @brief  Get the buffer status
/// @tparam T: The type of the values to be stored
/// @return g_buf_status_t: The status of the buffer

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

/// @brief Clear the buffer
/// @tparam T: The type of the values to be stored
/// @details Clear the buffer and reset the index and count.

template <class T>
void GenericMovingAverage<T>::clear()
{
    _index = 0;
    _count = 0;
    _values.clear();
}
