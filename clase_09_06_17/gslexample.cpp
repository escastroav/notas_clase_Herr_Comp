#include<cstdio>
#include<gsl/gsl_sf_bessel.h>

int main(void)
{
  double x = 0;
  double y = 0;
  
  for(int i = 0.; i <= 15000; i++)
    {
      x = 0.01*i;
      y = gsl_sf_bessel_J0(x);
      std::printf("%20.16e  %20.18e\n",x,y);
    }

  return 0;
}
