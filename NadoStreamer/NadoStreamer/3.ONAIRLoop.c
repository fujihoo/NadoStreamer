#include "ONAIR.h"

void gotoxy(int x, int y)

{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void Renewer_chat(FILE* fp)
{
	for (int i = 19; i > 0; --i)
	{
		memset(str[i], ' ', 128);

		if (str[i] == NULL)
		{
			continue;
		}
		strcpy(str[i], str[i - 1]);
		gotoxy(132, 22 - i);
		printf("                                                                   ");
		gotoxy(132, 22 - i);
		printf("%s", str[i]);
	}
	fgets(str[0], sizeof(str[0]), fp);

	gotoxy(132, 22);
	printf("                                                              ");
	gotoxy(132, 22);
	printf("%s", str[0]);
}

int ONAIR_Day(int* i_Day, int* cnt1)
{
	if (*cnt1 == 0)
	{
		gotoxy(5, 1);
		printf("Day:%d", *i_Day);
		gotoxy(5, 47);
		printf("ÇöÀç ½ÃÃ»ÀÚ ¼ö : 0");
	}
	(*cnt1)++;
	return (*cnt1);
}

int ONAIR_Viewer_Loop(int* i_Inc_View, int* i_Dec_View, int* i_Now_View, int* i_All_View, int* i_Day)
{
	srand((unsigned)time(NULL));

	int diff = 100 * (*i_Day - 1);
	int V_Time = 5000 - diff;



	static int NewTime = 0;
	static int OldTime = 0;

	NewTime = clock();



	if (NewTime - OldTime < V_Time)
	{
		return 1;
	}
	OldTime = NewTime;
	*i_Inc_View += *i_Day * rand() % (4 * (*i_Day));
	*i_Now_View = *i_Inc_View - *i_Dec_View;
	*i_All_View += *i_Inc_View;
	*i_Dec_View += *i_Day * rand() % (2 * (*i_Day));
	if (*i_Now_View >= 0)
	{
		gotoxy(5, 47);
		printf("                      ");
		gotoxy(5, 47);
		printf("ÇöÀç ½ÃÃ»ÀÚ ¼ö : %d", *i_Now_View);
	}
	else
	{
		*i_Now_View = 0;
		return *i_Now_View;
	}
	return 1;
}

int ONAIR_Chat_Loop(int* i_Day, FILE* fp)
{
	int diff = 100 * (*i_Day - 1);
	int C_Time = 10000 - diff;
	static int NewTime = 0;
	static int OldTime = 0;

	NewTime = clock();

	if (NewTime - OldTime < C_Time)
	{
		return 1;
	}
	OldTime = NewTime;
	Renewer_chat(fp);

	return 0;
	/**cnt = Renewer_Chat(*cnt2, fp);
	(*cnt)++;*/
}

int ONAIR_Dona_Loop(int* i_Dona, int* i_Now_Dona, int* i_All_Dona, int* i_Day)
{
	srand(time(NULL));

	int diff = 100 * (*i_Day - 1);
	int D_Time = 40000 - diff;
	char str[256] = { 0 };
	char viewer[28][128] = { "¸ù", "memooo1989", "¤·_¤·7", "Á¤¸»¶û¸»¶û", "¹ßÀå", "ÇÏ¿¬¢ÝÇÇ¾Æ³ë" "ÇìÀÌÁñ·µHi",
						 "ÃÖ±ÔÀÎ", "¸Í¼ö", "ÄáÅä¸¶Åä", "¹é¹¦»ç", "³«Å¸´àÀº»ç¶÷", "ÆäÇÇÆóÇÇ", "»£¹Ù¹ãºü¹Ù",
						 "º°ÀÇ_¸ñ¼Ò¸®", "Autozz", "[HP]¸Á³Ä´¨ÀÌ", "È®ÁøÀÚ¤Ð¤Ð¤Ð", "Nudiustertians", "·ç±â¾ÆÂ¯", "namj9748",
						 "¸¶´Ã²®µ¥±â", "edhu_the_king", "¾È¾¾92" "MarillinKarynh11", "ÈÄÁöÇÊ¸§", "Â¯", "°¨½ºÆ®" };
	static int NewTime = 0;
	static int OldTime = 0;

	NewTime = clock();

	if (NewTime - OldTime < D_Time)
	{
		return 1;
	}
	OldTime = NewTime;
	*i_Dona = (rand() % (300 * (*i_Day))) * 100;
	*i_Now_Dona += *i_Dona;
	*i_All_Dona += *i_Dona;
	gotoxy(150, 1);
	printf("%s´ÔÀÌ %d¿øÀ» ÈÄ¿øÇÏ¼Ì½À´Ï´Ù.\n", viewer[rand() % 28], *i_Dona);
	Sleep(3000);
	gotoxy(150, 1);
	printf("                                                  ");
}

int ONAIR_Image(int* cnt2, FILE* fp2)
{
	if (*cnt2 == 0)
	{
		fp2 = fopen("image.txt", "r");
		for (int i = 0; i < 25; i++)
		{
			char ASCII[30][128];
			gotoxy(150, 25 + i);
			fgets(ASCII[i], sizeof(ASCII[i]), fp2);
			printf("%s", ASCII[i]);
		}
	}
	else
	{
		return 1;
	}
	(*cnt2)++;
	return (*cnt2);
}