#include "ladder.h"

Ladder::Ladder(const string& name, const int& lines) :name(name)
{
	data = new Data(lines);
}

void Ladder::SetLadder(const arr_name& names)
{
	int lines = data->GetLines();
	LadderCode* tmp_lines[LINE_LENGTH];
	arr_name tmp_names = new string[lines];

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		tmp_lines[i] = new LadderCode[lines * 2 - 1];
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < LINE_LENGTH; i++)
	{
		for (int j = 0; j < lines * 2 - 1; j++)
		{
			if (j % 2 == 0)
			{
				tmp_lines[i][j] = VERTICAL;
			}
			else
			{
				// TODO : 랜덤조건 다듬기
				// 이전에 선이 그어졌으면 다음에는 안그어지기
				if (j > 2)
				{
					if (tmp_lines[i][j - 2] == HORIZONTAL)
						tmp_lines[i][j] = BLANK;
					else
					{
						int tmp = rand() % 2 + 1;
						tmp_lines[i][j] = (LadderCode)tmp;
					}
				}
				else
				{
					int tmp = rand() % 2 + 1;
					tmp_lines[i][j] = (LadderCode)tmp;
				}
			}
		}
	}

	for (int i = 0; i < lines; i++)
	{
		tmp_names[i] = names[i];
		
	}
	data->SetData(tmp_names, tmp_lines);
}

void Ladder::ShowResult() const
{
	cout << name << "사다리" << endl << endl;
	data->PrintLadderLines();
	data->PrintLadderLinesNames();
}

bool Ladder::IsCompleted() const
{
	return completed;
}