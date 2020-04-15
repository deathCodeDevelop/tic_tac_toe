#include "menu.h"

Menu ShowMenu()
{
	int cursorPosition = 0;
	bool menuWork = true;
	Menu menu;

	const int MENU_COUNT = 3;
	const int STRING_COUNT = 5;
	const int CHAR_COUNT = 23;

	char menuText[MENU_COUNT][STRING_COUNT][CHAR_COUNT] =
	{
		{
			"play with friend",
			"play with computer",
			"exit"
		},
		{
			"low",
			"medium",
			"ultra hard big ass",
			"return",
		},
		{
			"i am first",
			"bot first",
			"return",
		},
	};

	int stringCount[3] = { 0, 0, 0 };

	for (int i = 0; i < MENU_COUNT; i++)
	{
		for (size_t j = 0; j < STRING_COUNT; j++)
		{
			if (menuText[i][j][0] == '\0')
			{
				stringCount[i] = j;
				break;
			}
		}
	}

	size_t size = 3;
	char** text = new char* [size];
	int temp[3] = { 0,1,2 };
	int i = 0;
	bool returnMenu;

	do
	{
		menuWork = true;
		returnMenu = false;
		cursorPosition = 0;

		for (int j = 0; j < stringCount[i]; j++)
		{
			text[j] = menuText[i][j];
		}

		ScreenImage(cursorPosition, text, stringCount[i]);

		do
		{
			if (_kbhit())
			{
				Input(cursorPosition, menuWork, stringCount[i], returnMenu, i);
				ScreenImage(cursorPosition, text, stringCount[i]);
			}
		} while (menuWork);

		temp[i] = cursorPosition;

		if (i == 0 && cursorPosition == 0) 
		{
			temp[1] = 0;
			temp[2] = 0;
			break;
		}

		if (!returnMenu) 
			i++;
		else 
			i--;
	} while (i < 3);

	MakeStructure(temp, menu);

	return menu;
}

void ScreenImage(int cursorPosition, char** text, size_t size)
{
	system("cls");

	const int IMAGE_SIZE = 49;
	const int GLOBAL_SPACE = 30;

	ShowSpace(GLOBAL_SPACE); cout << "|\\     /|      |\\     /|(  ____ \\      (  ___  )\n";
	ShowSpace(GLOBAL_SPACE); cout << "( \\   / )      | )   ( || (    \\/      | (   ) |\n";
	ShowSpace(GLOBAL_SPACE); cout << " \\ (_) /       | |   | || (_____       | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << "  ) _ (        ( (   ) )(_____  )      | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << " / ( ) \\        \\ \\_/ /       ) |      | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << "( /   \\ )        \\   /  /\\____) |      | (___) |\n";
	ShowSpace(GLOBAL_SPACE); cout << "|/     \\|         \\_/   \\_______)      (_______)\n\n";

	for (size_t i = 0; i < size; i++)
	{
		int spaceCount = (IMAGE_SIZE - strlen(text[i]) - 4) / 2;

		if (cursorPosition == i)
		{
			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);

			for (size_t j = 0; j < strlen(text[i]) + 4; j++)
			{
				cout << "#";
			}
			cout << endl;

			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);
			cout << "# " << text[i] << " #\n";

			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);

			for (size_t j = 0; j < strlen(text[i]) + 4; j++)
			{
				cout << "#";
			}

			cout << endl;
		}
		else
		{
			cout << endl;
			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);
			cout << "  " << text[i] << "\n\n";
		}
	}

	cout << endl;
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "W OR ARROW UP - UP\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "S OR ARROW UP - DOWN\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "F OR ENTER - CONFIRM\n";
};

void ShowSpace(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << " ";
	}
}

void Input(int& cursorPosition, bool& menuWork, int size, bool& returnMenu, int menuPosition)
{
	switch (_getch())
	{
	case 'w':case 'W':case BUTTON_URROW_UP:
		if (cursorPosition > 0)
		{
			cursorPosition--;
		}
		break;
	case 's':case 'S':case BUTTON_URROW_DOWN:
		if (cursorPosition < size - 1)
		{
			cursorPosition++;
		}

		break;
	case 'f':case 'F':case BUTTON_ENTER:
		if (cursorPosition == size - 1 && menuPosition != 0)
		{
			returnMenu = true;
			menuWork = false;
		}
		else
		{
			menuWork = false;
		}
		break;
	case BUTTON_ESC:
		if (cursorPosition == size - 1 && menuPosition == 0)
		{
			returnMenu = true;
			menuWork = false;
		}
		break;
	}
}

void MakeStructure(int* arr, Menu& menu)
{
	if (arr[0] == 1)
		menu.playWithComputer = true;
	else
		menu.playWithComputer = false;

	menu.difficulty = arr[1];

	if (arr[3] == 1)
		menu.youFirstPlayer = true;
	else
		menu.youFirstPlayer = false;
}