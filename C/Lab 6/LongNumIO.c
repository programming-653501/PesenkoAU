#include "LongNumber.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 301
#define BUF 10

void EnterLongNumber (DDList** num_s, DDList** num_e){
  char str[MAX], buf[BUF];
  int len;

  fgets(str, MAX, stdin);
  str[strlen(str) - 1] = '\0';
  len = strlen(str);
  while (len - (BUF - 1) >= 0){
    struct Data *dat = (struct Data*) malloc(sizeof(struct Data));
    strcpy(buf, str + (len - (BUF - 1)) );
    dat -> milliard = atoi(buf);
    str[len - (BUF - 1)] = '\0';
    len = strlen(str);
    DDLAddToStart(dat, num_s, num_e);
  }
  if (str[0]){
    struct Data *dat = (struct Data*) malloc(sizeof(struct Data));
    dat -> milliard = atoi(str);
    DDLAddToStart(dat, num_s, num_e);
  }
}

void PrintList (struct Data* data){
  for (int r =100000000; r > 0; r /= 10)
    printf("%d", ( (data -> milliard / r) % 10 ) );
}
