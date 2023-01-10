
#include "/include/utils/generate_data.h"

#include "/include/MovingAverages/averages/GenericMovingAverage.h"

const uint16_t averagingSize = 64;
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

