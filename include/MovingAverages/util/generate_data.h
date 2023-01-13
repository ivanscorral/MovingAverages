#ifndef __GENERATE_DATA__H__
#define __GENERATE_DATA__H__

#include <iostream>
#include <vector>
#include "averages/GenericMovingAverage.h"
#include "util/VectorUtils.h"

using namespace std;
class generate_data
{
private:
    /* data */
public:
    generate_data(/* args */) = default;
    ~generate_data() = default;
    template <typename T>
    vector<T> filterArrayNoise(vector<T> origin, GenericMovingAverage<T> *filter, int averagingSize);
};

#include "util/generate_data.cpp"

#endif //!__GENERATE_DATA__H__
