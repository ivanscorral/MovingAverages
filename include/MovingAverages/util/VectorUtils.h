#ifndef __VECTORUTILS_H_
#define __VECTORUTILS_H_

#include <vector>


using namespace std;

class VectorUtils
{
public:
    VectorUtils() = default;
    ~VectorUtils() = default;
    template <typename T>
    vector<T> generateWithNoise(T value, size_t sampleSize, T maxNoise);
    template <typename T>
    float avg(vector<T>& vector);
    template <typename T>
    void printArray(vector<T>& array);
    template <typename T>
    vector<T> generate(T value, size_t sampleSize);
    template <typename T, typename S>
    auto absDiff(vector<T>& origin, S value) -> typename enable_if<is_arithmetic<T>::value &&
                                                                                is_arithmetic<S>::value, void>::type;
};

#include "util/VectorUtils.tpp"

#endif // __VECTORUTILS_H_
