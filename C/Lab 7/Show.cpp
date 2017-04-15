#include "actions.h"

void Show(List Li, bool other) {
	Person *curr = Li.getfirst();
	printf("�  %10s %10s %10s ��� ���� �������� ���� ��� %10s\n", "�������", "���", "��������", "�����");
	while (curr) {
		printf("%-2d %10s %10s %10s %s   %2d.%2d.%4d� %4d %3d %10s\n", curr->No, curr->surname, curr->firstName, curr->lastName,
			curr->sex ? "���" : "���", curr->date, curr->month, curr->year, curr->height, curr->weight, curr->city);
		curr = curr->next;
	}
	if (!other) {
		ReturnToMainMenue();
	}
}