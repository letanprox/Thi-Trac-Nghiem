#include "CONTROL.h"

using namespace std;

void CONTROL::IN_EXAM_CONTROL(char c){
    bool x = false;
	// MOVE ===========================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            exam->switchExamElement(true,false,dashboard->width);
		    x = true;
	    }
	    ///BOTTOM
	    if(c == 80  && x == false){
            exam->switchExamElement(true,true,dashboard->width);
		    x = true;
	    }
	    ///LEFT
	    if(c == 75  && x == false){
			if(exambundle->chose_exam_element >= 1 && exambundle->chose_exam_element <= 4) {
				exam->clearListQuestion(dashboard->width);
				exam->switchListQuestion(true,false,dashboard->width);
			}
	    	if(exambundle->chose_exam_element == 5) exam->switchListNumber(true,false,dashboard->width);
		    x = true;
	    }
	    ////RIGHT
	    if(c == 77  && x == false){
			if(exambundle->chose_exam_element >= 1 && exambundle->chose_exam_element <= 4) {
				exam->clearListQuestion(dashboard->width);
				exam->switchListQuestion(true,true,dashboard->width);
			}
	    	if(exambundle->chose_exam_element == 5) exam->switchListNumber(true,true,dashboard->width);
		    x = true;
	    }
	    /////CHECK HEIGHT
	    if(dashboard->current_height != exambundle->height){
            ///REDRAW LAST LINE
            dashboard->current_height = exambundle->height; 
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;   
            exam->keepExam(dashboard->width);    
		}
	    x = true;
	}
	///ENTER ===========================================================================
	if(c=='\r' && x == false){
		if(exambundle->chose_exam_element == 5){
			exam->clearListQuestion(dashboard->width);
            exam->EnterListNumber(dashboard->width);
            ////CHECK HEIGHT
	    	if(dashboard->current_height != exambundle->height){
            	///REDRAW LAST LINE
            	dashboard->current_height = exambundle->height; 
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
				dashboard->height = dashboard->current_height;   
            	exam->keepExam(dashboard->width);    
			}
        }
        if(exambundle->chose_exam_element >= 1 && exambundle->chose_exam_element <= 4){
		    exam->EnterChoseItem(dashboard->width);
		}
		if(exambundle->chose_exam_element == 6){	
			exam->clearBlankExamBottom(dashboard->width,8);
        	countdown->clearCLOCK();
        	exam->extractResultExam(dashboard->width);
    		//TITLE
			string title = " THANH TICH ";
	    	int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length())/2;
	    	frame->LineContent(dashboard->width,title,x);
            ///REDRAW LAST LINE
            dashboard->current_height = listSubjectbundle->height;
			frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;
			////GUIDE LINE
			frame->LineGuide(dashboard->height,"ENTER");
        	///CONDITION
        	exambundle->chose_exam_element = 1;
        	exambundle->is_finish_exam = true;
        	exambundle->is_temp_finish = false;
		}
	    x = true;
	}
}
