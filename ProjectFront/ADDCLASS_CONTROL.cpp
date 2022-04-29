#include "CONTROL.h"

using namespace std;

void CONTROL::ADDCLASS_CONTROL(char c){
	
	bool x = false;
	
	if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            addClassbundle->chose = 1;
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
		    addClassbundle->chose = 2;
		    x = true;
	    }
	    AddClass->switchElement(c);
	    x = true;
	}
	
	///ESC
	if((int)c == 27 && x == false){
		dashboard->inMenu = true;
        menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
		addClassbundle->chose = 0;
		customAttribute->setPosionCursor(0,0);
        x = true;
	}	
	
	///ENTER
	if(c=='\r' && x == false){          	
		if(addClassbundle->chose == 1){
			addClassbundle->chose = 2;
			AddClass->switchElement(' ');
		} 
	    x = true;
	}
	
	///TYPE CHARACTER
	if(x == false){
	    AddClass->executeElement(c);
        dashboard->current_height = addClassbundle->height;
        frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
        dashboard->height = dashboard->current_height;
        AddClass->switchElement(' ');
        x = true;
	}
}

