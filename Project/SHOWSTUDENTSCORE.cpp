#include "SHOWSTUDENTSCORE.h"

using namespace std;

void SHOWSTUDENTSCORE::getDataListScore(bool is_login){
	vector<variable> VARIABLE;
	if(is_login == false){
		showstudentscorebundle->MALOP = "";
		showstudentscorebundle->MALOP = listClassbundle->MALOP;
		showstudentscorebundle->MASV = "";
		showstudentscorebundle->MASV = listStudentbundle->MASV;
    }
	variable da1 = {"MALOP", showstudentscorebundle->MALOP };
	variable da2 = {"MASV", showstudentscorebundle->MASV };
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	listscore.clear();
    listscore = showAllScore(VARIABLE);
}
////==============================================================================================================
void SHOWSTUDENTSCORE::setListStudentScore(bool out,bool iscreate,int width){
    int x_leftFrame = showstudentscorebundle->margin + ((width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2 + 1;
    int x_middleFrame =  x_leftFrame + showstudentscorebundle->widthFrame*1/3;
    int x_rightFrame =  x_middleFrame + showstudentscorebundle->widthFrame*1/3;
    int size;if(showstudentscorebundle->size >= listscore.size()){size = listscore.size();}else{size = showstudentscorebundle->size;}
	///------------
    int y_content = showstudentscorebundle->y_title + 2;
	int x_text;
	string title;
    ///------------
	if(iscreate == true){
		//DRAW LINE WIDTH
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + showstudentscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showstudentscorebundle->y_title - 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + showstudentscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showstudentscorebundle->y_title + 1);
				cout<< "\xC4";}
    	for(int x = x_leftFrame - 1; x <= x_leftFrame + showstudentscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showstudentscorebundle->y_title + showstudentscorebundle->size + 2);
				cout<< "\xC4";}
		//DRAW LINE HEIGHT
    	for(int y = showstudentscorebundle->y_title-1; y <= showstudentscorebundle->y_title + showstudentscorebundle->size + 2; y++)
        	for(int x = x_leftFrame - 1; x <= x_leftFrame + showstudentscorebundle->widthFrame; x++){
		    	if(x == x_leftFrame - 1){
		    		customAttribute->setPosionCursor(x,y);
		    		if(y == showstudentscorebundle->y_title-1)cout<< "\xDA";
		    		else if(y == showstudentscorebundle->y_title + showstudentscorebundle->size + 2) cout<< "\xC0";
					else cout<< "\xB3";
				}
				if(x == x_middleFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == showstudentscorebundle->y_title-1) cout<< "\xC2";
		    		else if(y == showstudentscorebundle->y_title + showstudentscorebundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_rightFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == showstudentscorebundle->y_title-1) cout<< "\xC2";
		    		else if(y == showstudentscorebundle->y_title + showstudentscorebundle->size + 2) cout<< "\xC1";
					else cout<< "\xB3";
				}
				if(x == x_leftFrame + showstudentscorebundle->widthFrame){
					customAttribute->setPosionCursor(x,y);
		    		if(y == showstudentscorebundle->y_title-1) cout<< "\xBF";
		    		else if(y == showstudentscorebundle->y_title + showstudentscorebundle->size + 2) cout<< "\xD9";
					else cout<< "\xB3";
				}
			}
		//-----------------------------------------------
		title = "MA MON HOC";
		x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,showstudentscorebundle->y_title);
		cout << title;    
		///------------
    	title = "LAN THI";
		x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - 5)/2;
		customAttribute->setPosionCursor(x_text,showstudentscorebundle->y_title);
		cout << title;  
		///------------  
    	title = " DIEM THI";
		x_text = x_rightFrame + ((x_leftFrame+showstudentscorebundle->widthFrame-x_rightFrame) - (title).length())/2;
		customAttribute->setPosionCursor(x_text,showstudentscorebundle->y_title);
		cout << title;  
	}
	//DRAW ITEM
	//----------------------------------------------------
    int k = showstudentscorebundle->forward;
    int chose = 1;
	for(int i = y_content ; i < y_content + size ; i++){
		if(showstudentscorebundle->chose == chose){
			if(out == true) customAttribute->setBackgroundText(7,4); 
			else customAttribute->setBackgroundText(9,4); 
			    for(int e = x_leftFrame; e < x_leftFrame + showstudentscorebundle->widthFrame ; e++){
            		customAttribute->setPosionCursor(e,i);
		    		if(e == x_middleFrame)
		    		cout << "";	
		    		else if(e == x_rightFrame)
		    		cout << "";	
		    		else cout <<" ";
			    }
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (listscore[k].MAMH).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listscore[k].MAMH;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - 8)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << "Lan thi " <<listscore[k].LANTHI;	
			x_text = x_rightFrame + ((x_leftFrame +  showstudentscorebundle->widthFrame - x_rightFrame) - 3)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listscore[k].DIEM;	
		    customAttribute->setBackgroundText(7,0); 
			//GET VALUE
		    showstudentscorebundle->MAMH = listscore[k].MAMH;
		    showstudentscorebundle->LANTHI = listscore[k].LANTHI;	
		}else{
			customAttribute->setBackgroundText(7,0); 
			for(int e = x_leftFrame; e < x_leftFrame + showstudentscorebundle->widthFrame ; e++){
            	customAttribute->setPosionCursor(e,i);
		    	if(e == x_middleFrame)
		    		cout << "";	
		    	else if(e == x_rightFrame)
		    		cout << "";	
		    	else cout <<" ";
			}
			x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (listscore[k].MAMH).length())/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listscore[k].MAMH;	
			x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - 8)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << "Lan thi " <<listscore[k].LANTHI;	
			x_text = x_rightFrame + ((x_leftFrame +  showstudentscorebundle->widthFrame - x_rightFrame) - 3)/2;
				customAttribute->setPosionCursor(x_text,i); 
		    	cout << listscore[k].DIEM;	
		    customAttribute->setBackgroundText(7,0); 
		}
	k = k + 1;
	chose = chose + 1;	
	}
	///------------------
	showstudentscorebundle->height = y_content + showstudentscorebundle->max_size + 4;
	customAttribute->setPosionCursor(0,0);
	customAttribute->DisplayCursor(false);
}
////==============================================================================================================
void SHOWSTUDENTSCORE::createListScoreElement(int width,bool is_login){
	getDataListScore(is_login);
	showstudentscorebundle->max_size = 13;
	if(listscore.size() > showstudentscorebundle->max_size){showstudentscorebundle->size = showstudentscorebundle->max_size;}else{showstudentscorebundle->size = listscore.size();}
    showstudentscorebundle->forward = 0;    
    showstudentscorebundle->chose = 1;  
	showstudentscorebundle->widthFrame  = 61;
    showstudentscorebundle->y_title = 10;
    showstudentscorebundle->margin = 20;
    setListStudentScore(false,true,width);
}
////==============================================================================================================
void SHOWSTUDENTSCORE::keepListScoreElement(int width){
    setListStudentScore(false,true,width);
}
////==============================================================================================================
void SHOWSTUDENTSCORE::switchListScoreElement(int width,bool move){
    moveListScoreElement(width,move);
}
////==============================================================================================================
void SHOWSTUDENTSCORE::moveListScoreElement(int width,bool move){
	if(move == true){
		if(showstudentscorebundle->chose > 1 || showstudentscorebundle->forward != 0){
	    if(showstudentscorebundle->chose > 1){
			showstudentscorebundle->chose = showstudentscorebundle->chose - 1;
	    }else{
	    	if(showstudentscorebundle->forward > 0){
			    showstudentscorebundle->forward = showstudentscorebundle->forward - 1;
			}
		}
		setListStudentScore(false,false,width);
		}
	}else{
		if(showstudentscorebundle->chose < showstudentscorebundle->size || showstudentscorebundle->forward != listscore.size() - showstudentscorebundle->size){
	    if(showstudentscorebundle->chose < showstudentscorebundle->size){
			showstudentscorebundle->chose = showstudentscorebundle->chose + 1;
	    }else{
	    	if(showstudentscorebundle->forward < listscore.size() - showstudentscorebundle->size){
			    showstudentscorebundle->forward = showstudentscorebundle->forward + 1;
			}
		}
		setListStudentScore(false,false,width);
		}
	}
}
////==============================================================================================================
////==============================================================================================================
void SHOWSTUDENTSCORE::getdataForResultExam(){
	exam->listQuestion.clear();
	exam->listAnswer.clear();
	
	ostringstream ss;
    ss << showstudentscorebundle->LANTHI;
    string LANTHI = ss.str();
    
    exam->listAnswer = dataexam->getDatabase(showstudentscorebundle->MAMH,showstudentscorebundle->MASV,LANTHI);
    for(int i = 0;i < exam->listAnswer.size(); i++) exam->listQuestion.push_back(api_GetNodeQuestion(exam->listAnswer[i].Id));
}
////==============================================================================================================
void SHOWSTUDENTSCORE::getdataForArchieveExam(){
	ostringstream ss;
    ss << showstudentscorebundle->LANTHI;
    string LANTHI = ss.str();
	vector<string> select_title_element,select_element;
	select_title_element.push_back("TIME");
	select_title_element.push_back("TOTAL");
	select_title_element.push_back("SCORE");
	select_element.push_back("MASV="+showstudentscorebundle->MASV);
	select_element.push_back("MAMH="+showstudentscorebundle->MAMH);
	select_element.push_back("LANTHI="+LANTHI);
	vector<string> data = selectManyElement("DATAEXAM.txt",select_title_element,select_element);
	if(!data.empty()){
		showstudentscorebundle->DIEM = "";
		showstudentscorebundle->TIME = "";
		showstudentscorebundle->TOTAL = "";
        int count = 1;	
        for(int i = 0 ; i < data[0].size(); i++){
        	if((data[0][i]) != ('#')){
				if(count == 1){
				    showstudentscorebundle->DIEM = showstudentscorebundle->DIEM + data[0][i];
				}else if(count == 2){
				    showstudentscorebundle->TIME = showstudentscorebundle->TIME + data[0][i];
				}else if(count == 3){
				    showstudentscorebundle->TOTAL = showstudentscorebundle->TOTAL + data[0][i];
				}
	    	}else{
	 			count = count + 1;
			}
        }
	}
	NodeSTUDENT* ptr_nodestudent = api_GetNodeStudent(showstudentscorebundle->MALOP,showstudentscorebundle->MASV);
    showstudentscorebundle->HOTEN = ptr_nodestudent->HOTEN;
}
