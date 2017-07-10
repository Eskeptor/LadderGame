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
	for (int i = 1; i <= lines; i++)
	{
		cout << i << " : " << arr_ladder_line_names[i - 1] << "		";
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
				if (j == 0 && k == 0)
				{
					if (arr_ladder_lines[i][1] == HORIZONTAL)
						cout << "¦§";
					else
						cout << "¦¢";
				}
				else if (j == lines - 1 && k == 0)
				{
					if (arr_ladder_lines[i][lines * 2 - 3] == HORIZONTAL)
						cout << "¦©";
					else
						cout << "¦¢";
				}
				else
				{
					if (arr_ladder_lines[i][k + 2 * j - 1] == HORIZONTAL)
					{
						if (arr_ladder_lines[i][k + 2 * j + 1] == HORIZONTAL)
							cout << "¦«";
						else
							cout << "¦©";
					}
					else if (arr_ladder_lines[i][k + 2 * j] == HORIZONTAL)
						cout << "¦¡";
					else if (arr_ladder_lines[i][k + 2 * j] == BLANK)
						cout << "  ";
					else
					{
						if (arr_ladder_lines[i][k + 2 * j + 1] == HORIZONTAL)
							cout << "¦§";
						else
							cout << "¦¢";
					}
				}
				/*if (arr_ladder_lines[i][k + 2 * j] == VERTICAL)
					cout << "¦¢";
				else if (arr_ladder_lines[i][k + 2 * j] == HORIZONTAL)
					cout << "¦¡";
				else
					cout << "  ";*/
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