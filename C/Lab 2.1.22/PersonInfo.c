#include<stdio.h>

extern void clean_stdin();

void PersonInfo(int* Date, int* Month, int* SEX){
  char s;
  int m, d;

  printf("Пол (Мужской(Male) - m; Женский(Female) - f): ");
  scanf("%c", &s);
  clean_stdin();
  while (s != 'm' && s != 'M' && s != 'f' && s != 'F'){
    printf("Ошибка! Повторите ввод: ");
    scanf("%c", &s);
    clean_stdin();
  }
  if (s == 'm' || s == 'M') *SEX = 1;
  else if (s == 'f' || s == 'F') *SEX = 2;

  printf("Введите месяц рождения (номер): ");
  while (!scanf("%d", &m) || (m > 12 || m < 1)){
    clean_stdin();
    printf("Нет такого месяца! Повторите ввод: ");
  }
  clean_stdin();
  *Month = m;



  printf("Введите дату рождения: ");
  
k2:
  while (!scanf("%d", &d) || d < 1){
    clean_stdin();
    printf("Ошибка! Повторите ввод: ");
  }

  if (m % 2 == 1){
    if (d > 31){
      printf("Нету такой даты в этом месяце! Повторите ввод: ");
      goto k2;
    }
  }
  if (m == 2){
    if (d > 29){
      printf("Нету такой даты в этом месяце! Повторите ввод: ");
      goto k2;
    }
  }
  if (m % 2 == 0){
    if (d > 30){
      printf("Нету такой даты в этом месяце! Повторите ввод: ");
      goto k2;
    }
  }
  *Date = d;
  putchar('\n');
  clean_stdin();
}
