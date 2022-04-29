#include "CONTROL.h"

using namespace std;

void CONTROL::LISTSUBJECT_CONTROL(char c){
    bool x = false;
    //MOVE =============================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(listSubjectbundle->is_editsubject == false) ListSubject->switchElement(dashboard->width,true);
            else listSubjectbundle->chose_editsubject = 1;
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(listSubjectbundle->is_editsubject == false) ListSubject->switchElement(dashboard->width,false);
            else listSubjectbundle->chose_editsubject = 2;
		    x = true;
	    }	
	    if(listSubjectbundle->is_editsubject == true) ListSubject->switchEditSubject(c);
	    x = true;
	}
	///ESC =============================================================================
	if((int)c == 27 && x == false){
		if(listSubjectbundle->is_editsubject == false){
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 4;
		    ListSubject->setListSubject(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else{
        	ListSubject->clearBlankElement(dashboard->width);
			ListSubject->keepElement(dashboard->width);
			frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   ENTER");
			listSubjectbundle->is_editsubject = false;
		}
        x = true;
	}
	//F   ==============================================================================
	if((int)c == 0){
		c = getch();
		///F4
		if(c == 62  && x == false){
	    	if(listSubjectbundle->is_editsubject == false){
	   			if(listSubjectbundle->size>0){
	   				ListSubject->deleteElement();
	   				/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "XOA MON HOC THANH CONG";
					console->RISE_CONSOLE();
	    			ListSubject->clearBlankElement(dashboard->width);
			    	ListSubject->createElement(dashboard->width);
				}
			}
			x = true;
		}
		///F3
		if(c == 61  && x == false){
			if(listSubjectbundle->is_editsubject == false){
				ListSubject->clearBlankElement(dashboard->width);
            	ListSubject->createEditSubject(dashboard->width);
            	frame->LineGuide(dashboard->height,"ESC   ENTER");
            	listSubjectbundle->chose_editsubject = 1;
            	ListSubject->switchEditSubject(' ');
            	listSubjectbundle->is_editsubject = true;
        	}
        	x = true;
		}
	}	
	///ENTER  ==============================================================================
	if(c=='\r' && x == false){
        if(listSubjectbundle->is_editsubject == true){
        	if(listSubjectbundle->chose_editsubject == 1){
				listSubjectbundle->chose_editsubject = 2;
			    ListSubject->switchEditSubject(c);
			}else{
				ListSubject->updateEditSubject();
	   			/////RISE CONSOLE
				consolebundle->top = dashboard->height + 2;
				consolebundle->message = "CAP NHAT MON HOC THANH CONG";
				console->RISE_CONSOLE();
				ListSubject->clearBlankElement(dashboard->width);
			    ListSubject->keepElement(dashboard->width);
            	////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   ENTER");
				listSubjectbundle->is_editsubject = false;
			}
		}else{
			ListSubject->clearBlankElement(dashboard->width);
            ListQuestion->createElement(dashboard->width);
            int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," MON HOC: "+listSubjectbundle->MAMH+" ",x);
            ////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   F4:XOA   ENTER");
			listQuestionbundle->is_in_question = true;
		}
	    x = true;
	}
	///TYPE    ==============================================================================
	if(x == false){
		if(listSubjectbundle->is_editsubject == true) ListSubject->excuteEditSubject(c);
        x = true;
	}
}
