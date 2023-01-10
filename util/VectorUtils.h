#ifndef __VECTORUTILS_H_
#define __VECTORUTILS_H_

#include <bits/stdc++.h>
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
    template <typename T>
    void absDiff(vector<T>& origin, T value);
};

#include "VectorUtils.tpp"

#endif // __VECTORUTILS_H_
