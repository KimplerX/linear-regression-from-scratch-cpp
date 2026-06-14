#pragma once

#include <string>
#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

class TDataLoader {
public:
    TDataLoader() = default;

    bool CSVload(const std::string& filename, Matrix& X, Vector& Y);

    // Z-score нормалізація: обчислює mean/std і нормалізує X на місці
    static void normalize(Matrix& X, Vector& means, Vector& stds);

    // Нормалізація з уже відомими параметрами (для тестових даних)
    static void normalizeWithParams(Matrix& X, const Vector& means, const Vector& stds);
};
