#include "../../include/linear-regression-from-scratch-cpp/Model/LinearRegression.h"
#include <iostream>
#include <random>
#include <ctime>

LinearRegression::LinearRegression() {
    bias = 0.0;
    std::srand(std::time(0));
    for (int i =1; i <=3; i++) {
        double random_weight = (rand() % 200 - 100) / 100.0;  
        weights.push_back(random_weight);
    }
}

double LinearRegression::predict(const std::vector<double>& InputData) const {
    return bias + weights[0]*InputData[0] + weights[1]*InputData[1] + weights[2]*InputData[2];
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