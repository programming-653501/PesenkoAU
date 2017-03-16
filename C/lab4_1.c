#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define STR_NUM 3
#define STR_LEN 10

struct matrix{
  char string[STR_NUM][STR_LEN + 1];
};

void clear_stdin();
void delete_new_line(char* s); /*удаляет символ новой строки, который добавляет функция fgets();*/
void invitation(int* n);
void input(struct matrix*, int n);
void output(struct matrix*, int n);
void process(struct matrix*, int n);
int palindrom(char* s);
int mystrlen(char* s);



int main(){
  int n;
  struct matrix *array;
  setlocale(LC_ALL, "Russian");
  invitation(&n);
  array = (struct matrix*) calloc(n, sizeof(struct matrix));
  input(array, n);
  process(array, n);
  output(array, n);

  free(array);
  return 0;
}



void clear_stdin(){
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

void delete_new_line(char* s){
  while (*s){
    if (*s == '\n'){
      *s = '\0';
      return;
    }
    s++;
  }
}

void invitation(int* n){
  char a[3];
  printf("Эта программа работает с матрицами, состоящими из 3-х строк.\nВ каждой строке записано слово длиной до 10 букв.\n");
  printf("Для начала введите количество матриц: ");
  while (!scanf("%2[0-9]", a)){
    printf("Ошибка! Повторите ввод:");
    clear_stdin();
  }
  clear_stdin();
  *n = atoi(a);
}

void input(struct matrix* Matrix, int n){
  printf("\nТеперь вам нужно заполнить %d матриц словами! (не больше 10 букв)\n\n", n);
  for (int i = 0; i < n; i++){
    printf("Заполняем %d-ю матрицу:\n", i+1);
    for (int j = 0; j < STR_NUM; j++){
      fgets(Matrix[i].string[j], STR_LEN + 1, stdin);
      Matrix[i].string[j][STR_LEN + 1] = '\0';
      delete_new_line(Matrix[i].string[j]);
    }
    putchar('\n');
  }
}

void output(struct matrix* Matrix, int n){
  for (int i = 0; i < n; i++){
    printf("%d-я матрица:\n", i+1);
    for (int j = 0; j < STR_NUM; j++)
      printf("%s\n", Matrix[i].string[j]);
    putchar('\n');
  }
}

void process(struct matrix* Matrix, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < STR_NUM; j++)
      if (palindrom(Matrix[i].string[j]))
        Matrix[i].string[j][0] = '\0';
}

int palindrom(char* s){
  for (int start = 0, end = mystrlen(s) - 1; start < mystrlen(s) ; start++, end--)
    if (s[start] != s[end])
      return 0;
  return 1;
}

int mystrlen(char* s){
  int len = 0;
  while (*s){
    len++;
    s++;
  }
  return len;
}
