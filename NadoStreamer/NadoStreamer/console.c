#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
// Ŀ���� �ش� ��ġ�� �̵�
void Goto(int _x, int _y)
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//// Ŀ���� x, y ��ġ���� �˷���
//COORD GetXY(void)
//{
//	COORD pos;
//	CONSOLE_SCREEN_BUFFER_INFO curInfor;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
//	pos.X = curInfor.dwCursorPosition.X;
//	pos.Y = curInfor.dwCursorPosition.Y;
//}
// ȭ���� ����
void Clear(void)
{
	system("cls");
}
// ���ڻ�, ���� ���� (0 ~ 15���� �� 16��)
void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;
	//������ ���ڻ��� ���ÿ� �����ϴ� �Լ� - high 4bit : ����, Low 4 bit : ���ڻ�
	// 0x00f0�̸� f�� ��� ���, 0�� ���� �۾�
	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}
// Ŀ���� ���̰� �ϰų� (TRUE), ������ �ʰ� (FALSE) �ϴ� �Լ�
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&cursorInfo);
}
// �ܼ�â ������ ����
void SetConsole(int _x, int _y)
{
	char modeCmd[128];
	sprintf_s(modeCmd, sizeof(modeCmd),
		"mode con cols=%d lines=%d", _x, _y);
	system(modeCmd);
}