#include "../../include/linear-regression-from-scratch-cpp/DataLoader/DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

bool TDataLoader::CSVload(const std::string& filename, Matrix& X, Vector& Y) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "=============================="
                  << "\033[31m" 
                  << "\nError: could not open file: " << filename
                  << "\033[0m"
                  << "\n------------------------------\n";
        return false;
    }

    std::cout << "=============================="
              << "\033[32m" 
              << "\nData uploaded successfully: " << filename
              << "\033[0m"
              << "\n------------------------------\n";

    std::string line;
    // Пропускаємо заголовок
    getline(file, line);

    int lineNum = 1;
    while (getline(file, line)) {
        lineNum++;
        std::stringstream ss(line);
        std::string segment;
        std::vector<double> rowData;

        while (getline(ss, segment, ',')) {
            try {
                rowData.push_back(std::stod(segment));
            } catch (const std::exception& e) {
                std::cerr << "\033[33m[WARNING] Line " << lineNum 
                          << ": failed to parse '" << segment 
                          << "' — " << e.what() << "\033[0m\n";
                continue;
            }
        }

        if (!rowData.empty()) {
            double target = rowData.front();
            rowData.erase(rowData.begin());

            X.push_back(rowData);
            Y.push_back(target);
        }
    }

    file.close();
    return true;
}

void TDataLoader::normalize(Matrix& X, Vector& means, Vector& stds) {
    if (X.empty()) return;

    int n = X.size();
    int m = X[0].size();

    means.assign(m, 0.0);
    stds.assign(m, 0.0);

    // Обчислюємо середнє
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            means[j] += X[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        means[j] /= n;
    }

    // Обчислюємо стандартне відхилення
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double diff = X[i][j] - means[j];
            stds[j] += diff * diff;
        }
    }
    for (int j = 0; j < m; j++) {
        stds[j] = std::sqrt(stds[j] / n);
        if (stds[j] == 0.0) stds[j] = 1.0; // запобігаємо діленню на 0
    }

    // Нормалізуємо
    normalizeWithParams(X, means, stds);
}

void TDataLoader::normalizeWithParams(Matrix& X, const Vector& means, const Vector& stds) {
    for (size_t i = 0; i < X.size(); i++) {
        for (size_t j = 0; j < X[i].size(); j++) {
            X[i][j] = (X[i][j] - means[j]) / stds[j];
        }
    }
}