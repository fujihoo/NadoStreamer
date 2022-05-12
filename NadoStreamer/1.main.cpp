#include "GAME.h"
#include <locale.h>

int Opening();
int GAME_Loop();
int ONAIR_Loop(int*, int*, int*, int*, int*, int*, int*, int*);

int main(void)
{
	setlocale(LC_ALL, "");
	int i_dona = 0;
	int i_now_dona = 0;
	int i_all_dona = 0;
	int i_inc_view = 0;
	int i_dec_view = 0;
	int i_now_view = 0;
	int i_all_view = 0;
	int i_day = 1;

	ONAIR_Loop(&i_dona, &i_now_dona, &i_all_dona, &i_inc_view, &i_dec_view, &i_now_view, &i_all_view, &i_day);
}