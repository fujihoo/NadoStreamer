#include "ONAIR.h"

void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

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
}

int ONAIR_Chat_Loop(int* i_Day, FILE* fp, int* cnt2)
{
	int diff = 100 * (*i_Day - 1);
	int C_Time = 10000 - diff;
	char str[256] = { 0 };
	static int NewTime = 0;
	static int OldTime = 0;

	NewTime = clock();

	if (NewTime - OldTime < C_Time)
	{
		return 1;
	}
	OldTime = NewTime;
	fgets(str, sizeof(str), fp);
	gotoxy(136, 22 - (*cnt2));
	printf("%s", str);
	(*cnt2)++;

	return (*cnt2);
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