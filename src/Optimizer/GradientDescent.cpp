#include "../../include/linear-regression-from-scratch-cpp/Optimizer/GradientDescent.h"
#include <iostream>
#include <cmath>

GradientDescent::GradientDescent(double lr, int ep)
    : learningRate(lr), epochs(ep) {}

void GradientDescent::train(LinearRegression& model, const Matrix& X, const Vector& Y) {
    int n = static_cast<int>(X.size());
    int m = static_cast<int>(X[0].size());

    for (int epoch = 0; epoch < epochs; epoch++) {
        // Обчислюємо градієнти
        Vector gradW(m, 0.0);
        double gradB = 0.0;

        for (int i = 0; i < n; i++) {
            double prediction = model.predict(X[i]);
            double error = prediction - Y[i];

            for (int j = 0; j < m; j++) {
                gradW[j] += (2.0 / n) * error * X[i][j];
            }
            gradB += (2.0 / n) * error;
        }

        // Оновлюємо ваги
        Vector weights = model.getWeights();
        for (int j = 0; j < m; j++) {
            weights[j] -= learningRate * gradW[j];
        }
        model.setWeights(weights);
        model.setBias(model.getBias() - learningRate * gradB);

        // Логуємо прогрес
        if (epoch % 100 == 0 || epoch == epochs - 1) {
            double mse = computeMSE(model, X, Y);
            std::cout << "  Epoch " << epoch << "/" << epochs
                      << "  |  MSE: " << mse << std::endl;
        }
    }
}

double GradientDescent::computeMSE(const LinearRegression& model, const Matrix& X, const Vector& Y) {
    int n = static_cast<int>(X.size());
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double error = model.predict(X[i]) - Y[i];
        sum += error * error;
    }
    return sum / n;
}

double GradientDescent::computeMAE(const LinearRegression& model, const Matrix& X, const Vector& Y) {
    int n = static_cast<int>(X.size());
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(model.predict(X[i]) - Y[i]);
    }
    return sum / n;
}

double GradientDescent::computeR2(const LinearRegression& model, const Matrix& X, const Vector& Y) {
    int n = static_cast<int>(X.size());

    // Середнє Y
    double meanY = 0.0;
    for (int i = 0; i < n; i++) {
        meanY += Y[i];
    }
    meanY /= n;

    // SS_res та SS_tot
    double ssRes = 0.0;
    double ssTot = 0.0;
    for (int i = 0; i < n; i++) {
        double error = model.predict(X[i]) - Y[i];
        ssRes += error * error;
        double diff = Y[i] - meanY;
        ssTot += diff * diff;
    }

    return 1.0 - (ssRes / ssTot);
}
