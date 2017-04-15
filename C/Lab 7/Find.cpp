#include "actions.h"

void Match(Person* match, char *key, bool& found, char *check, char *word) {
	char buf[100];
	if (!strcmp(key, check)) {
		found = true;
		std::cout << "В элементе № " << match->No << ", в поле " << word << ": " << key << std::endl;
	}
}

void Find(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "Список клиентов пуст." << std::endl;
		ReturnToMainMenue();
		return;
	}

	std::cout << "Поиск:\n\t";
	char key[100];
	fgets(key, 100, stdin);
	rewind(stdin);
	DelNewLine(key);
	std::cout << std::endl;

	Person *curr;
	bool found = false;

	if (!strcmp(key, "муж")) {
		for (curr = Li.getfirst(); curr; curr = curr->next) {
			if (curr->sex == MALE) {
				found = true;
				std::cout << "В элементе № " << curr->No << ", в поле Пол: муж" << std::endl;
			}
		}
	}

	if (!strcmp(key, "жен")) {
		for (curr = Li.getfirst(); curr; curr = curr->next) {
			if (curr->sex == FEMALE) {
				found = true;
				std::cout << "В элементе № " << curr->No << ", в поле Пол: жен" << std::endl;
			}
		}
	}
	for (curr = Li.getfirst(); curr; curr = curr->next) {
		char buf[100];
		Match(curr, key, found, itoa(curr->No, buf, 10), "Регистрационный номер");
		Match(curr, key, found, curr->surname, "Фамилия");
		Match(curr, key, found, curr->firstName, "Имя");
		Match(curr, key, found, curr->lastName, "Отчество");
		Match(curr, key, found, itoa(curr->date, buf, 10), "Дата рождения");
		Match(curr, key, found, itoa(curr->month, buf, 10), "Месяц рождения");
		Match(curr, key, found, itoa(curr->year, buf, 10), "Год рождения");
		Match(curr, key, found, itoa(curr->height, buf, 10), "Рост");
		Match(curr, key, found, itoa(curr->weight, buf, 10), "Вес");
		Match(curr, key, found, curr->city, "Город");
		Match(curr, key, found, curr->interests, "Интересы");
		Match(curr, key, found, curr->badHabbits, "Вредные привычки");
		Match(curr, key, found, curr->info, "Информация о себе");
		Match(curr, key, found, curr->must, "Требования к партнёру");
	}

	if (!found)
		std::cout << "По вашему запросу элементы не найдены." << std::endl;

	ReturnToMainMenue();
}