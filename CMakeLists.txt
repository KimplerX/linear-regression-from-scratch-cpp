cmake_minimum_required(VERSION 3.10)
project(LinearRegressionFromScratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(MY_LIB_FILES
    src/DataLoader/DataLoader.cpp
    src/Model/LinearRegression.cpp
    src/Optimizer/GradientDescent.cpp
)

add_executable(LinearRegression src/main.cpp ${MY_LIB_FILES})

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})