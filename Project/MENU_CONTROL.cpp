#include "CONTROL.h"

using namespace std;

int i = 0;

void CONTROL::MENU_CONTROL(char c){
    bool x = false;
    //MOVE ============================================================================================
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
	///ENTER ==========================================================================================
	if(c=='\r' && x == false){
	    dashboard->inMenu = false;
	    dashboard->itemEnter = dashboard->item;
        dashboard->item = menu->MoveBottomItem(dashboard->itemEnter-1,dashboard->itemEnter,dashboard->inMenu);
        ///TRANSLATE-----------------------------------
        int item;
        if(loginbundle->maUser.compare("GV") == 0){
				 if(dashboard->item == 7) item = 8;			
			else if(dashboard->item == 8) item = 9;
			else if(dashboard->item == 9) item = 10;	
			   else item = dashboard->item;
		}else{
				 if(dashboard->item == 1) item = 7;
			else if(dashboard->item == 2) item = 8;
			else if(dashboard->item == 3) item = 9;	
			else if(dashboard->item == 4) item = 10;
		}
        ////-------------------------------------------------------------------------------------------------------
        if(dashboard->pre_Enter != item) frame->ClearContent(dashboard->width,dashboard->height);
	    ////-------------------------------------------------------------------------------------------------------                 
	    if(item == 1){
		    if(dashboard->pre_Enter == 1) ListClass->keepElement(dashboard->width);
			else {
				////CREATE LISTCLASS
				ListClass->createElement(dashboard->width);
                ////CHANGE TITLE CLASS
		    	int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH LOP ",x);
            	///LAST LINE
            	dashboard->current_height = listClassbundle->height;
				frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;
				//GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   TYPE:TIMKIEM   ENTER");
            }
        ////-------------------------------------------------------------------------------------------------------  
		}else if((item) == 2){
	        if(dashboard->pre_Enter != 2){
	        	//CREATE ELEMENT
				AddClass->createElement(dashboard->width);
				///TITLE
		    	int widthFrame = addClassbundle->widthFrame;
            	int margin = addClassbundle->margin;
				int x = margin + ((dashboard->width-margin) - widthFrame)/2;
				frame->LineContent(dashboard->width," THEM LOP ",x);
		        ////DRAW LASTLINE
				dashboard->current_height = addClassbundle->height;
				frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;
				///GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				addClassbundle->chose = 1;
				AddClass->switchElement(false,false,' ');
			}else{
				AddClass->switchElement(false,false,' '); 
			}
        ////-------------------------------------------------------------------------------------------------------  
		}else if((item) == 3){
		    if(dashboard->pre_Enter == 3) ListClass->keepElement(dashboard->width);
			else {
				///CREATE ELEMENT
			    ListClass->createElement(dashboard->width);
			    ////TITLE
			  	int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH LOP ",x);
		        ////DRAW LASTLINE
				dashboard->current_height = listClassbundle->height;
				frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;
            	///GUIDE LINE
            	frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
			}
		////-------------------------------------------------------------------------------------------------------  
		}else if(item == 4){
		    if(dashboard->pre_Enter == 4) ListSubject->keepElement(dashboard->width);
			else {
				////CREATE LISTCLASS
				ListSubject->createElement(dashboard->width);
                ////CHANGE TITLE CLASS
		    	int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            	///REDRAW LAST LINE
            	dashboard->current_height = listSubjectbundle->height;
				frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
            	////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   ENTER");
            }
        ////-------------------------------------------------------------------------------------------------------  
		}else if((item) == 5){
	        if(dashboard->pre_Enter != 5){
	        	/////CREATE ADDCLASSS
				AddSubject->createElement(dashboard->width);
				/////CHANGE TITLE
		    	int widthFrame = 50;
            	int margin = addSubjectbundle->margin;
				int x = margin + ((dashboard->width-margin) - widthFrame)/2;
				frame->LineContent(dashboard->width," THEM MON HOC ",x);
				////CHANGE POSITION LAST LINE 
				dashboard->current_height = addSubjectbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
            	dashboard->height = dashboard->current_height;
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
                ////CHOSE ELEMENT
				addSubjectbundle->chose = 1;
				AddSubject->switchElement(false,false,' ');	
			}else{
				////ELEMENT CURSOR
				AddSubject->switchElement(false,false,' '); 
			}
        ////-------------------------------------------------------------------------------------------------------  
		}else if(item == 6){
		    if(dashboard->pre_Enter == 6) ListSubject->keepElement(dashboard->width);
			else {
				////CREATE LISTCLASS
				ListSubject->createElement(dashboard->width);
                ////CHANGE TITLE CLASS
		    	int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            	///REDRAW LAST LINE
            	dashboard->current_height = listSubjectbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
            }
        ////-------------------------------------------------------------------------------------------------------  
		}else if((item) == 7){
			
			if(dashboard->pre_Enter == 7) ListSubject->keepElement(dashboard->width);
			else {
				////CREATE LISTCLASS
				ListSubject->createElement(dashboard->width);
                ////CHANGE TITLE CLASS
		    	int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            	///REDRAW LAST LINE
            	dashboard->current_height = listSubjectbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
			    ////CONDITION	
			    exambundle->is_in_condition_exam = false;
			    exambundle->is_in_exam = false;
            }
        ////-------------------------------------------------------------------------------------------------------  			
		}else if((item) == 8){
			if(dashboard->pre_Enter == 8){
				if(loginbundle->maUser.compare("GV") == 0) ListClass->keepElement(dashboard->width);
				else showstudentscore->keepListScoreElement(dashboard->width);
			}else {
				if(loginbundle->maUser.compare("GV") == 0){
					////CREATE LISTCLASS
					ListClass->createElement(dashboard->width);
                	////CHANGE TITLE CLASS
		    		int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    		frame->LineContent(dashboard->width," DANH SACH LOP ",x);
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
					//CONDITION
					showstudentscorebundle->chose_element = 1;
					dashboard->current_height = listClassbundle->height;
			    }else{
			    	showstudentscorebundle->MASV = loginbundle->maUser;
			    	showstudentscorebundle->MALOP = loginbundle->maLop;
            		showstudentscore->createListScoreElement(dashboard->width,true);
            		//TITLE
            		int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            		frame->LineContent(dashboard->width," MASV: "+showstudentscorebundle->MASV+" ",x);
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
            		///CONDITION
            		showstudentscorebundle->chose_element = 3;
            		dashboard->current_height = showstudentscorebundle->height;
				}
            		///LAST LINE
					frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    	dashboard->height = dashboard->current_height;	
		    }
        ////-------------------------------------------------------------------------------------------------------  	
		}else if((item) == 9){
			if(dashboard->pre_Enter == 9) ListClass->keepElement(dashboard->width);
			else {
				////CREATE LISTCLASS
				ListClass->createElement(dashboard->width);
                ////CHANGE TITLE CLASS
		    	int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    	frame->LineContent(dashboard->width," DANH SACH LOP ",x);
            	///REDRAW LAST LINE
            	dashboard->current_height = listClassbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;	
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
		    }	
        ////-------------------------------------------------------------------------------------------------------  	
		}else if((item) == 10){
			/////RISE CONSOLE
			consolebundle->top = dashboard->height + 2;
			consolebundle->message = "THOAT";
			console->RISE_CONSOLE();
			
     		dashboard->isLogin_ed = false;
			dashboard->isReset = true;
			dashboard->isLoadingLogin = true;
			
			dashboard->inMenu = true;
			dashboard->pre_Enter = 0;
			dashboard->itemEnter = 1;
			dashboard->item = 1;
			dashboard->isLoadingProgram = true;	
		}
	    x = true;
	}
}
