
#include <iostream>
#include <chrono>
#include <cmath>
#include <eigen3/Eigen/Dense>


double solvesystem(const int & size);

int main(int argc, char ** argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size

  double sum = 0, sum2 = 0;
  double time = 0;
  for (int rep = 0; rep < N; ++rep) {
    srand(rep+1);
    time = solvesystem(M);
    sum  += time;
    sum2 += time*time;
  }
  double mean = sum/N;
  double sigma = std::sqrt(N*(sum2/N - mean*mean)/(N-1));

  std::cout << M*M << "\t" << mean << "\t" << sigma << std::endl;  
  
  return 0;
}

double solvesystem(const int & size)
{
  std::chrono::time_point<std::chrono::system_clock> start, end;

  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);

  start = std::chrono::system_clock::now();
  Eigen::MatrixXd x = A.fullPivLu().solve(b);
  end   = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  //std::cout << elapsed_seconds.count() << std::endl;
  
  //double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm
  //std::cout << A << std::endl;
  //std::cout << b << std::endl;
  //std::cout << "The relative error is:\n" << relative_error << std::endl;

  return elapsed_seconds.count();
}
