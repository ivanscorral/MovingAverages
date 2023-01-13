#ifndef __GENERIC_MOVING_AVERAGE__H__
#define __GENERIC_MOVING_AVERAGE__H__

#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

/// @brief Buffer status enum
/// @details Enum to represent the status of the buffer

enum class g_buf_status_t : uint8_t
{
    BUFFER_EMPTY = 0b00,
    BUFFER_PARTIAL = 0b01,
    BUFFER_FULL = 0b11
};

/// @brief Class to calculate a moving average
/// @tparam T: The type of the values to calculate the moving average
template <typename T>
class GenericMovingAverage
{
protected:
    uint16_t _bufSize;
    uint16_t _index;
    vector<T> _values;

public:
    explicit GenericMovingAverage(uint16_t size);
    ~GenericMovingAverage();
    void push(T value);
    T getFilterOutput();
    T getLastValue();
    g_buf_status_t getBufferStatus();
    void clear();
};

// Include the template source file

#include "averages/GenericMovingAverage.tpp"

#endif //!__GENERIC_MOVING_AVERAGE__H__