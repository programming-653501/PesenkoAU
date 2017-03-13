#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void clear_stdin();
void input(int *k, int *l);
void fill(int **m, int k, int l);
void show(int **m, int k, int l);


int main(){
  int k, l;
  int **m;

  setlocale(LC_ALL, "Russian");
  input(&k, &l);
  m = (int**) calloc(k, sizeof(int*));
  for (int i = 0; i < k; i++)
    *(m + i) = (int*) calloc(l, sizeof(int));

  fill(m, k, l);
  show(m, k, l);

  for (int i = 0; i < k; i++)
    free(*(m+i));
  free(m);
  return 0;
}



void clear_stdin(){
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

void input(int *k, int *l){
  char ks[6], ls[6];
  puts("Введите размер матрицы (K x L):");
  printf("K: ");
  while (!scanf("%5[0-9]", ks)){
    printf("Ошибка! Повторите ввод: ");
    clear_stdin();
  }
  clear_stdin();
  printf("L: ");
  while (!scanf("%5[0-9]", ls)){
    printf("Ошибка! Повторите ввод: ");
    clear_stdin();
  }
  clear_stdin();
  *k = atoi(ks);
  *l = atoi(ls);
}

void fill(int **m, int k, int l){
  for (int i = 0; i< k; i++)
    for (int j = 0; j<l; j++)
      *(*(m+i)+ j) = ( (j%4 + 1) + ((i % 2)? 2 : 0) ) % 4 + 1;
}

void show(int **m, int k, int l){
  printf("\nИскомая матрица:\n");
  for (int i = 0; i < k; i++){
    for (int j = 0; j < l; j++)
      printf("%d ", *(*(m+i)+j));
    putchar('\n');
  }
}
