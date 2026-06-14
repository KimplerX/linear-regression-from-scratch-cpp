#pragma once

#include "../DataLoader/DataLoader.h"
#include "../Model/LinearRegression.h"

class GradientDescent {
private:
    double learningRate;
    int epochs;
public:
    GradientDescent(double lr, int ep);

    void train(LinearRegression& model, const Matrix& X, const Vector& Y);

    static double computeMSE(const LinearRegression& model, const Matrix& X, const Vector& Y);
    static double computeMAE(const LinearRegression& model, const Matrix& X, const Vector& Y);
    static double computeR2(const LinearRegression& model, const Matrix& X, const Vector& Y);
};
