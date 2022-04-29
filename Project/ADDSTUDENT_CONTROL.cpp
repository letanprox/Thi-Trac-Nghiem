#include "CONTROL.h"

using namespace std;

void CONTROL::ADDSTUDENT_CONTROL(char c){
    bool x = false;
    ///MOVE ===========================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            if(addstudentbundle->is_addstudent == false) ListClass->switchElement(dashboard->width,true);
            else AddStudent->switchElement(true,false,' ');
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
            if(addstudentbundle->is_addstudent == false) ListClass->switchElement(dashboard->width,false);
            else AddStudent->switchElement(true,true,' ');
		    x = true;
	    }
	    ///LEFT
	    if(c == 75  && x == false){
			if(addstudentbundle->is_addstudent == false)  ListClass->switchSearchElement(c);
			x = true;
		}
		///RIGHT
	    if(c == 77  && x == false){
			if(addstudentbundle->is_addstudent == false)  ListClass->switchSearchElement(c);
			x = true;
		}
	    if(addstudentbundle->is_addstudent == true) if(addstudentbundle->chose == 3) AddStudent->switchPhaiStudent(c);
	    if(addstudentbundle->is_addstudent == true) AddStudent->switchElement(false,false,c);
	    x = true;
	}
	///ESC ============================================================================
	if((int)c == 27 && x == false){
		if(addstudentbundle->is_addstudent == false){
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 3;
		    ListClass->setListClass(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
		}else{
			////CLEAR ELEMENT
	        AddStudent->clearBlankAddStudent(dashboard->width);
	        ////KEEP ELEMENT
			ListClass->keepElement(dashboard->width);
			////TITLE
			int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    frame->LineContent(dashboard->width," DANH SACH LOP ",x);
            ///GUIDE LINE
            frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
            ////RETURN 	
            addstudentbundle->is_addstudent = false;
		}
        x = true;
	}
	///ENTER ==========================================================================
	if(c=='\r' && x == false){
        if(addstudentbundle->is_addstudent == false){
        	///CLEAR LIST CLASS
        	ListClass->clearBlankElement(dashboard->width);
        	////CREATE FORM
		    AddStudent->createElement(dashboard->width);
		    ////TITLE
            int x =  addstudentbundle->margin + ((dashboard->width-addstudentbundle->margin) - addstudentbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
		    ////GUIDE LINE
		    frame->LineGuide(dashboard->height,"ESC   ENTER");
		    ///CURSOR
		    addstudentbundle->chose = 1;
		    AddStudent->switchElement(false,false,' ');
		    /////ADDSTUDENT
		    addstudentbundle->is_addstudent = true;
		}else{
			if(addstudentbundle->chose != 5){
			    AddStudent->switchElement(true,true,' ');
			}else{
				if(AddStudent->addStudent_() == true){	
					/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "THEM SINH VIEN THANH CONG";
					console->RISE_CONSOLE();	
				    /////RE DRAW
				    AddStudent->clearBlankAddStudent(dashboard->width);
				    AddStudent->createElement(dashboard->width);
			        addstudentbundle->chose = 1;
			        AddStudent->switchElement(false,false,' ');
				}else{
					/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "LOI KHI THEM SINH VIEN";
					console->RISE_CONSOLE();
				}	
			}	
		}
	    x = true;
	}
	//TYPE ==========================================================================
	if(x == false){
		if(addstudentbundle->is_addstudent == true) AddStudent->executeElement(c);
		if(addstudentbundle->is_addstudent == false){
			ListClass->excuteSearchElement(dashboard->width,c);
			ListClass->switchSearchElement(' ');
		}
        x = true;
	}
}
