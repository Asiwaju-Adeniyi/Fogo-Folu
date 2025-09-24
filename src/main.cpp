#include "matrix.hpp"
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

int main() {
    int matSize = 3;

    std::cout << "Enter the size of the matrix: ";
    std::cin >> matSize;

    Matrix matA(matSize), matB(matSize), matC(matSize);

    fillRandom(matA);
    fillRandom(matB);

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < matA.rowCount(); ++i) {
        for (int j = 0; j < matB.colCount(); ++j) {
            matC(i, j) = 0;
            for (int k = 0; k < matC.colCount(); ++k) {
                matC(i, j) += matA(i, k) * matB(k, j);
            }
        }
    }

    PrintMatrix(matC);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken for matrix multiplication: "
              << elapsed.count() << " seconds\n";

    float Throughput = (2 * matSize * matSize * matSize) / (elapsed.count() * 1e9); // GFLOPS

    std::fstream results("results.csv", std::ios::app);
    if (!results.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    results << std::fixed << std::setprecision(6);
    results << "Size (" << matSize << "),"
            << "Time (" << elapsed.count() << " seconds),"
            << "Throughput (" << Throughput << ")\n";

    results.close();
    std::cout << "Results written to results.csv" << std::endl;
}
