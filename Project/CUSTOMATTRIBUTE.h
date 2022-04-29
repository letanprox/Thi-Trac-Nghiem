#include <windows.h>
#include <conio.h>  
#include <iostream>

#ifndef CUSTOMATTRIBUTE_H
#define CUSTOMATTRIBUTE_H

class CUSTOMATTRIBUTE{
    public:
        void setPosionCursor(int x , int y);
        void setBackgroundText(int ForgC, int BackC);
        int  getWidthScreen();
        void DisplayCursor(bool visible);
};

#endif

