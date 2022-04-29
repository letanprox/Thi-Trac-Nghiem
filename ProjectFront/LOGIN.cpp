#include "LOGIN.h"

using namespace std;
    
    DrawInputForm* inputForm_login_1;
    DrawInputForm* inputForm_login_2;
    DrawButton* buttonForn_login_1;
    

    
void LOGIN::createElement(int width){
	
        int widthform = 40;
        
        int margin = width/2 - widthform/2;
	
	    inputForm_login_1  = new DrawInputForm();
	    inputForm_login_2  = new DrawInputForm();
	    
	    inputForm_login_1 -> text_input = new char[100];
	    inputForm_login_2 -> text_input = new char[100];
	    
        inputForm_login_1 -> width = width;
		inputForm_login_1 -> pos_x = margin;
		inputForm_login_1 -> cur_pos_y = 8;
        inputForm_login_1 -> margin_right = margin;
		inputForm_login_1 -> text_form = " Nhap MSSV "; 
		inputForm_login_1 -> ischangeWidth = true;  
		drawInputform->DrawInputFormFunction(inputForm_login_1,' ',true,0);

        inputForm_login_2 -> width = width;
		inputForm_login_2 -> pos_x = margin;
		inputForm_login_2 -> cur_pos_y = inputForm_login_1->cur_pos_y + inputForm_login_1->height_text + 5; 
		inputForm_login_2 -> margin_right = margin;
		inputForm_login_2 -> text_form = " Nhap mat khau "; 
		inputForm_login_2 -> ischangeWidth = true;  
		
		drawInputform->DrawInputFormFunction(inputForm_login_2,' ',true,0); 

		buttonForn_login_1 = new DrawButton();
		
		buttonForn_login_1 -> width = 20;
		buttonForn_login_1 -> height = 1;
		buttonForn_login_1 -> background_color = 8;
		buttonForn_login_1 -> text_button = "Dang nhap";
		buttonForn_login_1 -> is_check = false;
		buttonForn_login_1 -> is_reset = true;
		buttonForn_login_1 -> cur_pos_y = inputForm_login_2->cur_pos_y + inputForm_login_2->height_text + 5; 
		buttonForn_login_1 -> pos_x = margin + (widthform - (buttonForn_login_1->width))/2 ;
		
		drawbutton->DrawButtonFunction(buttonForn_login_1);
		
		
		loginbundle->height = buttonForn_login_1 -> pos_y + buttonForn_login_1->height + 2;
}


void LOGIN::keepElement(int width){
	    int widthform = 40;
        int margin = width/2 - widthform/2;
	
        inputForm_login_1 -> width = width; 
        inputForm_login_2 -> width = width;
        
        inputForm_login_1->ischangeWidth = true;
        inputForm_login_2->ischangeWidth = true;
        
        inputForm_login_1 -> margin_right = margin;
        inputForm_login_2 -> margin_right = margin;
        inputForm_login_1 -> pos_x = margin;
        inputForm_login_2 -> pos_x = margin;
        
        
        drawInputform->DrawInputFormFunction(inputForm_login_1,' ',true,loginbundle->height); 
        inputForm_login_2 -> cur_pos_y = inputForm_login_1->cur_pos_y + inputForm_login_1->height_text + 5; 
        drawInputform->DrawInputFormFunction(inputForm_login_2,' ',true,loginbundle->height);
        
        buttonForn_login_1 -> is_reset = true;
		buttonForn_login_1 -> pos_x = margin + (widthform - (buttonForn_login_1->width))/2 ;
		drawbutton->DrawButtonFunction(buttonForn_login_1);
}

int direction(bool direct,int max,int cur){
        if(direct == true){
		    if(max == cur) return 1;
		    else return cur+1;
		}else{
		    if(cur == 1) return max;
		    else return cur-1;		
		}
}



void LOGIN::switchElement(bool isMove,bool direct,char c){
	     
	    if(isMove == true){
	    	
	        if(direct == true) loginbundle->chose = direction(true,3,loginbundle->chose);
	        else loginbundle->chose = direction(false,3,loginbundle->chose);
	    
	    }
	    
        if(loginbundle->chose == 1 ){
        	buttonForn_login_1 -> background_color = 8;
		    drawbutton->DrawButtonFunction(buttonForn_login_1);
        	drawInputform->DrawInputFormFunction(inputForm_login_1,c,true,loginbundle->height); 
        	customAttribute->setPosionCursor(inputForm_login_1->position_cursor_x, inputForm_login_1->position_cursor_y);
		}
		if(loginbundle->chose == 2 ){ 
		    buttonForn_login_1 -> background_color = 8;
		    drawbutton->DrawButtonFunction(buttonForn_login_1);
		    drawInputform->DrawInputFormFunction(inputForm_login_2,c,true,loginbundle->height); 
            customAttribute->setPosionCursor(inputForm_login_2->position_cursor_x, inputForm_login_2->position_cursor_y);	
		}
		
		if(loginbundle->chose == 3 ){
			buttonForn_login_1 -> background_color = 9;
		    drawbutton->DrawButtonFunction(buttonForn_login_1);
		    customAttribute->setPosionCursor(0, 0);	
		}
		
		
}


void LOGIN::executeElement(char c){
        
        if(loginbundle->chose == 1 ){	
        	drawInputform->DrawInputFormFunction(inputForm_login_1,c,false,loginbundle->height); 
				
				inputForm_login_2 -> cur_pos_y = inputForm_login_1->cur_pos_y + inputForm_login_1->height_text + 5; 		    
				if(inputForm_login_2->cur_pos_y  != inputForm_login_2->pos_y){
					
				    inputForm_login_2->ischangeWidth =  true;	
                    drawInputform->DrawInputFormFunction(inputForm_login_2,' ',true,loginbundle->height); 
                    
                    buttonForn_login_1 -> cur_pos_y = inputForm_login_2->cur_pos_y + inputForm_login_2->height_text + 5; 
                    drawbutton->DrawButtonFunction(buttonForn_login_1);
                }      
		}
		if(loginbundle->chose == 2 ){
				drawInputform->DrawInputFormFunction(inputForm_login_2,c,false,loginbundle->height); 
				
				buttonForn_login_1 -> cur_pos_y = inputForm_login_2->cur_pos_y + inputForm_login_2->height_text + 5; 
				
				if(buttonForn_login_1->cur_pos_y  != buttonForn_login_1->pos_y){
				    drawbutton->DrawButtonFunction(buttonForn_login_1);
				}
				
		}
		
		loginbundle->height = buttonForn_login_1 -> pos_y + buttonForn_login_1->height + 2;
		
}


void LOGIN::emplementLogin(){

}

