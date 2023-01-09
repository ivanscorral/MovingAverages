#ifndef __GENERATE_DATA__H__
#define __GENERATE_DATA__H__

#include <iostream>
#include <vector>
#include "../MovingAverages/GenericMovingAverage.h"
#include "../util/VectorUtils.h"

using namespace std;
class generate_data
{
private:
    /* data */
public:
    generate_data(/* args */);
    ~generate_data();
    float avg(vector<uint16_t>& vector);
    template <typename T>
    vector<T> calculateAbsoluteDifferencesFromValue(vector<T> origin, T value);
    template <typename T>
    vector<T> generateRandomNoiseForValue(T value, size_t sampleSize);
    template <typename T>
    vector<T> filterArrayNoise(vector<T> origin, GenericMovingAverage<T> *filter, uint16_t averagingSize = 32);
    void printArray(vector<uint16_t> array);
};

#endif //!__GENERATE_DATA__H__
