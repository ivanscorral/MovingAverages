
#include "util/generate_data.h"
#include "averages/GenericMovingAverage.h"

using namespace std;

// TODO: Fix implementation, it's not working as expected

template <typename T>
vector<T> generate_data::filterArrayNoise(vector<T> origin, GenericMovingAverage<T> *filter, int averagingSize)
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

        if (filter->getBufferStatus() == g_buf_status_t::BUFFER_FULL)
        {
            auto lastValue = filter->getLastValue();
            auto bufVal = filter->getFilterOutput();
            result.push_back(bufVal);
        }
    }

    return result;
}
