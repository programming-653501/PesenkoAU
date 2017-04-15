#include "actions.h"

Person* Select(List& Li) {
	Show(Li, true);
	std::cout << "�������� �����: ";
	int num;
	while (!scanf("%d", &num)) {
		rewind(stdin);
		std::cout << "������! ��������� ����: ";
	}
	rewind(stdin);
	Person *curr = Li.getfirst();
	for (; curr; curr = curr->next) {
		if (curr->No == num)
			break;
		if (curr->next == NULL) {
			std::cout << "������� �� ������." << std::endl;
			ReturnToMainMenue();
			return NULL;
		}
	}
	return curr;
}

void Edit(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "������ �������� ����." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Person* curr = Select(Li);
	if (!curr) return;

	std::cout << std::endl << "��������� ���������� � �������:" << std::endl;

	Input(curr);

	std::cout << std::endl << "���������� � ������� ���� ��������." << std::endl;
	ReturnToMainMenue();
}

void Del(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "������ �������� ����." << std::endl;
		ReturnToMainMenue();
		return;
	}

	Person* curr = Select(Li);
	if (!curr) return;

	std::cout << "������� �������? (�� - Enter, ��� - Esc)";
	if (Question()) {
		Li.Del(curr);
		std::cout << std::endl << "������� ��� �����." << std::endl;
	}
	ReturnToMainMenue();
}