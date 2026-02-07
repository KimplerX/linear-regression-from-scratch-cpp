#pragma once

#include <string>
#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

class TDataLoader {
public:
    TDataLoader() = default;

    bool CSVload(const std::string& filename, Matrix& X, Vector& Y);
};
