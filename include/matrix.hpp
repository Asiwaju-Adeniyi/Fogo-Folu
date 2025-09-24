#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(int N);
    double& operator()(size_t i, size_t j);
    const double& operator()(size_t i, size_t j) const;
    size_t rowCount() const;
    size_t colCount() const;
};

// Function declarations
void fillRandom(Matrix& mat);
void PrintMatrix(const Matrix& mat);
