#include "LISTSUBJECT.h"

using namespace std;

void LISTSUBJECT::setListSubject(bool out,bool iscreate,int width){

    int x_leftFrame = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 + 1;
    int x_middleFrame =  x_leftFrame + listSubjectbundle->widthFrame*1/9;
    int x_rightFrame =  x_middleFrame + listSubjectbundle->widthFrame*3/9;
    int size;if(listSubjectbundle->size >= listsubject.size()){size = listsubject.size();}else{size = listSubjectbundle->size;}
    
    int y_content = listSubjectbundle->y_title + 2;
	int x_text;
	string title;

	if(iscreate == true){
		//DRAW LINE WIDTH
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listSubjectbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listSubjectbundle->y_title - 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listSubjectbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listSubjectbundle->y_title + 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + listSubjectbundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,listSubjectbundle->y_title + listSubjectbundle->size + 2);
				cout<< "\xC4";}
		//DRAW LINE HEIGHT
    	for(int y = listSubjectbundle->y_title-1; y <= listSubjectbundle->y_title + listSubjectbundle->size + 2; y++)
        	for(int x = x_leftFrame - 1; x <= x_leftFrame + listSubjectbundle->widthFrame; x++){
		    	if(x == x_leftFrame - 1){
		    		customAttribute->setPosionCursor(x,y);
		    		if(y == listSubjectbundle->y_title-1)cout<< "\xDA";
		    		else if(y == listSubjectbundle->y_title + listSubjectbundle->size + 2) cout<< "\xC0";
					else cout<< "\xB3";
				}
				if(x == x_middleFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listSubjectbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listSubjectbundle->y_title + listSubjectbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_rightFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listSubjectbundle->y_title-1) cout<< "\xC2";
		    		else if(y == listSubjectbundle->y_title + listSubjectbundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_leftFrame + listSubjectbundle->widthFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == listSubjectbundle->y_title-1) cout<< "\xBF";
		    		else if(y == listSubjectbundle->y_title + listSubjectbundle->size + 2) cout<< "\xD9";
					else cout<< "\xB3";
				}
			}
		//-----------------------------------------------
		title = "STT";
		x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listSubjectbundle->y_title);
		cout << title;    
		///------------
    	title = "MA MON HOC";
		x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listSubjectbundle->y_title);
		cout << title;  
		///------------  
    	title = "TEN MON HOC";
		x_text = x_rightFrame + ((x_leftFrame+listSubjectbundle->widthFrame-x_rightFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,listSubjectbundle->y_title);
		cout << title; 
	}
	//DRAW ITEM
	//----------------------------------------------------
    int k = listSubjectbundle->forward;
    int chose = 1;
	for(int i = y_content ; i < y_content + size ; i++){
		if(listSubjectbundle->chose == chose){
			if(out == true) customAttribute->setBackgroundText(7,4); 
			else customAttribute->setBackgroundText(9,4); 
			    for(int e = x_leftFrame; e < x_leftFrame + listSubjectbundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_middleFrame)
		    		cout << "";	
		    		else if(e == x_rightFrame)
		    		cout << "";	
		    		else cout <<" ";
			    }
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - 1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << k+1;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (listsubject[k].MAMH).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listsubject[k].MAMH;	
			x_text = x_rightFrame + ((x_leftFrame +  listSubjectbundle->widthFrame - x_rightFrame) - (listsubject[k].TENMH).length()+1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listsubject[k].TENMH;	
		    customAttribute->setBackgroundText(7,0); 
			//GET VALUE
		    listSubjectbundle->MAMH = listsubject[k].MAMH;
		    listSubjectbundle->TENMH = listsubject[k].TENMH;	
		}else{
			customAttribute->setBackgroundText(7,0); 
			for(int e = x_leftFrame; e < x_leftFrame + listSubjectbundle->widthFrame ; e++){
            	customAttribute->setPosionCursor(e,i);
		    	if(e == x_middleFrame)
		    		cout << "";	
		    	else if(e == x_rightFrame)
		    		cout << "";	
		    	else cout <<" ";
			}
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - 1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << k+1;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (listsubject[k].MAMH).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listsubject[k].MAMH;	
			x_text = x_rightFrame + ((x_leftFrame +  listSubjectbundle->widthFrame - x_rightFrame) - (listsubject[k].TENMH).length()+1)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listsubject[k].TENMH;	
		    	
		    customAttribute->setBackgroundText(7,0); 
		}
	k = k + 1;
	chose = chose + 1;	
	}
	///----------------------------------
	listSubjectbundle->height = y_content + listSubjectbundle->max_size+13-listSubjectbundle->max_size+ 2;
	customAttribute->setPosionCursor(0,0);
	customAttribute->DisplayCursor(false);
}
///-----------------------------------------------------------------------------------------
void LISTSUBJECT::clearBlankElement(int width){
        int pos_x = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
	    frame->ClearPart(pos_x-1,listSubjectbundle->y_title-1,pos_x + listSubjectbundle->widthFrame+3,listSubjectbundle->height - 1);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::createElement(int width){
	listsubject = showAllSubject();
	listSubjectbundle->max_size = 9;
	if(listsubject.size() > listSubjectbundle->max_size){
	    listSubjectbundle->size = listSubjectbundle->max_size;
	}else{
		listSubjectbundle->size = listsubject.size();
	}
    listSubjectbundle->forward = 0;    
    listSubjectbundle->chose = 1;  
	listSubjectbundle->widthFrame  = 50;
    listSubjectbundle->y_title = 12;
    listSubjectbundle->margin = 20;
    setListSubject(false,true,width);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::keepElement(int width){
    setListSubject(false,true,width);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::moveElement(int width,bool move){
	if(move == true){
		if(listSubjectbundle->chose > 1 || listSubjectbundle->forward != 0){
	    if(listSubjectbundle->chose > 1){
			listSubjectbundle->chose = listSubjectbundle->chose - 1;
	    }else{
	    	if(listSubjectbundle->forward > 0){
			    listSubjectbundle->forward = listSubjectbundle->forward - 1;
			}
		}
		setListSubject(false,false,width);
		}
	}else{
		if(listSubjectbundle->chose < listSubjectbundle->size || listSubjectbundle->forward != listsubject.size() - listSubjectbundle->size){
	    if(listSubjectbundle->chose < listSubjectbundle->size){
			listSubjectbundle->chose = listSubjectbundle->chose + 1;
	    }else{
	    	if(listSubjectbundle->forward < listsubject.size() - listSubjectbundle->size){
			    listSubjectbundle->forward = listSubjectbundle->forward + 1;
			}
		}
		setListSubject(false,false,width);
		}
	}
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::switchElement(int width,bool move){
    moveElement(width,move);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::deleteElement(){
    vector<variable> VARIABLE;
    string MAMH;
    MAMH = listSubjectbundle->MAMH;
	variable da1 = {"MAMH", MAMH};
	VARIABLE.push_back(da1);
	if(deleteSubject(VARIABLE) == true) listsubject = showAllSubject();
}
///===========================================================================================
void LISTSUBJECT::createEditSubject(int width){
	/////WRITE MAMH
	customAttribute->setPosionCursor(listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 + 1 , 11);
	cout << "MAMH: " <<listSubjectbundle->MAMH;
	////CONTRUCTOR VARIBALE
    input_editsubject = new DrawInput();
    input_editsubject->text_input = (char*) calloc (50,sizeof(char));
    ////ASIGN VARIABLE
    for(int i = 0; i<(listSubjectbundle->TENMH).size(); i++){
	    input_editsubject->text_input[i] = (listSubjectbundle->TENMH)[i];
	} 
	input_editsubject -> text_form = " Nhap ten mon hoc "; 
    input_editsubject -> width = width;
	input_editsubject -> pos_x = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 - 1;
	input_editsubject -> cur_pos_y = 13; 
	input_editsubject -> margin_right = width - input_editsubject->pos_x - listSubjectbundle->widthFrame;
	input_editsubject -> is_reset = true; 
	drawInput->DrawInputFunction(input_editsubject,' ',true);		
	//--------
	button_editsubject = new DrawButton();
	button_editsubject -> text_button = "Sua mon hoc";
	button_editsubject -> width = 14;
	button_editsubject -> cur_pos_y = 18; 
	button_editsubject -> pos_x = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 + 1;
	button_editsubject -> height = 1;
	button_editsubject -> background_color = 8;
	button_editsubject -> is_reset = true;
	drawbutton->DrawButtonFunction(button_editsubject);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::keepEditSubject(int width){
	customAttribute->setPosionCursor(listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 + 1 , 11);
	cout << "MAMH: " <<listSubjectbundle->MAMH;
	//------------
	input_editsubject -> pos_x = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 - 1;
	input_editsubject -> width = width;
	input_editsubject -> margin_right = width - input_editsubject -> pos_x - listSubjectbundle->widthFrame;
	input_editsubject -> is_reset = true;  
	drawInput->DrawInputFunction(input_editsubject,' ',false);	
	//-----------
	button_editsubject -> pos_x = listSubjectbundle->margin + ((width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2 + 1;
    drawbutton->DrawButtonFunction(button_editsubject);
}
///------------------------------------------------------------------------------------------
void LISTSUBJECT::switchEditSubject(char c){
    if(listSubjectbundle->chose_editsubject == 1){
    	if(button_editsubject -> background_color == 4){
    	    button_editsubject -> is_reset = true;  
			button_editsubject -> background_color = 8;
	    		drawbutton->DrawButtonFunction(button_editsubject);
	    }
	    drawInput->DrawInputFunction(input_editsubject,c,true); 
	}
	if(listSubjectbundle->chose_editsubject == 2){
		button_editsubject -> is_reset = true;  
		button_editsubject -> background_color = 4;
		    drawbutton->DrawButtonFunction(button_editsubject);
	}
}
///--------------------------------------------------------------------------------------------
void LISTSUBJECT::excuteEditSubject(char c){
    if(listSubjectbundle->chose_editsubject == 1) drawInput->DrawInputFunction(input_editsubject,c,false); 
}
///--------------------------------------------------------------------------------------------
void LISTSUBJECT::updateEditSubject(){
	vector<variable> VARIABLE;
    string MAMH,EDITTENMH;
    MAMH = listSubjectbundle->MAMH;
    EDITTENMH = input_editsubject->text_input;
	variable da1 = {"MAMH", MAMH};
	variable da2 = {"EDITTENMH", EDITTENMH};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	if(updateSubject(VARIABLE) == true) listsubject = showAllSubject();
}
