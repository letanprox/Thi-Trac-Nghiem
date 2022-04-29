#include "CONTROL.h"

using namespace std;

void CONTROL::ADDCLASS_CONTROL(char c){
	bool x = false;
	///MOVE ======================================================================================
	if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            AddClass->switchElement(true,false,c);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
		    AddClass->switchElement(true,true,c);
		    x = true;
	    }
	    AddClass->switchElement(false,true,c);
	    x = true;
	}
	///ESC ==========================================================================================
	if((int)c == 27 && x == false){
		dashboard->inMenu = true;
		dashboard->pre_Enter = 2;
        menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        x = true;
	}	
	///ENTER =========================================================================================
	if(c=='\r' && x == false){        
		if(addClassbundle->chose != 3) AddClass->switchElement(true,true,c);
		else{
			if(AddClass->addClass_() == true){
				/////RISE CONSOLE
				consolebundle->top = dashboard->height + 2;
				consolebundle->message = "THEM LOP THANH CONG";
				console->RISE_CONSOLE();
				frame->ClearContent(dashboard->width,dashboard->height);
				AddClass->createElement(dashboard->width);
				addClassbundle->chose = 1;	
			    AddClass->switchElement(false,false,' ');
			}else{
				/////RISE CONSOLE
				consolebundle->top = dashboard->height + 2;
				consolebundle->message = "LOI KHI THEM LOP";
				console->RISE_CONSOLE();
			}
		}
	    x = true;
	}
	///TYPE CHARACTER ===================================================================================
	if(x == false){
	    AddClass->executeElement(c);
        x = true;
	}
}
