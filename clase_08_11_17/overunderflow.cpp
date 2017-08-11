#include<iostream>

int main(){

  int n = 500;
  
  float under = 1.0f;
  float over = 1.0f;
  
  std::cout << "n" << "\t" << "under" << "\t" << "over" << std::endl;
  for(int i = 1; i <= n; i++){
    under = under / 2.0f;
    over = over * 2.0f;
    std::cout << i << "\t" << under << "\t" << over << std::endl;
  }
  return 0;
}
