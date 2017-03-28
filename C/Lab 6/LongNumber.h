#ifndef LONG_NUMBER
#define LONG_NUMBER

#include "DobDirList.h"

struct Data {
  int milliard;
};

void EnterLongNumber(DDList** num_s, DDList** num_e);
void LongSumLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last);
void LongSubLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last);
void LongMulLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last);
void LongDivLong(DDList* first, DDList* second, DDList** res_first, DDList** res_last);

void DigitShift(DDList **start, DDList **end, int razr);

#endif
