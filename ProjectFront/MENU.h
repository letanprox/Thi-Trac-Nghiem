#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "CUSTOMATTRIBUTE.h"

using namespace std;

#ifndef MENU_H
#define MENU_H

class MENU{
	private:
	CUSTOMATTRIBUTE* customAttribute;
    public:
	MENU(CUSTOMATTRIBUTE* customAttribute_){
        customAttribute = customAttribute_;
    }
    int  MoveTopItem(int item,int itemEnter,bool inMenu);
    int  MoveBottomItem(int item,int itemEnter,bool inMenu);
    void DisplayItem(int item,int itemEnter,bool inMenu);
    void DisplayItemPart(bool checkMove,bool checkEnter,bool inMenu,int pos_y,int pos_x,int width_menu,string text);

};

#endif
