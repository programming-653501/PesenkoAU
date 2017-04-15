#include "actions.h"

void Arch(List& Li) {
	FILE *ar = fopen("Archive.lom", "r");
	if (!ar) {
		std::cout << "Архив пуст";
		ReturnToMainMenue();
		return;
	}
	char s[508];

	int i = 0, N = 1;
	printf("№  %10s %10s %10s Пол Дата Рождения Рост Вес %10s\n", "Фамилия", "Имя", "Отчество", "Город");
	while (fgets(s, 508, ar)) {
		if (!(i % 2)) {
			std::cout << std::endl << "Пара №" << N++ << std::endl;
		}

		Person *nP = new Person;
		sscanf(s, "%d %s %s %s %d %d %d %d %d %d %s %s %s %s %s", &(nP->No), nP->surname, nP->firstName, nP->lastName,
			&(nP->sex), &(nP->date), &(nP->month), &(nP->year), &(nP->height), &(nP->weight), nP->city, nP->interests,
			nP->badHabbits, nP->info, nP->must);
		printf("%-2d %10s %10s %10s %s   %2d.%2d.%4dг %4d %3d %10s\n", nP->No, nP->surname, nP->firstName, nP->lastName,
			nP->sex ? "жен" : "муж", nP->date, nP->month, nP->year, nP->height, nP->weight, nP->city);

		i++;
	}

	fclose(ar);
	ReturnToMainMenue();
}

void ArchUpd(List& Li, bool other, Person* first, Person* second) {
	Person *partner1, *partner2;

	if (!other) {
		Show(Li, true);

		if (Li.getfirst() == NULL || Li.getfirst()->next == NULL) {
			std::cout << "Нет пар, некого добавлять.";
			ReturnToMainMenue();
			return;
		}

		std::cout << "Введите номер первого партнёра: ";
		int num1;
		while (!scanf("%d", &num1)) {
			rewind(stdin);
			std::cout << "Ошибка! Повторите ввод: ";
		}
		rewind(stdin);
		partner1 = Li.getfirst();
		for (; partner1; partner1 = partner1->next) {
			if (partner1->No == num1)
				break;
			if (partner1->next == NULL) {
				std::cout << "Клиент не найден.";
				ReturnToMainMenue();
				return;
			}
		}

		std::cout << "Введите номер второго партнёра: ";
		int num2;
		while (!scanf("%d", &num2)) {
			rewind(stdin);
			std::cout << "Ошибка! Повторите ввод: ";
		}
		rewind(stdin);
		if (num1 == num2) {
			std::cout << "Клиент не может быть с самим собой!" << std::endl;
			ReturnToMainMenue();
			return;
		}
		Person *partner2 = Li.getfirst();
		for (; partner2; partner2 = partner2->next) {
			if (partner2->No == num2)
				break;
			if (partner2->next == NULL) {
				std::cout << "Клиент не найден." << std::endl;
				ReturnToMainMenue();
				return;
			}
		}
	}
	else {
		partner1 = first;
		partner2 = second;
	}

	std::cout << "Перенести в архив? (Да - Enter, Нет - Esc)" << std::endl;
	if (Question()) {
		FILE *ar = fopen("Archive.lom", "a");

		fprintf(ar, "%d %s %s %s %d %d %d %d %d %d %s %s %s %s %s\n", partner1->No, partner1->surname, partner1->firstName,
			partner1->lastName, partner1->sex, partner1->date, partner1->month, partner1->year, partner1->height, partner1->weight,
			partner1->city, partner1->interests, partner1->badHabbits, partner1->info, partner1->must);

		fprintf(ar, "%d %s %s %s %d %d %d %d %d %d %s %s %s %s %s\n", partner2->No, partner2->surname, partner2->firstName,
			partner2->lastName, partner2->sex, partner2->date, partner2->month, partner2->year, partner2->height, partner2->weight,
			partner2->city, partner2->interests, partner2->badHabbits, partner2->info, partner2->must);

		fclose(ar);

		Li.Del(partner1);
		Li.Del(partner2);

		Save(Li);

		std::cout << "Пара добавлена в архив." << std::endl;
	}
	ReturnToMainMenue();
}