#ifndef __CONVOLUTED_MOVING_AVERAGE__H__
#define __CONVOLUTED_MOVING_AVERAGE__H__

#include "averages/GenericMovingAverage.h"

using namespace std;

template <typename T>
class ConvolutedMovingAverage : public GenericMovingAverage<T>
{
  public:
    ConvolutedMovingAverage(uint16_t size);
    T getFilterOutput() override;
};

#include "averages/ConvolutedMovingAverage.tpp"

#endif  //!__CONVOLUTED_MOVING_AVERAGE__H__