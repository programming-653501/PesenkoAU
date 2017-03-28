#ifndef DOB_DIR_LIST_H_
#define DOB_DIR_LIST_H_

#include <stddef.h>


/* Structure */

/* Type "struct Data" must be defined in program for correct use */

struct DobDirList{
  struct DobDirList* NEXT;
  struct DobDirList* PREV;
  struct Data* DATA;
};
typedef struct DobDirList DDList;


/* Functions */

void DDLAddToStart(struct Data* data, DDList** first, DDList** last);
void DDLAddToEnd(struct Data* data, DDList* last, DDList* first);
void DDLClear(DDList** start, DDList** end);
void DDLDel(DDList* del, DDList* first, DDList* last);
void DDLShowAll(DDList* end);


/* Implement Find function */

void PrintList(struct Data* data); /* Must be defined in program for printing
                                      all elements of "struct Data" */


#endif
