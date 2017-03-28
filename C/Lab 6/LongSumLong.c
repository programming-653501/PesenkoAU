#include "LongNumber.h"
#include <malloc.h>
#define BILL 1000000000

void LongSumLong (DDList* first, DDList* second, DDList** res_first, DDList** res_last){
  int buf = 0;
  DDList *curr1 = first, *curr2 = second;

  while (curr1 && curr2){
    struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
    (newItem -> milliard) = ((curr1 -> DATA) -> milliard) + ((curr2 -> DATA) -> milliard);
    if (buf){
      (newItem -> milliard) += buf;
      buf = 0;
    }
    if ((newItem -> milliard) >= BILL){
      buf = 1;
      (newItem -> milliard) -= BILL;
    }
    DDLAddToStart(newItem, res_first, res_last);
    curr1 = curr1 -> PREV;
    curr2 = curr2 -> PREV;
  }
  if (curr1 && (!curr2) )
    while (curr1){
      struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
      (newItem -> milliard) += ((curr1 -> DATA) -> milliard);
      if (buf){
        (newItem -> milliard) += buf;
        buf = 0;
      }
      DDLAddToStart(newItem, res_first, res_last);
      curr1 = curr1 -> PREV;
    }

  if ( (!curr1) && curr2)
    while (curr2){
      struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
      (newItem -> milliard) += ((curr2 -> DATA) -> milliard);
      if (buf){
        (newItem -> milliard) += buf;
        buf = 0;
      }
      DDLAddToStart(newItem, res_first, res_last);
      curr2 = curr2 -> PREV;
    }

  if (buf){
    struct Data* newItem = (struct Data*) calloc(1, sizeof(struct Data));
    (newItem -> milliard) += buf;
    DDLAddToStart(newItem, res_first, res_last);
  }
}
