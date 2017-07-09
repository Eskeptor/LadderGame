#pragma once
#include <iostream>
#include <string>
#include <ctime>
#define LINE_LENGTH 14

using namespace std;

enum IsComplete
{
	TRUE = 0,
	FALSE = 1
};

enum LadderCode
{
	VERTICAL = 0,
	HORIZONTAL = 1,
	BLANK = 2
};

enum MenuCode
{
	LADDER_CREATE = 1,
	LADDER_PRINT = 2,
	LADDER_PREV = 3,
	LADDER_EXIT = 4
};

typedef string* arr_name;
typedef LadderCode** arr_ladderlines;