#include<iostream>
#include<cstdlib>

//Generación de overflow y underflow

typedef int ENTERO;

int main(int argc, char **argv){

  int n = std::atoi(argv[1]);
  
  ENTERO under = 1.0;
  ENTERO over = 1.0;
  
  std::cout << "n" << "\t" << "under" << "\t" << "over" << std::endl;
  for(int i = 1; i <= n; i++){
    under = under / 2.0;
    over = over * 2.0;
    std::cout << i << "\t" << under << "\t" << over << std::endl;
  }
  return 0;
}
