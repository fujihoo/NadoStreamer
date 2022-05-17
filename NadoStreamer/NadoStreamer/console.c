#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
// 커서를 해당 위치로 이동
void Goto(int _x, int _y)
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//// 커서의 x, y 위치값을 알려줌
//COORD GetXY(void)
//{
//	COORD pos;
//	CONSOLE_SCREEN_BUFFER_INFO curInfor;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
//	pos.X = curInfor.dwCursorPosition.X;
//	pos.Y = curInfor.dwCursorPosition.Y;
//}
// 화면을 지움
void Clear(void)
{
	system("cls");
}
// 글자색, 배경색 변경 (0 ~ 15까지 총 16색)
void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;
	//배경색과 글자색을 동시에 설정하는 함수 - high 4bit : 배경색, Low 4 bit : 글자색
	// 0x00f0이면 f는 흰색 배경, 0은 검정 글씨
	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}
// 커서를 보이게 하거나 (TRUE), 보이지 않게 (FALSE) 하는 함수
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&cursorInfo);
}
// 콘솔창 사이즈 조정
void SetConsole(int _x, int _y)
{
	char modeCmd[128];
	sprintf_s(modeCmd, sizeof(modeCmd),
		"mode con cols=%d lines=%d", _x, _y);
	system(modeCmd);
}