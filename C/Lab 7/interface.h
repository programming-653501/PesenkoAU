#pragma once

#include <iostream>
#include <windows.h>

#define X 0
#define C 15
#define M 3
#define cursor '*'
#define EXIT 11
#define ExitY 1
#define ExitX 2

#include "actions.h"

void gotoxy(short int x, short int y);

void PrintMenue();
void ReturnToMainMenue();
int Select();
void Action(int s, List&, bool&);
bool Question();
bool SaveOnExitQuestion();