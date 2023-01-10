
// #include "generate_data.h"
#include <iostream>
#include <vector>
#include "../MovingAverages/GenericMovingAverage.h"
#include "generate_data.h"
#include "../util/VectorUtils.h"


const uint16_t averagingSize = 100;
const uint16_t datasetSize = 10000;
const uint16_t baseValue = 3300;
const uint16_t maxNoise = 15;

template <typename T>
vector<T> generate_data::filterArrayNoise(vector<T> origin, GenericMovingAverage<T> *filter, uint16_t averagingSize)
{
    vector<T> result;
    T noiseValue;

    if (!filter)
    {
        filter = new GenericMovingAverage<T>(averagingSize);
    }
    for (T noiseValue : origin)
    {
        filter->push(noiseValue);

        if(filter->getBufferStatus() == g_buf_status_t::BUFFER_FULL) {
            result.push_back(filter->getFilterOutput());
        }
    }

    return result;
}

generate_data::generate_data() { }

generate_data::~generate_data(){ }

int main()
{
    GenericMovingAverage<uint16_t> *filter = new GenericMovingAverage<uint16_t>(averagingSize);
    generate_data *dataGenerator = new generate_data();
    VectorUtils *vUtils = new VectorUtils();
    vector<uint16_t> test = vUtils->generateWithNoise<uint16_t>(baseValue, datasetSize, maxNoise);
    vector<uint16_t> filtered = dataGenerator->filterArrayNoise(test, filter);
    cout << "Generated array with size: " << test.size() << endl;
    cout << endl
         << "Generated avg: " << vUtils->avg(test) << endl;
    vUtils->absDiff(test, baseValue);
    cout << endl
         << "Generated differential avg: " << vUtils->avg(test) << endl;
    cout << "---------------------------------" << endl;
    cout << endl
         << "Filtered array size: " << filtered.size() << endl;
    cout << endl
         << "Filtered avg: " << vUtils->avg(filtered) << endl;
    vUtils->absDiff(filtered, baseValue);
    cout << "Filtered differential avg: " << vUtils->avg(filtered) << endl;
    delete filter;
    delete dataGenerator;
    delete vUtils;

    return 0;
}