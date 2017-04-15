#include "actions.h"

void Meet(List& Li) {
	if (Li.getfirst() == NULL || Li.getfirst()->next == NULL) {
		std::cout << "В списке нет пар." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Show(Li, true);

	std::cout << "Введите номер первого партнёра: ";
	int num1;
	while (!scanf("%d", &num1)) {
		rewind(stdin);
		std::cout << "Ошибка! Повторите ввод: ";
	}
	rewind(stdin);
	Person *partner1 = Li.getfirst();
	for (; partner1; partner1 = partner1->next) {
		if (partner1->No == num1)
			break;
		if (partner1->next == NULL) {
			std::cout << "Клиент не найден." << std::endl;
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
		std::cout << "Клиент пошёл на свидание с самим собой!";
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

	std::cout << "\nСвидание: " << partner1->firstName << " и " << partner2->lastName << std::endl;
	_sleep(5000);
	bool SEX = true;
	srand(time(0));
	SEX = rand() % 2;
	if (SEX) {
		std::cout << "Прошло хорошо! (:" << std::endl;
		std::cout << std::endl << "Перенести эту пару в архив? (Да - Enter, Нет - Esc)";
		if (Question()){
			ArchUpd(Li, true, partner1, partner2);
			return;
		}
	}
	else {
		std::cout << "Клиенты не сошлись друг с другом." << std::endl;
	}

	ReturnToMainMenue();
}