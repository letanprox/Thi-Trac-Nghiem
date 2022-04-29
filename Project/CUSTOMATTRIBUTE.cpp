#include "CUSTOMATTRIBUTE.h"

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void CUSTOMATTRIBUTE::setPosionCursor(int x , int y){
    HANDLE output  = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(output,position);
}

void CUSTOMATTRIBUTE::setBackgroundText(int ForgC, int BackC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

int  CUSTOMATTRIBUTE::getWidthScreen(){
	int width;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return width;
};

void CUSTOMATTRIBUTE::DisplayCursor(bool visible){
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 10;
	SetConsoleCursorInfo(console,&lpCursor);
}


