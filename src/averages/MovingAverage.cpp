/**
 * @file MovingAverage.cpp
 * @author Iván Sánchez (ivan.sanchezc@hotmail.com)
 * @brief Base class for different moving avg filter implementations
 * @version 0.1
 * @date 2023-01-07 01:50:32 AM
 * 
 * @copyright Copyright (c) 2023
 * 
 **/


#include <string.h>
#include "include/MovingAverages/averages/MovingAverage.h"

/**
 * @brief Constructor for MovingAverage class
 * @details This constructor initializes the variables, the buffer and sets the buffer size.
 * @param uint16_t size : Size of the sample storage buffer array
 **/
MovingAverage::MovingAverage(uint16_t size) {
    _bufSize = size;
    _values = new uint16_t[_bufSize];
    _index = 0;
    _count = 0;
}

MovingAverage::~MovingAverage()
{
    this->clear();
} 

/**
 * @fn void MovingAverage::push(uint16_t value)
 * @brief Pushes a new value to the buffer
 * @details This method pushes a new value to the buffer. If the buffer is full, the oldest value is overwritten.
 * @param uint16_t value : New value to be pushed to the buffer
 **/

void MovingAverage::push(uint16_t value) {
    if (_count == _bufSize) {
        _count = 0;
    }
    _values[_index] = value;
    _index = (_index + 1) % _bufSize;
    _count++;
}

/**
 * @brief Gets the average value of the buffer
 * @details This method returns the average value of the buffer. If the buffer is empty, it returns 0.
 * @return returnValue: uint16_t : Average value of the buffer
 */

uint16_t MovingAverage::getFilterOutput()
{
    uint16_t returnValue = 0;
    if (_count > 0) {
        _sum = 0;
        for (uint16_t i = 0; i < _count; i++) {
            _sum += _values[i];
        }
        returnValue = _sum / _count;
    }
    return returnValue;
}

/**
 * @fn uint16_t MovingAverage::get()
 * @brief Returns the average value of the buffer
 * @details This method returns the average value of the buffer. If the buffer is empty, it returns 0.
 * @return uint16_t : Last value written to the buffer
 */

uint16_t MovingAverage::getLastValue() {
    return _values[_index];
}

/**
 * @fn uint16_t MovingAverage::get()
 * @brief Returns the status of the buffer
 * @details This method returns the status of the buffer. 
 *         - If the buffer is empty, it returns BUFFER_EMPTY. 
 *         - If the buffer is full, it returns BUFFER_FULL.
 *         - If the buffer is partially full, it returns BUFFER_PARTIAL.           
 * @return buf_status_t : Status of the buffer.
 */
buf_status_t MovingAverage::getBufferStatus() {
    buf_status_t returnValue;
    switch (_count / _bufSize) {
        case 0:
            returnValue = BUFFER_PARTIAL;
            break;
        case 1:
            returnValue = BUFFER_FULL;
            break;
        default:
            returnValue = BUFFER_PARTIAL;
            break;
    }
    return returnValue;
}

/**
 * @fn void MovingAverage::clear()
 * @brief Clears the buffer
 * @details This method clears the buffer. It sets the index to 0, the count to 0 and sets all the values to 0.
 */

void MovingAverage::clear() {
    _index = 0;
    _count = 0;
    delete _values;
}
