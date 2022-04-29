#include "CONTROL.h"

using namespace std;

void CONTROL::FINISH_EXAM_CONTROL(char c){
    bool x = false;
	//MOVE ======================================================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	    	if(exambundle->is_view_answer == true) exam->switchResultExamElement(true,false,dashboard->width);
			else exambundle->chose_achieve_element = 1;
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
	    	if(exambundle->is_view_answer == true) exam->switchResultExamElement(true,true,dashboard->width);
			else exambundle->chose_achieve_element = 2;
		    x = true;
	    }
	    ///LEFT
	    if(c == 75  && x == false){
	    	if(exambundle->is_view_answer == true){
	    		if(exambundle->chose_exam_element == 1){
	    			exam->clearListQuestion(dashboard->width);
	    			exam->switchListAnswer(true,false,dashboard->width);
            		////CHECK HEIGHT
	    			if(dashboard->current_height != exambundle->height){
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
	    	if(exambundle->is_view_answer == true){	    		
	    		if(exambundle->chose_exam_element == 1){
	    			exam->clearListQuestion(dashboard->width);
	    			exam->switchListAnswer(true,true,dashboard->width);
            		////CHECK HEIGHT
	    			if(dashboard->current_height != exambundle->height){
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
	    ////------------------
	    if(exambundle->is_view_answer == false) exam->switchElementAchievementExam(dashboard->width);
	    x = true;
	}
	///ENTER ======================================================================================================
	if(c=='\r' && x == false){
		if(exambundle->is_temp_finish == true){
        	exam->clearBlankExamBottom(dashboard->width,8);
        	countdown->clearCLOCK();
        	exam->extractResultExam(dashboard->width);
			string title = " THANH TICH ";
	    	int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length())/2;
	    	frame->LineContent(dashboard->width,title,x);
            ////CHANGE LAST LINE
            dashboard->current_height = listSubjectbundle->height;
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;     
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ENTER");
			///CONDITION
			exambundle->chose_exam_element = 1;
			exambundle->is_temp_finish = false;   	
        }else{
        	if(exambundle->chose_achieve_element == 2){
        		frame->ClearContent(dashboard->width,listSubjectbundle->height);
				ListSubject->createElement(dashboard->width);
                ////CHANGE TITLE 
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
			    exambundle->is_temp_finish = false;
			    exambundle->is_finish_exam = false;
			    exambundle->chose_achieve_element = 1;
			}else{
			    if(exambundle->is_view_answer == false){
					frame->ClearContent(dashboard->width,listSubjectbundle->height);
					exam->createResulteExam(dashboard->width);
					////TITLE
                	string title = " MON THI " + listSubjectbundle->MAMH + " ";
	    			int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
                	frame->LineContent(dashboard->width,title,x);
            		///REDRAW LAST
            		dashboard->current_height = exambundle->height;
					frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    	dashboard->height = dashboard->current_height;
            		////GUIDE LINE
					frame->LineGuide(dashboard->height,"TOP BOTTOM LEFT RIGHT  ENTER");
			    	exam->keepResulteExam(dashboard->width);      
				    ////CONDITION
					exambundle->is_view_answer = true;    
				}else{
					if(exambundle->chose_exam_element == 2){
						exam->clearListQuestion(dashboard->width);
				    	exam->EnterListNumberAnswers(dashboard->width);
            			////CHECK HEIGHT
	    				if(dashboard->current_height != exambundle->height){
		    				dashboard->current_height = exambundle->height; 
							frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
							dashboard->height = dashboard->current_height;   
            				exam->keepResulteExam(dashboard->width); 
						} 
				    }else if(exambundle->chose_exam_element == 3){
        				frame->ClearContent(dashboard->width,dashboard->current_height );
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
			    		exambundle->is_temp_finish = false;
			    		exambundle->is_finish_exam = false;
			    		exambundle->is_view_answer = false;
			            exambundle->chose_exam_element == 1;
			    		exambundle->chose_achieve_element = 1;
					}
				}	
			}
		}
	    x = true;
	}
}
