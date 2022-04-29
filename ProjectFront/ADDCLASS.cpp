#include "ADDCLASS.h"

using namespace std;
    
    DrawInputForm* inputForm01;
    DrawInputForm* inputForm02;
    


void ADDCLASS::createElement(int width){
	    inputForm01  = new DrawInputForm();
	    inputForm02  = new DrawInputForm();
	    
	    inputForm01 -> text_input = new char[1000];
	    inputForm02 -> text_input = new char[1000];
	    
        inputForm01 -> ischangeWidth = true;  
        inputForm01 -> width = width;
		inputForm01 -> pos_x = 35;
		inputForm01 -> cur_pos_y = 11; 
		if(width > 130){
            inputForm01 -> margin_right = width/2;
		}else if(width < 100){
            inputForm01 -> margin_right = 20;
		}else{
            inputForm01 -> margin_right = 30;
		}
		inputForm01 -> text_form = " Nhap ma lop "; 
		drawInputform->DrawInputFormFunction(inputForm01,' ',true,0);

        inputForm02 -> ischangeWidth = true;  
        inputForm02 -> width = width;
		inputForm02 -> pos_x = 35;
		inputForm02 -> cur_pos_y = inputForm01->cur_pos_y + inputForm01->height_text + 5; 
		if(width > 130){
		    inputForm02 -> margin_right = width/2;
		}else if(width < 100){
			inputForm02 -> margin_right = 20;
		}else{
			inputForm02 -> margin_right = 30;
		}
		inputForm02 -> text_form = " Nhap ten lop "; 
		drawInputform->DrawInputFormFunction(inputForm02,' ',true,0); 
        
        addClassbundle->height = inputForm02->cur_pos_y + inputForm02->height_text+10;
}



void ADDCLASS::keepElement(int width){
        inputForm01 -> width = width; 
        inputForm02 -> width = width;
        
        inputForm01->ischangeWidth = true;
        inputForm02->ischangeWidth = true;
        
        if(width > 130){
		    inputForm02 -> margin_right = width/2;
            inputForm01 -> margin_right = width/2;
		}else if(width < 100){
			inputForm02 -> margin_right = 20;
            inputForm01 -> margin_right = 20;
		}else{
			inputForm02 -> margin_right = 30;
            inputForm01 -> margin_right = 30;
		}
        
        drawInputform->DrawInputFormFunction(inputForm01,' ',true,addClassbundle->height); 
        inputForm02 -> cur_pos_y = inputForm01->cur_pos_y + inputForm01->height_text + 5; 
        drawInputform->DrawInputFormFunction(inputForm02,' ',true,addClassbundle->height);
		
		addClassbundle->height = inputForm02->cur_pos_y + inputForm02->height_text + 10;
}

void ADDCLASS::switchElement(char c){
        if(addClassbundle->chose == 1 ){
        	drawInputform->DrawInputFormFunction(inputForm01,c,true,addClassbundle->height); 
        	customAttribute->setPosionCursor(inputForm01->position_cursor_x, inputForm01->position_cursor_y);
		}
		if(addClassbundle->chose == 2 ){ 
		    drawInputform->DrawInputFormFunction(inputForm02,c,true,addClassbundle->height); 
            customAttribute->setPosionCursor(inputForm02->position_cursor_x, inputForm02->position_cursor_y);	
		}
}


void ADDCLASS::executeElement(char c){
        
        if(addClassbundle->chose == 1 ){	
				drawInputform->DrawInputFormFunction(inputForm01,c,false,addClassbundle->height); 	
				
				inputForm02->cur_pos_y =  inputForm01->cur_pos_y + inputForm01->height_text + 5;		    
				if(inputForm02->cur_pos_y  != inputForm02->pos_y){
				    inputForm02->ischangeWidth =  true;	
                    drawInputform->DrawInputFormFunction(inputForm02,' ',true,addClassbundle->height); 
                }      
		}
		if(addClassbundle->chose == 2 ){
				drawInputform->DrawInputFormFunction(inputForm02,c,false,addClassbundle->height); 
		}
		
		addClassbundle->height = inputForm02->cur_pos_y + inputForm02->height_text + 10;
		
}





