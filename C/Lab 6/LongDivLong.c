#include "LongNumber.h"
#include <malloc.h>
#define BILL 1000000000

void DivThisShit(DDList* first, DDList* second, DDList** res_first, DDList** res_last, int k1, int k2, int buf1, int buf2);

void LongDivLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last){
  int k1 = 0, k2 = 0, buf1, buf2;
  DDList *curr1 = first, *curr2 = second;

  while (curr1){
    k1++;
    if (!(curr1 -> PREV)){
      buf1 = (curr1 -> DATA) -> milliard;
      goto m2;
    }
    curr1 = curr1 -> PREV;
  }

m2:
  while (curr2){
    k2++;
    if (!(curr2 -> PREV)){
      buf2 = (curr2 -> DATA) -> milliard;
      goto m3;
    }
    curr2 = curr2 -> PREV;
  }

m3:
  if (k2 > k1){
    struct Data *newItem = (struct Data*) calloc(1, sizeof(struct Data));
    DDLAddToStart(newItem, res_first, res_last);
    return;
  }
  if (k1 > k2) {
	  DivThisShit(first, second, res_first, res_last, k1 - 1, k2 - 1, buf1, buf2);
	  return;
  }
  if (k1 == k2){
	if (buf1 > buf2) {
	  DivThisShit(first, second, res_first, res_last, k1 - 1, k2 - 1, buf1, buf2);
	  return;
	}
    if (buf2 > buf1){
      struct Data *newItem = (struct Data*) calloc(1, sizeof(struct Data));
      DDLAddToStart(newItem, res_first, res_last);
      return;
    }
    if (buf1 == buf2){
      while ( ((curr1 -> DATA) -> milliard) == ((curr2 -> DATA) -> milliard) ){
        curr1 = curr1 -> NEXT;
        curr2 = curr2 -> NEXT;
    		if (!curr1 && !curr2) {
    			struct Data* newItem = (struct Data*) malloc(sizeof(struct Data));
				newItem -> milliard = 1;
    			DDLAddToStart(newItem, res_first, res_last);
    			return;
		    }
      }
      if ( ((curr2 -> DATA) -> milliard) > ((curr1 -> DATA) -> milliard) ){
        struct Data *newItem = (struct Data*) calloc(1, sizeof(struct Data));
        DDLAddToStart(newItem, res_first, res_last);
        return;
      }
	  if (((curr1->DATA)->milliard) > ((curr2->DATA)->milliard)) {
		  DivThisShit(first, second, res_first, res_last, k1 - 1, k2 - 1, buf1, buf2);
		  return;
	  }
    }
  }
}


void Sdvig(DDList *defo, DDList **ns, DDList **ne, int k){
  DDList *curr = defo;

  while (curr){
    struct Data* newItem = (struct Data*) malloc(sizeof(struct Data));
    newItem -> milliard = (curr -> DATA) -> milliard;
    DDLAddToStart(newItem, ns, ne);
    curr = curr -> PREV;
  }

  for (int i = 0; i < k; i++){
    DDList *cuuurr = *ns;
    int buf1 = 0, buf2 = 0;
    while (cuuurr){
      buf1 = ((cuuurr -> DATA) -> milliard) % 10;
      (cuuurr -> DATA) -> milliard /= 10;
      (cuuurr -> DATA) -> milliard += buf2 * (BILL / 10);
      buf2 = buf1;

      cuuurr = cuuurr -> NEXT;
    }
    if (!(((*ns) -> DATA) -> milliard)){
      DDList *del = *ns;
      free((*ns) -> DATA);
      *ns = (*ns) -> NEXT;
      free(del);
	  (*ns)->PREV = NULL;
    }
  }
}

int Compare(DDList **first_e, DDList **first_s, DDList *second){
  DDList *curr_f = *first_e, *curr_s = second;
  for(;curr_f -> PREV; curr_f = curr_f -> PREV);
  for(;curr_s -> PREV; curr_s = curr_s -> PREV);
  if ( (curr_f -> DATA) -> milliard < (curr_s -> DATA) -> milliard)
    return 0;
  else {
    DDList *buf_s = NULL, *buf_e = NULL;
    LongSubLong(*first_e, second, &buf_s, &buf_e);
    DDLClear(first_s, first_e);
    *first_s = buf_s;
    *first_e = buf_e;
    return 1;
  }
}

int GetDigit(DDList* num, int dig){
  int a, puf = 1;
  DDList *curr = num;

  for(; dig > 9; dig -= 9)
    curr = curr -> PREV;
  if (dig != 1)
	  for (int i = 1; i < dig; puf *= 10, i++);
  a = ( ((curr -> DATA) -> milliard) / puf ) % 10;
  return a;
}

void DivThisShit(DDList* first, DDList* second, DDList** res_first, DDList** res_last, int k1, int k2, int buf1, int buf2){
  int long1 = 9 * k1, long2 = 9 * k2;
  int i1 = 0, i2 = 0;
  DDList *videl_s = NULL, *videl_e = NULL;

  struct Data* DOTA = (struct Data*) calloc(1, sizeof(struct Data));

  DDList *chtobslojit_s = NULL, *chtobslojit_e = NULL;

  DDLAddToStart(DOTA, res_first, res_last);


  for (int r = 1; buf1 / r; i1++, r *= 10);
  for (int r = 1; buf2 / r; i2++, r *= 10);
  long1 += i1;
  long2 += i2;

  Sdvig(first, &videl_s, &videl_e, long1 - long2);
  for (int i = 0; i <= long1 - long2; i++){
    int shift = 0;
    DDList *bufs = NULL, *bufe = NULL;
    struct Data *plus = (struct Data*) malloc(sizeof(struct Data));
    DDList *schshes = NULL, *schshee = NULL;

    for(; Compare(&videl_e, &videl_s, second); shift++);
    struct Data* duta = (struct Data*) malloc(sizeof(struct Data));
	duta->milliard = shift;
    DDLAddToStart(duta, &bufs, &bufe);
    DigitShift(&bufs, &bufe, (long1 - long2) - i + 1);
    LongSumLong(bufe, *res_last, &chtobslojit_s, &chtobslojit_e);
    DDLClear(&bufs, &bufe);
    DDLClear(res_first, res_last);
    *res_first = chtobslojit_s;
    *res_last = chtobslojit_e;
    chtobslojit_s = NULL;
    chtobslojit_e = NULL;

    DigitShift(&videl_s, &videl_e, 2);
    plus -> milliard = GetDigit(first, (long1 - long2) - i);
    DDLAddToStart(plus, &schshes, &schshee);
    LongSumLong(schshee, videl_e, &chtobslojit_s, &chtobslojit_e);
    DDLClear(&schshes, &schshee);
    DDLClear(&videl_s, &videl_e);
    videl_s = chtobslojit_s;
    videl_e = chtobslojit_e;
    chtobslojit_s = NULL;
    chtobslojit_e = NULL;
  }
  DDLClear(&videl_s, &videl_e);
}
