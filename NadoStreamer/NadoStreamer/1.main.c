#include "GAME.h"
#include <locale.h>

int Opening();
int GAME_Loop();
int ONAIR_Day(int *, int *);
int ONAIR_Viewer_Loop(int *, int *, int *, int *, int *);
int ONAIR_Chat_Loop(int *, FILE *);
int ONAIR_Dona_Loop(int *, int *, int *, int *);
int ONAIR_Image(int *, FILE *);

int main(void)
{
	system("mode con cols=200 lines=50");
	setlocale(LC_ALL, "");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

	int i_dona = 0;
	int i_now_dona = 0;
	int i_all_dona = 0;
	int i_inc_view = 0;
	int i_dec_view = 0;
	int i_now_view = 0;
	int i_all_view = 0;
	int i_day = 1;
	int cnt1 = 0;
	int cnt2 = 0;

	fp = fopen("a.txt", "r");

	for (int i = 0; i < 20; i++)
	{
		while (1)
		{

			if (_kbhit())//(GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				if (_getch() == 32)
				{
					i_day++;

					cnt1 = 0;
					cnt2 = 0;
					memset(str, 0, sizeof(str));
					system("cls");
					break;
				}
			}
			cnt1 = ONAIR_Day(&i_day, &cnt1);
			cnt2 = ONAIR_Image(&cnt2, fp2);
			if (!(ONAIR_Viewer_Loop(&i_inc_view, &i_dec_view, &i_now_view, &i_all_view, &i_day)))
			{
				continue;
			}
			ONAIR_Chat_Loop(&i_day, fp);
			ONAIR_Dona_Loop(&i_dona, &i_now_dona, &i_all_dona, &i_day);
 		}
	}
}