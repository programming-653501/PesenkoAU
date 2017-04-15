#include "interface.h"

#include <conio.h>

short int Y = 3;

void PrintMenue() {
	std::cout << "���� ������ �������� ���������.\n\n������� ����" << std::endl;
	std::cout << "  ����������� ���� ��������" << std::endl;
	std::cout << "  �������� �������" << std::endl;
	std::cout << "  ������������� ���������� � �������" << std::endl;
	std::cout << "  ������� �������" << std::endl;
	std::cout << "  ��������� ����" << std::endl;
	std::cout << "  �����" << std::endl;
	std::cout << "  ��������� �������� ��� �������" << std::endl;
	std::cout << "  ��������� �������" << std::endl;
	std::cout << "  ����������� �����" << std::endl;
	std::cout << "  ��������� ���� � �����" << std::endl;
	gotoxy(X, Y);
	std::cout << cursor;
	gotoxy(X, C - 1);
	std::cout << "Esc - �����.";
	gotoxy(X, C);
}

void gotoxy(short int x, short int y) {
	COORD coordinates = { x, y };
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(outputHandle, coordinates);
}

void navigate(char ch) {
	{
		if (ch == '+')
			gotoxy(X, Y++);
		else
			gotoxy(X, Y--);
	}
	std::cout << ' ';
	gotoxy(X, Y);
	std::cout << cursor;
	gotoxy(X, C);
}

int Select() {
	PrintMenue();
	int action = 0;
	while (action != 13) {
		action = _getch();
		if (action == 224) {
			action = _getch();
			if (action == 72) { //UP
				if (Y > 3)
					navigate('-');
			}
			if (action == 80) { //DOWN
				if (Y < 12)
					navigate('+');
			}
		}
		if (action == 27) {
			system("cls");
			return EXIT;
		}
	}
	system("cls");
	return Y - M;
}

enum { SHOW, ADD, EDIT, DEL, SAVE, FIND, PICKUP, MEET, ARCH, ARCHUPD };

void Action(int s, List& Li, bool& saved) {
	switch (s) {
	case SHOW:
		Show(Li);
		break;
	case ADD:
		Add(Li);
		saved = false;
		break;
	case EDIT:
		Edit(Li);
		saved = false;
		break;
	case DEL:
		Del(Li);
		saved = false;
		break;
	case SAVE:
		Save(Li);
		saved = true;
		std::cout << "���� ��� �������." << std::endl;
		system("Pause");
		system("cls");
		break;
	case FIND:
		Find(Li);
		break;
	case PICKUP:
		Pickup(Li);
		break;
	case MEET:
		Meet(Li);
		break;
	case ARCH:
		Arch(Li);
		break;
	case ARCHUPD:
		ArchUpd(Li);
		break;
	}
}

void ReturnToMainMenue() {
	std::cout << std::endl << "������� Enter ��� �������� � ������� ����." << std::endl;
	while (_getch() != 13);
	system("cls");
}

bool Question() {
	char key = 0;
	while (key != 13 && key != 27) {
		key = _getch();
	}
	if (key == 13)
		return true;
	if (key == 27)
		return false;
}

bool SaveOnExitQuestion() {
	std::cout << "��������� ����� �������?" << std::endl;
	bool YES = true;
	std::cout << "   ��    ���" << std::endl;
	char key = 0;
	gotoxy(ExitX, ExitY);
	std::cout << cursor;
	gotoxy(0, 2);
	while (key != 13) {
		key = _getch();
		if (key == -32) {
			key = _getch();
			if (key == 75) //LEFT
				YES = true;
			if (key == 77) //RIGHT
				YES = false;
		}
		gotoxy(ExitX, ExitY);
		std::cout << ' ';
		gotoxy(ExitX + 6, ExitY);
		std::cout << ' ';
		YES ? gotoxy(ExitX, ExitY) : gotoxy(ExitX + 6, ExitY);
		std::cout << cursor;
		gotoxy(0, 2);
	}
	if (YES)
		return true;
	else
		return false;
}