#include "CONTROL.h"

using namespace std;

void CONTROL::ADDSUBJECT_CONTROL(char c){
	bool x = false;
	//MOVE ===============================================================================
	if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            AddSubject->switchElement(true,false,c);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
		    AddSubject->switchElement(true,true,c);
		    x = true;
	    }
	    AddSubject->switchElement(false,true,c);
	    x = true;
	}
	///ESC ===============================================================================
	if((int)c == 27 && x == false){
		dashboard->inMenu = true;
		dashboard->pre_Enter = 5;
        menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        x = true;
	}	
	///ENTER =============================================================================
	if(c=='\r' && x == false){        
		if(addSubjectbundle->chose != 3) AddSubject->switchElement(true,true,c);
		else{
			if(AddSubject->addSubject_() == true){
				/////RISE CONSOLE
				consolebundle->top = dashboard->height + 2;
				consolebundle->message = "THEM MON HOC THANH CONG";
				console->RISE_CONSOLE();
				////CREATE
				frame->ClearContent(dashboard->width,dashboard->height);
				AddSubject->createElement(dashboard->width);
				////CURSOR ELEMENT
			    addSubjectbundle->chose = 1;
			    AddSubject->switchElement(false,false,' ');	
			}else{
				/////RISE CONSOLE
				consolebundle->top = dashboard->height + 2;
				consolebundle->message = "LOI KHI THEM MON HOC";
				console->RISE_CONSOLE();
			}
		} 
	    x = true;
	}
	///TYPE CHARACTER =====================================================================
	if(x == false){
	    AddSubject->executeElement(c);
        x = true;
	}
}
