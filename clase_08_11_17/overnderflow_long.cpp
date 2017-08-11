#include<iostream>
#include<cstdlib>

//Generación de overflow y underflow

typedef long double REAL;

int main(int argc, char **argv){

  int n = std::atoi(argv[1]);
  
  REAL under = 1.0;
  REAL over = 1.0;
  
  std::cout << "n" << "\t" << "under" << "\t" << "over" << std::endl;
  for(int i = 1; i <= n; i++){
    under = under / 2.0;
    over = over * 2.0;
    std::cout << i << "\t" << under << "\t" << over << std::endl;
  }
  return 0;
}
