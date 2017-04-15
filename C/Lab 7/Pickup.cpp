#include "actions.h"

void Pickup(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "Список клиентов пуст." << std::endl;
		ReturnToMainMenue();
		return;
	}
	if (Li.getfirst()->next == NULL) {
		std::cout << "Нету пары" << std::endl;
		ReturnToMainMenue();
		return;
	}

	Show(Li, true);

	std::cout << "\nВведите номер партнёра: ";
	int num;
	while (!scanf("%d", &num)) {
		rewind(stdin);
		std::cout << "Ошибка! Повторите ввод: ";
	}
	rewind(stdin);
	Person *client = Li.getfirst();
	for (; client; client = client->next) {
		if (client->No == num)
			break;
		if (client->next == NULL) {
			std::cout << "Клиент не найден." << std::endl;
			ReturnToMainMenue();
			return;
		}
	}

	List variants;
	bool keySex = !(client->sex);
	for (Person *curr = Li.getfirst(); curr; curr = curr->next) {

		if (keySex == curr->sex)
			variants.Add(curr);

		if (!(curr->next) && variants.getfirst() == NULL) {
			std::cout << "Для этого клиента только однополые партнёры..." << std::endl;
			ReturnToMainMenue();
			return;
		}
	}

	bool foundKey = false;

	for (Person *curr = variants.getfirst(); curr; curr = curr->next)
		if (abs(curr->year - client->year) <= 3) {
			foundKey = true;
			break;
		}
	if (foundKey) {
		for (Person *curr = variants.getfirst(); curr;) {
			if (abs(curr->year - client->year) > 3) {
				Person *todel = curr;
				curr = curr->next;
				variants.Del(todel);
				continue;
			}
			curr = curr->next;
		}
	}
	else {
		for (Person *curr = variants.getfirst(); curr;) {
			if (abs(curr->year - client->year) > 10){
				Person *todel = curr;
				curr = curr->next;
				variants.Del(todel);
				continue;
			}
			curr = curr->next;
		}
	}
	foundKey = false;

	if (!variants.getfirst()) {
		std::cout << "Алгоритм не нашёл оптимальную пару для клиента." << std::endl;
		ReturnToMainMenue();
		return;
	}

	double clientIndex = client->weight / pow((client->height / 100.0), 2);
	for (Person *curr = variants.getfirst(); curr;) {
		
		double index = curr->weight / pow((curr->height / 100.0), 2);
		
		if (client->sex == MALE) {
			if (clientIndex > 25) {
				if (index <= 24) {
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
			else if (clientIndex < 19) {
				if (index >= 19){
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
			else {
				if (index < 19 || index > 24){
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
		}
		else {
			if (clientIndex > 24) {
				if (index <= 25){
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
			else if (clientIndex < 19) {
				if (index >= 19){
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
			else {
				if (index < 19 || index > 25){
					Person *todel = curr;
					curr = curr->next;
					variants.Del(todel);
					continue;
				}
				curr = curr->next;
			}
		}
	}

	if (!variants.getfirst()) {
		std::cout << "Алгоритм не нашёл оптимальную пару для клиента." << std::endl;
		ReturnToMainMenue();
		return;
	}

	for (Person *curr = variants.getfirst(); curr; curr = curr->next) {
		if ( !strcmp(curr->city, client->city) ) {
			foundKey = true;
			break;
		}
	}
	if (foundKey) {
		for (Person *curr = variants.getfirst(); curr; curr = curr->next) {
			if ( strcmp(curr->city, client->city) ){
				Person *todel = curr;
				curr = curr->next;
				variants.Del(todel);
				continue;
			}
			curr = curr->next;
		}
	}

	if (!variants.getfirst()) {
		std::cout << "Алгоритм не нашёл оптимальную пару для клиента." << std::endl;
	}
	else {
		std::cout << "Оптимальные партнёры для клиента:" << std::endl;
		for (Person *curr = variants.getfirst(); curr; curr = curr->next)
			printf("\t%d %s %s %s\n", curr->No, curr->firstName, curr->lastName, curr->surname);
	}
	ReturnToMainMenue();
	return;
}