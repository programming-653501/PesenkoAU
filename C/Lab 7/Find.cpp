#include "actions.h"

void Match(Person* match, char *key, bool& found, char *check, char *word) {
	char buf[100];
	if (!strcmp(key, check)) {
		found = true;
		std::cout << "� �������� � " << match->No << ", � ���� " << word << ": " << key << std::endl;
	}
}

void Find(List& Li) {
	if (Li.getfirst() == NULL) {
		std::cout << "������ �������� ����." << std::endl;
		ReturnToMainMenue();
		return;
	}

	std::cout << "�����:\n\t";
	char key[100];
	fgets(key, 100, stdin);
	rewind(stdin);
	DelNewLine(key);
	std::cout << std::endl;

	Person *curr;
	bool found = false;

	if (!strcmp(key, "���")) {
		for (curr = Li.getfirst(); curr; curr = curr->next) {
			if (curr->sex == MALE) {
				found = true;
				std::cout << "� �������� � " << curr->No << ", � ���� ���: ���" << std::endl;
			}
		}
	}

	if (!strcmp(key, "���")) {
		for (curr = Li.getfirst(); curr; curr = curr->next) {
			if (curr->sex == FEMALE) {
				found = true;
				std::cout << "� �������� � " << curr->No << ", � ���� ���: ���" << std::endl;
			}
		}
	}
	for (curr = Li.getfirst(); curr; curr = curr->next) {
		char buf[100];
		Match(curr, key, found, itoa(curr->No, buf, 10), "��������������� �����");
		Match(curr, key, found, curr->surname, "�������");
		Match(curr, key, found, curr->firstName, "���");
		Match(curr, key, found, curr->lastName, "��������");
		Match(curr, key, found, itoa(curr->date, buf, 10), "���� ��������");
		Match(curr, key, found, itoa(curr->month, buf, 10), "����� ��������");
		Match(curr, key, found, itoa(curr->year, buf, 10), "��� ��������");
		Match(curr, key, found, itoa(curr->height, buf, 10), "����");
		Match(curr, key, found, itoa(curr->weight, buf, 10), "���");
		Match(curr, key, found, curr->city, "�����");
		Match(curr, key, found, curr->interests, "��������");
		Match(curr, key, found, curr->badHabbits, "������� ��������");
		Match(curr, key, found, curr->info, "���������� � ����");
		Match(curr, key, found, curr->must, "���������� � �������");
	}

	if (!found)
		std::cout << "�� ������ ������� �������� �� �������." << std::endl;

	ReturnToMainMenue();
}