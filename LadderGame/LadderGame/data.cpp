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

void Data::SetData(const arr_name& names, const arr_ladderlines& ladder_line)
{
	arr_ladder_line_names = new string[lines];
	arr_ladder_lines = new LadderCode*[LINE_LENGTH];

	for (int i = 0; i < lines; i++)
	{
		arr_ladder_line_names[i] = names[i];
	}

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		arr_ladder_lines[i] = new LadderCode[lines * 2 - 1];
	}

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines * 2 - 1; j++)
		{
			arr_ladder_lines[i][j] = ladder_line[i][j];
		}
	}
}

void Data::PrintLadderLinesNames() const
{
	for (int i = 0; i < lines; i++)
	{
		cout << i << " : " << arr_ladder_line_names[i] << "    ";
		if (i % 2 == 0)
			cout << endl;
	}
	cout << endl;
	system("pause");
}

void Data::PrintLadderLines() const
{
	for (int i = 0; i < lines; i++)
	{
		cout << i << "   ";
	}
	cout << endl;

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (k == 1 && j == lines - 1)
					continue;
				// TODO : 라인을 그을때 이전과 연결되면 다음도 연결되게 그려지기
				if (arr_ladder_lines[i][k + 2 * j] == VERTICAL)
					cout << "│";
				else if (arr_ladder_lines[i][k + 2 * j] == HORIZONTAL)
					cout << "─";
				else
					cout << "  ";
				//cout << arr_ladder_lines[i][k + 2 * j];
			}
		}
		cout << endl;
	}
}

int Data::GetLines() const
{
	return lines;
}