#include "headers.h"
#include "ladder.h"


// TODO : 사다리 밑에 쓰는거 만들기
// TODO : 사다리 기록 만들기
void MainMenu()
{
	system("cls");
	cout << "=====================" << endl;
	cout << "1. 사다리 생성" << endl;
	cout << "2. 사다리 출력" << endl;
	cout << "3. 이전에 생성한 사다리" << endl;
	cout << "4. 종료" << endl;
	cout << "=====================" << endl;
	cout << "> ";
}

Ladder* CreateLadder()
{
	int lines;
	string name;
	Ladder* ladder;
	string* line_names;

	system("cls");
	cout << "생성할 사다리 이름 : ";
	cin >> name;
	cout << "생성할 라인 : ";
	cin >> lines;
	
	line_names = new string[lines];
	ladder = new Ladder(name, lines);

	for (int i = 0; i < lines; i++)
	{
		cout << i + 1 << "번째 라인 이름 : ";
		cin >> line_names[i];
	}

	ladder->SetLadder(line_names);
	return ladder;
}

int main(void)
{
	int menu_select;
	bool isFinished = false;
	Ladder* ladder;
	int lines;
	string name;

	while (!isFinished)
	{
		MainMenu();
		cin >> menu_select;

		switch (menu_select)
		{
		case LADDER_CREATE:
			/*system("cls");
			cout << "생성할 사다리 이름 : ";
			cin >> name;
			cout << "생성할 라인 : ";
			cin >> lines;

			ladder = new Ladder(name, lines);*/
			ladder = CreateLadder();
			break;
		case LADDER_PRINT:
			ladder->ShowResult();
			break;
		case LADDER_PREV:

			break;
		case LADDER_EXIT:
			isFinished = true;
			break;
		default:
			break;
		}
	}

	return 0;
}
