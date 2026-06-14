#include <iostream>
#include <iomanip>
#include <linear-regression-from-scratch-cpp/DataLoader/DataLoader.h>
#include <linear-regression-from-scratch-cpp/Model/LinearRegression.h>
#include <linear-regression-from-scratch-cpp/Optimizer/GradientDescent.h>

int main() {
    std::cout << "\n==========================================\n";
    std::cout << "  Linear Regression From Scratch (C++)\n";
    std::cout << "  Multiple Linear Regression + GD\n";
    std::cout << "==========================================\n\n";

    // ========== 1. Завантаження тренувальних даних ==========
    TDataLoader loader;
    Matrix X_train;
    Vector Y_train;

    if (!loader.CSVload("data/training.csv", X_train, Y_train)) {
        std::cerr << "Failed to load training data!\n";
        return 1;
    }

    std::cout << "Training samples: " << X_train.size()
              << " | Features: " << X_train[0].size() << "\n";

    // ========== 2. Нормалізація фічей ==========
    Vector means, stds;
    TDataLoader::normalize(X_train, means, stds);

    std::cout << "\nNormalization params:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Means: ";
    for (auto m : means) std::cout << m << " ";
    std::cout << "\n  Stds:  ";
    for (auto s : stds) std::cout << s << " ";
    std::cout << "\n";

    // ========== 3. Створення моделі ==========
    int numFeatures = static_cast<int>(X_train[0].size());
    LinearRegression model(numFeatures);

    std::cout << "\nInitial weights: ";
    for (auto w : model.getWeights()) std::cout << std::setprecision(4) << w << " ";
    std::cout << "\nInitial bias: " << model.getBias() << "\n";

    // ========== 4. Тренування ==========
    std::cout << "\n--- Training (Gradient Descent) ---\n";
    GradientDescent optimizer(0.01, 1000);
    optimizer.train(model, X_train, Y_train);

    // ========== 5. Метрики на тренувальних даних ==========
    std::cout << "\n--- Training Metrics ---\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "  MSE:  " << GradientDescent::computeMSE(model, X_train, Y_train) << "\n";
    std::cout << "  MAE:  " << GradientDescent::computeMAE(model, X_train, Y_train) << "\n";
    std::cout << "  R^2:  " << GradientDescent::computeR2(model, X_train, Y_train) << "\n";

    // ========== 6. Завантаження та оцінка тестових даних ==========
    Matrix X_test;
    Vector Y_test;

    if (loader.CSVload("data/testing.csv", X_test, Y_test)) {
        TDataLoader::normalizeWithParams(X_test, means, stds);

        std::cout << "\nTest samples: " << X_test.size() << "\n";

        std::cout << "\n--- Testing Metrics ---\n";
        std::cout << "  MSE:  " << GradientDescent::computeMSE(model, X_test, Y_test) << "\n";
        std::cout << "  MAE:  " << GradientDescent::computeMAE(model, X_test, Y_test) << "\n";
        std::cout << "  R^2:  " << GradientDescent::computeR2(model, X_test, Y_test) << "\n";

        // ========== 7. Приклади прогнозів ==========
        std::cout << "\n--- Sample Predictions (Test) ---\n";
        std::cout << std::setw(10) << "Actual"
                  << std::setw(12) << "Predicted"
                  << std::setw(10) << "Error" << "\n";
        std::cout << "--------------------------------\n";

        int samplesToShow = std::min(10, static_cast<int>(X_test.size()));
        for (int i = 0; i < samplesToShow; i++) {
            double pred = model.predict(X_test[i]);
            double err = pred - Y_test[i];
            std::cout << std::setw(10) << Y_test[i]
                      << std::setw(12) << pred
                      << std::setw(10) << err << "\n";
        }
    }

    // ========== 8. Фінальна модель ==========
    std::cout << "\n--- Final Model ---\n";
    std::cout << "Weights: ";
    for (auto w : model.getWeights()) std::cout << w << " ";
    std::cout << "\nBias:    " << model.getBias() << "\n";

    std::cout << "\n==========================================\n";
    std::cout << "  Done!\n";
    std::cout << "==========================================\n\n";

    return 0;
}