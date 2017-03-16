#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char str[256];
  int size = 0, i = 0, summ = 0, words = 0;

  setlocale(LC_ALL, "Russian");
  FILE *file = fopen("file.txt", "r");
  if (!file){
    puts("Ошибка открытия файла! Выход из программы.");
    return 1;
  }
  do {
    str[size] = fgetc(file);
  } while (str[size++] != EOF);
  size -= 2;
  str[size] = '\0';
  fclose(file);

  while (str[i]){
    if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
      summ += str[i] - '0';
    i++;
  }
  if (strtok(str, " ")){
    words++;
    while (strtok(NULL, " "))
      words++;
  }

  if (words == summ)
    puts("Cумма числовых значений цифр равна количеству слов.");
  else
    puts("Сумма числовых значений цифр не равна количеству слов.");

  return 0;
}
