#include "ONAIR.h"


int ONAIR_Loop(int* i_Dona, int* i_Now_Dona, int* i_All_Dona, int* i_Inc_View, int* i_Dec_View, int* i_Now_View, int* i_All_View, int* i_Day)
{
	FILE* fp;
	char str[256] = { 0 };

	fp = fopen("./a.txt", "r");

	while (1)
	{
		for (int i = 0; i < 10; i++)			// 도네이션
		{
			if (i != 0)
			{
				*i_Dona = (rand() % (300 * (*i_Day))) * 100;
				*i_Now_Dona += *i_Dona;
				*i_All_Dona += *i_Dona;
				printf("%d원을 후원하셨습니다.\n", *i_Dona);
			}
			for (int j = 0; j < 4 * (*i_Day); j++)		// 채팅
			{
				if (j != 0)
				{
					fgets(str, sizeof(str), fp);
					printf("%s", str);
				}
				for (int k = 0; k < 3; k++)	// 시청자 수 증감
				{
					printf("Day : %d\n", *i_Day);			// 초기 값 표시
					printf("현재 시청자 수 : %d\n", *i_Now_View);

					//Sleep(5000 / *i_Day);
					system("cls");

					*i_Inc_View += *i_Day * rand() % (3 * (*i_Day));
					*i_Now_View = *i_Inc_View - *i_Dec_View;
					*i_All_View += *i_Inc_View;
					printf("Day : %d\n", *i_Day);
					if (*i_Now_View >= 0)
					{
						printf("현재 시청자 수 : %d\n", *i_Now_View);
					}
					else
					{
						*i_Now_View = 0;
						printf("현재 시청자 수 : %d\n", *i_Now_View);
					}
					*i_Dec_View += *i_Day * rand() % (3 * (*i_Day));

					//Sleep(5000 / *i_Day);
					system("cls");
				}
			}
		}
		// 하루를 마침
		printf("방송 마무리 할게요");
		printf("누적 시청자 수 : %d\n", *i_All_View);
		*i_Day++;
		if (*i_Day > 30)
		{
			fclose("./a.text");
			return 0;
		}
	}
}

