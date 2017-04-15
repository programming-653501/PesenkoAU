#pragma once

#include <iostream>
#include <cstdio>
#include <conio.h>

enum {MALE, FEMALE};

struct Person {
	int	   No;				//��������������� �����
	char   surname[11];		//�������
	char   firstName[11];	//���
	char   lastName[11];	//��������
	int    sex;				//��� (:
	int    date;			//���� ��������
	int    month;			//����� ��������
	int    year;			//��� ��������
	int    height;			//����
	int    weight;			//���
	char   city[11];		//�����
	char   interests[100];	//��������
	char   badHabbits[100];	//������� ��������
	char   info[100];		//���������� � ����
	char   must[100];		//���������� � �������
	Person *prev;			//��������� �� ���������� �������
	Person *next;			//��������� �� ����������� �������
};

class List {
	int    regNum;			//��������� ��������������� �����
	Person *first;			//������ ������ � ������
	Person *last;			//��������� ������ � ������
public:
	List();					//������������� ������ ��������
	void Add(Person*);		//���������� ������� � ������
	void Del(Person*);		//������ ��������� �� �����
	void Clear();			//�������� ������ ��������
	Person* getfirst();
	void setregnum(int);
};

List Initialize();			//��������� ����
void Save(List);			//��������� ����

void Arch(List&);																			//�������� �����
void ArchUpd(List& Li, bool other = false, Person* first = NULL, Person* second = NULL);	//��������� ���� � �����