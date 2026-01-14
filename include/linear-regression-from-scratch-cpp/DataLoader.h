#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <string>
#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

class TDataLoader {
public:
    TDataLoader() = default;

    bool CSVload(const std::string& filename, Matrix& X, Vector& Y);
};

#endif