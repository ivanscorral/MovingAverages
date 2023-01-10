
#include "VectorUtils.h"

using namespace std;

/// @brief Generate a vector with random noise added to a base value
/// @tparam T: Type of the vector
/// @param T value: The base value
/// @param T sampleSize: The size of the vector
/// @param T maxNoise: The maximum noise value
/// @return vector<T> result: The vector with random noise added or substracted to the base value

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

/// @brief Generate a vector with a constant value
/// @tparam T: Type of the vector
/// @param T value: The value to fill the vector with
/// @param T sampleSize: The size of the vector
/// @return vector<T> result: The vector with the constant value

template <typename T>
vector<T> VectorUtils::generate(T value, size_t sampleSize) {
    vector<T> result(sampleSize, value);
    return result;
}

/// @brief Get the average value of all the elements in a vector
/// @tparam T: Type of the vector
/// @param vector<T>& vector: The vector to get the average of
/// @return float: The average value of the vector

template <typename T>
float VectorUtils::avg(vector<T>& vector) {
    if (vector.empty()) {
        throw invalid_argument("Cannot calculate the average of an empty vector");
    }
    T sum = 0;
    for (const auto& it : vector) {
        sum += it;
    }
    return static_cast<float>(sum) / vector.size();
}

/// @brief Prints a vector to the console
/// @details Prints the vector to the console, separated by spaces 
/// @tparam T: Type of the vector
/// @param vector<T>& array: The vector to print

template <typename T>
void VectorUtils::printArray(vector<T>& array) {
    for (T it : array)
    {
        cout << it << " ";
    }
    cout << endl;
}

/// @brief Generates a vector with the absolute differences of the elements in the origin vector and the specified value
/// @tparam T: Type of the vector
/// @param vector<T>& origin: The vector to calculate the differences from and to store the result in
/// @param T value: The value to calculate the differences from
    
template <typename T>
void VectorUtils::absDiff(vector<T>& origin, T value) {
    for (T& it : origin)
    {
        it = abs(value - it);
    }
}


