#include "ladder.h"

Ladder::Ladder(const string& name, const int& lines) :name(name)
{
	data = new Data(lines);
}


// TODO : 사다리 설정 만들기
void Ladder::SetLadder(const arr_string& names)
{
	int lines = data->GetLines();
	srand((unsigned int)time(NULL));

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines * 2 - 1; j++)
		{
			if (j % 2 == 0)
			{

			}
		}
	}
}

void Ladder::ShowResult() const
{
	arr_int line_data = data->GetLadderLines();
	arr_string name_data = data->GetLadderLineNames();
	int lines = data->GetLines();
	
	for (int i = 0; i <= LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (j == lines - 1 && k == 1)
					continue;
				if (i == 0)
				{
					if (k == 0)
						printf("%d", j);
					else
						printf(" ");
				}
				else
					printf("%d", line_data[i - 1][j + k]);
			}
		}
		printf("\n");
	}
}

bool Ladder::IsCompleted() const
{
	return completed;
}