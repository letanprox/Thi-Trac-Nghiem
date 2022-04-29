#include "LISTSTUDENT.h"

#include "APIGETDATA.h"

using namespace std;

void LISTSTUDENT::setListStudent(bool out,bool iscreate,int width){
if(liststudent.size() > 0){

    int x_leftFrame = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 + 1;
    int x_middleFrame_one =  x_leftFrame + listStudentbundle->widthFrame*1/10;
    int x_middleFrame_two =  x_middleFrame_one + listStudentbundle->widthFrame*3/10;
    int x_rightFrame =  x_middleFrame_two + listStudentbundle->widthFrame*4/10;	
    int size;if(listStudentbundle->size >= liststudent.size()){size = liststudent.size();}else{size = listStudentbundle->size;}
    
    int y_content = listStudentbundle->y_title + 2;
	int x_text;
	string title;
	
	if(iscreate == true){
		//DRAW LINE WIDTH
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listStudentbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listStudentbundle->y_title - 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listStudentbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listStudentbundle->y_title + 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listStudentbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listStudentbundle->y_title + listStudentbundle->size + 2);
				cout<< "\xC4";}
		//DRAW LINE HEIGHT
    	for(int y = listStudentbundle->y_title-1; y <= listStudentbundle->y_title + listStudentbundle->size + 2; y++)
        	for(int x = x_leftFrame - 1; x <= x_leftFrame + listStudentbundle->widthFrame; x++){
		    	if(x == x_leftFrame - 1){
		    		customAttribute->setPosionCursor(x,y);
		    		if(y == listStudentbundle->y_title-1)cout<< "\xDA";
		    		else if(y == listStudentbundle->y_title + listStudentbundle->size + 2) cout<< "\xC0";
					else cout<< "\xB3";
				}
				if(x == x_middleFrame_one){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listStudentbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listStudentbundle->y_title + listStudentbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_middleFrame_two){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listStudentbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listStudentbundle->y_title + listStudentbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_rightFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listStudentbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listStudentbundle->y_title + listStudentbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_leftFrame + listStudentbundle->widthFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listStudentbundle->y_title-1) cout<< "\xBF";
		    		else if(y == listStudentbundle->y_title + listStudentbundle->size + 2) cout<< "\xD9";
					else cout<< "\xB3";
				}
			}
		//-----------------------------------------------
		//DRAW TITLE
		title = "STT";
		x_text = x_leftFrame + ((x_middleFrame_one - x_leftFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listStudentbundle->y_title);
		cout << title;    		
		//DRAW TITLE
		title = "MASV";
		x_text = x_middleFrame_one + ((x_middleFrame_two - x_middleFrame_one) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listStudentbundle->y_title);
		cout << title;  	
		//DRAW TITLE
		title = "HO TEN";
		x_text = x_middleFrame_two + ((x_rightFrame - x_middleFrame_two) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listStudentbundle->y_title);
		cout << title;  
		//DRAW TITLE
		title = "GIOI TINH";
		x_text = x_rightFrame + ((x_leftFrame+listStudentbundle->widthFrame-x_rightFrame) - (title).length() + 1)/2;
		customAttribute->setPosionCursor(x_text,listStudentbundle->y_title);
		cout << title;  
	}
	//DRAW ITEM
	//----------------------------------------------------
    int k = listStudentbundle->forward;
    int chose = 1;
	for(int i = y_content ; i < y_content + size ; i++){
		if(listStudentbundle->chose == chose){
			if(out == true) customAttribute->setBackgroundText(7,4); 
			else customAttribute->setBackgroundText(9,4); 
			    for(int e = x_leftFrame; e < x_leftFrame + listStudentbundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_middleFrame_one)
		    		cout << "";	
		    		else if(e == x_middleFrame_two)
		    		cout << "";	
		    		else if(e == x_rightFrame)
		    		cout << "";	
		    		else cout <<" ";
			    } 
			///ADD TEXT
			x_text = x_leftFrame + ((x_middleFrame_one - x_leftFrame) - 1)/2;
				customAttribute->setPosionCursor(x_text,i); 
			    cout << k+1;	   
	    	x_text = x_middleFrame_one + ((x_middleFrame_two - x_middleFrame_one) - (liststudent[k].MASV).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
			    cout << liststudent[k].MASV;	    
			x_text = x_middleFrame_two + ((x_rightFrame - x_middleFrame_two) - (liststudent[k].HOTEN).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
			    cout << liststudent[k].HOTEN;	
			
			string PHAI;
	    	    if(liststudent[k].PHAI == true) PHAI = "Nam";
	    		else PHAI = "Nu ";
			x_text = x_rightFrame + ((x_leftFrame+listStudentbundle->widthFrame-x_rightFrame) - (PHAI).length()+1)/2;
				customAttribute->setPosionCursor(x_text,i); 
			    cout << PHAI;  
			customAttribute->setBackgroundText(7,0); 
			//GET VALUE
		    listStudentbundle->MASV = liststudent[k].MASV;
		    listStudentbundle->HOTEN = liststudent[k].HOTEN;
		    listStudentbundle->PHAI = PHAI;
		    listStudentbundle->PASSWORD = liststudent[k].PASSWORD;
		}else{
			customAttribute->setBackgroundText(7,0); 
		
			for(int e = x_leftFrame; e < x_leftFrame + listStudentbundle->widthFrame ; e++){
            	customAttribute->setPosionCursor(e,i);
		    	if(e == x_middleFrame_one)
		    		cout << "";	
		    	else if(e == x_middleFrame_two)
		    		cout << "";	
		    	else if(e == x_rightFrame)
		    		cout << "";	
		    	else cout <<" ";
			}	
			///ADD TEXT
			x_text = x_leftFrame + ((x_middleFrame_one - x_leftFrame) - 1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << k+1;	   
	    	x_text = x_middleFrame_one + ((x_middleFrame_two - x_middleFrame_one) - (liststudent[k].MASV).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << liststudent[k].MASV;	    		   
			x_text = x_middleFrame_two + ((x_rightFrame - x_middleFrame_two) - (liststudent[k].HOTEN).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << liststudent[k].HOTEN;		
			string PHAI;
	        	if(liststudent[k].PHAI == true) PHAI = "Nam";
	    		else PHAI = "Nu ";
			x_text = x_rightFrame + ((x_leftFrame+listStudentbundle->widthFrame-x_rightFrame) - (PHAI).length()+1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << PHAI; 
			customAttribute->setBackgroundText(7,0); 
		}
	k = k + 1;
	chose = chose + 1;	
	}
	listStudentbundle->height = y_content + listStudentbundle->max_size + 3;
	///-------------
	customAttribute->setPosionCursor(0,0);
	customAttribute->DisplayCursor(false);
}
}
//----------------------------------------------------------------------------------------------------------
void LISTSTUDENT::clearBlankElement(int width){
        int pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,input_search_hoten->pos_y,pos_x + listStudentbundle->widthFrame+2,listStudentbundle->height - 1);
}
void LISTSTUDENT::clearBlankListElement(int width){
        int pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,listStudentbundle->y_title-1,pos_x + listStudentbundle->widthFrame+2,listStudentbundle->height - 1);
}
//----------------------------------------------------------------------------------------------------------
void LISTSTUDENT::createElement(int width){
	vector<variable> VARIABLE;
    string MALOP = listClassbundle->MALOP;
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	liststudent = showAllStudent(VARIABLE);
	
	listStudentbundle->max_size = 13;
	if(liststudent.size() > listStudentbundle->max_size){listStudentbundle->size = listStudentbundle->max_size;}else{listStudentbundle->size = liststudent.size();}
    listStudentbundle->forward = 0;    
    listStudentbundle->chose = 1;  
	listStudentbundle->widthFrame  = 70;
    listStudentbundle->y_title = 11;
    listStudentbundle->margin = 20;
    setListStudent(false,true,width);

	searchElement(width,' ');
    status = 1;
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::keepElement(int width){
	keepSearchElement(width,' ');
    setListStudent(false,true,width);
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::switchElement(int width,bool move){
    moveElement(width,move);
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::moveElement(int width,bool move){
	if(move == true){
		if(listStudentbundle->chose > 1 || listStudentbundle->forward != 0){
	    if(listStudentbundle->chose > 1){
			listStudentbundle->chose = listStudentbundle->chose - 1;
	    }else{
	    	if(listStudentbundle->forward > 0){
			    listStudentbundle->forward = listStudentbundle->forward - 1;
			}
		}
		setListStudent(false,false,width);
		}
	}else{
		if(listStudentbundle->chose < listStudentbundle->size || listStudentbundle->forward != liststudent.size() - listStudentbundle->size){
	    if(listStudentbundle->chose < listStudentbundle->size){
			listStudentbundle->chose = listStudentbundle->chose + 1;
	    }else{
	    	if(listStudentbundle->forward < liststudent.size() - listStudentbundle->size){
			    listStudentbundle->forward = listStudentbundle->forward + 1;
			}
		}
		setListStudent(false,false,width);
		}
	}
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::deleteElement(){
    vector<variable> VARIABLE;
    string MALOP,MASV;
    MALOP = listClassbundle->MALOP;
    MASV = listStudentbundle->MASV;
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	variable da2 = {"MASV", MASV};
	VARIABLE.push_back(da2);
	if(deleteStudent(VARIABLE) == true) liststudent = showAllStudent(VARIABLE);
}
///=================================================================================================================
void LISTSTUDENT::searchElement(int width,char c){
	input_search_hoten = new DrawInputSearch();
	input_search_hoten -> text_form = "TIM KIEM (HOTEN): "; 
    input_search_hoten -> width = width;
    input_search_hoten -> text_input = (char*) calloc (50,sizeof(char));
    input_search_hoten -> width_text = 19;
	input_search_hoten -> pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 + 1;
	input_search_hoten -> pos_y = 9;
	input_search_hoten -> is_reset = true;
	drawInputSearch->DrawInputSearchFunction(input_search_hoten,' ',true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::keepSearchElement(int width,char c){
    input_search_hoten -> width = width;
	input_search_hoten -> pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 + 1;
	input_search_hoten -> is_reset = true;
	drawInputSearch->DrawInputSearchFunction(input_search_hoten,' ',true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::switchSearchElement(char c){
	drawInputSearch->DrawInputSearchFunction(input_search_hoten,c,true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::excuteSearchElement(int width,char c){
	drawInputSearch->DrawInputSearchFunction(input_search_hoten,c,false);	
	if(input_search_hoten->text_length > 0){
		if(searchStudent(listClassbundle->MALOP,input_search_hoten->text_input).size() > 0){
			clearBlankListElement(width);
			liststudent.clear();
			liststudent = searchStudent(listClassbundle->MALOP,input_search_hoten->text_input);
			if(liststudent.size() > listStudentbundle->max_size){listStudentbundle->size = listStudentbundle->max_size;}else{listStudentbundle->size = liststudent.size();}
    		listStudentbundle->forward = 0; 
    		listStudentbundle->chose = 1;
    		setListStudent(false,true,width);
    		status = 2;
		}else{
			if(status != 3){
				clearBlankListElement(width);
				customAttribute->setPosionCursor(input_search_hoten -> pos_x,listStudentbundle->y_title + 1);
				cout <<"KHONG TIM THAY";
				status = 3;
			}
		}
    }else{
    	if(status != 1) createElement(width);
    	status = 1;
	}
}
///=================================================================================================================
void LISTSTUDENT::clearBlankEditElement(int width){
    int pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2-1;
    frame->ClearPart(pos_x,listStudentbundle->y_title,pos_x + listStudentbundle->widthFrame,listStudentbundle->height - 2);
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::createEditStudent(int width){
	int top = 9;
	/////WRITE MALOP
	customAttribute->setPosionCursor(listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 + 1 , top);
	cout << "MASV: " <<listStudentbundle->MASV;	
	////CONTRUCTOR VARIBALE
    input_edit_hoten = new DrawInput();
    input_edit_password = new DrawInput();
    input_edit_hoten->text_input = (char*) calloc (50,sizeof(char));
    input_edit_password->text_input = (char*) calloc (50,sizeof(char));
    ////ASIGN VARIABLE
    for(int i = 0; i<(listStudentbundle->HOTEN).size(); i++){
	    input_edit_hoten->text_input[i] = (listStudentbundle->HOTEN)[i];
	} 
	////ASIGN VARIABLE
    for(int i = 0; i<(listStudentbundle->PASSWORD).size(); i++){
	    input_edit_password->text_input[i] = (listStudentbundle->PASSWORD)[i];
	} 	
	input_edit_hoten -> text_form = " Nhap ho ten "; 
    input_edit_hoten -> width = width;
	input_edit_hoten -> pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2-1;
	input_edit_hoten -> cur_pos_y = top+2; 
	input_edit_hoten -> margin_right = width - input_edit_hoten->pos_x - 60;
	input_edit_hoten -> is_reset = true; 
	drawInput->DrawInputFunction(input_edit_hoten,' ',true);	
	
	switchinput_edit_phai = new DrawSwitchInput();
	switchinput_edit_phai->text = listStudentbundle->PHAI;
	switchinput_edit_phai->text_form = "Gioi tinh ";
	switchinput_edit_phai->cur_pos_y = input_edit_hoten->cur_pos_y +5;
	switchinput_edit_phai->pos_x = input_edit_hoten -> pos_x + 2;
	switchinput_edit_phai->width = 11;
	switchinput_edit_phai->height = 1;
	switchinput_edit_phai->background_color = 0;
	switchinput_edit_phai->background_color_switch = 4;
	switchinput_edit_phai->is_reset = true;
	drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);
	
	input_edit_password -> text_form = " Nhap mat khau "; 
    input_edit_password -> width = width;
	input_edit_password -> pos_x = input_edit_hoten -> pos_x;
	input_edit_password -> cur_pos_y = switchinput_edit_phai->cur_pos_y + 2; 
	input_edit_password -> margin_right = input_edit_hoten -> margin_right;
	input_edit_password -> is_reset = true; 
	drawInput->DrawInputFunction(input_edit_password,' ',true);	
	
	button_edit_student = new DrawButton();
	button_edit_student -> text_button = "Sua sinh vien";
	button_edit_student -> width = 18;
	button_edit_student -> cur_pos_y = input_edit_password->cur_pos_y+5; 
	button_edit_student -> pos_x = switchinput_edit_phai->pos_x;
	button_edit_student -> height = 1;
	button_edit_student -> background_color = 8;
	button_edit_student -> is_reset = true;
	drawbutton->DrawButtonFunction(button_edit_student);
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::keepEditStudent(int width){
	/////WRITE MALOP
	customAttribute->setPosionCursor(listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 + 1 , 9);
	cout << "MASV: " <<listStudentbundle->MASV;	
	
	input_edit_hoten -> width = width;
	input_edit_hoten -> pos_x = listStudentbundle->margin + ((width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2 - 1;
	input_edit_hoten -> margin_right = width - input_edit_hoten->pos_x - 60;
	input_edit_hoten -> is_reset = true; 
	drawInput->DrawInputFunction(input_edit_hoten,' ',true);	
	
    input_edit_password -> width = width;
	input_edit_password -> pos_x = input_edit_hoten -> pos_x;
	input_edit_password -> margin_right = input_edit_hoten -> margin_right;
	input_edit_password -> is_reset = true; 
	drawInput->DrawInputFunction(input_edit_password,' ',true);	
	
	switchinput_edit_phai->pos_x = input_edit_hoten -> pos_x + 2;
	drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);	

	button_edit_student -> pos_x = switchinput_edit_phai->pos_x;
	drawbutton->DrawButtonFunction(button_edit_student);	
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::switchEditPhaiStudent(char c){
	switchinput_edit_phai->is_rise_event = true;
    if((int)c == 75){
    	switchinput_edit_phai->is_next = false;
    	switchinput_edit_phai->text = "Nam";
		drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);
	}
	if((int)c == 77){
		switchinput_edit_phai->is_next = true;
    	switchinput_edit_phai->text = "Nu ";
		drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);	
	}
	switchinput_edit_phai->is_rise_event = false;
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::switchEditStudent(bool isMove,bool direct,char c){
	    if(isMove == true){
	        if(direct == true) listStudentbundle->chose_edit_elementstudent = frame->direction(true,4,listStudentbundle->chose_edit_elementstudent);
	        else listStudentbundle->chose_edit_elementstudent = frame->direction(false,4,listStudentbundle->chose_edit_elementstudent);
	    }
	    if(listStudentbundle->chose_edit_elementstudent == 1){
	    	if(switchinput_edit_phai->background_color != 0){
	    	    switchinput_edit_phai->background_color = 0;
		        drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);
			}
			if(button_edit_student -> background_color != 8){
	    	    button_edit_student -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_edit_student);
			}
		    drawInput->DrawInputFunction(input_edit_hoten,c,true);
		}
		if(listStudentbundle->chose_edit_elementstudent == 2){
			switchinput_edit_phai->background_color = 8;
		    drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);
		}
		if(listStudentbundle->chose_edit_elementstudent == 3){
	    	if(switchinput_edit_phai->background_color != 0){
	    	    switchinput_edit_phai->background_color = 0;
		        drawswitchinput->DrawSwitchInputFunction(switchinput_edit_phai);
			}
			if(button_edit_student -> background_color != 8){
	    	    button_edit_student -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_edit_student);
			}
			drawInput->DrawInputFunction(input_edit_password,c,true);	
		}
		if(listStudentbundle->chose_edit_elementstudent == 4){
			button_edit_student -> background_color = 4;
			drawbutton->DrawButtonFunction(button_edit_student);
		}
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::excuteEditStudent(char c){
	if(listStudentbundle->chose_edit_elementstudent == 1){
	    drawInput->DrawInputFunction(input_edit_hoten,c,false);	
	}
    if(listStudentbundle->chose_edit_elementstudent == 3){
	    drawInput->DrawInputFunction(input_edit_password,c,false);	
	}
}
//--------------------------------------------------------------------------------------------------------
void LISTSTUDENT::updateEditStudent(){
    vector<variable> VARIABLE;
    string MALOP,MASV,EDITHOTEN,EDITPHAI,EDITPASSWORD;
    
    MALOP = listClassbundle->MALOP;
    MASV = listStudentbundle->MASV;
    EDITHOTEN = input_edit_hoten->text_input;
    EDITPHAI = switchinput_edit_phai->text;
    EDITPASSWORD = input_edit_password->text_input;
    
    if(EDITPHAI.compare("Nam")==0) EDITPHAI = "1";  
	else EDITPHAI = "0";  
	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"EDITHOTEN", EDITHOTEN};
	variable da4 = {"EDITPHAI", EDITPHAI};
	variable da5 = {"EDITPASSWORD", EDITPASSWORD};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	VARIABLE.push_back(da5);
	
	if(updateStudent(VARIABLE) == true) liststudent = showAllStudent(VARIABLE);
}
