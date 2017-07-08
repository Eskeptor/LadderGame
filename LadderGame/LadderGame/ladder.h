#pragma once
#include "headers.h"
#include "data.h"

class Ladder
{
private:
	int id;
	string name;
	bool completed;
	Data* data;
public:
	Ladder(const string&, const int&);
	void SetLadder(const arr_string&);
	void ShowResult() const;
	bool IsCompleted() const;

};