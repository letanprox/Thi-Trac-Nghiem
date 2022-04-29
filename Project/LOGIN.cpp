#include "LOGIN.h"
#include "APIGETDATA.h"

using namespace std;
//====================================================================================
void LOGIN::createElement(int width){
        int widthform = 40;
        int margin = width/2 - widthform/2;
	
	    inputForm_login_1  = new DrawInputForm();
	    inputForm_login_2  = new DrawInputForm();
		buttonForn_login_1 = new DrawButton();
			    
	    inputForm_login_1 -> text_input = (char*) calloc (500,sizeof(char));
	    inputForm_login_2 -> text_input = (char*) calloc (500,sizeof(char));
	    
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

		buttonForn_login_1 -> width = 20;
		buttonForn_login_1 -> height = 1;
		buttonForn_login_1 -> background_color = 8;
		buttonForn_login_1 -> text_button = "Dang nhap";
		buttonForn_login_1 -> is_reset = true;
		buttonForn_login_1 -> cur_pos_y = inputForm_login_2->cur_pos_y + inputForm_login_2->height_text + 5; 
		buttonForn_login_1 -> pos_x = margin + (widthform - (buttonForn_login_1->width))/2 ;
		drawbutton->DrawButtonFunction(buttonForn_login_1);
				
		loginbundle->height = buttonForn_login_1 -> pos_y + buttonForn_login_1->height + 2;
}
//====================================================================================
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
//====================================================================================
void LOGIN::switchElement(bool isMove,bool direct,char c){
	    if(isMove == true){
	        if(direct == true) loginbundle->chose = frame_login->direction(true,3,loginbundle->chose);
	        else loginbundle->chose = frame_login->direction(false,3,loginbundle->chose);
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
			buttonForn_login_1 -> background_color = 4;
		    drawbutton->DrawButtonFunction(buttonForn_login_1);
		}
}
//====================================================================================
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
//====================================================================================
void LOGIN::implementLogin(){
	if(loginbundle->chose == 3){
		//GET CHAIN
    	string MASV_ = frame_login->RemoveSpaceString(inputForm_login_1->text_input);
		string PASSWORD_ = inputForm_login_2->text_input;
		//CONDITION
		if(!MASV_.empty()){
			//	CONDITON
			if(MASV_.compare("GV") == 0){
				if(PASSWORD_.compare("GV") == 0){
					consolebundle->message = "DANG NHAP THANH CONG";
					loginbundle->isGotoProgram = true;
	    			loginbundle->nameUser = "KY THU";
	    			loginbundle->maUser = "GV";	
	    			loginbundle->maLop = "GV";
	    		}else consolebundle->message = "SAI MAT KHAU";
			}else{
				//QUERY DATABASE
				vector<string> select_title_element,select_element;
				select_title_element.push_back("MALOP");
				select_title_element.push_back("MASV");
				select_title_element.push_back("HOTEN");
				select_title_element.push_back("PASSWORD");
				select_element.push_back("MASV="+MASV_);
    			vector<string> data = selectManyElement("student.txt",select_title_element,select_element);
    			//CHECK DATABASE
    			if(!data.empty()){
        			string MALOP = "";
        			string MASV = "";
        			string HOTEN = "";
        			string PASSWORD = "";
        			int o = 1;	
    
					for(int i = 0 ; i < data[0].size(); i++){
        				if(o == 1)
		        			if((data[0][i]) != ('#')) MALOP = MALOP + data[0][i];
		        			else o = 2;
		        			
		        		else if(o == 2)
		        			if((data[0][i]) != ('#')) MASV = MASV + data[0][i];
		        			else o = 3;
		        
	 	    			else if(o == 3) 
						 	if((data[0][i]) != ('#')) HOTEN = HOTEN + data[0][i];
		        			else o = 4;
			   	
		    			else if(o == 4)
			    			if((data[0][i]) != ('#')) PASSWORD = PASSWORD + data[0][i];
			    			
					}

	    			if(PASSWORD.compare(PASSWORD_) == 0){
	    				consolebundle->message = "DANG NHAP THANH CONG";
				    	loginbundle->isGotoProgram = true;
	    				loginbundle->nameUser = HOTEN;
	    				loginbundle->maUser = MASV;	
	    				loginbundle->maLop = MALOP;
	    			}else consolebundle->message = "SAI MAT KHAU";
					
				}else consolebundle->message = "KHONG CO SINH VIEN";

			}
		}
	}
}
