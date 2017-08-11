#include<iostream>

//Generación de overflow y underflow

int main(){

  int n = 1100;
  
  double under = 1.0d;
  double over = 1.0d;
  
  std::cout << "n" << "\t" << "under" << "\t" << "over" << std::endl;
  for(int i = 1; i <= n; i++){
    under = under / 2.0d;
    over = over * 2.0d;
    std::cout << i << "\t" << under << "\t" << over << std::endl;
  }
  return 0;
}
