#include "EXAM.h"

using namespace std;

///=====================================================================================================================================
void EXAM::showAchievementExam(bool is_live,int width){	
    string MAMH;
    string TIME;
    string MASV;
    string TOTAL;
    string HOTEN;
    string DIEM;   
    int width_Frame;
	
	if(is_live == true){
		ostringstream convert1,convert2,convert3;   
		convert1 << exambundle->Score;     
		convert2 << exambundle->time_exam;     
		convert3 << exambundle->max_question;   		
	    MAMH = listSubjectbundle->MAMH;
	    TIME = convert2.str();
	    MASV = loginbundle->maUser;
	    TOTAL = convert3.str();
	    HOTEN = loginbundle->nameUser;
	    DIEM =  convert1.str();
	    DIEM = DIEM.substr(0,3);
	    width_Frame = examquestionbundle->width_Frame; 
	}else{
	    MAMH = exambundle->MAMH;
	    TIME = exambundle->TIME;
	    MASV = exambundle->MASV;
	    TOTAL = exambundle->TOTAL;
	    HOTEN = exambundle->HOTEN;
	    DIEM =  exambundle->DIEM; 
		width_Frame = 50;
	}
	if(HOTEN.length() > 13 ){
		string temp = "";
		for(int i = HOTEN.size() - 13 ;i < HOTEN.size(); i++)
			temp = temp + HOTEN[i];
			
		HOTEN = ".."+temp;
	}
	
    int margin = exambundle->margin;
	int height_Frame = 12;
    int pos_x = margin + ((width-margin) - width_Frame)/2;
    int pos_y = 9;
    ////DRAW TOP LINE INPUT
		for (int i = pos_x ; i <= pos_x + width_Frame ; i++) {
	        customAttribute->setPosionCursor(i,pos_y);
	        if( i == pos_x){
				cout<< "\xDA";
			}else if( i == (pos_x + width_Frame)){
				cout<< "\xBF";
			}else{
				cout<< "\xC4";
			}
        }
    ////DRAW TWO VERTICLE LINE FORM 
        for (int i = pos_y ; i <  pos_y + height_Frame; i++) {	
	        customAttribute->setPosionCursor(pos_x , i);
	        if( i ==  pos_y ){
				cout<< "\xDA";
			}else if( i == (pos_y + height_Frame) - 1){
				cout<< "\xC0";
			}else{
				cout<< "\xB3";
			}
	        customAttribute->setPosionCursor(pos_x + width_Frame, i);
	        if( i ==  pos_y ){
				cout<< "\xBF";
			}else if( i == (pos_y + height_Frame) - 1){
				cout<< "\xD9";
			}else{
				cout<< "\xB3";
			}
        }
    ////DRAW BOTTOM LINE INPUT
        for (int i = pos_x; i <= (pos_x + width_Frame); i++) {
	        customAttribute->setPosionCursor(i,  pos_y + height_Frame-1);
	        if( i == pos_x){
				cout<< "\xC0";
			}else if( i == (pos_x + width_Frame)){
				cout<< "\xD9";
			}else{
				cout<< "\xC4";
			}
        }
        
        string title = " MON THI: " + MAMH + " ";
        pos_x = margin + ((width-margin) - title.length())/2;
        customAttribute->setPosionCursor(pos_x + 1, pos_y);
        cout << title;
    
    	pos_x = margin + ((width-margin) - width_Frame)/2;
        pos_x = pos_x + 7;
        pos_y = pos_y + 2;
        customAttribute->setPosionCursor(pos_x, pos_y);
        cout << "THOI GIAN: " << TIME << " P";
        
        customAttribute->setPosionCursor(pos_x, pos_y + 2);
        cout << "MASV: " << MASV;
        
        pos_x = pos_x + width_Frame/2 - 4;
        pos_y = pos_y;
        customAttribute->setPosionCursor(pos_x, pos_y);
        cout << "SO CAU HOI: " << TOTAL;
        
        customAttribute->setPosionCursor(pos_x, pos_y + 2);
        cout << "HOTEN: " << HOTEN;
            
        title = "DIEM: 100";
        pos_x = margin + ((width-margin) - title.length())/2;
        pos_y = pos_y + 6;
        for(int y = pos_y-1;y <= pos_y + 1; y++)
            for(int i = pos_x-3; i <= pos_x+title.length()+2 ; i++ ){
            	customAttribute->setPosionCursor(i,y);
			    customAttribute->setBackgroundText(7,9);
			    cout << " ";			
			}
        customAttribute->setPosionCursor(pos_x, pos_y);
        customAttribute->setBackgroundText(7,9);
        cout << "DIEM: " << DIEM;
        customAttribute->setBackgroundText(7,0);
        
    	buttonViewExam = new DrawButton();
		buttonViewExam->cur_pos_y = pos_y + 5;
		buttonViewExam->height = 1;
		buttonViewExam->width = 21;
		buttonViewExam->pos_x = margin + ((width-margin) - buttonViewExam->width)/2;
		buttonViewExam -> background_color = 10;
		buttonViewExam -> is_reset = true;
		buttonViewExam -> text_button = "Xem bai thi ";
		drawbutton->DrawButtonFunction(buttonViewExam);
		
    	buttonExit = new DrawButton();
		buttonExit->cur_pos_y = pos_y + 7;
		buttonExit->height = 1;
		buttonExit->width = 21;
		buttonExit->pos_x = margin + ((width-margin) - buttonExit->width)/2;
		buttonExit -> background_color = 8;
		buttonExit -> is_reset = true;
		buttonExit -> text_button = "Thoat ";
		drawbutton->DrawButtonFunction(buttonExit);
}
///=====================================================================================================================================
void EXAM::keepAchievementExam(bool is_live,int width){
	    string MAMH = exambundle->MAMH;
	    string TIME = exambundle->TIME;
	    string MASV = exambundle->MASV;
	    string TOTAL = exambundle->TOTAL;
	    string HOTEN = exambundle->HOTEN;
	    string DIEM = exambundle->DIEM;  
	    
	int width_Frame;
	if(is_live == true){
	    width_Frame = examquestionbundle->width_Frame; 
	}else{
		width_Frame = 50;
	}
    int margin = exambundle->margin;
	int height_Frame = 12;
    int pos_x = margin + ((width-margin) - width_Frame)/2;
    int pos_y = 9;
    ////DRAW TOP LINE INPUT
		for (int i = pos_x ; i <= pos_x + width_Frame ; i++) {
	        customAttribute->setPosionCursor(i,pos_y);
	        if( i == pos_x){
				cout<< "\xDA";
			}else if( i == (pos_x + width_Frame)){
				cout<< "\xBF";
			}else{
				cout<< "\xC4";
			}
        }
    ////DRAW TWO VERTICLE LINE FORM 
        for (int i = pos_y ; i <  pos_y + height_Frame; i++) {	
	        customAttribute->setPosionCursor(pos_x , i);
	        if( i ==  pos_y ){
				cout<< "\xDA";
			}else if( i == (pos_y + height_Frame) - 1){
				cout<< "\xC0";
			}else{
				cout<< "\xB3";
			}
	        customAttribute->setPosionCursor(pos_x + width_Frame, i);
	        if( i ==  pos_y ){
				cout<< "\xBF";
			}else if( i == (pos_y + height_Frame) - 1){
				cout<< "\xD9";
			}else{
				cout<< "\xB3";
			}
        }
    ////DRAW BOTTOM LINE INPUT
        for (int i = pos_x; i <= (pos_x + width_Frame); i++) {
	        customAttribute->setPosionCursor(i,  pos_y + height_Frame-1);
	        if( i == pos_x){
				cout<< "\xC0";
			}else if( i == (pos_x + width_Frame)){
				cout<< "\xD9";
			}else{
				cout<< "\xC4";
			}
        } 
        string title = " MON THI: " + MAMH + " ";
        pos_x = margin + ((width-margin) - title.length())/2;
        customAttribute->setPosionCursor(pos_x + 1, pos_y);
        cout << title;
    
    	pos_x = margin + ((width-margin) - width_Frame)/2;
        pos_x = pos_x + 7;
        pos_y = pos_y + 2;
        customAttribute->setPosionCursor(pos_x, pos_y);
        cout << "THOI GIAN: " << TIME << " P";
        
        customAttribute->setPosionCursor(pos_x, pos_y + 2);
        cout << "MASV: " << MASV;
        
        pos_x = pos_x + width_Frame/2 - 4;
        pos_y = pos_y;
        customAttribute->setPosionCursor(pos_x, pos_y);
        cout << "SO CAU HOI: " << TOTAL;
        
        customAttribute->setPosionCursor(pos_x, pos_y + 2);
        cout << "HOTEN: " << HOTEN;
            
        title = "DIEM: 100";
        pos_x = margin + ((width-margin) - title.length())/2;
        pos_y = pos_y + 6;
        for(int y = pos_y-1;y <= pos_y + 1; y++)
            for(int i = pos_x-3; i <= pos_x+title.length()+2 ; i++ ){
            	customAttribute->setPosionCursor(i,y);
			    customAttribute->setBackgroundText(7,9);
			    cout << " ";			
			}
        customAttribute->setPosionCursor(pos_x, pos_y);
        customAttribute->setBackgroundText(7,9);
        cout << "DIEM: " << DIEM;
        customAttribute->setBackgroundText(7,0);

		buttonViewExam->pos_x = margin + ((width-margin) - buttonViewExam->width)/2;
		buttonViewExam -> is_reset = true;
		drawbutton->DrawButtonFunction(buttonViewExam);
		
		buttonExit->pos_x = margin + ((width-margin) - buttonExit->width)/2;
		buttonExit -> is_reset = true;
		drawbutton->DrawButtonFunction(buttonExit);
}
///=====================================================================================================================================
void EXAM::switchElementAchievementExam(int width){
	if(exambundle->chose_achieve_element == 1){
		if(buttonExit -> background_color != 8){
			buttonExit -> background_color = 8;
			buttonExit -> is_reset = true;
			drawbutton->DrawButtonFunction(buttonExit);
		}
		buttonViewExam -> background_color = 10;
		buttonViewExam -> is_reset = true;
		drawbutton->DrawButtonFunction(buttonViewExam);
	}
	if(exambundle->chose_achieve_element == 2){
		if(buttonViewExam -> background_color != 8){
			buttonViewExam -> background_color = 8;
			buttonViewExam -> is_reset = true;
			drawbutton->DrawButtonFunction(buttonViewExam);
		}
		buttonExit -> background_color = 10;
		buttonExit -> is_reset = true;
		drawbutton->DrawButtonFunction(buttonExit);
    }
}
