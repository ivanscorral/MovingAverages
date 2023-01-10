#ifndef __CONVOLUTEDMOVINGAVERAGE__H__
#define __CONVOLUTEDMOVINGAVERAGE__H__

#include <vector>
#include "GenericMovingAverage.h"

using namespace std;

class ConvolutedMovingAverage: public MovingAverage
{
    private:
        uint16_t _convolutionSize;
    protected:
    
    public:
};

#endif  //!__CONVOLUTEDMOVINGAVERAGE__H__