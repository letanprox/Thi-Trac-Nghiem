#include "EXAM.h"

using namespace std;
//===============================================================================================================================
void EXAM::createResulteExam(int width){	
 	exambundle->max_question = listQuestion.size();
	exambundle->chose_exam_element = 1;
	int margin = exambundle->margin;
	/////WE MAKE CHOSE ELEMENT ONE AND ONE
	examquestionbundle->chose = listAnswer[0].chose;
	examquestionbundle->corect_chose = listAnswer[0].corect_chose;
	examquestionbundle->number_question = 1;
	
	listnumberbundle->chose = 1;
    listnumberbundle->temp_chose = 0;
    exambundle->temp_chose_number = 1;
	//------------------------------------------------------------------------
	examquestionbundle->width_Frame = 50;
	examquestionbundle->x_Frame = margin + ((width-margin) - examquestionbundle->width_Frame)/2;
	examquestionbundle->y_Frame = 8;
    examquestionbundle->NOIDUNG = listQuestion[0].NOIDUNG;
	examquestionbundle->A = listQuestion[0].A;
	examquestionbundle->B = listQuestion[0].B;
	examquestionbundle->C = listQuestion[0].C;
	examquestionbundle->D = listQuestion[0].D;
	examquestion->showExamanswers(width);
	////------------------------------------------------------------------
    if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
    listnumberbundle->max_number = exambundle->max_question;
    listnumberbundle->width_Frame = 70;
    listnumberbundle->x_Frame = margin + ((width-margin) - listnumberbundle->width_Frame)/2;
    listnumber->createList(width);
    ///----------------------------------------------------------------
    ButtonThoat = new DrawButton();
	ButtonThoat->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	ButtonThoat->height = 1;
	ButtonThoat->width = 20;
	ButtonThoat->pos_x = margin + ((width-margin) - ButtonThoat->width)/2;
	ButtonThoat -> background_color = 8;
	ButtonThoat -> is_reset = true;
	ButtonThoat -> text_button = " Thoat ";
	drawbutton->DrawButtonFunction(ButtonThoat);
	////-------------------------------------------------------------------
    exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
}
//===============================================================================================================================
void EXAM::keepResulteExam(int width){
	int margin = exambundle->margin;
	//-----------
	examquestionbundle->x_Frame = margin + ((width-margin) - examquestionbundle->width_Frame)/2;
	examquestion->showExamanswers(width);
    //-----------
    if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
    listnumberbundle->x_Frame = margin + ((width-margin) - listnumberbundle->width_Frame)/2;
    listnumber->createList(width);
    //-----------
	ButtonThoat->pos_x = margin + ((width-margin) - ButtonThoat->width)/2;
	ButtonThoat -> is_reset = true;
	drawbutton->DrawButtonFunction(ButtonThoat);
    //-----------
    exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
}
//===============================================================================================================================
void EXAM::switchResultExamElement(bool isMove,bool direct,int width){
    if(isMove == true){
	    if(direct == true){
	        exambundle->chose_exam_element = frame->direction(true,3,exambundle->chose_exam_element);
		}else {
		    exambundle->chose_exam_element = frame->direction(false,3,exambundle->chose_exam_element);
		
		}
	}
	if(exambundle->chose_exam_element == 1 ){
		if(listnumberbundle->temp_chose != 0){
		    exambundle->temp_chose_number = listnumberbundle->temp_chose;
		    listnumberbundle->temp_chose = 0;
		    listnumber->createList(width);
		}
		if(ButtonThoat -> background_color != 8){
	  	    ButtonThoat -> background_color = 8;
		    drawbutton->DrawButtonFunction(ButtonThoat);
		}
	 	examquestion->showExamanswers(width);
	}  
	if(exambundle->chose_exam_element == 2){
		if(ButtonThoat -> background_color != 8){
	  	    ButtonThoat -> background_color = 8;
		    drawbutton->DrawButtonFunction(ButtonThoat);
		}
		listnumberbundle->temp_chose = exambundle->temp_chose_number;
		listnumber->createList(width);
	}  
	if(exambundle->chose_exam_element == 3){
		if(listnumberbundle->temp_chose != 0){
		    exambundle->temp_chose_number = listnumberbundle->temp_chose;
		    listnumberbundle->temp_chose = 0;
		    listnumber->createList(width);
		}
	  	ButtonThoat -> background_color = 4;
	    drawbutton->DrawButtonFunction(ButtonThoat);
	}  
}
//===============================================================================================================================
void EXAM::switchListAnswer(bool isMove,bool direct,int width){
    if(isMove == true){
	    if(direct == true) examquestionbundle->number_question = frame->direction(true,exambundle->max_question,examquestionbundle->number_question);
	    else examquestionbundle->number_question = frame->direction(false,exambundle->max_question,examquestionbundle->number_question);
	}
	examquestionbundle->chose = listAnswer[examquestionbundle->number_question-1].chose;
	examquestionbundle->corect_chose = listAnswer[examquestionbundle->number_question-1].corect_chose;	
	
    examquestionbundle->NOIDUNG = listQuestion[examquestionbundle->number_question-1].NOIDUNG;
	examquestionbundle->A = listQuestion[examquestionbundle->number_question-1].A;
	examquestionbundle->B = listQuestion[examquestionbundle->number_question-1].B;
	examquestionbundle->C = listQuestion[examquestionbundle->number_question-1].C;
	examquestionbundle->D = listQuestion[examquestionbundle->number_question-1].D;
	examquestion->showExamanswers(width);
	
	/////CHECK CONDITION
	if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
	if(exambundle->height !=  listnumberbundle->y_Frame +  listnumberbundle->height + 4){
		clearBlankExamBottom(width,listnumberbundle->y_Frame);
		exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
	}	

	listnumberbundle->chose = examquestionbundle->number_question;
    exambundle->temp_chose_number  =  examquestionbundle->number_question;
    listnumber->createList(width);
    
    ButtonThoat->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	ButtonThoat -> is_reset = false;
	drawbutton->DrawButtonFunction(ButtonThoat);
	ButtonThoat -> is_reset = true;
}
//===============================================================================================================================
void EXAM::EnterListNumberAnswers(int width){
    examquestionbundle->number_question =  listnumberbundle->temp_chose;
    examquestionbundle->corect_chose = listAnswer[examquestionbundle->number_question-1].corect_chose;	
    examquestionbundle->chose = listAnswer[examquestionbundle->number_question-1].chose;
    
    examquestionbundle->NOIDUNG = listQuestion[examquestionbundle->number_question-1].NOIDUNG;
	examquestionbundle->A = listQuestion[examquestionbundle->number_question-1].A;
	examquestionbundle->B = listQuestion[examquestionbundle->number_question-1].B;
	examquestionbundle->C = listQuestion[examquestionbundle->number_question-1].C;
	examquestionbundle->D = listQuestion[examquestionbundle->number_question-1].D;
    
	examquestion->showExamanswers(width);
	/////CHECK CONDITION
	if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
	if(exambundle->height !=  listnumberbundle->y_Frame +  listnumberbundle->height + 4){
		clearBlankExamBottom(width,listnumberbundle->y_Frame);
		exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
	}
    listnumberbundle->chose = listnumberbundle->temp_chose;
    listnumber->createList(width);
    
    ButtonThoat->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	ButtonThoat -> is_reset = false;
	drawbutton->DrawButtonFunction(ButtonThoat);
	ButtonThoat -> is_reset = true;
}
