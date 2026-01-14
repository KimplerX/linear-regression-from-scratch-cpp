#include "DataLoader/DataLoader.h"
#include <iostream>

int main() {
    std::vector<double> OutputData;
    std::vector<std::vector<double>> InputData;
    std::string filename = "../linear-regression-from-scratch-cpp/data/training.csv";
    TDataLoader loader;
    loader.CSVload(filename, InputData, OutputData);

    for(int i = 0; i < InputData.size();  i++) {
        std::cout << OutputData[i] << ", ";
        for (int j = 0; j < InputData[0].size(); j++) {
            std::cout << InputData[i][j] << (j == (InputData[0].size() - 1) ? "\n" : ", ");
        }
    }

    return 0;
}
