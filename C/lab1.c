#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<locale.h>

void output(int a){
  char bin[32];
  int i = 0;
  static int count = 1;
  printf("\nЧисло %d:\nДесятичный вид: %i\nДвоичный вид: ", count, a);
  count++;
  while(a){
    (a & 1) ? (bin[i++]='1') : (bin[i++]='0');
    a = a >> 1;
  }
  for(i--; i >= 0; i--)
    putchar(bin[i]);
  putchar('\n');
}

void clean_stdin(){
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}



int main(){
  int i = 0, m, work = 3;
  bool in = false;
  /*work == 3(11 в двоичной системе) - первое искомое число.
  Будем использовать его для нахождения остальных.*/

  setlocale(LC_ALL, "Russian");
  printf("Введите натуральное число m: ");
  while (!in){
    in = scanf("%i", &m);
    clean_stdin();
    if (!in){
      printf("Ошибка! Повторите ввод: ");
      continue;
    }
    else
      if (m <= 0){
        in = false;
        printf("Ошибка! Повторите ввод: ");
      }
  }

  /*Закономерность для нахождения нужных чисел:
    -дописать справа 00 к двоичному представлению числа - умножить его на 4;
    -дописать справа 11 к двоичному представлению числа - умножить его на 4 и прибавить 3;
  Новые числа получаются последовательным дописыванием справа 00 и 11
                            к двоичному представлению первого искомого числа.*/
  printf("\nИскомые числа меньше m:\n");
  if (work <= m){
    while (work <= m && work <= INT_MAX / 4){
      output(work);
      (i++ % 2) ? (work = work * 4 + 3) : (work *= 4);
    }
  }
  else
    printf("Не найдены.\n");

  printf("\nНажмите Enter для выхода...");
  getchar();
  return 0;
}
