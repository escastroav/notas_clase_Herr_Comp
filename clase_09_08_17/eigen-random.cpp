
#include <iostream>
#include <eigen3/Eigen/Dense>

int main(void)
{
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(5,5);
  std::cout << m << std::endl;
  
  return 0; 
}
