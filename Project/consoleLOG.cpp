#include "consoleLOG.h"

using namespace std;

void setPosionCursor(int x , int y){
    HANDLE output  = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(output,position);
}

void setBackgroundText(int ForgC, int BackC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

int getWidthScreen(){
	int width;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return width;
};

void consoleLOG::RISE_CONSOLE(){
	        int width = getWidthScreen();
	        int left  = (width-consolebundle->width_Frame)/2;
            ////DRAW TOP LINE INPUT
		    for (int i = left; i <= width-left ; i++) {
	            setPosionCursor(i,consolebundle->top);
	            if( i == left){
				    cout<< "\xDA";
				}else if( i ==  width-left){
					cout<< "\xBF";
				}else{
					cout<< "\xC4";
				}
            }
            ////DRAW BOTTOM LINE INPUT
            for (int i = left; i <= width-left ; i++) {
	            setPosionCursor(i,consolebundle->top+2);
	            if( i == left){
				    cout<< "\xC0";
				}else if( i ==  width-left){
					cout<< "\xD9";
				}else{
					cout<< "\xC4";
				}
            }

            for(int i = left+2 ; i < width-left-1 ;i++ ){
            	Sleep(10);
                setPosionCursor(i,consolebundle->top+1);
                cout << ".";
			}
	
			setPosionCursor(left+2,consolebundle->top+1);
			cout << consolebundle->message+" ";
			Sleep(570);
            ////CLEAR TOP LINE INPUT
		    for (int h = consolebundle->top; h <= consolebundle->top+2 ; h++) {
		    	for (int i = left; i <= width-left ; i++) {
	                setPosionCursor(i,h);
	                cout << " ";
                }
	        }
}
