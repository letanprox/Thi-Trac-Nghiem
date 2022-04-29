#include "CONTROL.h"

using namespace std;

void CONTROL::LISTSTUDENT_CONTROL(char c){
    bool x = false;
    //MOVE =============================================================================================
    if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
	        if(listStudentbundle->is_editstudent == false)  ListStudent->switchElement(dashboard->width,true);
            else ListStudent->switchEditStudent(true,false,' ');
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
		    if(listStudentbundle->is_editstudent == false)  ListStudent->switchElement(dashboard->width,false);
            else ListStudent->switchEditStudent(true,true,' ');	
		    x = true;
	    }
	    //LEFT
	    if(c == 75  && x == false){
			if(listStudentbundle->is_editstudent == false)  ListStudent->switchSearchElement(c);
		}
		//RIGHT
	    if(c == 77  && x == false){
			if(listStudentbundle->is_editstudent == false)  ListStudent->switchSearchElement(c);
		}
		if(listStudentbundle->is_editstudent == true){  
			    if(listStudentbundle->chose_edit_elementstudent == 1)  ListStudent->switchEditStudent(false,true,c);
		        if(listStudentbundle->chose_edit_elementstudent == 2)  ListStudent->switchEditPhaiStudent(c);
	            if(listStudentbundle->chose_edit_elementstudent == 3)  ListStudent->switchEditStudent(false,true,c);
	            x = true;
	    }
	    x = true;
	}
	///ESC =============================================================================================
	if((int)c == 27 && x == false){	
		if(listStudentbundle->is_editstudent == false){   
            ListStudent->clearBlankElement(dashboard->width);
            ListClass->keepElement(dashboard->width);
            int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," DANH SACH LOP ",x);
            frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   TYPE:TIMKIEM   ENTER");
            listStudentbundle->is_in_student = false;
        }else{
        	ListStudent->clearBlankEditElement(dashboard->width);
        	ListStudent->keepElement(dashboard->width);
        	int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
            frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
            frame->LineGuide(dashboard->height,"ESC   F4:XOA   TYPE:TIMKIEM   ENTER:SUA");
            listStudentbundle->is_editstudent = false;
		}
        x = true;
	}
	///F   =============================================================================================
	if((int)c == 0){
		c = getch();
		///F4
		if(c == 62  && x == false){
			if(listStudentbundle->is_editstudent == false){
			    ListStudent->deleteElement();
			    ///CONSOLE
		    	consolebundle->message = "XOA SINH VIEN THANH CONG";
		    	consolebundle->top = dashboard->height + 2;
		    	console->RISE_CONSOLE();	
		        ListStudent->clearBlankElement(dashboard->width);
		        ListStudent->createElement(dashboard->width);
			}
			x = true;
		}
	}
	///ENTER ===========================================================================================
	if(c=='\r' && x == false){
		if(listStudentbundle->is_editstudent == false){
			if(listStudentbundle->size > 0){ 
		    	ListStudent->clearBlankElement(dashboard->width);
		    	ListStudent->createEditStudent(dashboard->width);
            	int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
            	frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
            	frame->LineGuide(dashboard->height,"ESC   ENTER");
            	listStudentbundle->chose_edit_elementstudent = 4;
            	ListStudent->switchEditStudent(true,true,' ');  
            	listStudentbundle->is_editstudent = true;
            }
        }else{
        	if(listStudentbundle->chose_edit_elementstudent == 4){
        	    ListStudent->updateEditStudent();
			    ///CONSOLE
		    	consolebundle->message = "CAP NHAT SINH VIEN THANH CONG";
		    	consolebundle->top = dashboard->height + 2;
		    	console->RISE_CONSOLE();
        	    ListStudent->clearBlankEditElement(dashboard->width);
				ListStudent->keepElement(dashboard->width);
        	    int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
                frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
                frame->LineGuide(dashboard->height,"ESC   F4:XOA   TYPE:TIMKIEM   ENTER:SUA");
                listStudentbundle->is_editstudent = false;
            }else ListStudent->switchEditStudent(true,true,' ');	
		}
	    x = true;
	}
	///TYPE ============================================================================================
	if(x == false){
		if(listStudentbundle->is_editstudent == true) ListStudent->excuteEditStudent(c);
		if(listStudentbundle->is_editstudent == false){
			ListStudent->excuteSearchElement(dashboard->width,c);
			ListStudent->switchSearchElement(' ');
		}
        x = true;
	}
}
