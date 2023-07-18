%%writefile OpenMP.c
#include <stdio.h>
#include <time.h>
#include <omp.h>

int func(int m, int n) {
  if (m == 0) return n + 1;
  else if (n == 0) return func(m - 1, 1);
  else return func(m - 1, func(m, n - 1));
}

int main() {
  int V[] = {10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13};
  int Vr[16];

  clock_t inicio = clock();

  #pragma omp parallel for schedule(static) num_threads(2)
  for (int i = 0; i < 16; i++) {
    Vr[i] = func(3, V[i]);
  }

  for (int i = 0; i < 16; i++) printf("%d, ", Vr[i]);

  clock_t fin = clock();

  printf("\nTime: %f\n", (double)(fin - inicio)/CLOCKS_PER_SEC);

  return 0;
}