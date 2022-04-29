#include "CONTROL.h"

using namespace std;

void CONTROL::ADDQUESTION_CONTROL(char c){
    bool x = false;
	//MOVE ==================================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(listQuestionbundle->is_editquestion == false) ListSubject->switchElement(dashboard->width,true);
	    	else ListQuestion->switchEditQuestion(true,false,' ');
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(listQuestionbundle->is_editquestion == false) ListSubject->switchElement(dashboard->width,false);
	    	else ListQuestion->switchEditQuestion(true,true,' ');	
		    x = true;
	    }
		if(listQuestionbundle->is_editquestion == true) {
		    if(listQuestionbundle->chose_edit_elementquestion == 6) ListQuestion->switchEditAnswerQuestion(c);
			ListQuestion->switchEditQuestion(false,true,c);	
	    }	
	    x = true;
	}
	///ESC ===================================================================================
	if((int)c == 27 && x == false){
		if(listQuestionbundle->is_editquestion == false){ 
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 6;
		    ListSubject->setListSubject(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else{
        	///CLEAR EDIT ELEMENT
           	ListQuestion->clearBlankEditElement(dashboard->width);
           	///SHOW SUBJECT LIST
		    ListSubject->keepElement(dashboard->width);
            ///REDRAW LAST LINE
            dashboard->current_height = listSubjectbundle->height;
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;
			////TITLE
		    int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
            ///CONDITION
            listQuestionbundle->is_editquestion = false;
		}
        x = true;
	}
	///ENTER ======================================================================================
	if(c=='\r' && x == false){
        if(listQuestionbundle->is_editquestion == false){    
            /////CLEAR LIST SUBJECT
			ListSubject->clearBlankElement(dashboard->width);
			/////CREATE ATTRIBUTE
			listQuestionbundle->widthFrame  = 61;
            listQuestionbundle->margin = 20;
            listQuestionbundle->y_title = 9;
            ////SHOW EDIT QUESTION 
		    ListQuestion->createEditQuestion(true,dashboard->width);
          	///REDRAW LAST LINE
          	dashboard->current_height = listQuestionbundle->height;
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
		    dashboard->height = dashboard->current_height;
		    ////TITLE
            int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," THEM CAU HOI CHO MON " + listSubjectbundle->MAMH + " " ,x);
            ////REDRAW EDIT QUESTION
		    ListQuestion->keepEditQuestion(dashboard->width);
            ////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
		    ////CURSOR
		    listQuestionbundle->chose_edit_elementquestion = 1 ;
			ListQuestion->switchEditQuestion(false,false,' ');
			/////CONDITION
			listQuestionbundle->is_editquestion = true;
        }else{
        	if(listQuestionbundle->chose_edit_elementquestion == 7){
        	    if(ListQuestion->addQuestion_() == true){
        	    	/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "THEM CAU HOI THANH CONG";
					console->RISE_CONSOLE();
        			///CLEAR EDIT ELEMENT
           			ListQuestion->clearBlankEditElement(dashboard->width);
					ListQuestion->createEditQuestion(true,dashboard->width);
		   			////CURSOR
		    		listQuestionbundle->chose_edit_elementquestion = 1 ;
					ListQuestion->switchEditQuestion(false,false,' ');
			    }else{
			    	/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "LOI KHI THEM CAU HOI";
					console->RISE_CONSOLE();
				}
			}else{
				ListQuestion->switchEditQuestion(true,true,' ');
			}
		}
	    x = true;
	}
	///TYPE =========================================================================================
	if(x == false){
		if(listQuestionbundle->is_editquestion == true){
			////EXCUTE ELEMENT
		    ListQuestion->excuteEditQuestion(c);
		    ////IF HEIGHT CHANGE
		    if(dashboard->current_height != listQuestionbundle->height){
				dashboard->current_height = listQuestionbundle->height;
            	///REDRAW LAST LINE
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
			    ////CURSOR
			    ListQuestion->switchEditQuestion(false,false,' ');
			}
		}
        x = true;
	}
}
