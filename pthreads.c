%%writefile pthread.c
#include <stdio.h>
#include <time.h>
#include <pthread.h>

int NUM_THREAD = 2; //El número de procesadores logicos en colab es de 2.

int V[] = {10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13};
int Vr[16];

int func(int m, int n) {
  if (m == 0) return n + 1;
  else if (n == 0) return func(m - 1, 1);
  else return func(m - 1, func(m, n - 1));
}

void* calcularHilos(void* arg) {
    int thread_id = *(int*) arg;
    int section_size = 16 / NUM_THREAD;
    int start_index = thread_id * section_size;
    int end_index = (thread_id == NUM_THREAD - 1) ? 16 : start_index + section_size;

    for (int i = start_index; i < end_index; i++) Vr[i] = func(3, V[i]);

    return NULL;
}

int main() {

  pthread_t threads[NUM_THREAD];
  int thread_ids[NUM_THREAD];

  clock_t inicio = clock();

  for (int i = 0; i < NUM_THREAD; i++) {
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, calcularHilos, &thread_ids[i]);
  }
  for (int i = 0; i < NUM_THREAD; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < 16; i++) printf("%d, ", Vr[i]);

  clock_t fin = clock();

  printf("\nTime: %f\n", (double)(fin - inicio)/CLOCKS_PER_SEC);

  return 0;
}