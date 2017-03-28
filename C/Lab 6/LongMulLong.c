#include "LongNumber.h"
#include <malloc.h>
#define BILL 1000000000

void DigitShift(DDList **start, DDList **end, int razr);

void LongMulLong(DDList *first, DDList *second, DDList **res_first, DDList **res_last){
  DDList *mult = second;
  int razr = 0;
  struct Data *dumta = (struct Data*) calloc(1, sizeof(struct Data));
  DDList *suk_s = NULL, *suk_e = NULL;
  DDLAddToStart(dumta, &suk_s, &suk_e);

  while(mult){
    int multNum = (mult -> DATA) -> milliard;

    for (int r = 1; r < BILL; r *= 10){
      int cif = (multNum / r) % 10;
	  razr++;
	  if (cif) {
  		DDList *pros_s = NULL, *pros_e = NULL;
  		struct Data *dustap = (struct Data*) calloc(1, sizeof(struct Data));
  		DDList *sss = NULL, *eee = NULL;
  		DDLAddToStart(dustap, &sss, &eee);

  		for (int i = 0; i < cif; i++) {
  			DDList *buf_s = NULL, *buf_e = NULL;
  			LongSumLong(eee, first, &buf_s, &buf_e);
  			DDLClear(&sss, &eee);
  			sss = buf_s; eee = buf_e;
  		}

  		DigitShift(&sss, &eee, razr);
  		LongSumLong(eee, suk_e, &pros_s, &pros_e);
  		DDLClear(&sss, &eee);
  		DDLClear(&suk_s, &suk_e);
  		suk_s = pros_s; suk_e = pros_e;
	  }
    }

    *res_first = suk_s; *res_last = suk_e;
    mult = mult -> PREV;
  }
}

void DigitShift(DDList **start, DDList **end, int razr){
  for (int i = 0; i < razr - 1; i++) {
    int buf1 = 0, buf2 = 0;
	  DDList *curr = *end;

    while (curr){
      buf1 = ((curr -> DATA) -> milliard) / (BILL / 10);
      (curr -> DATA) -> milliard %= (BILL / 10);
      (curr -> DATA) -> milliard *= 10;
      (curr -> DATA) -> milliard += buf2;
      buf2 = buf1;
      curr = curr -> PREV;
    }
    if (buf2){
      struct Data *duta = (struct Data*) malloc(sizeof(struct Data));
      duta -> milliard = buf2;
      DDLAddToStart(duta, start, end);
    }
  }
}
