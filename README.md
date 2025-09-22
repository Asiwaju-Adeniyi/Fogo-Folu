# AI Workload Benchmarking Tool

A simple **C++ program** that benchmarks matrix multiplication, a core operation in AI workloads.  
The program generates random matrices, multiplies them, measures execution time, computes throughput (in GFLOPS), and logs results to a CSV file.

---

##  Features
- **Matrix Multiplication**: Multiply two randomly generated `N x N` matrices.  
- **Benchmarking**: Measure execution time using `std::chrono::steady_clock`.  
- **Throughput Calculation**: Report performance in GFLOPS (billion floating-point operations per second).  
- **CSV Logging**: Append results to `results.csv` for later analysis.  
- **Custom Input**: User specifies the size of the matrix at runtime.  

---

## Example Output

### Console
Enter the size of the matrix: 3
1.234 0.567 2.345
0.987 1.543 3.210
2.123 0.876 1.111

Time taken for matrix multiplication: 0.000123 seconds
Throughput: 0.425 GFLOPS

### CSV (`results.csv`)
Size (3), Time (0.000123 seconds), Throughput (0.425)



---

## Tech Stack
- **Language**: C++17  
- **Libraries**: `<vector>`, `<chrono>`, `<random>`, `<fstream>`, `<iomanip>`  

---

## Next Steps (Possible Extensions)
Add multithreading / OpenMP to test scaling across cores.

Compare naive vs. cache-friendly / blocked matrix multiplication.

Support larger workloads (e.g., N x M matrices, batched multiplications).

Automate performance plots (Python + Matplotlib to visualize results.csv).


