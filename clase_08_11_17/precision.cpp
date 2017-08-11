#include<iostream>

int main()
{
  int n = 100;
  
  float eps = 1.0;
  float c_o = 1.0;

  float c = 0;

  for(int i = 1; i <= n; i++){
    eps /= 2.0;
    c = c_o + eps;
    std::cout<< i << "\t" <<  c << "\t" << eps << std::endl;
  }
  return 0;
}
