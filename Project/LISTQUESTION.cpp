#include "LISTQUESTION.h"
#include <sstream>

#include "APIGETDATA.h"

using namespace std;

void LISTQUESTION::setListQuestion(bool out,bool iscreate,int width){
if(listquestion.size() > 0){
    int x_leftFrame = listQuestionbundle->margin + ((width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2 + 1;
    int x_rightFrame =  x_leftFrame + listQuestionbundle->widthFrame*1/7;
    int size;if(listQuestionbundle->size >= listquestion.size()){size = listquestion.size();}else{size = listQuestionbundle->size;}
    //----------------------
    int y_content = listQuestionbundle->y_title + 2;
	int x_text;
	string title;
	//-----------------------
	if(iscreate == true){
		//DRAW LINE WIDTH
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listQuestionbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listQuestionbundle->y_title - 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listQuestionbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listQuestionbundle->y_title + 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listQuestionbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listQuestionbundle->y_title + listQuestionbundle->size + 2);
				cout<< "\xC4";}	
		//DRAW LINE HEIGHT
    	for(int y = listQuestionbundle->y_title-1; y <= listQuestionbundle->y_title + listQuestionbundle->size + 2; y++)
        	for(int x = x_leftFrame - 1; x <= x_leftFrame + listQuestionbundle->widthFrame; x++){
		    	if(x == x_leftFrame - 1){
		    		customAttribute->setPosionCursor(x,y);
		    		if(y == listQuestionbundle->y_title-1)cout<< "\xDA";
		    		else if(y == listQuestionbundle->y_title + listQuestionbundle->size + 2) cout<< "\xC0";
					else cout<< "\xB3";
				}
				if(x == x_rightFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listQuestionbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listQuestionbundle->y_title + listQuestionbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_leftFrame + listQuestionbundle->widthFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listQuestionbundle->y_title-1) cout<< "\xBF";
		    		else if(y == listQuestionbundle->y_title + listQuestionbundle->size + 2) cout<< "\xD9";
					else cout<< "\xB3";
				}
			}
		title = "Id";
		x_text = x_leftFrame + ((x_rightFrame - x_leftFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listQuestionbundle->y_title);
		cout << title;    		
    	title = "NOIDUNG";
		x_text = x_rightFrame + ((x_leftFrame +  listQuestionbundle->widthFrame - x_rightFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listQuestionbundle->y_title);
		cout << title;   
	} 
	//DRAW ITEM
	//----------------------------------------------------
    int k = listQuestionbundle->forward;
    int chose = 1;
	for(int i = y_content ; i < y_content + size ; i++){
		string NOIDUNG;
		if((listquestion[k].NOIDUNG).length() + 3 > (x_leftFrame +  listQuestionbundle->widthFrame - x_rightFrame)){
		    for(int i = 0; i < (x_leftFrame +  listQuestionbundle->widthFrame - x_rightFrame) - 6 ; i ++){
			    NOIDUNG = NOIDUNG + listquestion[k].NOIDUNG[i];
			}
			NOIDUNG = NOIDUNG + "...";
		}else{
			NOIDUNG = listquestion[k].NOIDUNG;
		}    
		if(listQuestionbundle->chose == chose){
			if(out == true) customAttribute->setBackgroundText(7,4); 
			else customAttribute->setBackgroundText(9,4); 
			    for(int e = x_leftFrame; e < x_leftFrame + listQuestionbundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_rightFrame) cout << "";	
		    		else cout <<" ";
			    }
				x_text = x_leftFrame + ((x_rightFrame - x_leftFrame) - 2)/2;
					customAttribute->setPosionCursor(x_text,i); 
		    		cout << listquestion[k].Id;	
				x_text = x_rightFrame + ((x_leftFrame +  listQuestionbundle->widthFrame - x_rightFrame) - (NOIDUNG).length() + 1)/2;
					customAttribute->setPosionCursor(x_text,i); 
		    		cout << NOIDUNG;	
		    	customAttribute->setBackgroundText(7,0); 
				//GET VALUE      
    			ostringstream convert;   
    			convert << listquestion[k].Id;      
		    	listQuestionbundle->Id = convert.str();
	    		listQuestionbundle->NOIDUNG = listquestion[k].NOIDUNG;	
				listQuestionbundle->A = listquestion[k].A;	
				listQuestionbundle->B = listquestion[k].B;	
				listQuestionbundle->C = listquestion[k].C;	
				listQuestionbundle->D = listquestion[k].D;	
		    	listQuestionbundle->ANSWER = listquestion[k].ANSWER;	
			}else{
				customAttribute->setBackgroundText(7,0); 
			    for(int e = x_leftFrame; e < x_leftFrame + listQuestionbundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_rightFrame) cout << "";	
		    		else cout <<" ";
			    }
				x_text = x_leftFrame + ((x_rightFrame - x_leftFrame) - 2)/2;
					customAttribute->setPosionCursor(x_text,i); 
		    		cout << listquestion[k].Id;	
				x_text = x_rightFrame + ((x_leftFrame +  listQuestionbundle->widthFrame - x_rightFrame) - (NOIDUNG).length() + 1)/2;
					customAttribute->setPosionCursor(x_text,i); 
		    		cout << NOIDUNG;	
		    	customAttribute->setBackgroundText(7,0); 
			}
	k = k + 1;
	chose = chose + 1;	
	}
	///---------------
	listQuestionbundle->height = y_content + listQuestionbundle->max_size+ 3;
	customAttribute->setPosionCursor(0,0);
	customAttribute->DisplayCursor(false);
}
}
//------------------------------------------------------------------------------------------
void LISTQUESTION::clearBlankElement(int width){
        int pos_x = listQuestionbundle->margin + ((width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,listQuestionbundle->y_title-1,pos_x + listQuestionbundle->widthFrame+2,listQuestionbundle->height - 1);
}
//------------------------------------------------------------------------------------------
void LISTQUESTION::createElement(int width){
	vector<variable> VARIABLE;
    string MAMH = listSubjectbundle->MAMH;
	variable da1 = {"MAMH", MAMH};
	VARIABLE.push_back(da1);
	listquestion.clear();
	listquestion = showAllQuestion(VARIABLE);
	listQuestionbundle->max_size = 13;
	if(listquestion.size() > listQuestionbundle->max_size){listQuestionbundle->size = listQuestionbundle->max_size;}else{listQuestionbundle->size = listquestion.size();}
    listQuestionbundle->forward = 0;    
    listQuestionbundle->chose = 1;  
	listQuestionbundle->widthFrame  = 60;
    listQuestionbundle->y_title = 10;
    listQuestionbundle->margin = 20;
    setListQuestion(false,true,width);
}
//------------------------------------------------------------------------------------------
void LISTQUESTION::keepElement(int width){
    setListQuestion(false,true,width);
}
//------------------------------------------------------------------------------------------
void LISTQUESTION::switchElement(int width,bool move){
    moveElement(width,move);
}
//------------------------------------------------------------------------------------------
void LISTQUESTION::moveElement(int width,bool move){
	if(move == true){
		if(listQuestionbundle->chose > 1 || listQuestionbundle->forward != 0){
	    if(listQuestionbundle->chose > 1){
			listQuestionbundle->chose = listQuestionbundle->chose - 1;
	    }else{
	    	if(listQuestionbundle->forward > 0){
			    listQuestionbundle->forward = listQuestionbundle->forward - 1;
			}
		}
		setListQuestion(false,false,width);
		}
	}else{
		if(listQuestionbundle->chose < listQuestionbundle->size || listQuestionbundle->forward != listquestion.size() - listQuestionbundle->size){
	    if(listQuestionbundle->chose < listQuestionbundle->size){
			listQuestionbundle->chose = listQuestionbundle->chose + 1;
	    }else{
	    	if(listQuestionbundle->forward < listquestion.size() - listQuestionbundle->size){
			    listQuestionbundle->forward = listQuestionbundle->forward + 1;
			}
		}
		setListQuestion(false,false,width);
		}
	}
}
//------------------------------------------------------------------------------------------
bool LISTQUESTION::deleteElement(){
    vector<variable> VARIABLE;
	variable da1 = {"Id",listQuestionbundle->Id};
    VARIABLE.push_back(da1);
	if(deleteQuestion(VARIABLE) == true) return true;
	else return false;	
}
//===========================================================================================
void LISTQUESTION::clearBlankEditElement(int width){
        int pos_x = listQuestionbundle->margin + ((width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
	    frame->ClearPart(pos_x,listQuestionbundle->y_title-1,pos_x + listQuestionbundle->widthFrame,listQuestionbundle->height);
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::createEditQuestion(bool is_add,int width){
	int top = 9;
	int x = listQuestionbundle->margin + ((width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
	
	input_edit_NOIDUNG = new DrawInputForm();
	input_edit_A = new DrawInputForm();
	input_edit_B = new DrawInputForm();
	input_edit_C = new DrawInputForm();
	input_edit_D = new DrawInputForm();
	switchinput_edit_ANSWER = new DrawSwitchInput();
	button_edit_QUESTION = new DrawButton();
	
    input_edit_NOIDUNG->text_input = (char*) calloc (700,sizeof(char));
    input_edit_A->text_input = (char*) calloc (500,sizeof(char));
    input_edit_B->text_input = (char*) calloc (500,sizeof(char));
    input_edit_C->text_input = (char*) calloc (500,sizeof(char));
    input_edit_D->text_input = (char*) calloc (500,sizeof(char));
    
    if(is_add == false){
	    for(int i = 0; i<(listQuestionbundle->NOIDUNG).size(); i++)
	    input_edit_NOIDUNG->text_input[i] = (listQuestionbundle->NOIDUNG)[i];
	    for(int i = 0; i<(listQuestionbundle->A).size(); i++)
	    input_edit_A->text_input[i] = (listQuestionbundle->A)[i];
	    for(int i = 0; i<(listQuestionbundle->B).size(); i++)
	    input_edit_B->text_input[i] = (listQuestionbundle->B)[i];
	    for(int i = 0; i<(listQuestionbundle->C).size(); i++)
	    input_edit_C->text_input[i] = (listQuestionbundle->C)[i];
	    for(int i = 0; i<(listQuestionbundle->D).size(); i++)
	    input_edit_D->text_input[i] = (listQuestionbundle->D)[i];
	    listQuestionbundle->chose_answer = listQuestionbundle->ANSWER;
	    button_edit_QUESTION -> text_button = "Sua cau hoi ";
	}else{
		listQuestionbundle->chose_answer = 1;
		listQuestionbundle->chose_edit_elementquestion = 1;
		listQuestionbundle->A = "";
		listQuestionbundle->B = "";
		listQuestionbundle->C = "";
		listQuestionbundle->D = "";
		listQuestionbundle->ANSWER = 1;
		button_edit_QUESTION -> text_button = "Them cau hoi ";
	}
	    
    input_edit_NOIDUNG->pos_x = x;
    input_edit_NOIDUNG->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame;
    input_edit_NOIDUNG->cur_pos_y = top;
    input_edit_NOIDUNG->text_form = " Nhap cau hoi ";
    input_edit_NOIDUNG->width = width;
    input_edit_NOIDUNG->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_NOIDUNG,' ',true,listQuestionbundle->height);
    
    input_edit_A->pos_x = x;
    input_edit_A->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_A->cur_pos_y = input_edit_NOIDUNG->cur_pos_y + 4 + input_edit_NOIDUNG->height_text;
    input_edit_A->text_form = " Nhap dap an A ";
    input_edit_A->width = width;
    input_edit_A->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_A,' ',true,listQuestionbundle->height);
    
    input_edit_B->pos_x = x;
    input_edit_B->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_B->cur_pos_y = input_edit_A->cur_pos_y +  4 + input_edit_A->height_text;
    input_edit_B->text_form = " Nhap dap an B ";
    input_edit_B->width = width;
    input_edit_B->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_B,' ',true,listQuestionbundle->height);
    
    input_edit_C->pos_x = x;
    input_edit_C->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_C->cur_pos_y = input_edit_B->cur_pos_y + 4 + input_edit_B->height_text;
    input_edit_C->text_form = " Nhap dap an C ";
    input_edit_C->width = width;
    input_edit_C->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_C,' ',true,listQuestionbundle->height);
    
    input_edit_D->pos_x = x;
    input_edit_D->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_D->cur_pos_y = input_edit_C->cur_pos_y + 4 + input_edit_C->height_text;
    input_edit_D->text_form = " Nhap dap an D ";
    input_edit_D->width = width;
    input_edit_D->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_D,' ',true,listQuestionbundle->height);
    
    switchEditAnswerQuestion(' ');
    switchinput_edit_ANSWER->text_form = "Dap an ";
	switchinput_edit_ANSWER->cur_pos_y = input_edit_D->cur_pos_y + 4 + input_edit_D->height_text;
	switchinput_edit_ANSWER->pos_x = input_edit_D->pos_x + 2;
	switchinput_edit_ANSWER->width = 11;
	switchinput_edit_ANSWER->height = 1;
	switchinput_edit_ANSWER->background_color = 0;
	switchinput_edit_ANSWER->background_color_switch = 4;
	switchinput_edit_ANSWER->is_reset = true;
	drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
	
	button_edit_QUESTION -> width = 18;
	button_edit_QUESTION -> cur_pos_y = switchinput_edit_ANSWER->cur_pos_y + 2; 
	button_edit_QUESTION -> pos_x = input_edit_D->pos_x + 2;
	button_edit_QUESTION -> height = 1;
	button_edit_QUESTION -> background_color = 8;
	button_edit_QUESTION -> is_reset = true;
	drawbutton->DrawButtonFunction(button_edit_QUESTION);
    
    listQuestionbundle->height = button_edit_QUESTION->cur_pos_y + 3;
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::keepEditQuestion(int width){
	int top = 9;
	int x = listQuestionbundle->margin + ((width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
	
    input_edit_NOIDUNG->pos_x = x;
    input_edit_NOIDUNG->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame;
    input_edit_NOIDUNG->cur_pos_y = top;
    input_edit_NOIDUNG->width = width;
    input_edit_NOIDUNG->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_NOIDUNG,' ',true,listQuestionbundle->height);
    
    input_edit_A->pos_x = x;
    input_edit_A->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_A->cur_pos_y = input_edit_NOIDUNG->cur_pos_y + 4 + input_edit_NOIDUNG->height_text;
    input_edit_A->width = width;
    input_edit_A->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_A,' ',true,listQuestionbundle->height);
    
    input_edit_B->pos_x = x;
    input_edit_B->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_B->cur_pos_y = input_edit_A->cur_pos_y +  4 + input_edit_A->height_text;
    input_edit_B->width = width;
    input_edit_B->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_B,' ',true,listQuestionbundle->height);

    input_edit_C->pos_x = x;
    input_edit_C->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_C->cur_pos_y = input_edit_B->cur_pos_y + 4 + input_edit_B->height_text;
    input_edit_C->width = width;
    input_edit_C->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_C,' ',true,listQuestionbundle->height);
    
    input_edit_D->pos_x = x;
    input_edit_D->margin_right = width - input_edit_NOIDUNG->pos_x - listQuestionbundle->widthFrame + 10;
    input_edit_D->cur_pos_y = input_edit_C->cur_pos_y + 4 + input_edit_C->height_text;
    input_edit_D->width = width;
    input_edit_D->ischangeWidth = true;
    drawInputform->DrawInputFormFunction(input_edit_D,' ',true,listQuestionbundle->height);

	switchinput_edit_ANSWER->cur_pos_y = input_edit_D -> cur_pos_y + 4 +  input_edit_D->height_text;
	switchinput_edit_ANSWER->pos_x = input_edit_D -> pos_x + 2;
	switchinput_edit_ANSWER->is_reset = true;
	drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
	
	button_edit_QUESTION -> cur_pos_y = switchinput_edit_ANSWER->cur_pos_y + 2; 
	button_edit_QUESTION -> pos_x = input_edit_D->pos_x + 2;
	button_edit_QUESTION -> is_reset = true;
	drawbutton->DrawButtonFunction(button_edit_QUESTION);
    
    listQuestionbundle->height = button_edit_QUESTION->cur_pos_y + 3;
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::switchEditQuestion(bool isMove,bool direct,char c){
    	if(isMove == true){
	        if(direct == true) listQuestionbundle->chose_edit_elementquestion = frame->direction(true,7, listQuestionbundle->chose_edit_elementquestion);
	        else listQuestionbundle->chose_edit_elementquestion = frame->direction(false,7,listQuestionbundle->chose_edit_elementquestion);
	    }
	    
	    if(listQuestionbundle->chose_edit_elementquestion == 1){
    		if(button_edit_QUESTION -> background_color == 4){
				button_edit_QUESTION -> background_color = 8;
				button_edit_QUESTION -> is_reset = true;
				drawbutton->DrawButtonFunction(button_edit_QUESTION);
			}
			drawInputform->DrawInputFormFunction(input_edit_NOIDUNG,c,true,listQuestionbundle->height);
		}
	    
	    if(listQuestionbundle->chose_edit_elementquestion == 2){
		    drawInputform->DrawInputFormFunction(input_edit_A,c,true,listQuestionbundle->height);
		}
		
	    if(listQuestionbundle->chose_edit_elementquestion == 3){
        	drawInputform->DrawInputFormFunction(input_edit_B,c,true,listQuestionbundle->height);
		}
		
	    if(listQuestionbundle->chose_edit_elementquestion == 4){
		    drawInputform->DrawInputFormFunction(input_edit_C,c,true,listQuestionbundle->height);
		}
		
	    if(listQuestionbundle->chose_edit_elementquestion == 5){
	    	if(switchinput_edit_ANSWER->background_color == 8){
			    switchinput_edit_ANSWER->background_color = 0;
			    switchinput_edit_ANSWER->is_reset = true;
	            drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
			}
		    drawInputform->DrawInputFormFunction(input_edit_D,c,true,listQuestionbundle->height);
		}
		
	    if(listQuestionbundle->chose_edit_elementquestion == 6){
	        if(button_edit_QUESTION -> background_color == 4){
				button_edit_QUESTION -> background_color = 8;
				button_edit_QUESTION -> is_reset = true;
				drawbutton->DrawButtonFunction(button_edit_QUESTION);
			}    
			switchinput_edit_ANSWER->background_color = 8;	
		    drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
		}
		
	    if(listQuestionbundle->chose_edit_elementquestion == 7){
	    	if(switchinput_edit_ANSWER->background_color == 8){
			    switchinput_edit_ANSWER->background_color = 0;
			    switchinput_edit_ANSWER->is_reset = true;
	            drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
			}
			button_edit_QUESTION -> background_color = 4;
			button_edit_QUESTION -> is_reset = true;
		    drawbutton->DrawButtonFunction(button_edit_QUESTION);
		}
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::checkElement(){
	int top = 8;
    input_edit_NOIDUNG->cur_pos_y = top;
    drawInputform->DrawInputFormFunction(input_edit_NOIDUNG,' ',true,listQuestionbundle->height);
    
    input_edit_A->cur_pos_y = input_edit_NOIDUNG->cur_pos_y + 4 + input_edit_NOIDUNG->height_text;
    drawInputform->DrawInputFormFunction(input_edit_A,' ',true,listQuestionbundle->height);
    
    input_edit_B->cur_pos_y = input_edit_A->cur_pos_y +  4 + input_edit_A->height_text;
    drawInputform->DrawInputFormFunction(input_edit_B,' ',true,listQuestionbundle->height);

    input_edit_C->cur_pos_y = input_edit_B->cur_pos_y + 4 + input_edit_B->height_text;
    drawInputform->DrawInputFormFunction(input_edit_C,' ',true,listQuestionbundle->height);
    
    input_edit_D->cur_pos_y = input_edit_C->cur_pos_y + 4 + input_edit_C->height_text;
    drawInputform->DrawInputFormFunction(input_edit_D,' ',true,listQuestionbundle->height);

	switchinput_edit_ANSWER->cur_pos_y = input_edit_D -> cur_pos_y + 4 + input_edit_D->height_text;
	switchinput_edit_ANSWER->is_reset = false;
	drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
	
	button_edit_QUESTION -> cur_pos_y = switchinput_edit_ANSWER->cur_pos_y + 2; 
	button_edit_QUESTION->is_reset = false;
	drawbutton->DrawButtonFunction(button_edit_QUESTION);
    
    switchinput_edit_ANSWER->is_reset = true;
 	button_edit_QUESTION->is_reset = true;   
 	
    listQuestionbundle->height = button_edit_QUESTION->cur_pos_y + 3;
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::excuteEditQuestion(char c){
	    if(listQuestionbundle->chose_edit_elementquestion == 1){
			drawInputform->DrawInputFormFunction(input_edit_NOIDUNG,c,false,listQuestionbundle->height);
		}
	    if(listQuestionbundle->chose_edit_elementquestion == 2){
		    drawInputform->DrawInputFormFunction(input_edit_A,c,false,listQuestionbundle->height);
		}
	    if(listQuestionbundle->chose_edit_elementquestion == 3){
        	drawInputform->DrawInputFormFunction(input_edit_B,c,false,listQuestionbundle->height);
		}
	    if(listQuestionbundle->chose_edit_elementquestion == 4){
		    drawInputform->DrawInputFormFunction(input_edit_C,c,false,listQuestionbundle->height);
		}
	    if(listQuestionbundle->chose_edit_elementquestion == 5){
		    drawInputform->DrawInputFormFunction(input_edit_D,c,false,listQuestionbundle->height);
		}
        checkElement();
        switchEditQuestion(false,false,' ');
}
//-------------------------------------------------------------------------------------------
void LISTQUESTION::switchEditAnswerQuestion(char c){
	    bool is_move = false;
		if((int)c == 75){
			switchinput_edit_ANSWER->is_next = false;
            listQuestionbundle->chose_answer = frame->direction(false,4, listQuestionbundle->chose_answer);
            is_move = true;
	    }   
	    if((int)c == 77){
	    	switchinput_edit_ANSWER->is_next = true;
            listQuestionbundle->chose_answer = frame->direction(true,4,listQuestionbundle->chose_answer);
            is_move = true;
	    }
	    if(listQuestionbundle->chose_answer == 1){
		    switchinput_edit_ANSWER->text = "A";
		}
	    if(listQuestionbundle->chose_answer == 2){
		    switchinput_edit_ANSWER->text = "B";
		}
	    if(listQuestionbundle->chose_answer == 3){
		    switchinput_edit_ANSWER->text = "C";
		}
	    if(listQuestionbundle->chose_answer == 4){
		    switchinput_edit_ANSWER->text = "D";
		}
		if(is_move == true){
		switchinput_edit_ANSWER->is_rise_event = true;	
		drawswitchinput->DrawSwitchInputFunction(switchinput_edit_ANSWER);
		switchinput_edit_ANSWER->is_rise_event = false;
		}
}
//-------------------------------------------------------------------------------------------
bool LISTQUESTION::updateEditQuestion(){
    vector<variable> VARIABLE;
    string MAMH = listSubjectbundle->MAMH;
    string NOIDUNG = input_edit_NOIDUNG->text_input;
    string A = input_edit_A->text_input;
    string B = input_edit_B->text_input;
    string C = input_edit_C->text_input;
    string D = input_edit_D->text_input;
    int number = listQuestionbundle->chose_answer;            
    ostringstream convert;   
    convert << number;      
    string ANSWER = convert.str();
    string Id = listQuestionbundle->Id;
    variable da1 = {"MAMH", MAMH};
        variable da2 = {"NOIDUNG", NOIDUNG};
            variable da3 = {"A", A};
                variable da4 = {"B", B};
                    variable da5 = {"C", C};
                        variable da6 = {"D", D};
                        variable da7 = {"ANSWER", ANSWER};
                        variable da8 = {"Id", Id};
    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    VARIABLE.push_back(da3);
    VARIABLE.push_back(da4);
    VARIABLE.push_back(da5);
    VARIABLE.push_back(da6);
    VARIABLE.push_back(da7);       
	VARIABLE.push_back(da8);       
	if(updateQuestion(VARIABLE) == true){
	   listquestion = showAllQuestion(VARIABLE);
	   return true;
	}else{
	    return false;
	};
}
//-------------------------------------------------------------------------------------------
bool LISTQUESTION::addQuestion_(){
    string MAMH = listSubjectbundle->MAMH;
    string NOIDUNG = input_edit_NOIDUNG->text_input;
    string A = input_edit_A->text_input;
    string B = input_edit_B->text_input;
    string C = input_edit_C->text_input;
    string D = input_edit_D->text_input;
    if(!NOIDUNG.empty() && !A.empty() && !B.empty() && !C.empty() && !D.empty()){
    vector<variable> VARIABLE;
    int number = listQuestionbundle->chose_answer;            
    ostringstream convert;   
    convert << number;      
    string ANSWER = convert.str();
    
    variable da1 = {"MAMH",MAMH };
        variable da2 = {"NOIDUNG", NOIDUNG};
            variable da3 = {"A", A};
                variable da4 = {"B", B};
                    variable da5 = {"C", C};
                        variable da6 = {"D", D};
                        variable da7 = {"ANSWER", ANSWER};

    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    VARIABLE.push_back(da3);
    VARIABLE.push_back(da4);
    VARIABLE.push_back(da5);
    VARIABLE.push_back(da6);
    VARIABLE.push_back(da7);
    
    if(addQuestion(VARIABLE) == true){
	   return true;
	}else{
		return false;
	}
	VARIABLE.clear();
	}else return false;
}
