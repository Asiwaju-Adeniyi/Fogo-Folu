#include "matrix.hpp"
#include <random>
#include <iostream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix(int N) : rows(N), cols(N) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

double& Matrix::operator()(size_t i, size_t j) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index is out of range");
    }
    return data[i][j];
}

const double& Matrix::operator()(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index is out of range");
    }
    return data[i][j];
}

size_t Matrix::rowCount() const { return rows; }
size_t Matrix::colCount() const { return cols; }

void fillRandom(Matrix& mat) {
    std::mt19937 engine(std::random_device{}());
    std::uniform_real_distribution<double> dist(0, 1);

    for (size_t i = 0; i < mat.rowCount(); ++i) {
        for (size_t j = 0; j < mat.colCount(); ++j) {
            mat(i, j) = dist(engine);
        }
    }
}

void PrintMatrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.rowCount(); ++i) {
        for (size_t j = 0; j < mat.colCount(); ++j) {
            std::cout << std::setw(10) << std::setprecision(4) << mat(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
