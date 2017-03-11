#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



enum menue { show = 1, person1, person2, zodiac, friendship, business, marriage, about };
enum sex { male = 1, female };
enum zodiac { Aries = 1, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpius, Sagittarius, Capricornus, Aquarius, Pisces };
enum element { Fire, Earth, Air, Water };

void cls();
void clean_stdin();
void print_menue();

void show_partner(int *D, int *M, int *S);
void show_zodiac(int Z);
void show_info();

int Element(int Z);
extern int Zodiac(int D, int M);
extern void PersonInfo(int* Date, int* Month, int* SEX);
extern void Friendship(int E1, int E2);
extern void Business(int Z1, int Z2);
extern void Marriage(int S1, int E1, int S2, int E2);



int main(){
  int select = 3;
  int DateFirst, MonthFirst, SexFirst, ZodiacFirst, ElementFirst;
  int DateSecond, MonthSecond, SexSecond, ZodiacSecond, ElementSecond;

  setlocale(LC_ALL, "Russian");
  cls();
  printf("Вы открыли программу \"Гороскоп!\"\nСначала введите данные двух партнёров:\n\n");
  printf("Ввод инфомации о первом партнёре:\n");
  PersonInfo(&DateFirst, &MonthFirst, &SexFirst);
  printf("Ввод инфомации о втором партнёре:\n");
  PersonInfo(&DateSecond, &MonthSecond, &SexSecond);
  ZodiacFirst = Zodiac(DateFirst, MonthFirst);
  ZodiacSecond = Zodiac(DateSecond, MonthSecond);
  ElementFirst = Element(ZodiacFirst);
  ElementSecond = Element(ZodiacSecond);

  while (select){
    cls();
    print_menue();
    while (!scanf("%d", &select) || (select > 8 || select < 0)){
      clean_stdin();
      printf("Ошибка! Повторите ввод: ");
    }
    clean_stdin();
    cls();

    switch(select){
      case show:
        printf("Первый партнёр:\n");
        show_partner(&DateFirst, &MonthFirst, &SexFirst);
        printf("Второй партнёр:\n");
        show_partner(&DateSecond, &MonthSecond, &SexSecond);
        printf("\nEnter - в главное меню");
        getchar();
        break;
      case person1:
        printf("Изменение инфомации о первом партнёре:\n");
        PersonInfo(&DateFirst, &MonthFirst, &SexFirst);
        ZodiacFirst = Zodiac(DateFirst, MonthFirst);
        ElementFirst = Element(ZodiacFirst);
        break;
      case person2:
        printf("Изменение инфомации о втором партнёре:\n");
        PersonInfo(&DateSecond, &MonthSecond, &SexSecond);
        ZodiacSecond = Zodiac(DateSecond, MonthSecond);
        ElementSecond = Element(ZodiacSecond);
        break;
      case zodiac:
        printf("Первый партнёр: ");
        show_zodiac(ZodiacFirst);
        printf("Второй партнёр: ");
        show_zodiac(ZodiacSecond);
        printf("\nEnter - в главное меню");
        getchar();
        break;
      case friendship:
        Friendship(ElementFirst, ElementSecond);
        break;
      case business:
        Business(ZodiacFirst, ZodiacSecond);
        break;
      case marriage:
        Marriage(SexFirst, ElementFirst, SexSecond, ElementSecond);
        break;
      case about:
        show_info();
        break;
    }
  }
  cls();
  return 0;
}



void cls(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void clean_stdin(){
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

void print_menue(){
  printf("Гороскоп!\n\nГлавное меню:\n");
  printf("\t1. Вывести информацию о партнёрах.\n");
  printf("\t2. Изменить данные первого партнёра.\n");
  printf("\t3. Изменить данные второго партнёра.\n");
  printf("\t4. Показать знаки зодиака партнёров.\n");
  printf("\t5. Решение, возможна ли между партнёрами дружба.\n");
  printf("\t6. Решение, подходят ли они друг другу в бизнесе.\n");
  printf("\t7. Решение, смогут ли они жить в браке.\n");
  printf("\t8. О программе.\n");
  printf("\t0. Выход\n\n");
  printf("Ваше действие: ");
}

int Element(int Z){
  switch(Z){
    case Aries:
    case Leo:
    case Sagittarius:
      return Fire;
    case Capricornus:
    case Taurus:
    case Virgo:
      return Earth;
    case Libra:
    case Aquarius:
    case Gemini:
      return Air;
    case Cancer:
    case Scorpius:
    case Pisces:
      return Water;
  }
}

void show_partner(int *D, int *M, int *S){
  printf("\tПол: ");
  *S == 1 ? printf("Мужской\n") : printf("Женский\n");
  printf("\tДата рождения: %d ", *D);
  switch(*M){
    case 1: printf("Января"); break;
    case 2: printf("Февраля"); break;
    case 3: printf("Марта"); break;
    case 4: printf("Апреля"); break;
    case 5: printf("Мая"); break;
    case 6: printf("Июня"); break;
    case 7: printf("Июля"); break;
    case 8: printf("Августа"); break;
    case 9: printf("Сентября"); break;
    case 10: printf("Октября"); break;
    case 11: printf("Ноября"); break;
    case 12: printf("Декабря"); break;
  }
  putchar('\n');
}

void show_zodiac(int Z){
  switch(Z){
    case Aries: puts("Овен"); break;
    case Taurus: puts("Телец"); break;
    case Gemini: puts("Близнецы"); break;
    case Cancer: puts("Рак"); break;
    case Leo: puts("Лев"); break;
    case Virgo: puts("Дева"); break;
    case Libra: puts("Весы"); break;
    case Scorpius: puts("Скорпион"); break;
    case Sagittarius: puts("Стрелец"); break;
    case Capricornus: puts("Козерог"); break;
    case Aquarius: puts("Водолей"); break;
    case Pisces: puts("Рыбы"); break;
  }
}

void show_info(){
  printf("#------------------------------------------------------------------------------#\n");
  printf("\"Гороскоп!\" Версия 1.0. 2017.\n");
  printf("Автор: Песенко Алексей Юрьевич\n");
  printf("Автор о программе: Докатился! Разбираюсь в астрономии и астрофизике, ни капли не верю в гороскопы...\n");
  printf("Запиливаю гороскопы...\n");
  printf("#------------------------------------------------------------------------------#\n\n");
  printf("Enter - в главное меню");
  getchar();
}
