#include "data.h"

Data::Data(const int& lines):lines(lines)
{

}

Data::~Data()
{
	if (arr_ladder_lines != NULL)
	{
		for (int i = 0; i < LINE_LENGTH; i++)
		{
			delete[] arr_ladder_lines[i];
		}
		delete[] arr_ladder_lines;
	}

	if (arr_ladder_line_names != NULL)
	{
		delete[] arr_ladder_line_names;
	}
}

void Data::SetData(const arr_string& names, const arr_int& ladder_line)
{
	arr_ladder_line_names = new string[lines];
	arr_ladder_lines = new int*[LINE_LENGTH];

	for (int i = 0; i < lines; i++)
	{
		arr_ladder_line_names[i] = names[i];
	}

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		arr_ladder_lines[i] = new int[lines * 2 - 1];
	}

	// TODO : 사다리 라인 채우기
	for (int i = 0; i < LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines * 2 - 1; j++)
		{
			
		}
	}
}

arr_int Data::GetLadderLines() const
{
	return arr_ladder_lines;
}

arr_string Data::GetLadderLineNames() const
{
	return arr_ladder_line_names;
}

int Data::GetLines() const
{
	return lines;
}