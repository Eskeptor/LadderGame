#include "headers.h"
#include "ladder.h"


// TODO : ��ٸ� �ؿ� ���°� �����
// TODO : ��ٸ� ��� �����
void MainMenu()
{
	system("cls");
	cout << "=====================" << endl;
	cout << "1. ��ٸ� ����" << endl;
	cout << "2. ��ٸ� ���" << endl;
	cout << "3. ������ ������ ��ٸ�" << endl;
	cout << "4. ����" << endl;
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
	cout << "������ ��ٸ� �̸� : ";
	cin >> name;
	cout << "������ ���� : ";
	cin >> lines;
	
	line_names = new string[lines];
	ladder = new Ladder(name, lines);

	for (int i = 0; i < lines; i++)
	{
		cout << i + 1 << "��° ���� �̸� : ";
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
			cout << "������ ��ٸ� �̸� : ";
			cin >> name;
			cout << "������ ���� : ";
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
