#include "CONTROL.h"

using namespace std;

void CONTROL::SHOWCLASSSCORE_CONTROL(char c){

    bool x = false;
    
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(showclassscorebundle->chose_element == 1) ListClass->switchElement(dashboard->width,true);
	    	if(showclassscorebundle->chose_element == 2) ListSubject->switchElement(dashboard->width,true);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(showclassscorebundle->chose_element == 1) ListClass->switchElement(dashboard->width,false);
	    	if(showclassscorebundle->chose_element == 2) ListSubject->switchElement(dashboard->width,false);
		    x = true;
	    }	
	    ///LEFT
	    if(c == 75  && x == false){
	    	if(showclassscorebundle->chose_element == 1) ListClass->switchSearchElement(c);
	    	if(showclassscorebundle->chose_element == 3) showclassscore->switchListScoreElement(true,true,dashboard->width);
		    x = true;
	    }
	    ////RIGHT
	    if(c == 77  && x == false){
	    	if(showclassscorebundle->chose_element == 1) ListClass->switchSearchElement(c);
	    	if(showclassscorebundle->chose_element == 3) showclassscore->switchListScoreElement(true,false,dashboard->width);
		    x = true;
	    }
	    x = true;
	}
    ///=============================================================================================================    
	///ESC
	if((int)c == 27 && x == false){
		if(showclassscorebundle->chose_element == 1){
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 9;
		    ListClass->setListClass(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else if(showclassscorebundle->chose_element == 2){
		    ListSubject->clearBlankElement(dashboard->width);
		    ////CREATE LISTCLASS
			ListClass->keepElement(dashboard->width);
            ////CHANGE TITLE 
			int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    frame->LineContent(dashboard->width," DANH SACH LOP ",x);
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
		    showclassscorebundle->chose_element = 1;
		}else if(showclassscorebundle->chose_element == 3){
			showclassscore->clearBlankElement_(dashboard->width);
			////CREATE LISTSUBJECT
			ListSubject->keepElement(dashboard->width);
            ////CHANGE TITLE CLASS
		    int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   ENTER");
		    showclassscorebundle->chose_element = 2;
		}
        x = true;
	}
	///ENTER
	if(c=='\r' && x == false){
		if(showclassscorebundle->chose_element == 1){
			ListClass->clearBlankElement(dashboard->width);
			////CREATE LISTSUBJECT
			ListSubject->createElement(dashboard->width);
            ////CHANGE TITLE CLASS
		    int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   ENTER");
		    showclassscorebundle->chose_element = 2;
		}else if(showclassscorebundle->chose_element == 2){
			showclassscore->getDataForStudent();
			ListSubject->clearBlankElement(dashboard->width);
			showclassscore->createListScoreElement(dashboard->width);
			////CHANGE TITLE CLASS
			string title = " DANH SACH DIEM LOP: " + listClassbundle->MALOP + " ";
		    int i = showclassscorebundle->margin + ((dashboard->width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2 - 1;
		    frame->LineContent(dashboard->width,title,i);
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   <- RIGHT   LEFT ->");
			showclassscorebundle->chose_element = 3;
		}
	    x = true;
	}
	if(x == false){
		if(showclassscorebundle->chose_element == 1){
			ListClass->excuteSearchElement(dashboard->width,c);
			ListClass->switchSearchElement(' ');
		}
        x = true;
	}
}
