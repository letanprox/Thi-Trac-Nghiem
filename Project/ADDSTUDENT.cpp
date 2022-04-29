#include "ADDSTUDENT.h"

using namespace std;

void ADDSTUDENT::clearBlankAddStudent(int width){
        int pos_x = addstudentbundle->margin + ((width-addstudentbundle->margin) - addstudentbundle->widthFrame)/2;
	    frame->ClearPart(pos_x,input_masv -> cur_pos_y,pos_x + addstudentbundle->widthFrame + addstudentbundle->margin,addstudentbundle->height-1);
}
//-----------------------------------------------------------------------------------
void ADDSTUDENT::createElement(int width){
	int top = 9;
	addstudentbundle->widthFrame = 50;
    addstudentbundle->margin = 10 ;
	////CONTRUCTOR VARIBALE
	input_masv = new DrawInput();
    input_hoten = new DrawInput();
    input_password = new DrawInput();
    
    switchinput_phai = new DrawSwitchInput();
	button_add_student = new DrawButton();
    
    input_masv->text_input = (char*) calloc (50,sizeof(char));
    input_hoten->text_input =  (char*) calloc (50,sizeof(char));
    input_password->text_input =  (char*) calloc (50,sizeof(char));

	input_masv -> text_form = " Nhap ma sv "; 
    input_masv -> width = width;
	input_masv -> pos_x = addstudentbundle->margin + ((width-addstudentbundle->margin) - addstudentbundle->widthFrame)/2;
	input_masv -> cur_pos_y = top; 
	input_masv -> margin_right = width - input_masv->pos_x - addstudentbundle->widthFrame;
	input_masv -> is_reset = true; 
	drawInput->DrawInputFunction(input_masv,' ',true);

	input_hoten -> text_form = " Nhap ho ten "; 
    input_hoten -> width = width;
	input_hoten -> pos_x = input_masv -> pos_x;
	input_hoten -> cur_pos_y = top + 5; 
	input_hoten -> margin_right = input_masv -> margin_right;
	input_hoten -> is_reset = true; 
	drawInput->DrawInputFunction(input_hoten,' ',true);	
	
	switchinput_phai->text_form = "Gioi tinh ";
	switchinput_phai->text = "Nam";
	switchinput_phai->cur_pos_y = input_hoten -> cur_pos_y + 5;
	switchinput_phai->pos_x = input_masv -> pos_x + 2;
	switchinput_phai->width = 11;
	switchinput_phai->height = 1;
	switchinput_phai->background_color = 0;
	switchinput_phai->background_color_switch = 4;
	switchinput_phai->is_reset = true;
	drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
	
	input_password -> text_form = " Nhap mat khau "; 
    input_password -> width = width;
	input_password -> pos_x = input_masv -> pos_x;
	input_password -> cur_pos_y = switchinput_phai->cur_pos_y  + 2; 
	input_password -> margin_right = input_masv -> margin_right;
	input_password -> is_reset = true; 
	drawInput->DrawInputFunction(input_password,' ',true);	
	
	button_add_student -> text_button = "Them sinh vien ";
	button_add_student -> width = 18;
	button_add_student -> cur_pos_y = input_password -> cur_pos_y + 5; 
	button_add_student -> pos_x = input_masv->pos_x + 2;
	button_add_student -> height = 1;
	button_add_student -> background_color = 8;
	button_add_student -> is_reset = true;
	drawbutton->DrawButtonFunction(button_add_student);
	
	addstudentbundle->height = button_add_student -> cur_pos_y + 3;
}
//-----------------------------------------------------------------------------------
void ADDSTUDENT::keepElement(int width){
    input_masv -> width = width;
	input_masv -> pos_x = addstudentbundle->margin + ((width-addstudentbundle->margin) - addstudentbundle->widthFrame)/2;
	input_masv -> margin_right = width - input_masv->pos_x - addstudentbundle->widthFrame;
	input_masv -> is_reset = true; 
	drawInput->DrawInputFunction(input_masv,' ',true);

    input_hoten -> width = width;
	input_hoten -> pos_x = input_masv -> pos_x;
	input_hoten -> margin_right = input_masv -> margin_right;
	input_hoten -> is_reset = true; 
	drawInput->DrawInputFunction(input_hoten,' ',true);	
	
	switchinput_phai->pos_x = input_masv -> pos_x + 2;
	switchinput_phai->is_reset = true;
	drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
	
    input_password -> width = width;
	input_password -> pos_x = input_masv -> pos_x;
	input_password -> margin_right = input_masv -> margin_right;
	input_password -> is_reset = true; 
	drawInput->DrawInputFunction(input_password,' ',true);	

	button_add_student -> pos_x = input_masv->pos_x + 2;
	button_add_student -> is_reset = true;
	drawbutton->DrawButtonFunction(button_add_student);
}
//-----------------------------------------------------------------------------------
void ADDSTUDENT::switchElement(bool isMove,bool direct,char c){
	    if(isMove == true){
	        if(direct == true) addstudentbundle->chose = frame->direction(true,5,addstudentbundle->chose);
	        else addstudentbundle->chose = frame->direction(false,5,addstudentbundle->chose);
	    }
	    if(addstudentbundle->chose == 1){
			if(button_add_student -> background_color != 8){
	    	    button_add_student -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_add_student);
			}
		    drawInput->DrawInputFunction(input_masv,c,true);
		}
		if(addstudentbundle->chose == 2){
	   	    if(switchinput_phai->background_color != 0){
	    	    switchinput_phai->background_color = 0;
		        drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
			}
		    drawInput->DrawInputFunction(input_hoten,c,true);
		}
		if(addstudentbundle->chose == 3){
			switchinput_phai->background_color = 8;
		    drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
		}
		if(addstudentbundle->chose == 4){
			if(button_add_student -> background_color != 8){
	    	    button_add_student -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_add_student);
			}
	   	    if(switchinput_phai->background_color != 0){
	    	    switchinput_phai->background_color = 0;
		        drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
			}
		    drawInput->DrawInputFunction(input_password,c,true);
		}
		if(addstudentbundle->chose == 5){
			button_add_student -> background_color = 4;
			drawbutton->DrawButtonFunction(button_add_student);
		}
}
//-----------------------------------------------------------------------------------
void ADDSTUDENT::switchPhaiStudent(char c){
	switchinput_phai->is_rise_event = true;
    if((int)c == 75){
    	switchinput_phai->is_next = false;
    	switchinput_phai->text = "Nam";
		drawswitchinput->DrawSwitchInputFunction(switchinput_phai);
	}
	if((int)c == 77){
		switchinput_phai->is_next = true;
    	switchinput_phai->text = "Nu ";
		drawswitchinput->DrawSwitchInputFunction(switchinput_phai);	
	}
	switchinput_phai->is_rise_event = false;
}
//-----------------------------------------------------------------------------------
void ADDSTUDENT::executeElement(char c){
	    if(addstudentbundle->chose == 1) drawInput->DrawInputFunction(input_masv,c,false);
		if(addstudentbundle->chose == 2) drawInput->DrawInputFunction(input_hoten,c,false);
		if(addstudentbundle->chose == 4) drawInput->DrawInputFunction(input_password,c,false);		
}
//-----------------------------------------------------------------------------------
bool ADDSTUDENT::addStudent_(){
    string MALOP,MASV,HOTEN,PHAI,PASSWORD;
    MALOP = listClassbundle->MALOP;
    MASV = input_masv->text_input;
    HOTEN = input_hoten->text_input;
    PHAI = switchinput_phai->text;
    PASSWORD = input_password->text_input;
    if(!MALOP.empty() && !MASV.empty() && !HOTEN.empty()){
    vector<variable> VARIABLE;
    if(PHAI.compare("Nam")==0) PHAI = "1";  
	else PHAI = "0";  
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"HOTEN", HOTEN};
	variable da4 = {"PHAI", PHAI};
	variable da5 = {"PASSWORD", PASSWORD};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	VARIABLE.push_back(da5);
	if(addStudent(VARIABLE) == true) return true;
	else return false;
	}else return false;
}
