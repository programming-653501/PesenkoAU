#include <clocale>
#include <windows.h>

#include "interface.h"
#include "data.h"
#include "actions.h"

int main() {
	List database = Initialize();
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int s = 0;
	bool saved = true;

	while (s != EXIT) {  // EXIT определён в "interface.h"
		s = Select();
		Action(s, database, saved);
	}
	if (!saved)
		if (SaveOnExitQuestion())
			Save(database);

	database.Clear();
    return 0;
}

