#pragma once

#include <iostream>
#include <cstdio>
#include <conio.h>

enum {MALE, FEMALE};

struct Person {
	int	   No;				//Регистрационный номер
	char   surname[11];		//Фамилия
	char   firstName[11];	//Имя
	char   lastName[11];	//Отчество
	int    sex;				//Пол (:
	int    date;			//Дата рождения
	int    month;			//Месяц рождения
	int    year;			//Год рождения
	int    height;			//Рост
	int    weight;			//Вес
	char   city[11];		//Город
	char   interests[100];	//Интересы
	char   badHabbits[100];	//Вредные привычки
	char   info[100];		//Информация о себе
	char   must[100];		//Требования к партнёру
	Person *prev;			//Указатель на следующего клиента
	Person *next;			//Указатель на предыдущего клиента
};

class List {
	int    regNum;			//Следующий регистрационный номер
	Person *first;			//Первый клиент в списке
	Person *last;			//Последний клиент в списке
public:
	List();					//Инициализация списка клиентов
	void Add(Person*);		//Добавление клиента в список
	void Del(Person*);		//Клиент отказался от услуг
	void Clear();			//Очистить список клиентов
	Person* getfirst();
	void setregnum(int);
};

List Initialize();			//Загрузить файл
void Save(List);			//Сохранить файл

void Arch(List&);																			//Показать архив
void ArchUpd(List& Li, bool other = false, Person* first = NULL, Person* second = NULL);	//Перенести пару в архив