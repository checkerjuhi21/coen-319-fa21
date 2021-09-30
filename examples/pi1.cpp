#include <iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int sum = 0;
  int npoints = 10000000;
  #pragma omp parallel reduction(+:sum)  
  {
    int tid = omp_get_thread_num();
    int nt = omp_get_num_threads();
    unsigned int seed = 764 + tid * 97;
    int ntries = (int)((double)npoints/nt);
    #pragma omp single
    {
      double x = (double) (rand_r(&seed)/(double) RAND_MAX);
      double y = (double) (rand_r(&seed)/(double) RAND_MAX);
      cout << "ntries = " << ntries << endl;
      cout << "x = " << x << endl;
      cout << "y = " << y << endl;
    }
    for(int i=0; i < ntries; ++i){
      double x = (double) (rand_r(&seed)/(double) RAND_MAX);
      double y = (double) (rand_r(&seed)/(double) RAND_MAX);
      if(((x-0.5) * (x-0.5) + (y-0.5) * (y-0.5)) < 0.25){
        sum += 1;
      }
    }
  }

  cout << "sum = " << sum << endl;
  cout << "pi = " << 4.0 * ((double) sum)/npoints << endl;

  return 0;
}
