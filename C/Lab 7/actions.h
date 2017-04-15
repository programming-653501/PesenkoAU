#pragma once

#include <ctime>
#include <cmath>

#include "data.h"
#include "interface.h"

void Show(List, bool other = false);
void Add(List&);
void Edit(List&);
void Del(List&);
void Find(List&);
void Pickup(List&);
void Meet(List&);

void DelNewLine(char *s);

void Input(Person *newPers);