#include "LISTCLASS.h"

using namespace std;

void LISTCLASS::setListClass(bool out,bool iscreate,int width){
	
    int x_leftFrame = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 + 1;
    int x_middleFrame =  x_leftFrame + listClassbundle->widthFrame*1/9;
    int x_rightFrame =  x_middleFrame + listClassbundle->widthFrame*3/9;
    int size;if(listClassbundle->size >= listclass.size()){size = listclass.size();}else{size = listClassbundle->size;}
    
    int y_content = listClassbundle->y_title + 2;
	int x_text;
	string title;
	
	if(iscreate == true){
		//DRAW LINE WIDTH
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listClassbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listClassbundle->y_title - 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listClassbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listClassbundle->y_title + 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listClassbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listClassbundle->y_title + listClassbundle->size + 2);
				cout<< "\xC4";}
		//DRAW LINE HEIGHT
    	for(int y = listClassbundle->y_title-1; y <= listClassbundle->y_title + listClassbundle->size + 2; y++)
        	for(int x = x_leftFrame - 1; x <= x_leftFrame + listClassbundle->widthFrame; x++){
		    	if(x == x_leftFrame - 1){
		    		customAttribute->setPosionCursor(x,y);
		    		if(y == listClassbundle->y_title-1)cout<< "\xDA";
		    		else if(y == listClassbundle->y_title + listClassbundle->size + 2) cout<< "\xC0";
					else cout<< "\xB3";
				}
				if(x == x_middleFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listClassbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listClassbundle->y_title + listClassbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_rightFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listClassbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listClassbundle->y_title + listClassbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_leftFrame + listClassbundle->widthFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listClassbundle->y_title-1) cout<< "\xBF";
		    		else if(y == listClassbundle->y_title + listClassbundle->size + 2) cout<< "\xD9";
					else cout<< "\xB3";
				}
			}
		//-----------------------------------------------
		title = "STT";
		x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listClassbundle->y_title);
		cout << title;    
		///------------
    	title = "MA LOP";
		x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listClassbundle->y_title);
		cout << title;  
		///------------  
    	title = "TEN LOP";
		x_text = x_rightFrame + ((x_leftFrame+listClassbundle->widthFrame-x_rightFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listClassbundle->y_title);
		cout << title; 
	}
	//DRAW ITEM
	//----------------------------------------------------
    int k = listClassbundle->forward;
    int chose = 1;
	for(int i = y_content ; i < y_content + size ; i++){
		if(listClassbundle->chose == chose){
			if(out == true) customAttribute->setBackgroundText(7,4); 
			else customAttribute->setBackgroundText(9,4); 
			    for(int e = x_leftFrame; e < x_leftFrame + listClassbundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_middleFrame)
		    		cout << "";	
		    		else if(e == x_rightFrame)
		    		cout << "";	
		    		else cout <<" ";
			    }
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - 2)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << k+1;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (listclass[k].MALOP).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listclass[k].MALOP;	
			x_text = x_rightFrame + ((x_leftFrame +  listClassbundle->widthFrame - x_rightFrame) - (listclass[k].TENLOP).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listclass[k].TENLOP;	
		    customAttribute->setBackgroundText(7,0); 
			//GET VALUE
		    listClassbundle->MALOP = listclass[k].MALOP;
		    listClassbundle->TENLOP = listclass[k].TENLOP;	
		}else{
			customAttribute->setBackgroundText(7,0); 
			for(int e = x_leftFrame; e < x_leftFrame + listClassbundle->widthFrame ; e++){
            	customAttribute->setPosionCursor(e,i);
		    	if(e == x_middleFrame)
		    		cout << "";	
		    	else if(e == x_rightFrame)
		    		cout << "";	
		    	else cout <<" ";
			}
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - 2)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << k+1;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (listclass[k].MALOP).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listclass[k].MALOP;	
			x_text = x_rightFrame + ((x_leftFrame +  listClassbundle->widthFrame - x_rightFrame) - (listclass[k].TENLOP).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listclass[k].TENLOP;	
		    	
		    customAttribute->setBackgroundText(7,0); 
		}
	k = k + 1;
	chose = chose + 1;	
	}
	///----------------------------------
	listClassbundle->height = y_content + listClassbundle->max_size+ 3;
	customAttribute->setPosionCursor(0,0);
	customAttribute->DisplayCursor(false);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::clearBlankElement(int width){
        int pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,input_search_tenlop->pos_y,pos_x + listClassbundle->widthFrame+2,listClassbundle->height - 1);
}
void LISTCLASS::clearBlankListElement(int width){
        int pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,listClassbundle->y_title-1,pos_x + listClassbundle->widthFrame+2,listClassbundle->height - 1);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::createElement(int width){
	listclass = showAllClass();
	listClassbundle->max_size = 13;
	if(listclass.size() > listClassbundle->max_size){listClassbundle->size = listClassbundle->max_size;}else{listClassbundle->size = listclass.size();}
    listClassbundle->forward = 0;    
    listClassbundle->chose = 1;  
	listClassbundle->widthFrame  = 60;
    listClassbundle->y_title = 11;
    listClassbundle->margin = 20;
    setListClass(false,true,width);
    
    searchElement(width,' ');
    status = 1;
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::keepElement(int width){
	keepSearchElement(width,' ');
    setListClass(false,true,width);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::moveElement(int width,bool move){
	if(move == true){
		if(listClassbundle->chose > 1 || listClassbundle->forward != 0){
	    if(listClassbundle->chose > 1){
			listClassbundle->chose = listClassbundle->chose - 1;
	    }else{
	    	if(listClassbundle->forward > 0){
			    listClassbundle->forward = listClassbundle->forward - 1;
			}
		}
		setListClass(false,false,width);
		}
	}else{
		if(listClassbundle->chose < listClassbundle->size || listClassbundle->forward != listclass.size() - listClassbundle->size){
	    if(listClassbundle->chose < listClassbundle->size){
			listClassbundle->chose = listClassbundle->chose + 1;
	    }else{
	    	if(listClassbundle->forward < listclass.size() - listClassbundle->size){
			    listClassbundle->forward = listClassbundle->forward + 1;
			}
		}
		setListClass(false,false,width);
		}
	}
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::switchElement(int width,bool move){
    moveElement(width,move);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::deleteElement(){
    vector<variable> VARIABLE;
    string MALOP;
    MALOP = listClassbundle->MALOP;
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	if(deleteClass(VARIABLE) == true) listclass = showAllClass();
}
///========================================================================================================================
void LISTCLASS::searchElement(int width,char c){
	input_search_tenlop = new DrawInputSearch();
	input_search_tenlop -> text_form = "TIM KIEM (TENLOP): "; 
    input_search_tenlop -> width = width;
    input_search_tenlop -> text_input = (char*) calloc (50,sizeof(char));
    input_search_tenlop -> width_text = 40;
	input_search_tenlop -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2+1;
	input_search_tenlop -> pos_y = 9;
	input_search_tenlop -> is_reset = true;
	drawInputSearch->DrawInputSearchFunction(input_search_tenlop,' ',true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTCLASS::keepSearchElement(int width,char c){
    input_search_tenlop -> width = width;
	input_search_tenlop -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2+1;
	input_search_tenlop -> is_reset = true;
	drawInputSearch->DrawInputSearchFunction(input_search_tenlop,' ',true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTCLASS::switchSearchElement(char c){
	drawInputSearch->DrawInputSearchFunction(input_search_tenlop,c,true);	
}
//--------------------------------------------------------------------------------------------------------
void LISTCLASS::excuteSearchElement(int width,char c){
	drawInputSearch->DrawInputSearchFunction(input_search_tenlop,c,false);	
	if(input_search_tenlop->text_length > 0){
		if(searchClass(input_search_tenlop->text_input).size() > 0){
			clearBlankListElement(width);
			listclass.clear();
			listclass = searchClass(input_search_tenlop->text_input);
			if(listclass.size() > listClassbundle->max_size){listClassbundle->size = listClassbundle->max_size;}else{listClassbundle->size = listclass.size();}
			listClassbundle->forward = 0;    
    		listClassbundle->chose = 1;  
    		setListClass(false,true,width);
    		status = 2;
		}else{
			if(status != 3){
				clearBlankListElement(width);
				customAttribute->setPosionCursor(input_search_tenlop -> pos_x,listClassbundle->y_title + 1);
				cout <<"KHONG TIM THAY";
				status = 3;
			}
		}
    }else{
    	if(status != 1) createElement(width);
    	status = 1;
	}
}
///========================================================================================================================
void LISTCLASS::createEditClass(int width){
	/////WRITE MALOP
	customAttribute->setPosionCursor(listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 + 1 , 11);
	cout << "MALOP: " <<listClassbundle->MALOP;
	////CONTRUCTOR VARIBALE
    input_editclass = new DrawInput();
    input_editclass->text_input = (char*) calloc (50,sizeof(char));
    ////ASIGN VARIABLE
    for(int i = 0; i<(listClassbundle->TENLOP).size(); i++){
	    input_editclass->text_input[i] = (listClassbundle->TENLOP)[i];
	} 
	input_editclass -> text_form = " Nhap ten lop "; 
    input_editclass -> width = width;
	input_editclass -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 - 1;
	input_editclass -> cur_pos_y = 13; 
	input_editclass -> margin_right = width - input_editclass->pos_x - listClassbundle->widthFrame;
	input_editclass -> is_reset = true; 
	drawInput->DrawInputFunction(input_editclass,' ',true);		
	//--------
	button_editclass = new DrawButton();
	button_editclass -> text_button = "Sua lop";
	button_editclass -> width = 14;
	button_editclass -> cur_pos_y = 18; 
	button_editclass -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 + 1;
	button_editclass -> height = 1;
	button_editclass -> background_color = 8;
	button_editclass -> is_reset = true;
	drawbutton->DrawButtonFunction(button_editclass);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::keepEditClass(int width){
	customAttribute->setPosionCursor(listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 + 1 , 11);
	cout << "MALOP: " <<listClassbundle->MALOP;
	//------------
	input_editclass -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 - 1;
	input_editclass -> width = width;
	input_editclass -> margin_right = width - input_editclass -> pos_x - listClassbundle->widthFrame;
	input_editclass -> is_reset = true;  
	drawInput->DrawInputFunction(input_editclass,' ',false);	
	//-----------
	button_editclass -> pos_x = listClassbundle->margin + ((width-listClassbundle->margin) - listClassbundle->widthFrame)/2 + 1;
    drawbutton->DrawButtonFunction(button_editclass);
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::switchEditClass(char c){
    if(listClassbundle->chose_editclass == 1){
    	if(button_editclass -> background_color == 4){
    	    button_editclass -> is_reset = true;  
			button_editclass -> background_color = 8;
	    		drawbutton->DrawButtonFunction(button_editclass);
	    }
	    drawInput->DrawInputFunction(input_editclass,c,true); 
	}
	if(listClassbundle->chose_editclass == 2){
		button_editclass -> is_reset = true;  
		button_editclass -> background_color = 4;
		    drawbutton->DrawButtonFunction(button_editclass);
	}
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::excuteEditClass(char c){
    if(listClassbundle->chose_editclass == 1) drawInput->DrawInputFunction(input_editclass,c,false); 
}
//---------------------------------------------------------------------------------------------------
void LISTCLASS::updateEditClass(){
	vector<variable> VARIABLE;
    string MALOP,EDITTENLOP;
    MALOP = listClassbundle->MALOP;
    EDITTENLOP = input_editclass->text_input;
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"EDITTENLOP", EDITTENLOP};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	if(updateClass(VARIABLE) == true) listclass = showAllClass();
}
