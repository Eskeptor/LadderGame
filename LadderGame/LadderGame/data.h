#pragma once
#include "headers.h"

class Data
{
private:
	arr_ladderlines arr_ladder_lines;
	arr_name arr_ladder_line_names;
	int lines;
public:
	Data(const int&);
	~Data();
	void SetData(const arr_name&, const arr_ladderlines&);
	void PrintLadderLines() const;
	void PrintLadderLinesNames() const;
	int GetLines() const;
};