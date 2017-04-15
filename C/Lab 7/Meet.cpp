#include "actions.h"

void Meet(List& Li) {
	if (Li.getfirst() == NULL || Li.getfirst()->next == NULL) {
		std::cout << "� ������ ��� ���." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Show(Li, true);

	std::cout << "������� ����� ������� �������: ";
	int num1;
	while (!scanf("%d", &num1)) {
		rewind(stdin);
		std::cout << "������! ��������� ����: ";
	}
	rewind(stdin);
	Person *partner1 = Li.getfirst();
	for (; partner1; partner1 = partner1->next) {
		if (partner1->No == num1)
			break;
		if (partner1->next == NULL) {
			std::cout << "������ �� ������." << std::endl;
			ReturnToMainMenue();
			return;
		}
	}

	std::cout << "������� ����� ������� �������: ";
	int num2;
	while (!scanf("%d", &num2)) {
		rewind(stdin);
		std::cout << "������! ��������� ����: ";
	}
	rewind(stdin);
	if (num1 == num2) {
		std::cout << "������ ����� �� �������� � ����� �����!";
		ReturnToMainMenue();
		return;
	}
	Person *partner2 = Li.getfirst();
	for (; partner2; partner2 = partner2->next) {
		if (partner2->No == num2)
			break;
		if (partner2->next == NULL) {
			std::cout << "������ �� ������." << std::endl;
			ReturnToMainMenue();
			return;
		}
	}

	std::cout << "\n��������: " << partner1->firstName << " � " << partner2->lastName << std::endl;
	_sleep(5000);
	bool SEX = true;
	srand(time(0));
	SEX = rand() % 2;
	if (SEX) {
		std::cout << "������ ������! (:" << std::endl;
		std::cout << std::endl << "��������� ��� ���� � �����? (�� - Enter, ��� - Esc)";
		if (Question()){
			ArchUpd(Li, true, partner1, partner2);
			return;
		}
	}
	else {
		std::cout << "������� �� ������� ���� � ������." << std::endl;
	}

	ReturnToMainMenue();
}