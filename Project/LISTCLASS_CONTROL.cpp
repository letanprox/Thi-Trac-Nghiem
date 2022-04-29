#include "CONTROL.h"

using namespace std;

void CONTROL::LISTCLASS_CONTROL(char c){
    bool x = false;
    ///MOVE
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(listClassbundle->is_editclass == false) ListClass->switchElement(dashboard->width,true);
            else listClassbundle->chose_editclass = 1;
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(listClassbundle->is_editclass == false) ListClass->switchElement(dashboard->width,false);
            else listClassbundle->chose_editclass = 2;
		    x = true;
	    }	
	    ///LEFT
	    if(c == 75  && x == false){
			if(listClassbundle->is_editclass == false)  ListClass->switchSearchElement(c);
			x = true;
		}
		///RIGHT
	    if(c == 77  && x == false){
			if(listClassbundle->is_editclass == false)  ListClass->switchSearchElement(c);
			x = true;
		}
	    if(listClassbundle->is_editclass == true) ListClass->switchEditClass(c);
	    x = true;
	}
	///ESC
	if((int)c == 27 && x == false){
		if(listClassbundle->is_editclass == false){
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 1;
		    ListClass->setListClass(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else{
        	ListClass->clearBlankElement(dashboard->width);
			ListClass->keepElement(dashboard->width);
			frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   TYPE:TIMKIEM   ENTER");
			listClassbundle->is_editclass = false;
		}
        x = true;
	}
	///F CONTROL
	if((int)c == 0){
		c = getch();
		///F4
		if(c == 62  && x == false){
	    	if(listClassbundle->is_editclass == false){
	   			if(listClassbundle->size>0){
		    		ListClass->deleteElement();
		    		///CONSOLE
		    		consolebundle->message = "XOA LOP THANH CONG";
		    		consolebundle->top = dashboard->height + 2;
		    		console->RISE_CONSOLE();
		    		ListClass->clearBlankElement(dashboard->width);
			    	ListClass->createElement(dashboard->width);
				}
			}
			x = true;
		}
		///F3
		if(c == 61  && x == false){
			if(listClassbundle->is_editclass == false){
				ListClass->clearBlankElement(dashboard->width);
            	ListClass->createEditClass(dashboard->width);
            	listClassbundle->chose_editclass = 1;
 				frame->LineGuide(dashboard->height,"ESC   ENTER");
            	ListClass->switchEditClass(' ');
            	listClassbundle->is_editclass = true;
        	}
        	x = true;
		}
	}
	///ENTER
	if(c=='\r' && x == false){
        if(listClassbundle->is_editclass == false){
            ListClass->clearBlankElement(dashboard->width);
            ListStudent->createElement(dashboard->width);
            int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
            frame->LineGuide(dashboard->height,"ESC   F4:XOA   TYPE:TIMKIEM   ENTER:SUA");
            listStudentbundle->is_in_student = true;  
		}else{
			if(listClassbundle->chose_editclass == 1){
				listClassbundle->chose_editclass = 2;
			    ListClass->switchEditClass(c);
			}else{
				ListClass->updateEditClass();
		    	///CONSOLE
		    	consolebundle->message = "CAP NHAT LOP THANH CONG";
		    	consolebundle->top = dashboard->height + 2;
		    	console->RISE_CONSOLE();	
		    	ListClass->clearBlankElement(dashboard->width);
			    ListClass->keepElement(dashboard->width);
			    frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   TYPE:TIMKIEM   ENTER");
			    listClassbundle->is_editclass = false;
			}
		}
	    x = true;
	}
	///TYPE CHARACTER
	if(x == false){
		if(listClassbundle->is_editclass == true) ListClass->excuteEditClass(c);
		if(listClassbundle->is_editclass == false){
			ListClass->excuteSearchElement(dashboard->width,c);
			ListClass->switchSearchElement(' ');
		}
        x = true;
	}
}
