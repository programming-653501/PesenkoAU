#include <stdio.h>
#include <locale.h>

#include "LongNumber.h"



int main(){
  DDList *first_num_start = NULL, *first_num_end = NULL,
         *second_num_start = NULL, *second_num_end = NULL,
         *result_start = NULL, *result_end = NULL;
  setlocale(LC_ALL, "Russian");

  puts("Введите первое число:");
  EnterLongNumber(&first_num_start, &first_num_end);
  puts("Введите второе число:");
  EnterLongNumber(&second_num_start, &second_num_end);

  printf("\nСложение:\n");
  LongSumLong(first_num_end, second_num_end, &result_start, &result_end);
  DDLShowAll(result_start);
  DDLClear(&result_start, &result_end);

  printf("\nВычитание:\n");
  LongSubLong(first_num_end, second_num_end, &result_start, &result_end);
  DDLShowAll(result_start);
  DDLClear(&result_start, &result_end);

  printf("\nУмножение:\n");
  LongMulLong(first_num_end, second_num_end, &result_start, &result_end);
  DDLShowAll(result_start);
  DDLClear(&result_start, &result_end);

  printf("\nДеление:\n");
  LongDivLong(first_num_end, second_num_end, &result_start, &result_end);
  DDLShowAll(result_start);
  DDLClear(&result_start, &result_end);

  DDLClear(&first_num_start, &first_num_end);
  DDLClear(&second_num_start, &second_num_end);

  putchar('\n');
  return 0;
}
