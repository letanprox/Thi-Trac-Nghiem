#include "CONTROL.h"

using namespace std;

int i = 0;

void CONTROL::MENU_CONTROL(char c){
	
    bool x = false;
    
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
		    dashboard->item = menu->MoveTopItem(dashboard->item,dashboard->itemEnter,dashboard->inMenu);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
		    dashboard->item = menu->MoveBottomItem(dashboard->item,dashboard->itemEnter,dashboard->inMenu);
		    x = true;
	    }	
	    x = true;
	}
	
	///ENTER
	if(c=='\r' && x == false){
	    dashboard->inMenu = false;
	    dashboard->itemEnter = dashboard->item;
        dashboard->item = menu->MoveBottomItem(dashboard->itemEnter-1,dashboard->itemEnter,dashboard->inMenu);
        frame->ClearContent(dashboard->width,dashboard->height);
	                     
	    if(dashboard->itemEnter == 2){
			AddClass->createElement(dashboard->width);
			dashboard->current_height = addClassbundle->height;
			frame->LineContent(dashboard->width," THEM LOP ");
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
            dashboard->height = dashboard->current_height;
			addClassbundle->chose = 1;
			AddClass->switchElement(' ');	
		}else{
			frame->LineContent(dashboard->width,"  ");
		}
		
	    x = true;
	}
}
