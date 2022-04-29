#include "CONTROL.h"

using namespace std;

void CONTROL::SHOWSTUDENTSCORE_CONTROL(char c){
    bool x = false;
    //MOVE ==================================================================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(showstudentscorebundle->chose_element == 1) ListClass->switchElement(dashboard->width,true);
	    	if(showstudentscorebundle->chose_element == 2) ListStudent->switchElement(dashboard->width,true);
	    	if(showstudentscorebundle->chose_element == 3) showstudentscore->switchListScoreElement(dashboard->width,true);
	    	if(showstudentscorebundle->chose_element == 4) exambundle->chose_achieve_element = 1;
	    	if(showstudentscorebundle->chose_element == 5) exam->switchResultExamElement(true,false,dashboard->width);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(showstudentscorebundle->chose_element == 1) ListClass->switchElement(dashboard->width,false);
	    	if(showstudentscorebundle->chose_element == 2) ListStudent->switchElement(dashboard->width,false);
	    	if(showstudentscorebundle->chose_element == 3) showstudentscore->switchListScoreElement(dashboard->width,false);
	    	if(showstudentscorebundle->chose_element == 4) exambundle->chose_achieve_element = 2;
	    	if(showstudentscorebundle->chose_element == 5) exam->switchResultExamElement(true,true,dashboard->width);
		    x = true;
	    }	
	    if(showstudentscorebundle->chose_element == 4) exam->switchElementAchievementExam(dashboard->width);
	    ///LEFT
	    if(c == 75  && x == false){
	    	if(showstudentscorebundle->chose_element == 1) ListClass->switchSearchElement(c);
	    	if(showstudentscorebundle->chose_element == 2) ListStudent->switchSearchElement(c);
	    	if(showstudentscorebundle->chose_element == 5){
	    		if(exambundle->chose_exam_element == 1){
	    			exam->clearListQuestion(dashboard->width);
	    			exam->switchListAnswer(true,false,dashboard->width);
            		////CHECK HEIGHT
	    			if(dashboard->current_height != exambundle->height){
            			///REDRAW LAST LINE
            			dashboard->current_height = exambundle->height; 
						frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
						dashboard->height = dashboard->current_height;   
            			exam->keepResulteExam(dashboard->width); 
					}    			
	    		}
	    		if(exambundle->chose_exam_element == 2) exam->switchListNumber(true,false,dashboard->width);
            }
		    x = true;
	    }
	    ////RIGHT
	    if(c == 77  && x == false){
	    	if(showstudentscorebundle->chose_element == 1) ListClass->switchSearchElement(c);
	    	if(showstudentscorebundle->chose_element == 2) ListStudent->switchSearchElement(c);
	    	if(showstudentscorebundle->chose_element == 5){	    		
	    		if(exambundle->chose_exam_element == 1){
	    			exam->clearListQuestion(dashboard->width);
	    			exam->switchListAnswer(true,true,dashboard->width);
            		////CHECK HEIGHT
	    			if(dashboard->current_height != exambundle->height){
            			///REDRAW LAST LINE
            			dashboard->current_height = exambundle->height; 
						frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
						dashboard->height = dashboard->current_height;   
            			exam->keepResulteExam(dashboard->width);    
					}
	    		}
	    		if(exambundle->chose_exam_element == 2) exam->switchListNumber(true,true,dashboard->width);
            }
		    x = true;
	    }
	    x = true;
	}
	///ESC ==================================================================================================================
	if((int)c == 27 && x == false){
		if(showstudentscorebundle->chose_element == 1){
		    dashboard->inMenu = true;
		    dashboard->pre_Enter = 8;
		    ListClass->setListClass(true,false,dashboard->width);
            menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
        }else if(showstudentscorebundle->chose_element == 2){
		    ListStudent->clearBlankElement(dashboard->width);
            ListClass->keepElement(dashboard->width);
            int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," DANH SACH LOP ",x);
			frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
            showstudentscorebundle->chose_element = 1;
		}else if(showstudentscorebundle->chose_element == 3){
			if(loginbundle->maUser.compare("GV") == 0){
        		ListStudent->clearBlankElement(dashboard->width);
        		ListStudent->keepElement(dashboard->width);
        		int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
            	frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
				frame->LineGuide(dashboard->height,"ESC   ENTER");
				showstudentscorebundle->chose_element = 2;
			}else{
		    	dashboard->inMenu = true;
		    	dashboard->pre_Enter = 8;
		    	showstudentscore->setListStudentScore(true,false,dashboard->width);
            	menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
			}
		}else if(showstudentscorebundle->chose_element == 4){
		    frame->ClearContent(dashboard->width,dashboard->height);
		    showstudentscore->keepListScoreElement(dashboard->width);
            int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," MASV: "+showstudentscorebundle->MASV+" ",x); 
            if(loginbundle->maUser.compare("GV") == 0) frame->LineGuide(dashboard->height,"ESC   ENTER");
			else frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");	
            showstudentscorebundle->chose_element = 3;
		}
        x = true;
	}
	///ENTER ==================================================================================================================
	if(c=='\r' && x == false){
		///-------------------------------------------------------------------------------------
        if(showstudentscorebundle->chose_element == 1){
			ListClass->clearBlankElement(dashboard->width);
            ListStudent->createElement(dashboard->width);
            int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
			frame->LineGuide(dashboard->height,"ESC   ENTER");
            showstudentscorebundle->chose_element = 2;
        ///-------------------------------------------------------------------------------------
		}else if(showstudentscorebundle->chose_element == 2){
			ListStudent->clearBlankElement(dashboard->width);
            showstudentscore->createListScoreElement(dashboard->width,false);
            int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," MASV: "+listStudentbundle->MASV+" ",x);
			frame->LineGuide(dashboard->height,"ESC   ENTER");
            showstudentscorebundle->chose_element = 3;
        ///-------------------------------------------------------------------------------------
		}else if(showstudentscorebundle->chose_element == 3){
			exambundle->margin = 15;
			showstudentscore->getdataForArchieveExam();
			if(showstudentscorebundle->size > 0){
            	exambundle->MAMH = showstudentscorebundle->MAMH;
        		exambundle->TIME = showstudentscorebundle->TIME;
        		exambundle->MASV = showstudentscorebundle->MASV;
        		exambundle->TOTAL = showstudentscorebundle->TOTAL;
       			exambundle->HOTEN = showstudentscorebundle->HOTEN;
        		exambundle->DIEM = showstudentscorebundle->DIEM;	
        		frame->ClearContent(dashboard->width,dashboard->height);
				exam->showAchievementExam(false,dashboard->width);	
				////TITLE
				string title = " THANH TICH ";
	    		int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length())/2;
	    		frame->LineContent(dashboard->width,title,x);  		    	
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC   ENTER");
            	///CONDITION
				showstudentscorebundle->chose_element = 4;
			}
		///-------------------------------------------------------------------------------------
		}else if(showstudentscorebundle->chose_element == 4){
		    if(exambundle->chose_achieve_element == 1){
				exambundle->margin = 15;
				showstudentscore->getdataForResultExam();
				frame->ClearContent(dashboard->width,dashboard->height);
				exam->createResulteExam(dashboard->width);		
				////TITLE
           		string title = " MON THI " + showstudentscorebundle->MAMH + " ";
	    		int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
            	frame->LineContent(dashboard->width,title,x);
            	///REDRAW LAST LINE
            	dashboard->current_height = exambundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;
				frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
				exam->keepResulteExam(dashboard->width);   
			    showstudentscorebundle->chose_element = 5;
			}else{
		    	frame->ClearContent(dashboard->width,dashboard->height);
		    	showstudentscore->keepListScoreElement(dashboard->width);
            	int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            	frame->LineContent(dashboard->width," MASV: "+showstudentscorebundle->MASV+" ",x); 	
				if(loginbundle->maUser.compare("GV") == 0)frame->LineGuide(dashboard->height,"ESC   ENTER");
				else frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				exambundle->chose_achieve_element = 1;	
				showstudentscorebundle->chose_element = 3;
			}
		///-------------------------------------------------------------------------------------
		}else if(showstudentscorebundle->chose_element == 5){
		    if(exambundle->chose_exam_element == 2){
					exam->clearListQuestion(dashboard->width);
				    exam->EnterListNumberAnswers(dashboard->width);
            		////CHECK HEIGHT
	    			if(dashboard->current_height != exambundle->height){
            			///REDRAW LAST LINE
            			dashboard->current_height = exambundle->height; 
						frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
						dashboard->height = dashboard->current_height;   
            			exam->keepResulteExam(dashboard->width); 
					} 
	        //-----------------------
			}else if(exambundle->chose_exam_element == 3){
		    	frame->ClearContent(dashboard->width,dashboard->height);
		   	 	showstudentscore->keepListScoreElement(dashboard->width);
            	int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            	frame->LineContent(dashboard->width," MASV: "+showstudentscorebundle->MASV+" ",x);  
            	///REDRAW LAST LINE
            	dashboard->current_height = showstudentscorebundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;
				if(loginbundle->maUser.compare("GV") == 0) frame->LineGuide(dashboard->height,"ESC   ENTER");
				else frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				showstudentscorebundle->chose_element = 3;
			}
		}
	    x = true;
	}
	if(x == false){
		if(showstudentscorebundle->chose_element == 1) {
			ListClass->excuteSearchElement(dashboard->width,c);
			ListClass->switchSearchElement(' ');
		}
		if(showstudentscorebundle->chose_element == 2) {
			ListStudent->excuteSearchElement(dashboard->width,c);
			ListStudent->switchSearchElement(' ');
		}
        x = true;
	}
}
