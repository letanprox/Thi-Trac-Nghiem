#include "ADDCLASS.h"

using namespace std;
    
void ADDCLASS::createElement(int width){
	////CONTRUCTOR VARIBALE
    addClassbundle->widthFrame = 50;
    addClassbundle->margin = 20;

    input01 = new DrawInput();
    input01 -> text_input = (char*) calloc (50,sizeof(char));
	input01 -> text_form = " Nhap ma lop "; 
    input01 -> width = width;
	input01 -> pos_x = addClassbundle->margin + ((width-addClassbundle->margin) - addClassbundle->widthFrame)/2;
	input01 -> cur_pos_y = 11; 
	input01 -> margin_right = width - input01->pos_x - addClassbundle->widthFrame;
	input01 -> is_reset = true; 
	drawInput->DrawInputFunction(input01,' ',true);	
	
    input02 = new DrawInput();
    input02 -> text_input = (char*) calloc (50,sizeof(char));
	input02 -> text_form = " Nhap ten lop "; 
    input02 -> width = width;
	input02 -> pos_x = input01->pos_x;
	input02 -> cur_pos_y = 16; 
	input02 -> margin_right = input01->margin_right;
	input02 -> is_reset = true; 
	drawInput->DrawInputFunction(input02,' ',true);	
	
	buttonEnter = new DrawButton();
	buttonEnter -> text_button = "Them lop ";
	buttonEnter -> width = 14;
	buttonEnter -> cur_pos_y = 21; 
	buttonEnter -> pos_x = input02->pos_x+2;
	buttonEnter -> height = 1;
	buttonEnter -> background_color = 8;
	buttonEnter -> is_reset = true;
	drawbutton->DrawButtonFunction(buttonEnter);
	
    addClassbundle->height = buttonEnter->cur_pos_y + 8;
}
///--------------------------------------------------------------------------------------------------
void ADDCLASS::keepElement(int width){
	////CONTRUCTOR VARIBALE
    input01 -> width = width;
	input01 -> pos_x = addClassbundle->margin + ((width-addClassbundle->margin) - addClassbundle->widthFrame)/2;
	input01 -> margin_right = width - input01->pos_x - addClassbundle->widthFrame;
	input01 -> is_reset = true; 
	drawInput->DrawInputFunction(input01,' ',true);	

    input02 -> width = width;
	input02 -> pos_x = input01->pos_x;
	input02 -> margin_right = input01->margin_right;
	input02 -> is_reset = true; 
	drawInput->DrawInputFunction(input02,' ',true);	
	
	buttonEnter -> pos_x = input02 -> pos_x + 2;
	buttonEnter -> is_reset = true;
	drawbutton->DrawButtonFunction(buttonEnter);
}
///--------------------------------------------------------------------------------------------------
void ADDCLASS::switchElement(bool isMove,bool direct,char c){
		if(isMove == true){
	        if(direct == true) addClassbundle->chose = frame->direction(true,3,addClassbundle->chose);
	        else addClassbundle->chose = frame->direction(false,3,addClassbundle->chose);
	    }
	    if(addClassbundle->chose == 1){
			if(buttonEnter -> background_color != 8){
	    	    buttonEnter -> background_color = 8;
			    drawbutton->DrawButtonFunction(buttonEnter);
			}
		    drawInput->DrawInputFunction(input01,c,true);
		}
		if(addClassbundle->chose == 2){
			if(buttonEnter -> background_color != 8){
	    	    buttonEnter -> background_color = 8;
			    drawbutton->DrawButtonFunction(buttonEnter);
			}
			drawInput->DrawInputFunction(input02,c,true);	
		}
		if(addClassbundle->chose == 3){
			buttonEnter -> background_color = 4;
			drawbutton->DrawButtonFunction(buttonEnter);
		}
}
///--------------------------------------------------------------------------------------------------
void ADDCLASS::executeElement(char c){
	    if(addClassbundle->chose == 1) drawInput->DrawInputFunction(input01,c,false);
		if(addClassbundle->chose == 2) drawInput->DrawInputFunction(input02,c,false);		
}
///--------------------------------------------------------------------------------------------------
bool ADDCLASS::addClass_(){
    string MALOP = input01->text_input;
    string TENLOP = input02->text_input;
    if(!MALOP.empty() && !TENLOP.empty()){
    vector<variable> VARIABLE;
    variable da1 = {"MALOP", MALOP};
    variable da2 = {"TENLOP", TENLOP};
    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    if(addClass(VARIABLE) == true) return true;
	else return false;
	}else return false;
}
