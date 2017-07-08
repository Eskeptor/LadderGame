#pragma once
#include "headers.h"

class Data
{
private:
	arr_int arr_ladder_lines;
	arr_string arr_ladder_line_names;
	int lines;
public:
	Data(const int&);
	~Data();
	void SetData(const arr_string&, const arr_int&);
	arr_int GetLadderLines() const;
	arr_string GetLadderLineNames() const;
	int GetLines() const;
};