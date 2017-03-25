#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct tree{
  char letter;
  struct tree *YoungerSon;
  struct tree *ElderSon;
} Tree;

void GrowTree(Tree **Root, char ch);
void WatchTree(Tree *Root);   /* Для отладки */
void CutTree(Tree *Root);

int FindNods(Tree *Root, char ch);



int main(){
  char str[256];
  char ch;
  int nods;
  Tree *Root = NULL;

  setlocale(LC_ALL, "Russian");
  puts("Введите строку:");
  fgets(str, 256, stdin);

  for (char *w = str; *w != '\n'; w++)
    GrowTree(&Root, *w);

  puts("Введите букву:");
  ch = getchar();
  nods = FindNods(Root, ch);
  if (nods == -1)
    puts("Этой буквы нет в строке.");
  else
    printf("Количетво узлов у этой буквы: %d\n", nods);

  CutTree(Root);

  return 0;
}



void GrowTree(Tree **Root, char ch){
  Tree *newLeaf = (Tree*) calloc(1, sizeof(Tree));
  Tree *Brunch = *Root;
  newLeaf -> letter = ch;
  newLeaf -> ElderSon = NULL;
  newLeaf -> YoungerSon = NULL;

  if (!(*Root)){
    *Root = newLeaf;
    return;
  }

  while(1){
    if (ch < (Brunch -> letter)){
      if (!(Brunch -> YoungerSon)){
        Brunch -> YoungerSon = newLeaf;
        return;
      }
      else {
        Brunch = Brunch -> YoungerSon;
        continue;
      }
    }
    if (ch >= (Brunch -> letter)){
      if (!(Brunch -> ElderSon)){
        Brunch -> ElderSon = newLeaf;
        return;
      }
      else {
        Brunch = Brunch -> ElderSon;
        continue;
      }
    }
  }
}

void WatchTree(Tree *Root){
  if (Root -> YoungerSon)
    WatchTree(Root -> YoungerSon);
  putchar(Root -> letter);
  if (Root -> ElderSon)
    WatchTree(Root -> ElderSon);
}

void CutTree(Tree *Root){
  if (Root -> YoungerSon)
    CutTree(Root -> YoungerSon);
  if (Root -> ElderSon)
    CutTree(Root -> ElderSon);
  free(Root);
}

int CountLeaves(Tree *Node);

int FindNods(Tree *Root, char ch){
  Tree *Brunch = Root;
  int err = 0;

  while ((Brunch -> letter) != ch){
    if (ch < (Brunch -> letter)){
      if (Brunch -> YoungerSon){
        Brunch = Brunch -> YoungerSon;
        continue;
      }
      else {
        err = -1;
        break;
      }
    }
    if (ch > (Brunch -> letter)){
      if (Brunch -> ElderSon){
        Brunch = Brunch -> ElderSon;
        continue;
      }
      else {
        err = -1;
        break;
      }
    }
  }

  if (err)
    return err;
  else
    return CountLeaves(Brunch);
}

int CountLeaves(Tree *Node){
  int leaves = 0;
  if (Node -> YoungerSon){
    leaves++;
    leaves += CountLeaves(Node -> YoungerSon);
  }
  if (Node -> ElderSon){
    leaves++;
    leaves += CountLeaves(Node -> ElderSon);
  }
  return leaves;
}
