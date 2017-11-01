#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  const int N = 100000;
  int i, a[N];
  double sum = 0, prom = 0;
    
#pragma omp parallel for
  for(i = 0; i < N; i++)
    a[i] = 1;

#pragma omp parallel for
  for(i = 0; i < N; i++)
    sum += a[i];

  prom = sum / N;

  printf("mean value is %f \n",prom);
  
  return 0;
}
