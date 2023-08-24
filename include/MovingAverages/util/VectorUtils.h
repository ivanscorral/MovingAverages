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
    T avg(const vector<T>& vec);
    template <typename T>
    void printArray(vector<T> &array);
    template <typename T>
    vector<T> generate(T value, size_t sampleSize);
    template <typename T, typename S>
    void absDiff(vector<T> &origin, S value);
};

#include "util/VectorUtils.tpp"

#endif // __VECTORUTILS_H_
