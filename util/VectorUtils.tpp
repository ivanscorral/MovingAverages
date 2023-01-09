
#include "VectorUtils.h"

using namespace std;

template <typename T>
vector<T> VectorUtils::generateWithNoise(T value, size_t sampleSize, T maxNoise) {
    vector<T> result;
    T noiseValue;
    for (size_t i = 0; i < sampleSize; i++)
    {
        noiseValue = rand() % maxNoise;
        result.push_back(value + ((rand() % 2) ? noiseValue : -noiseValue));
    }
    return result;
}

template <typename T>
vector<T> VectorUtils::generate(T value, size_t sampleSize) {
    vector<T> result(sampleSize, value);
    return result;
}
template <typename T>
float VectorUtils::avg(vector<T>& vector) {
    // Set the sum type to the type of the vector, or int if the vector is not a floating point type    
    float sum = 0;
    for (T it : vector)
    {
        sum += it;
    }
    return (float)(sum / vector.size());
}

template <typename T>
void VectorUtils::printArray(vector<T> array) {
    for (T it : array)
    {
        cout << it << " ";
    }
    cout << endl;
}

template <typename T>
void VectorUtils::absDiff(vector<T>& origin, T value) {
    for (T& it : origin)
    {
        it = abs(value - it);
    }
}


