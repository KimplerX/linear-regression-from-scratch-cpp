#pragma once

#include <vector>

class LinearRegression {
private:
    std::vector<double> weights;
    double bias;
public:
    LinearRegression() {};

    double predict(const std::vector<double>& InputData) const;

    const std::vector<double>& getWeights() const;
    double getBias() const;

    void setWeights(const std::vector<double>& w);
    void setBias(double b);
};
