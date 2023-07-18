#include <stdio.h>

int func(int m, int n) {
  if (m == 0) return n + 1;
  else if (n == 0) return func(m - 1, 1);
  else return func(m - 1, func(m, n - 1));
}

int main() {
  int V[] = {10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13};
  int Vr[16];

  for (int i = 0; i < 16; i++) Vr[i] = func(3, V[i]);

  for (int i = 0; i < 16; i++) printf("%d\n", Vr[i]);

  return 0;
}