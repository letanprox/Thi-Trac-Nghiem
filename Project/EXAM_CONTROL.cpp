#include "CONTROL.h"

using namespace std;

void CONTROL::EXAM_CONTROL(char c){
    bool x = false;
	//MOVE ======================================================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(exambundle->is_in_condition_exam == false) ListSubject->switchElement(dashboard->width,true);
	    	else{ if(exambundle->is_in_exam == false) exam->switchConditionExam(true,false,' ');}
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(exambundle->is_in_condition_exam == false) ListSubject->switchElement(dashboard->width,false);
	    	else{ if(exambundle->is_in_exam == false) exam->switchConditionExam(true,true,' ');}
		    x = true;
	    }
	    ///LEFT RIGHT
	    if(exambundle->is_in_condition_exam == true){ if(exambundle->is_in_exam == false) exam->switchConditionExam(false,false,c);}
	    x = true;
	}
	///ESC ========================================================================================================
	if((int)c == 27 && x == false){
		if(exambundle->is_in_condition_exam == false){ 
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 7;
		    ListSubject->setListSubject(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else{
        	if(exambundle->is_in_exam == false){
            	exam->clearBlankConditionExam(dashboard->width);
          		////SHOW LISTSUBJECT
				ListSubject->keepElement(dashboard->width);
            	////CHANGE TITLE LISTSUBJECT
		    	int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            	///REDRAW LAST LINE
            	dashboard->current_height = listSubjectbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
			    ///CONDITION
			    exambundle->is_in_condition_exam = false;
			}
		}
        x = true;
	}
	///ENTER ======================================================================================================
	if(c=='\r' && x == false){
        if(exambundle->is_in_condition_exam == false){
		    /////CLEAR LIST SUBJECT
			ListSubject->clearBlankElement(dashboard->width);
	        ////CREATE ELEMENT
			exam->createConditionExam(dashboard->width);
			////TITLE
            string title = " NHAP CAU HOI CHO BAI THI ";
	    	int x = exambundle->margin + ((dashboard->width-exambundle->margin) - exambundle->widthFrame)/2 - 1;
	    	frame->LineContent(dashboard->width,title,x);
            ///REDRAW LAST LINE
            dashboard->current_height = exambundle->height;		
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   ENTER");
		    ////CURSOR ELEMENT
			exambundle->chose_condition_exam  = 1;
			exam->switchConditionExam(false,false,' ');
			////CONDITION	
			exambundle->is_in_condition_exam = true;
		}else{
			if(exambundle->is_in_exam == false){
				if(exambundle->chose_condition_exam != 3) exam->switchConditionExam(true,true,' ');
				else{
					if(exam->getValueForExam() == 1){
						/////RISE CONSOLE
						consolebundle->top = dashboard->height + 2;
						consolebundle->message = "CHUA NHAP DAY DU";
						console->RISE_CONSOLE();
					}
					if(exam->getValueForExam() == 2){
						/////RISE CONSOLE
						consolebundle->top = dashboard->height + 2;
						consolebundle->message = "VUOT QUA CAU HOI TRONG DU LIEU";
						console->RISE_CONSOLE();
					}
					if(exam->getValueForExam() == 3){	
						/////RISE CONSOLE
						consolebundle->top = dashboard->height + 2;
						consolebundle->message = "VAO THI";
						console->RISE_CONSOLE();
						//CREATE EXAM
						exam->clearBlankConditionExam(dashboard->width);
                    	exam->createExam(dashboard->width);
						////TITLE
            			string title = " MON THI " + listSubjectbundle->MAMH + " ";
	    				int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
                    	frame->LineContent(dashboard->width,title,x);
            			///LAST LINE
            			dashboard->current_height = exambundle->height;
						frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    		dashboard->height = dashboard->current_height;
            			////GUIDE LINE
						frame->LineGuide(dashboard->height,"TOP BOTTOM LEFT RIGHT  ENTER");     
						////CONDITION
						exam->keepExam(dashboard->width);   
						exambundle->is_in_exam = true;     
					}       
				}
			}
		}
	    x = true;
	}
	//TYPE =======================================================================================================
	if(x == false){
		if(exambundle->is_in_condition_exam == true) 
	    	    if(exambundle->is_in_exam == false) exam->excuteConditionExam(c);
        x = true;
	}
}
