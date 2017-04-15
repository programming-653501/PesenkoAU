#include "actions.h"

Person* Select(List& Li) {
	Show(Li, true);
	std::cout << "Выберите номер: ";
	int num;
	while (!scanf("%d", &num)) {
		rewind(stdin);
		std::cout << "Ошибка! Повторите ввод: ";
	}
	rewind(stdin);
	Person *curr = Li.getfirst();
	for (; curr; curr = curr->next) {
		if (curr->No == num)
			break;
		if (curr->next == NULL) {
			std::cout << "Элемент не найден." << std::endl;
			ReturnToMainMenue();
			return NULL;
		}
	}
	return curr;
}

void Edit(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "Список клиентов пуст." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Person* curr = Select(Li);
	if (!curr) return;

	std::cout << std::endl << "Изменение информации о клиенте:" << std::endl;

	Input(curr);

	std::cout << std::endl << "Информация о клиенте была изменена." << std::endl;
	ReturnToMainMenue();
}

void Del(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "Список клиентов пуст." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Person* curr = Select(Li);
	if (!curr) return;

	std::cout << "Удалить клиента? (Да - Enter, Нет - Esc)";
	if (Question()) {
		Li.Del(curr);
		std::cout << std::endl << "Клиенте был удалён." << std::endl;
	}
	ReturnToMainMenue();
}