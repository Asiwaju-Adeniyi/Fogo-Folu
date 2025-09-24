#include <vector>
#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <random>
#include <fstream> 


class Matrix {
    private: 
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

    public: 
    Matrix(int N) : rows(N), cols(N) {
        data.resize(rows, std::vector<double>(cols, 0.0));

    }

   decltype(auto) operator() (size_t i, size_t j) {
    if(i >= rows || j >= cols) {
        throw std::out_of_range("Index is out of range");
    }
        return data[i][j];
   }

   decltype(auto) operator() (size_t i, size_t j) const {
    if(i >= rows || j >= cols) {
        throw std::out_of_range("Index is out of range");
    }
        return data[i][j];
   }

   size_t rowCount() const {
    return rows;}

   size_t colCount() const {
    return cols;
   }

    };

    void fillRandom(Matrix& mat) {
        std::mt19937 engine(std::random_device{}());
        std::uniform_real_distribution<double> dist(0, 1);

        for(int i = 0; i < mat.rowCount(); ++i) {
            for(int j = 0; j < mat.colCount(); ++j) {
                mat(i, j) = dist(engine);
            }
        }

    }


    void PrintMatrix(const Matrix& mat) {
        for(int i = 0; i < mat.rowCount(); ++i) {
            for(int j = 0; j < mat.colCount(); ++j) {
                std::cout << std::setw(10) << std::setprecision(4) << mat(i, j) << " ";
            }
            std::cout << std::endl;
        }
    };

    

    int main() {

        int matSize = 3;

        std::cout << "Enter the size of the matrix: ";
        std::cin >> matSize;


        Matrix matA(matSize);        Matrix matB(matSize);
        Matrix matC(matSize);

        fillRandom(matA);
        fillRandom(matB);

        auto start = std::chrono::steady_clock::now();

        for(int i = 0; i < matA.rowCount(); ++i) {
            for(int j = 0; j < matB.colCount(); ++j) {
                matC(i, j) = 0;
                for(int k = 0; k < matC.colCount(); ++k) {
                    matC(i, j) += matA(i, k) * matB(k, j);
                }
            }
        }

        PrintMatrix(matC);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time taken for matrix multiplication: " << elapsed.count() << " seconds\n";


        float Throughput = (2 * matSize * matSize * matSize) / (elapsed.count() * 1e9); // in GFLOPS


        std::fstream results;
        results.open("results.csv", std::ios::app);

        if(!results.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }

        if (results.is_open()) {
            results << std::fixed << std::setprecision(6);
            results << "Size (" << matSize << ")" << "," << "Time (" << elapsed.count() << " seconds)" << ", Througput (" << Throughput << ")" << "\n";
            std::cout << "Writing results for matrix size: " << matSize << std::endl;

            results.close();

        }

    }
