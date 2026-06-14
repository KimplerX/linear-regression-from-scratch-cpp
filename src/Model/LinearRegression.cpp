#include "../../include/linear-regression-from-scratch-cpp/Model/LinearRegression.h"
#include <random>

LinearRegression::LinearRegression(int numFeatures) : bias(0.0) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-0.5, 0.5);

    weights.resize(numFeatures);
    for (int i = 0; i < numFeatures; i++) {
        weights[i] = dist(gen);
    }
}

double LinearRegression::predict(const std::vector<double>& InputData) const {
    double result = bias;
    for (size_t i = 0; i < weights.size(); i++) {
        result += weights[i] * InputData[i];
    }
    return result;
}

const std::vector<double>& LinearRegression::getWeights() const {
    return weights;
}

double LinearRegression::getBias() const {
    return bias;
}

void LinearRegression::setWeights(const std::vector<double>& w) {
    weights = w;
}

void LinearRegression::setBias(double b) {
    bias = b;
}