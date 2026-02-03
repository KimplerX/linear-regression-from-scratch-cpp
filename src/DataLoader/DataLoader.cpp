#include "../../include/linear-regression-from-scratch-cpp/DataLoader/DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool TDataLoader::CSVload(const std::string& filename, Matrix& X, Vector& Y) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "=============================="
                     "\nError: could not open file!"
                     "\n------------------------------\n";
        return false;
    } else {
        std::cout << "=============================="
                     "\nData uploaded successfully";
                     "\n------------------------------\n";

        std::string line;
        getline(file, line);

        while(getline(file, line)) {

            std::stringstream ss(line);
            std::string segment;
            std::vector<double> rowData;

            while(getline(ss, segment, ',')) {
                try {
                    rowData.push_back(std::stod(segment));
                } catch(...) {
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
        

    }
    file.close();
    return true;
}