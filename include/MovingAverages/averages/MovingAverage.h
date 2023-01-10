
/**
 * @file MovingAverage.h
 * @author Iván Sánchez (ivan.sanchezc@hotmail.com)
 * @brief Base header for different avg filter implementations
 * @version 0.1
 * @date 2023-01-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MOVING_AVERAGE__H__
#define __MOVING_AVERAGE__H__

#include <iostream>

using namespace std;



/**
 * @enum buf_status_t
 * @brief Declares the status of the sample buffer.
 * @var BUFFER_EMPTY: The buffer is empty (value 0x00).
 * @var BUFFER_FULL: The buffer is full (value 0xFF).
 * @var BUFFER_PARTIAL: The buffer is partially full (value 0xF0).
 * 
 */

typedef enum
{
    BUFFER_EMPTY = 0x00,
    BUFFER_FULL = 0xFF,
    BUFFER_PARTIAL = 0xF0
} buf_status_t;


/**
 * @class MovingAverage
 * @brief Moving average filter main class
 * @details This class implements a moving average filter. It is a base class for other filters. 
 */

class MovingAverage
{
    protected:
        uint16_t _bufSize;
        uint16_t _index;
        uint16_t _count;
        uint32_t _sum;
        uint16_t *_values;
    public:
        MovingAverage(uint16_t size);
        ~MovingAverage();
        void push(uint16_t value);
        uint16_t getFilterOutput();
        uint16_t getLastValue();
        buf_status_t getBufferStatus();
        void clear();
};

#endif  //!__MOVING_AVERAGE__H__


