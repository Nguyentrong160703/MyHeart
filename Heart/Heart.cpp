#include <iostream>
#include <Windows.h>
#include <fstream>

#define ColorCode_DarkBlue	
#define ColorCode_DarkGreen		
#define ColorCode_DarkCyan		
#define ColorCode_DarkRed		
#define ColorCode_DarkPink		
#define ColorCode_DarkYellow	
#define ColorCode_DarkWhite		
#define ColorCode_Grey			
#define ColorCode_Blue			
#define ColorCode_Green			
#define ColorCode_Cyan			
#define ColorCode_Red		
#define ColorCode_Pink	
#define ColorCode_Yellow		
#define ColorCode_White			

using namespace std;

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	int i = -1;
	while (true)
	{
		clrscr();
		i = (i + 1) % 15;
		textColor(i);
		ifstream input("heart.txt");
		char st[500];
		while (input.getline(st, 500))
		{
			cout << st << endl;
		}
		Sleep(300);
		input.close();
	}
}
