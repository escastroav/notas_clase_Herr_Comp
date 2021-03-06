#include<iostream>
#include<cmath>

int factorial(int k){
  int Fac = 1;
  for(int j=2; j <=k; j++){
    Fac *=j; 
  }
  return Fac;
}

double ExpSerie (double x, int N){
  double Sum = 0.; double term = 0;
  for(int k = 0;k<=N;k++)
    {
      term =std::pow(-x,k)/factorial(k); 
      Sum +=term;
    }
  return Sum;
}

double ExpGood (double x, int N){
  double sum = 1; double term = 1;
  for(int k = 0; k<N; k++){
    term *= (-x)/(k+1);
    sum += term;
  }
  return sum;
}

int main()
{
  double fix_X = 4.2;
  for(int n=0;n <=100; n++)
    {
      //std::cout << "poop exp: " << n <<"\t"<< ExpSerie(fix_X, n) << std::endl;
      std::cout <<  n <<"\t"<< ExpGood(fix_X, n) << std::endl;
      //std::cout << "real exp: " << n <<"\t"<< std::exp(-fix_X) << std::endl; 
    }
}
