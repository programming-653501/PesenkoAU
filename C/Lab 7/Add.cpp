#include "actions.h"

void DelNewLine(char *s) {
	while (*s) {
		if (*s == '\n')
			*s = '\0';
		s++;
	}
}

void Input(Person *newPers) {
	std::cout << "������� �������:" << std::endl;
	fgets(newPers->surname, 11, stdin);
	rewind(stdin);
	DelNewLine(newPers->surname);

	std::cout << "������� ���:" << std::endl;
	fgets(newPers->firstName, 11, stdin);
	rewind(stdin);
	DelNewLine(newPers->firstName);

	std::cout << "������� ��������:" << std::endl;
	fgets(newPers->lastName, 11, stdin);
	rewind(stdin);
	DelNewLine(newPers->lastName);

	std::cout << "��� (�������(Male) - m; �������(Female)- f): ";
	char sexxx = 0;
	std::cin >> sexxx;
	rewind(stdin);
	while (sexxx != 'm' && sexxx != 'M' && sexxx != 'f' && sexxx != 'F') {
		std::cout << "������! ��������� ����: ";
		std::cin >> sexxx;
		rewind(stdin);
	}
	rewind(stdin);
	(sexxx == 'm' || sexxx == 'M') ? newPers->sex = MALE : newPers->sex = FEMALE;

	std::cout << "������� ����� �������� (�����): ";
	while (!scanf("%d", &(newPers->month)) || (newPers->month > 12 || newPers->month < 1)) {
		rewind(stdin);
		std::cout << "��� ������ ������! ��������� ����: ";
	}
	rewind(stdin);

	std::cout << "������� ���� ��������: ";
	while (true) {
		while (!scanf("%d", &(newPers->date)) || newPers->date < 1) {
			rewind(stdin);
			std::cout << "������! ��������� ����: ";
		}
		rewind(stdin);
		if (newPers->month == 2) {
			if (newPers->date > 29) {
				std::cout << "���� ����� ���� � ���� ������! ��������� ����: ";
				continue;
			}
		}
		else {
			if (newPers->month < 8) {
				if (newPers->month % 2 == 1)
					if (newPers->date > 31) {
						std::cout << "���� ����� ���� � ���� ������! ��������� ����: ";
						continue;
					}
				if (newPers->month % 2 == 0)
					if (newPers->date > 30) {
						std::cout << "���� ����� ���� � ���� ������! ��������� ����: ";
						continue;
					}
			}
			else {
				if (newPers->month % 2 == 1)
					if (newPers->date > 30) {
						std::cout << "���� ����� ���� � ���� ������! ��������� ����: ";
						continue;
					}
				if (newPers->month % 2 == 0)
					if (newPers->date > 31) {
						std::cout << "���� ����� ���� � ���� ������! ��������� ����: ";
						continue;
					}
			}
		}
		break;
	}
	rewind(stdin);

	std::cout << "������� ��� ��������: ";
	while (!scanf("%d", &(newPers->year)) || newPers->year > 1999) {
		rewind(stdin);
		std::cout << "Slishkom molodoy! ��������� ����: ";
	}
	rewind(stdin);

	std::cout << "������� ����: ";
	while (!scanf("%d", &(newPers->height))) {
		rewind(stdin);
		std::cout << "������! ��������� ����: ";
	}
	rewind(stdin);

	std::cout << "������� ���: ";
	while (!scanf("%d", &(newPers->weight))) {
		rewind(stdin);
		std::cout << "������! ��������� ����: ";
	}
	rewind(stdin);

	std::cout << "������� �����:" << std::endl;
	fgets(newPers->city, 11, stdin);
	rewind(stdin);
	DelNewLine(newPers->city);

	std::cout << "��������:" << std::endl;
	fgets(newPers->interests, 100, stdin);
	rewind(stdin);
	DelNewLine(newPers->interests);

	std::cout << "������� ��������:" << std::endl;
	fgets(newPers->badHabbits, 100, stdin);
	rewind(stdin);
	DelNewLine(newPers->badHabbits);

	std::cout << "���������� � ����:" << std::endl;
	fgets(newPers->info, 100, stdin);
	rewind(stdin);
	DelNewLine(newPers->info);

	std::cout << "���������� � �������:" << std::endl;
	fgets(newPers->must, 100, stdin);
	rewind(stdin);
	DelNewLine(newPers->must);

	if (newPers->surname[0] == 0) { newPers->surname[0] = '-'; newPers->surname[1] = 0; }
	if (newPers->firstName[0] == 0) { newPers->firstName[0] = '-'; newPers->firstName[1] = 0; }
	if (newPers->lastName[0] == 0) { newPers->lastName[0] = '-'; newPers->lastName[1] = 0; }
	if (newPers->city[0] == 0) { newPers->city[0] = '-'; newPers->city[1] = 0; }
	if (newPers->interests[0] == 0) { newPers->interests[0] = '-'; newPers->interests[1] = 0; }
	if (newPers->badHabbits[0] == 0) { newPers->badHabbits[0] = '-'; newPers->badHabbits[1] = 0; }
	if (newPers->info[0] == 0) { newPers->info[0] = '-'; newPers->info[1] = 0; }
	if (newPers->must[0] == 0) { newPers->must[0] = '-'; newPers->must[1] = 0; }
}

void Add(List &Li) {
	Person *newPers = new Person;
	std::cout << "���������� �������:" << std::endl;

	Input(newPers);

	Li.Add(newPers);
	std::cout << std::endl << "������ ��� ��������.";
	ReturnToMainMenue();
}