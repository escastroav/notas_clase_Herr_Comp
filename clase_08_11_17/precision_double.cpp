#include<iostream>

int main()
{
  std::cout.precision(16);
  
  int n = 100;
  
  double eps = 1.0;
  double c_o = 1.0;

  double c = 0;

  for(int i = 1; i <= n; i++){
    eps /= 2.0;
    c = c_o + eps;
    std::cout<< i << "\t" <<  c << "\t" << eps << std::endl;
  }
  return 0;
}
