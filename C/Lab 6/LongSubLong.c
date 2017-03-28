#include "LongNumber.h"
#include <malloc.h>
#define BILL 1000000000

void Sub(DDList* first, DDList* second, DDList** res_first, DDList** res_last);

void LongSubLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last){
  int k1 = 0, k2 = 0, buf1, buf2;
  DDList *curr1 = first, *curr2 = second;

  while (curr1){
    k1++;
    if (!(curr1 -> PREV)){
      buf1 = (curr1 -> DATA) -> milliard;
      goto k2;
    }
    curr1 = curr1 -> PREV;
  }

k2:
  while (curr2){
    k2++;
    if (!(curr2 -> PREV)){
      buf2 = (curr2 -> DATA) -> milliard;
      goto k3;
    }
    curr2 = curr2 -> PREV;
  }

k3:
  if (k2 > k1){
    putchar('-');
    Sub(second, first, res_first, res_last);
  }
  if (k1 > k2)
    Sub(first, second, res_first, res_last);
  if (k1 == k2){
    if (buf1 > buf2)
      Sub(first, second, res_first, res_last);
    if (buf2 > buf1){
      putchar('-');
      Sub(second, first, res_first, res_last);
    }
    if (buf1 == buf2){
      while ( ((curr1 -> DATA) -> milliard) == ((curr2 -> DATA) -> milliard) ){
        curr1 = curr1 -> NEXT;
        curr2 = curr2 -> NEXT;
		if (!curr1 && !curr2) {
			struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
			DDLAddToStart(newItem, res_first, res_last);
			return;
		}
      }
      if ( ((curr2 -> DATA) -> milliard) > ((curr1 -> DATA) -> milliard) ){
        Sub(second, first, res_first, res_last);
        putchar('-');
      }
      if ( ((curr1 -> DATA) -> milliard) > ((curr2 -> DATA) -> milliard) )
        Sub(first, second, res_first, res_last);
    }
  }
}

void Sub(DDList* first, DDList* second, DDList** res_first, DDList** res_last){
  int flag = 0;
  DDList *curr1 = first, *curr2 = second;

  while (curr1 && curr2){
    struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
    newItem -> milliard = (curr1 -> DATA -> milliard) - (curr2 -> DATA -> milliard);
    if (flag){
      newItem -> milliard -= 1;
      flag = 0;
    }
    if (newItem -> milliard < 0){
      flag = 1;
      newItem -> milliard += BILL;
    }
    DDLAddToStart(newItem, res_first, res_last);
    curr1 = curr1 -> PREV;
    curr2 = curr2 -> PREV;
  }
  while (curr1){
    struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
    newItem -> milliard = (curr1 -> DATA -> milliard);
    if (flag){
      newItem -> milliard -= 1;
      flag = 0;
    }
    DDLAddToStart(newItem, res_first, res_last);
    curr1 = curr1 -> PREV;
  }
}
