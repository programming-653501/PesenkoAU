#include "DobDirList.h"
#include <malloc.h>

void DDLClear(DDList** start, DDList** end){
  DDList *curr = *start, *del;

  while (curr){
    free(curr -> DATA);
    del = curr;
    curr = curr -> NEXT;
    free(del);
  }

  *start = NULL;
  *end = NULL;
}
