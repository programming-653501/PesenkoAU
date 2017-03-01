#include<stdio.h>
#include<locale.h>
#include<math.h>

double sinx = 0; /*Глобальная переменная*/

/*Очистка буфера ввода*/
void clean_stdin(){
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

double sin_iter(double x, int n){
  double rez = pow(x, 2*n - 1);
  for (int i = 2; i <= 2*n - 1; i++)
    rez /= i;
  return rez;
}

double sin_rec(double x, double rez, double summ, double eps){
  static int n = 1, sign = 1;
  n += 2; sign *= -1;
  if (fabs(rez - sinx) < eps)
    return rez;
  else
    return sin_rec(x, rez + sign * (summ * x * x)/(n * (n - 1)), (summ * x * x)/(n * (n - 1)), eps);
}



int main(){
  double x, eps, sinx_dec = 0;
  int n = 1, sign = 1;

  setlocale(LC_ALL, "Russian");
  printf("Введите x: ");
  while (!scanf("%lf", &x)){
    clean_stdin();
    printf("Ошибка! Повторите ввод: ");
  }
  clean_stdin();
  printf("Введите допустимую погрешность: ");
  while (!scanf("%lf", &eps)){
    clean_stdin();
    printf("Ошибка! Повторите ввод: ");
  }
  clean_stdin();
  eps = fabs(eps);

  sinx = sin(x);
  printf("Функция из стандартной библиотеки: sin x = %lf\n", sinx);
  printf("Итерационное вычисление: sin x = ");
  while (fabs(sinx - sinx_dec) > eps){
    sinx_dec += sin_iter(x, n) * sign;
    n++; sign = -sign;
  }
  printf("%lf\n", sinx_dec);
  n--;
  printf("Номер итерации, при которой достигается заданная точность: %d\n", n);
  printf("Рекурсивное вычисление: sin x = %lf", sin_rec(x, x, x, eps));

  printf("\nНажмите Enter для выхода...");
  getchar();
  return 0;
}
