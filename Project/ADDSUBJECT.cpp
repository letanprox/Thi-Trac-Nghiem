#include "ADDSUBJECT.h"

using namespace std;
    
void ADDSUBJECT::createElement(int width){
	////CONTRUCTOR VARIBALE
    addSubjectbundle->widthFrame = 50;
    addSubjectbundle->margin = 20;

    input01_subject = new DrawInput();
    input01_subject -> text_input = (char*) calloc (50,sizeof(char));
	input01_subject -> text_form = " Nhap ma mon hoc "; 
    input01_subject -> width = width;
	input01_subject -> pos_x = addSubjectbundle->margin + ((width-addSubjectbundle->margin) - addSubjectbundle->widthFrame)/2;
	input01_subject -> cur_pos_y = 11; 
	input01_subject -> margin_right = width - input01_subject->pos_x - addSubjectbundle->widthFrame;
	input01_subject -> is_reset = true; 
	drawInput->DrawInputFunction(input01_subject,' ',true);	
	
    input02_subject = new DrawInput();
    input02_subject -> text_input = (char*) calloc (50,sizeof(char));
	input02_subject -> text_form = " Nhap ten mon hoc "; 
    input02_subject -> width = width;
	input02_subject -> pos_x = input01_subject->pos_x;
	input02_subject -> cur_pos_y = 16; 
	input02_subject -> margin_right = input01_subject->margin_right;
	input02_subject -> is_reset = true; 
	drawInput->DrawInputFunction(input02_subject,' ',true);	
	
	buttonEnter_subject = new DrawButton();
	buttonEnter_subject -> text_button = "Them mon hoc ";
	buttonEnter_subject -> width = 14;
	buttonEnter_subject -> cur_pos_y = 21; 
	buttonEnter_subject -> pos_x = input02_subject->pos_x+2;
	buttonEnter_subject -> height = 1;
	buttonEnter_subject -> background_color = 8;
	buttonEnter_subject -> is_reset = true;
	drawbutton->DrawButtonFunction(buttonEnter_subject);
	
    addSubjectbundle->height = buttonEnter_subject->cur_pos_y + 8;
}
//--------------------------------------------------------------------------------------------------------
void ADDSUBJECT::keepElement(int width){
	////CONTRUCTOR VARIBALE
    input01_subject -> width = width;
	input01_subject -> pos_x = addSubjectbundle->margin + ((width-addSubjectbundle->margin) - addSubjectbundle->widthFrame)/2;
	input01_subject -> margin_right = width - input01_subject->pos_x - addSubjectbundle->widthFrame;
	input01_subject -> is_reset = true; 
	drawInput->DrawInputFunction(input01_subject,' ',true);	

    input02_subject -> width = width;
	input02_subject -> pos_x = input01_subject->pos_x;
	input02_subject -> margin_right = input01_subject->margin_right;
	input02_subject -> is_reset = true; 
	drawInput->DrawInputFunction(input02_subject,' ',true);	
	
	buttonEnter_subject -> pos_x = input02_subject -> pos_x + 2;
	buttonEnter_subject -> is_reset = true;
	drawbutton->DrawButtonFunction(buttonEnter_subject);
}
//--------------------------------------------------------------------------------------------------------
void ADDSUBJECT::switchElement(bool isMove,bool direct,char c){
		if(isMove == true){
	        if(direct == true) addSubjectbundle->chose = frame->direction(true,3,addSubjectbundle->chose);
	        else addSubjectbundle->chose = frame->direction(false,3,addSubjectbundle->chose);
	    }
	    if(addSubjectbundle->chose == 1){
			if(buttonEnter_subject -> background_color != 8){
	    	    buttonEnter_subject -> background_color = 8;
			    drawbutton->DrawButtonFunction(buttonEnter_subject);
			}
		    drawInput->DrawInputFunction(input01_subject,c,true);
		}
		if(addSubjectbundle->chose == 2){
			if(buttonEnter_subject -> background_color != 8){
	    	    buttonEnter_subject -> background_color = 8;
			    drawbutton->DrawButtonFunction(buttonEnter_subject);
			}
			drawInput->DrawInputFunction(input02_subject,c,true);	
		}
		if(addSubjectbundle->chose == 3){
			buttonEnter_subject -> background_color = 4;
			drawbutton->DrawButtonFunction(buttonEnter_subject);
		}
}
//--------------------------------------------------------------------------------------------------------
void ADDSUBJECT::executeElement(char c){
	    if(addSubjectbundle->chose == 1) drawInput->DrawInputFunction(input01_subject,c,false);
		if(addSubjectbundle->chose == 2) drawInput->DrawInputFunction(input02_subject,c,false);		
}
//--------------------------------------------------------------------------------------------------------
bool ADDSUBJECT::addSubject_(){
    string MAMH = input01_subject->text_input;
    string TENMH = input02_subject->text_input;
    if(!MAMH.empty() && !TENMH.empty()){
    vector<variable> VARIABLE;
    variable da1 = {"MAMH", MAMH};
    VARIABLE.push_back(da1);
    variable da2 = {"TENMH", TENMH};
    VARIABLE.push_back(da2);
    if(addSubject(VARIABLE) == true) return true;
	else return false;
	} return false;
}

