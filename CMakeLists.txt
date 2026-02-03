cmake_minimum_required(VERSION 3.10)
project(LinearRegressionFromScratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(MY_LIB_FILES
    src/DataLoader/DataLoader.cpp
    src/Model/LinearRegression.cpp
    src/Optimizer/GradientDescent.cpp
)

# 1. Збираємо основну програму
add_executable(run_app src/main.cpp ${MY_LIB_FILES})

# 2. Збираємо тести
enable_testing()
add_executable(run_tests tests/test.cpp ${MY_LIB_FILES})

# 3. Копіюємо папку data (щоб програма бачила csv файли)
file(COPY data DESTINATION ${CMAKE_BINARY_DIR})