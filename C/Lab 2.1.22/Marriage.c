#include<stdio.h>

enum element { Fire, Earth, Air, Water };

void Marriage(int S1, int E1, int S2, int E2){
  if (S1 != S2 && ( (E1 == Fire && E2 == Earth) || (E1 == Earth && E2 == Fire) || (E1 == Air && E2 == Water) || (E1 == Water && E2 == Air) ) )
    printf("Астрологи говорят что у партнёров будет гармоничная семейная жизнь!");
  else if (S1 == S2)
    printf("Это Европа, у нас так можно. Будете жить долго и счастливо!");
  else
    printf("Астрологи решили, что у партнёров плохая совместимость в браке...");

  printf("\n\nEnter - в главное меню");
  getchar();
}
