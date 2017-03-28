#include "DobDirList.h"
#include <stdio.h>

void DDLShowAll(DDList* end){
  if (!end){
    puts("List is empty!");
    return;
  }
  DDList* curr = end;
  if (!(end -> PREV)){
    while (curr){
      PrintList(curr -> DATA);
      curr = curr -> NEXT;
    }
  }
  else if (!(end -> NEXT)){
    while (curr){
      PrintList(curr -> DATA);
      curr = curr -> PREV;
    }
  }
}
