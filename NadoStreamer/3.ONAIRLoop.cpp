#include "ONAIR.h"


int ONAIR_Loop(int* i_Dona, int* i_Now_Dona, int* i_All_Dona, int* i_Inc_View, int* i_Dec_View, int* i_Now_View, int* i_All_View, int* i_Day)
{
	FILE* fp;
	char str[256] = { 0 };

	fp = fopen("./a.txt", "r");

	while (1)
	{
		for (int i = 0; i < 10; i++)			// �����̼�
		{
			if (i != 0)
			{
				*i_Dona = (rand() % (300 * (*i_Day))) * 100;
				*i_Now_Dona += *i_Dona;
				*i_All_Dona += *i_Dona;
				printf("%d���� �Ŀ��ϼ̽��ϴ�.\n", *i_Dona);
			}
			for (int j = 0; j < 4 * (*i_Day); j++)		// ä��
			{
				if (j != 0)
				{
					fgets(str, sizeof(str), fp);
					printf("%s", str);
				}
				for (int k = 0; k < 3; k++)	// ��û�� �� ����
				{
					printf("Day : %d\n", *i_Day);			// �ʱ� �� ǥ��
					printf("���� ��û�� �� : %d\n", *i_Now_View);

					//Sleep(5000 / *i_Day);
					system("cls");

					*i_Inc_View += *i_Day * rand() % (3 * (*i_Day));
					*i_Now_View = *i_Inc_View - *i_Dec_View;
					*i_All_View += *i_Inc_View;
					printf("Day : %d\n", *i_Day);
					if (*i_Now_View >= 0)
					{
						printf("���� ��û�� �� : %d\n", *i_Now_View);
					}
					else
					{
						*i_Now_View = 0;
						printf("���� ��û�� �� : %d\n", *i_Now_View);
					}
					*i_Dec_View += *i_Day * rand() % (3 * (*i_Day));

					//Sleep(5000 / *i_Day);
					system("cls");
				}
			}
		}
		// �Ϸ縦 ��ħ
		printf("��� ������ �ҰԿ�");
		printf("���� ��û�� �� : %d\n", *i_All_View);
		*i_Day++;
		if (*i_Day > 30)
		{
			fclose("./a.text");
			return 0;
		}
	}
}

