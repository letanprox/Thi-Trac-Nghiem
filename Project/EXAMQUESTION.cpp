#include "EXAMQUESTION.h"

using namespace std;

void EXAMQUESTION::NOIDUNG(int width){
	        int width_text = examquestionbundle->width_Frame - 4;
	        int text_length = examquestionbundle->NOIDUNG.length();
            ////DRAW TOP LINE INPUT
		    for (int i = examquestionbundle->x_Frame; i < examquestionbundle->width_Frame + examquestionbundle->x_Frame ; i++) {
	            customAttribute->setPosionCursor(i,examquestionbundle->y_Frame);
	            if( i == examquestionbundle->x_Frame){
				    cout<< "\xDA";
				}else if( i == (examquestionbundle->width_Frame + examquestionbundle->x_Frame) - 1){
					cout<< "\xBF";
				}else{
					cout<< "\xC4";
				}
            }
            string title = " CAU HOI: ";
            int pos_title = examquestionbundle->x_Frame + (examquestionbundle->width_Frame - title.length())/2 - 1;
            ///PRINT TITLE TEXT FORM
            customAttribute->setPosionCursor(pos_title,examquestionbundle->y_Frame);
                cout<< title << examquestionbundle->number_question << " ";       
            int height_text  =  text_length/width_text;
            if( width_text*height_text < text_length )
			    height_text = height_text + 1;
			////DRAW TWO VERTICLE LINE FORM 
            for (int i = examquestionbundle->y_Frame + 1; i <  examquestionbundle->y_Frame + height_text + 3; i++){
	            customAttribute->setPosionCursor(examquestionbundle->x_Frame , i);
	            if( i ==  examquestionbundle->y_Frame ){
				    cout<< "\xDA";
				}else if( i == (examquestionbundle->y_Frame + height_text + 3) - 1){
					cout<< "\xC0";
				}else{
					cout<< "\xB3";
				}
	            customAttribute->setPosionCursor(examquestionbundle->x_Frame + width_text + 3 , i);
	            if( i ==  examquestionbundle->y_Frame  ){
				    cout<< "\xBF";
				}else if( i == (examquestionbundle->y_Frame + height_text + 3) - 1){
					cout<< "\xD9";
				}else{
					cout<< "\xB3";
				}
            }
            int p = 0;
			for(int i=0; i < height_text ; i++){
			    for(int k = 0; k < width_text ; k++){
			    	if(p < text_length){
				        customAttribute->setPosionCursor(k + examquestionbundle->x_Frame + 2,i + examquestionbundle->y_Frame + 2);
				        cout <<  examquestionbundle->NOIDUNG[p];
				    }
				p++;
				}
			}
			////DRAW BOTTOM LINE INPUT
            for (int i = examquestionbundle->x_Frame; i < examquestionbundle->width_Frame + examquestionbundle->x_Frame; i++) {
	            customAttribute->setPosionCursor(i, examquestionbundle->y_Frame + height_text + 2);
	            if( i == examquestionbundle->x_Frame){
				    cout<< "\xC0";
				}else if( i == (examquestionbundle->width_Frame + examquestionbundle->x_Frame) - 1){
					cout<< "\xD9";
				}else{
					cout<< "\xC4";
				}
            }
            examquestionbundle->height = examquestionbundle->y_Frame + height_text + 4;
}
//-----------------------------------------------------------------------------------------------------------------
void EXAMQUESTION::E(string E,string content,bool is_temp_chose,bool is_chose,bool is_correct,int width){
	        int color_text,color_back;
	        if(is_temp_chose == true && is_chose == true){
	        	if(is_correct == true) color_text = 4 ;
	        	else color_text = 9;
			    color_back = 10;
			}else{
				color_text = 7;
				color_back = 8;
				if(is_temp_chose == true){
			    	if(is_correct == true) color_back = 4;
	        		else color_back = 9;
				}
				if(is_chose == true){
					color_back = 10;
				}
			}
	        int width_text = examquestionbundle->width_Frame - 12;
	        int text_length = content.length();
			int height_text  =  text_length/width_text;
            if( width_text*height_text < text_length )
			    height_text = height_text + 1;
		    int y_Frame = examquestionbundle->height;
		    int x_Frame = examquestionbundle->x_Frame + 5;
		    customAttribute->setPosionCursor(examquestionbundle->x_Frame + 2,y_Frame+1);
			cout << E << ".";			    
			customAttribute->setBackgroundText(color_text,color_back);
			for (int i = y_Frame; i <  y_Frame + height_text + 2; i++)
				for (int k = x_Frame; k < examquestionbundle->width_Frame + examquestionbundle->x_Frame - 5; k++) {
					customAttribute->setPosionCursor(k, i);
					cout << " ";
				}
			int p = 0;
			for(int i=0; i < height_text ; i++)
			    for(int k = 0; k < width_text ; k++){
			    	if(p < text_length){
				        customAttribute->setPosionCursor(k + x_Frame + 1,i + y_Frame + 1);
				        cout <<  content[p];
				        }
				    p++;
				}
			customAttribute->setBackgroundText(7,0);
			examquestionbundle->height = examquestionbundle->height + height_text + 3;
			customAttribute->DisplayCursor(false);
}
//-----------------------------------------------------------------------------------------------------------------
void EXAMQUESTION::createExamquestion(int width){
    NOIDUNG(width);   
    bool E_chose = false;
    bool E_temp = false;
    if(examquestionbundle->chose == 1) E_chose = true;
    if(examquestionbundle->temp_chose == 1) E_temp = true;
        E("A",examquestionbundle->A,E_temp,E_chose,false,width);
    E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 2) E_chose = true;
    if(examquestionbundle->temp_chose == 2) E_temp = true;
		E("B",examquestionbundle->B,E_temp,E_chose,false,width);
	E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 3) E_chose = true;
    if(examquestionbundle->temp_chose == 3) E_temp = true;
		E("C",examquestionbundle->C,E_temp,E_chose,false,width);
	E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 4) E_chose = true;
    if(examquestionbundle->temp_chose == 4) E_temp = true;	
		E("D",examquestionbundle->D,E_temp,E_chose,false,width);	
}
//-----------------------------------------------------------------------------------------------------------------
void EXAMQUESTION::showExamanswers(int width){
    NOIDUNG(width);   
    bool E_chose = false;
    bool E_temp = false;
    if(examquestionbundle->chose == 1) E_chose = true;
    if(examquestionbundle->corect_chose == 1) E_temp = true;
        E("A",examquestionbundle->A,E_temp,E_chose,true,width);
    E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 2) E_chose = true;
    if(examquestionbundle->corect_chose == 2) E_temp = true;
		E("B",examquestionbundle->B,E_temp,E_chose,true,width);
	E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 3) E_chose = true;
    if(examquestionbundle->corect_chose == 3) E_temp = true;
		E("C",examquestionbundle->C,E_temp,E_chose,true,width);
	E_chose = false;
    E_temp = false;	
	if(examquestionbundle->chose == 4) E_chose = true;
    if(examquestionbundle->corect_chose == 4) E_temp = true;	
		E("D",examquestionbundle->D,E_temp,E_chose,true,width);
}
