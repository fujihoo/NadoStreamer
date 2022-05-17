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
		gotoxy(136, 22 - i);
		printf("                                                                   ");
		gotoxy(136, 22 - i);
		printf("%s", str[i]);
	}
	fgets(str[0], sizeof(str[0]), fp);

	gotoxy(136, 22);
	printf("                                                              ");
	gotoxy(136, 22);
	printf("%s", str[0]);
}

//int Renewer_chat(FILE* fp)
//{
//	char* str[20][128] = { " " };
//	int i;
//	int j;
//
//	fgets(str, sizeof(str), fp);
//	for (i = 0; i < 19; i++)
//	{
//		if (!strcmp(str[i], " "))
//		{
//			continue;
//		}
//		strcpy(str[0], fscanf(fp, str));
//		strcpy(str[i + 1], str[i]);
//		for (j = 0; j < 20; j++)
//		{
//			gotoxy(136, 22 - j);
//			printf("                                                              ");
//		}
//		gotoxy(136, 22 - i);
//		printf("%s", str[i]);
//	}
//}

//int Renewer_Chat(int* cnt, FILE* fp)
//{
//	*cnt = 0;
//	char str[20][128] = { 0 };
//
//	for (int i = 0; i < 20; i++)
//	{
//		if (!strcmp(str[i], " "))
//		{
//			continue;
//		}
//		gotoxy(136, 2 + i);
//		printf("                                       ");
//	}
//	if (*cnt >= 18)
//	{
//		return (*cnt);
//	}
//	gotoxy(136, 2 + *cnt);
//	str[*cnt + 1][127] = str[*cnt][127];
//	str[0][127] = fgets(str, sizeof(str), fp);
//	printf("%s", *str);
//}

int ONAIR_Day(int* i_Day, int* cnt1)
{
	if (*cnt1 == 0)
	{
		gotoxy(5, 1);
		printf("Day:%d", *i_Day);
		gotoxy(5, 47);
		printf("���� ��û�� �� : 0");
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
	*i_Inc_View += *i_Day * rand() % (3 * (*i_Day));
	*i_Now_View = *i_Inc_View - *i_Dec_View;
	*i_All_View += *i_Inc_View;
	*i_Dec_View += *i_Day * rand() % (3 * (*i_Day));
	if (*i_Now_View >= 0)
	{
		gotoxy(5, 47);
		printf("                      ");
		gotoxy(5, 47);
		printf("���� ��û�� �� : %d", *i_Now_View);
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
	char viewer[28][128] = { "��", "memooo1989", "��_��7", "����������", "����", "�Ͽ����ǾƳ�" "������Hi",
						 "�ֱ���", "�ͼ�", "���丶��", "�鹦��", "��Ÿ�������", "��������", "���ٹ����",
						 "����_��Ҹ�", "Autozz", "[HP]���Ĵ���", "Ȯ���ڤФФ�", "Nudiustertians", "����¯", "namj9748",
						 "���ò�����", "edhu_the_king", "�Ⱦ�92" "MarillinKarynh11", "�����ʸ�", "¯", "����Ʈ" };
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
	printf("%s���� %d���� �Ŀ��ϼ̽��ϴ�.\n", viewer[rand() % 28], *i_Dona);
	Sleep(3000);
	gotoxy(150, 1);
	printf("                                                  ");
}

int image(int* cnt2, FILE* fp2)
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