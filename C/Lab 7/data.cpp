#include "data.h"

List::List() {
	first = NULL;
	last = NULL;
	regNum = 1;
}

List Initialize() {
	FILE *f = fopen("Clients.lom", "r");
	while (!f) {
		f = fopen("Clients.lom", "w");
		fclose(f);
		f = fopen("Clients.lom", "r");
	}
	char s[508];
	List newList;
	while (fgets(s, 508, f)) {
		Person *nP = new Person;
		sscanf(s, "%d %s %s %s %d %d %d %d %d %d %s %s %s %s %s", &(nP->No), nP->surname, nP->firstName, nP->lastName,
			&(nP->sex), &(nP->date), &(nP->month), &(nP->year), &(nP->height), &(nP->weight), nP->city, nP->interests,
			nP->badHabbits, nP->info, nP->must);
		newList.Add(nP);
		newList.setregnum(nP->No + 1);
	}
	fclose(f);
	return newList;
}

void List::Add(Person* P) {
	if (!first) {
		P->prev = NULL;
		first = P;
	}
	else {
		P->prev = last;
		P->prev->next = P;
	}
	P->next = NULL;
	last = P;
	P->No = regNum++;
}

void List::Del(Person* todel) {
	if (first == last) {
		first = NULL;
		last = NULL;
	}
	else if (todel == first) {
		todel->next->prev = NULL;
		first = todel->next;
	} 
	else if (todel == last) {
		todel->prev->next = NULL;
		last = todel->prev;
	}
	else {
		todel->next->prev = todel->prev;
		todel->prev->next = todel->next;
	}
	delete todel;
}

void List::Clear() {
	Person *curr = first;
	while (curr) {
		Person *del = curr;
		curr = curr->next;
		delete del;
	}
}

Person* List::getfirst() {
	return first;
}

void List::setregnum(int n) {
	regNum = n;
}

void Save(List sv) {
	FILE *f = NULL;
	while (!f)
		f = fopen("Clients.lom", "w");
	Person *curr = sv.getfirst();
	while (curr) {
		fprintf(f, "%d %s %s %s %d %d %d %d %d %d %s %s %s %s %s\n", curr->No, curr->surname, curr->firstName, curr->lastName,
			curr->sex, curr->date, curr->month, curr->year, curr->height, curr->weight, curr->city, curr->interests,
			curr->badHabbits, curr->info, curr->must);
		curr = curr->next;
	}
	fclose(f);
}