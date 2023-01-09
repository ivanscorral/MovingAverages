#ifndef __GENERIC_MOVING_AVERAGE__H__
#define __GENERIC_MOVING_AVERAGE__H__

#include <cstdint>
#include <vector>

using namespace std;

enum class g_buf_status_t : uint8_t
{
    BUFFER_EMPTY = 0b00,
    BUFFER_PARTIAL = 0b01,
    BUFFER_FULL = 0b11
};

template <typename T>
class GenericMovingAverage
{
private:
    bool initialized = false;
protected:
    uint16_t _bufSize;
    uint16_t _index;
    uint16_t _count;
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

#include "GenericMovingAverage.tpp"

#endif  //!__GENERIC_MOVING_AVERAGE__H__