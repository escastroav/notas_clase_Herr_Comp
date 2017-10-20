#include <omp.h>
#include <math.h>
#include <stdio.h>

double function(double x);
double Num_Integral(double a, double b, const int N);

int main()
{
  const int N = 1000;
  double a = 0, b = 1, Sum = 0;
  double time = 0, time_old = 0;

  time_old = omp_get_wtime();

  printf("time proccesing:%f\n",time_old);

  #pragma omp parallel
  {
    int n = omp_get_num_threads();
    int ID = omp_get_thread_num();
    
    printf("there are %d used.\n", n);
    Sum = Num_Integral(a,b,N); 
    printf("value of thread (%d): %f \n",ID,Sum);
  }
  
  time = omp_get_wtime();

  printf("time proccesing:%f\n",time - time_old);
  
  return 0;
}

double function(double x)
{
  double denom = (1. + x*x);

  return (4./denom);
}

double Num_Integral(double a, double b, const int N)
{
  double Sum_i = 0, h_1 = 0, dx = (b-a)/((double)N);
  for(int ii = 1; ii <= N; ii++)
    {
      h_1 = function(a+ii*dx);
      Sum_i += (h_1)*dx;
    }
  return Sum_i;
}



