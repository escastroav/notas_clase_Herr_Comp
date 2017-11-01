#include <iostream>
#include <vector>
#include <cmath>

const double Delta = 0.1;
const double L = 1.479;
const int N = int(L/Delta)+1;
const int steps = 100;

typedef std::vector<double> Matrix;

void initial_cond(Matrix & m);
void boundary_cond(Matrix & m);
void evolve (Matrix & m);

void print(Matrix & m);

int main ()
{
  
  Matrix mesh2d(N*N);

  initial_cond(mesh2d);
  boundary_cond(mesh2d);
  for(int k = 1;k<=steps;k++)
    evolve(mesh2d);
  evolve(mesh2d);
  print(mesh2d);
  
  return 0;
  
}

void initial_cond(Matrix & m)
{
  
  for(int ii = 0; ii<N; ++ii){
    for(int jj = 0; jj<N; ++jj){
      m[ii*N + jj] = 1.0; 
    }
  }
  
}
void print(Matrix & m)
{
  
  for(int ii = 0; ii<N; ++ii){
    for(int jj = 0; jj<N; ++jj){
      std::cout << ii * Delta << " "
		<< jj * Delta << " "
		<< m[ii*N + jj] << "\n"; 
    }
    std::cout << "\n";
  }
  
}
void boundary_cond(Matrix & m)
{
  int ii = 0, jj = 0;

  ii = 0;
  for(jj = 0; jj<N; ++jj){
    m[ii*N + jj] = 100; 
  }

  ii = N-1;
  for(jj = 0; jj<N; ++jj){
    m[ii*N + jj] = 0; 
  }

  jj = 0;
  for(ii = 1; ii<N; ++ii){
    m[ii*N + jj] = 0; 
  }
  jj = N-1;
  for(ii = 1; ii<N; ++ii){
    m[ii*N + jj] = 0; 
  }
}
void evolve (Matrix & m){
  for(int ii = 0; ii<N; ++ii){
    for(int jj = 0; jj<N; ++jj){
      if(ii == 0) continue;
      if(ii == N-1) continue;
      if(jj == 0) continue;
      if(jj == N-1) continue;
      m[ii*N + jj] = (m[(ii+1)*N+jj] +
		      m[(ii-1)*N+jj] +
		      m[ii*N+(jj+1)] +
		      m[ii*N+(jj-1)])*0.25; 
    }
  }
}
