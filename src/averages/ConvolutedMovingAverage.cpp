
#include "averages/ConvolutedMovingAverage.h"

ConvolutedMovingAverage::ConvolutedMovingAverage(uint16_t size)  : _bufSize(size) {
    _values = new vector<T>[_bufSize];
    _index = 0;
    _count = 0;
}
T ConvolutedMovingAverage::getFilterOutput() {
    T returnValue;
    return returnValue;
}

