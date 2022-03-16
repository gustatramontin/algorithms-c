#include <stdio.h>

int main() {

  int numbers[] = {5, 2, 4, 6, 1, 3};

  int i;
  int chave;

  for (int j = 1; j < sizeof(numbers) / sizeof(int); j++) {
    i = j - 1;

    chave = numbers[j];

    while (i >= 0 && numbers[i] > chave) {
      numbers[i + 1] = numbers[i];

      i = i - 1;
      for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {

        printf("%i,", numbers[i]);
      }
      printf("\n");
    }

    printf("%i\n", chave);

    numbers[i + 1] = chave;
  }

  for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {

    printf("%i", numbers[i]);
  }

  return 0;
}
