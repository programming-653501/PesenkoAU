#include "actions.h"

void Show(List Li, bool other) {
	Person *curr = Li.getfirst();
	printf("№  %10s %10s %10s Пол Дата Рождения Рост Вес %10s\n", "Фамилия", "Имя", "Отчество", "Город");
	while (curr) {
		printf("%-2d %10s %10s %10s %s   %2d.%2d.%4dг %4d %3d %10s\n", curr->No, curr->surname, curr->firstName, curr->lastName,
			curr->sex ? "жен" : "муж", curr->date, curr->month, curr->year, curr->height, curr->weight, curr->city);
		curr = curr->next;
	}
	if (!other) {
		ReturnToMainMenue();
	}
}