#include "DobDirList.h"
#include <malloc.h>

void DDLAddToStart(struct Data* data, DDList** first, DDList** last){
  DDList *newItem = (DDList*) malloc(sizeof(DDList));
  newItem -> DATA = data;

  if (*first == NULL){
    newItem -> NEXT = NULL;
    newItem -> PREV = NULL;
    *first = newItem;
    *last = newItem;
  }
  else {
    newItem -> PREV = NULL;
    newItem -> NEXT = *first;
    *first = newItem;
    (newItem -> NEXT) -> PREV = *first;
  }
}
