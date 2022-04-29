#include "CONTROL.h"

using namespace std;

void CONTROL::LISTQUESTION_CONTROL(char c){
    bool x = false;
    // MOVE ==========================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	        if(listQuestionbundle->is_editquestion == false)  ListQuestion->switchElement(dashboard->width,true);
            else ListQuestion->switchEditQuestion(true,false,' ');
		    x = true;
	    }
	    ///BOTTOM 	
	    if(c == 80  && x == false){
		    if(listQuestionbundle->is_editquestion == false) ListQuestion->switchElement(dashboard->width,false);
            else ListQuestion->switchEditQuestion(true,true,' ');	
		    x = true;
	    }
	    if(listQuestionbundle->is_editquestion == true) {
		    if(listQuestionbundle->chose_edit_elementquestion == 6){
		    	ListQuestion->switchEditAnswerQuestion(c);
			}
			ListQuestion->switchEditQuestion(false,true,c);	
	    }
	    x = true;
	}
	///ESC  ==============================================================================
	if((int)c == 27 && x == false){	
		if(listQuestionbundle->is_editquestion == false){   
            ListQuestion->clearBlankElement(dashboard->width);
            ListSubject->keepElement(dashboard->width);
            ////TITLE
            int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            ////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   ENTER");
            listQuestionbundle->is_in_question = false;
        }else{
		    ListQuestion->clearBlankEditElement(dashboard->width);
		    ListQuestion->keepElement(dashboard->width);
            ///REDRAW LAST LINE
            dashboard->current_height = listQuestionbundle->height;
			frame->ReDrawFrameContent(dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			dashboard->height = dashboard->current_height;
			///TITLE
		    int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;	
            frame->LineContent(dashboard->width," MON HOC: "+listSubjectbundle->MAMH+" ",x);
            ////GUIDE LINE
			frame->LineGuide(dashboard->height,"ESC   F4:XOA   ENTER");
            listQuestionbundle->is_editquestion = false;
		}
        x = true;
	}
	//F  ================================================================================
	if((int)c == 0){
		c = getch();
		///F4
		if(c == 62  && x == false){
        	if(listQuestionbundle->is_editquestion == false){
			    if(ListQuestion->deleteElement() == true){
					/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "DA XOA CAU HOI";
					console->RISE_CONSOLE();
		        	ListQuestion->clearBlankElement(dashboard->width);
		        	ListQuestion->createElement(dashboard->width);
		        }
			}
			x = true;
		}
	}
	///ENTER ============================================================================
	if(c=='\r' && x == false){
		if(listQuestionbundle->is_editquestion == false){
			if(listQuestionbundle->size>0){ 
			    ////CLEAR LIST QUESTION ELEMENT
		    	ListQuestion->clearBlankElement(dashboard->width);
		    	////SHOW EDIT ELEMENT
		    	ListQuestion->createEditQuestion(false,dashboard->width);
            	dashboard->current_height = listQuestionbundle->height;
            	///REDRAW LAST LINE
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
			    ///TITLE
			    int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
            	frame->LineContent(dashboard->width," Id Cau hoi: "+listQuestionbundle->Id+" ",x);
            	////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
            	////REDRAW EDIT
			    ListQuestion->keepEditQuestion(dashboard->width);
			    ////CURSOR
			    listQuestionbundle->chose_edit_elementquestion = 1 ;
			    ListQuestion->switchEditQuestion(false,false,' ');
			    /////CONDITION
			    listQuestionbundle->is_editquestion = true;
            }
        }else{
        	if(listQuestionbundle->chose_edit_elementquestion != 7){
                ListQuestion->switchEditQuestion(true,true,' ');
            }else{
            	if(ListQuestion->updateEditQuestion() == true){
            		/////RISE CONSOLE
					consolebundle->top = dashboard->height + 2;
					consolebundle->message = "CAP NHAT CAU HOI THANH CONG";
					console->RISE_CONSOLE();
				}
			}
		}
	    x = true;
	}
	///TYPE   ============================================================================
	if(x == false){
		if(listQuestionbundle->is_editquestion == true){
			////EXCUTE ELEMENT
		    ListQuestion->excuteEditQuestion(c);
		    ////IF HEIGHT CHANGE
		    if(dashboard->current_height != listQuestionbundle->height){
				dashboard->current_height = listQuestionbundle->height;
				frame->ReDrawFrameContent( dashboard->current_height,dashboard->height,dashboard->width,dashboard->color_Theme);
			    dashboard->height = dashboard->current_height;
			    ////CURSOR
			    ListQuestion->switchEditQuestion(false,false,' ');
			}
		}
        x = true;
	}
}
