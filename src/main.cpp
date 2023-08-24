#include <cstdint>
#include <vector>
#include <iostream>

#include "util/generate_data.h"
#include "util/VectorUtils.h"
#include "averages/GenericMovingAverage.h"

const uint16_t averagingSize = 32;
const uint16_t datasetSize = 10000;
const uint16_t baseValue = 330;
const uint16_t maxNoise = 30;

int main()
{
    GenericMovingAverage<uint16_t> *filter = new GenericMovingAverage<uint16_t>(averagingSize);
    generate_data *dataGenerator = new generate_data();
    VectorUtils *vUtils = new VectorUtils();
    vector<uint16_t> test = vUtils->generateWithNoise<uint16_t>(baseValue, datasetSize, maxNoise);
    for (uint8_t i = 0; i < 255; i++)
    {
        //print the value of the generated array
        cout << test[i] << endl;
    }

    vector<uint16_t> filtered = dataGenerator->filterArrayNoise<uint16_t>(test, filter, averagingSize);
    cout << "Generated array with size: " << test.size() << endl;
    cout << "Generated avg: " << vUtils->avg(test) << endl;
    vUtils->absDiff(test, baseValue);
    cout << "Generated differential avg: " << vUtils->avg(test) << endl;
    cout << "---------------------------------" << endl;
    cout << endl
         << "Filtered array size: " << filtered.size() << endl;
    cout << "Filtered avg: " << vUtils->avg(filtered) << endl;
    vUtils->absDiff(filtered, baseValue);
    cout << "Filtered differential avg: " << vUtils->avg(filtered) << endl;
    delete filter;
    delete dataGenerator;
    delete vUtils;

    return 0;
}
