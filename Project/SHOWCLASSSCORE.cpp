#include "SHOWCLASSSCORE.h"

using namespace std;
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::clearBlankElement(int width){
        int pos_x = showclassscorebundle->margin + ((width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2 - 1;
	    frame->ClearPart(pos_x,showclassscorebundle->y_title-1,pos_x + showclassscorebundle->widthFrame + 2,
		showclassscorebundle->y_title + showclassscorebundle->max_line + 5);
}
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::clearBlankElement_(int width){
        int pos_x = showclassscorebundle->margin + ((width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2 - 1;
	    frame->ClearPart(pos_x,showclassscorebundle->y_title-3,pos_x + showclassscorebundle->widthFrame + 2,
		showclassscorebundle->y_title + showclassscorebundle->max_line + 5);
}
//---------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::getDataForStudent(){
	liststudent.clear();
	listClassScore.clear();
	vector<variable> VARIABLE;
    string MALOP = listClassbundle->MALOP;
 	string MAMH = listSubjectbundle->MAMH;
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	liststudent = showAllStudent(VARIABLE);
	for(int i = 0; i < liststudent.size(); i++){
		string MASV = liststudent[i].MASV;
		NodeClassScore newNode;
		newNode.MASV = MASV;
		newNode.HOTEN = liststudent[i].HOTEN;
		if(api_GetFinalNodeScore(MALOP,MASV,MAMH) != NULL){ newNode.DIEM = api_GetFinalNodeScore(MALOP,MASV,MAMH)->DIEM;}
		else{ newNode.DIEM = "-1";}
		listClassScore.push_back(newNode);
	}
}
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::ClassscoreTable(int width){
    if(listClassScore.size() > 0){
	
	if(13*showclassscorebundle->page <= listClassScore.size()) showclassscorebundle->max_line = 13;
	else showclassscorebundle->max_line = listClassScore.size() - 13*(showclassscorebundle->page-1);
	int p = 13*showclassscorebundle->page - 13;
    int x_leftFrame = showclassscorebundle->margin + ((width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2;
    int x_middleFrame =  x_leftFrame + showclassscorebundle->widthFrame*2/7;
    int x_rightFrame =  x_middleFrame + showclassscorebundle->widthFrame*3/7;
    for(int x = x_leftFrame - 1; x <= x_leftFrame + showclassscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showclassscorebundle->y_title - 1);
				cout<< "\xC4";
	}
    for(int x = x_leftFrame - 1; x <= x_leftFrame + showclassscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showclassscorebundle->y_title + 1);
				cout<< "\xC4";
	}
    for(int x = x_leftFrame - 1; x <= x_leftFrame + showclassscorebundle->widthFrame; x++){
		    	customAttribute->setPosionCursor(x,showclassscorebundle->y_title + showclassscorebundle->max_line + 2);
				cout<< "\xC4";
	}
    for(int y = showclassscorebundle->y_title-1; y <= showclassscorebundle->y_title + showclassscorebundle->max_line + 2; y++)
        for(int x = x_leftFrame - 1; x <= x_leftFrame + showclassscorebundle->widthFrame; x++){
		    if(x == x_leftFrame - 1){
		    	customAttribute->setPosionCursor(x,y);
		    	if(y == showclassscorebundle->y_title-1)cout<< "\xDA";
		    	else if(y == showclassscorebundle->y_title + showclassscorebundle->max_line + 2) cout<< "\xC0";
				else cout<< "\xB3";
			}
			if(x == x_middleFrame){
				customAttribute->setPosionCursor(x,y);
		    	if(y == showclassscorebundle->y_title-1) cout<< "\xC2";
		    	else if(y == showclassscorebundle->y_title + showclassscorebundle->max_line + 2) cout<< "\xC1";
				else cout<< "\xB3";
			}
			if(x == x_rightFrame){
				customAttribute->setPosionCursor(x,y);
		    	if(y == showclassscorebundle->y_title-1) cout<< "\xC2";
		    	else if(y == showclassscorebundle->y_title + showclassscorebundle->max_line + 2) cout<< "\xC1";
				else cout<< "\xB3";
			}
			if(x == x_leftFrame + showclassscorebundle->widthFrame){
				customAttribute->setPosionCursor(x,y);
		    	if(y == showclassscorebundle->y_title-1) cout<< "\xBF";
		    	else if(y == showclassscorebundle->y_title + showclassscorebundle->max_line + 2) cout<< "\xD9";
				else cout<< "\xB3";
			}
		}
	///------------
    int y_content = showclassscorebundle->y_title + 2;
	int x_text;
	string title;
    ///------------
	title = "";
	title = "MA SV";
	x_text = 0;
	x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (title).length())/2;
	customAttribute->setPosionCursor(x_text,showclassscorebundle->y_title);
	cout << title;    
	///------------
	title = "";
    title = "HO TEN";
	x_text = 0;
	x_text = x_middleFrame + ((x_rightFrame - x_middleFrame) - (title).length())/2;
	customAttribute->setPosionCursor(x_text,showclassscorebundle->y_title);
	cout << title;  
	///------------  
	title = "";
    title = "DIEM THI";
	x_text = 0;
	x_text = x_rightFrame + ((x_leftFrame+showclassscorebundle->widthFrame-x_rightFrame) - (title).length())/2;
	customAttribute->setPosionCursor(x_text,showclassscorebundle->y_title);
	cout << title;    	
	///------------
	for(int k = showclassscorebundle->y_title + 2; k < showclassscorebundle->y_title + showclassscorebundle->max_line + 2; k++){
		x_text = 0;
		x_text = x_leftFrame + ((x_middleFrame - x_leftFrame) - (listClassScore[p].MASV).length())/2;
			customAttribute->setPosionCursor(x_text,k); 
		    	cout << listClassScore[p].MASV;	
		x_text = 0;
		x_text = 1 + x_middleFrame + ((x_rightFrame - x_middleFrame) - (listClassScore[p].HOTEN).length())/2;
			customAttribute->setPosionCursor(x_text,k); 
		    	cout << listClassScore[p].HOTEN;	
	    x_text = 0;
			    if(listClassScore[p].DIEM.compare("-1") == 0){
					x_text = x_rightFrame + (x_leftFrame+showclassscorebundle->widthFrame-x_rightFrame - 5)/2;
						customAttribute->setPosionCursor(x_text,k); 
		    				cout << "chuathi";	
		    	}else{
					x_text = x_rightFrame + (x_leftFrame+showclassscorebundle->widthFrame-x_rightFrame)/2;
						customAttribute->setPosionCursor(x_text,k); 
		    				cout << listClassScore[p].DIEM;	
				}
	    p = p + 1;
	}
	title = "";
    title = "Page 1";
	x_text = 0;
	x_text = 1 + x_leftFrame + ((showclassscorebundle->widthFrame) - (title).length())/2;
	customAttribute->setPosionCursor(x_text,showclassscorebundle->y_title + showclassscorebundle->max_line + 3);
	cout << "page " << showclassscorebundle->page;    
	
	}
}
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::createListScoreElement(int width){
	showclassscorebundle->page = 1;
	showclassscorebundle->max_line = 13;
    showclassscorebundle->choseTable = 1;  
	showclassscorebundle->widthFrame  = 61;
    showclassscorebundle->y_title = 10;
    showclassscorebundle->margin = 20;
	customAttribute->setPosionCursor(showclassscorebundle->margin + ((width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2,
									showclassscorebundle->y_title - 2);
	cout << "MAMH: " << listSubjectbundle->MAMH;  
	ClassscoreTable(width);
}
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::keepListScoreElement(int width){
	customAttribute->setPosionCursor(showclassscorebundle->margin + ((width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2,
									showclassscorebundle->y_title - 2);
	cout << "MAMH: " << listSubjectbundle->MAMH;   
	ClassscoreTable(width);
}
//--------------------------------------------------------------------------------------------------
void SHOWCLASSSCORE::switchListScoreElement(bool isMove,bool direct,int width){
    int total_page = (listClassScore.size()-1)/13 + 1;
    if(total_page > 1){
    	clearBlankElement(width);
		if(isMove == true){
	        if(direct == true) showclassscorebundle->page = frame->direction(true,total_page,showclassscorebundle->page);
	        else showclassscorebundle->page = frame->direction(false,total_page,showclassscorebundle->page);
	    }
	ClassscoreTable(width);
	}
}
