#include "EXAM.h"

using namespace std;
//=====================================================================================================================================
void EXAM::createExam(int width){
	int margin = exambundle->margin;
	exambundle->chose_exam_element = 1;
	/////WE MAKE CHOSE ELEMENT ONE AND ONE
	examquestionbundle->chose = 0;
    examquestionbundle->temp_chose = 1;
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
	examquestion->createExamquestion(width);
	////------------------------------------------------------------------
    if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
    listnumberbundle->max_number = exambundle->max_question;
    listnumberbundle->width_Frame = 70;
    listnumberbundle->x_Frame = margin + ((width-margin) - listnumberbundle->width_Frame)/2;
    listnumber->createList(width);
    ///----------------------------------------------------------------
    buttonNopBai = new DrawButton();
	buttonNopBai->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	buttonNopBai->height = 1;
	buttonNopBai->width = 20;
	buttonNopBai->pos_x = margin + ((width-margin) - buttonNopBai->width)/2;
	buttonNopBai -> background_color = 8;
	buttonNopBai -> is_reset = true;
	buttonNopBai -> text_button = " Nop bai ";
	drawbutton->DrawButtonFunction(buttonNopBai);
	////-------------------------------------------------------------------
    exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
}
//==============================================================================================================================
void EXAM::keepExam(int width){
	int margin = exambundle->margin;
	//-----------
	examquestionbundle->x_Frame = margin + ((width-margin) - examquestionbundle->width_Frame)/2;
	examquestion->createExamquestion(width);
    //-----------
    if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
    listnumberbundle->x_Frame = margin + ((width-margin) - listnumberbundle->width_Frame)/2;
    listnumber->createList(width);
    //-----------
	buttonNopBai->pos_x = margin + ((width-margin) - buttonNopBai->width)/2;
	buttonNopBai -> is_reset = true;
	drawbutton->DrawButtonFunction(buttonNopBai);
    //-----------
    exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
}
//===============================================================================================================================
void EXAM::clearBlankExamBottom(int width,int y){
	int margin = exambundle->margin;
    int pos_x = margin + ((width-margin) - listnumberbundle->width_Frame)/2;
	frame->ClearPart(pos_x,y,pos_x + listnumberbundle->width_Frame,exambundle->height);
}
//===============================================================================================================================
void EXAM::switchExamElement(bool isMove,bool direct,int width){
    if(isMove == true){
	    if(direct == true){
	        exambundle->chose_exam_element = frame->direction(true,6,exambundle->chose_exam_element);
		}else {
		    exambundle->chose_exam_element = frame->direction(false,6,exambundle->chose_exam_element);
		}
	}
	if(exambundle->chose_exam_element >= 1 && exambundle->chose_exam_element <= 4){
		if(listnumberbundle->temp_chose != 0){
		    exambundle->temp_chose_number = listnumberbundle->temp_chose;
		    listnumberbundle->temp_chose = 0;
		    listnumber->createList(width);
		}
		if(buttonNopBai -> background_color != 8){
	  	    buttonNopBai -> background_color = 8;
		    drawbutton->DrawButtonFunction(buttonNopBai);
		}
		examquestionbundle->temp_chose =  exambundle->chose_exam_element;
	 	examquestion->createExamquestion(width);
	}  
	if(exambundle->chose_exam_element == 5){
	    if(examquestionbundle->temp_chose != 0){
			examquestionbundle->temp_chose = -1;
	 	    examquestion->createExamquestion(width);
		}
		if(buttonNopBai -> background_color != 8){
	  	    buttonNopBai -> background_color = 8;
		    drawbutton->DrawButtonFunction(buttonNopBai);
		}
		listnumberbundle->temp_chose = exambundle->temp_chose_number;
		listnumber->createList(width);
	}  
	if(exambundle->chose_exam_element == 6){
		if(listnumberbundle->temp_chose != 0){
		    exambundle->temp_chose_number = listnumberbundle->temp_chose;
		    listnumberbundle->temp_chose = 0;
		    listnumber->createList(width);
		}
	    if(examquestionbundle->temp_chose != 0){
			examquestionbundle->temp_chose =  -1;
	 	    examquestion->createExamquestion(width);
		}
	  	buttonNopBai -> background_color = 4;
	    drawbutton->DrawButtonFunction(buttonNopBai);
	}  
}
//===============================================================================================================================
void EXAM::clearListQuestion(int width){
	int margin = exambundle->margin;
    int pos_x = margin + ((width-margin) - examquestionbundle->width_Frame)/2;
	frame->ClearPart(pos_x,7,pos_x + examquestionbundle->width_Frame,examquestionbundle->height);
}
//===============================================================================================================================
void EXAM::switchListQuestion(bool isMove,bool direct,int width){
    if(isMove == true){
	    if(direct == true) examquestionbundle->number_question = frame->direction(true,exambundle->max_question,examquestionbundle->number_question);
	    else examquestionbundle->number_question = frame->direction(false,exambundle->max_question,examquestionbundle->number_question);
	}
	examquestionbundle->chose = listAnswer[examquestionbundle->number_question-1].chose;	
	if(examquestionbundle->chose == 0){
	    examquestionbundle->temp_chose = 1;
	    exambundle->chose_exam_element = 1;
	}else{
	    examquestionbundle->temp_chose = listAnswer[examquestionbundle->number_question-1].chose;
	    exambundle->chose_exam_element = listAnswer[examquestionbundle->number_question-1].chose;
	}
    examquestionbundle->NOIDUNG = listQuestion[examquestionbundle->number_question-1].NOIDUNG;
	examquestionbundle->A = listQuestion[examquestionbundle->number_question-1].A;
	examquestionbundle->B = listQuestion[examquestionbundle->number_question-1].B;
	examquestionbundle->C = listQuestion[examquestionbundle->number_question-1].C;
	examquestionbundle->D = listQuestion[examquestionbundle->number_question-1].D;
	examquestion->createExamquestion(width);
	
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
    
    buttonNopBai->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	buttonNopBai -> is_reset = false;
	drawbutton->DrawButtonFunction(buttonNopBai);
	buttonNopBai -> is_reset = true;
}
//===============================================================================================================================
void EXAM::switchItemQuestion(bool isMove,bool direct,int width){
    if(isMove == true){
	    if(direct == true){
	    	if(examquestionbundle->temp_chose == 0) examquestionbundle->temp_chose = 4;
		    examquestionbundle->temp_chose = frame->direction(true,4,examquestionbundle->temp_chose);
		}else{
			if(examquestionbundle->temp_chose == 0) examquestionbundle->temp_chose = 1;
		    examquestionbundle->temp_chose = frame->direction(false,4,examquestionbundle->temp_chose);
		}
	}	    
    examquestion->createExamquestion(width);
}
//===============================================================================================================================
void EXAM::EnterChoseItem(int width){
	examquestionbundle->chose = examquestionbundle->temp_chose;
	listAnswer[examquestionbundle->number_question-1].chose = examquestionbundle->temp_chose;
    		examquestion->createExamquestion(width);
}
//===============================================================================================================================
void EXAM::switchListNumber(bool isMove,bool direct,int width){
	if(isMove == true){
	    if(direct == true) listnumberbundle->temp_chose = frame->direction(true,exambundle->max_question,listnumberbundle->temp_chose );
	    else listnumberbundle->temp_chose  = frame->direction(false,exambundle->max_question,listnumberbundle->temp_chose );
	}
    listnumber->createList(width);
} 
//===============================================================================================================================
void EXAM::EnterListNumber(int width){
    examquestionbundle->number_question =  listnumberbundle->temp_chose;
    examquestionbundle->chose = listAnswer[examquestionbundle->number_question-1].chose ;
    
    examquestionbundle->NOIDUNG = listQuestion[examquestionbundle->number_question-1].NOIDUNG;
	examquestionbundle->A = listQuestion[examquestionbundle->number_question-1].A;
	examquestionbundle->B = listQuestion[examquestionbundle->number_question-1].B;
	examquestionbundle->C = listQuestion[examquestionbundle->number_question-1].C;
	examquestionbundle->D = listQuestion[examquestionbundle->number_question-1].D;
    
    examquestionbundle->temp_chose = -1;
	examquestion->createExamquestion(width);
	
	/////CHECK CONDITION
	if(examquestionbundle->height > 33) listnumberbundle->y_Frame = examquestionbundle->height;
	else listnumberbundle->y_Frame = 33;
	if(exambundle->height !=  listnumberbundle->y_Frame +  listnumberbundle->height + 4){
		clearBlankExamBottom(width,listnumberbundle->y_Frame);
		exambundle->height = listnumberbundle->y_Frame +  listnumberbundle->height + 4;
	}
	
    listnumberbundle->chose = listnumberbundle->temp_chose;
    listnumber->createList(width);
    
    buttonNopBai->cur_pos_y = listnumberbundle->y_Frame +  listnumberbundle->height + 1;
	buttonNopBai -> is_reset = false;
	drawbutton->DrawButtonFunction(buttonNopBai);
	buttonNopBai -> is_reset = true;
}
///=====================================================================================================================================
void EXAM::notTimeout(int width){
	int margin = exambundle->margin;
	int widthFrame =  examquestionbundle->width_Frame + 6;
    int pos_x = margin + ((width-margin) - widthFrame)/2;
    int pos_y = 15;
    
    customAttribute->setBackgroundText(7,4);   
    for(int y = pos_y; y < pos_y+8; y++)
    	for(int i = pos_x ;i < pos_x + widthFrame; i++){
	        customAttribute->setPosionCursor(i,y);
	        cout << " ";
		}
	
	string text = "DA HET THOI GIAN LAM BAI..";
	string text_ = "NHAN ENTER DE TIEP TUC";
	int pos_x_text = margin + ((width-margin) - text.length())/2;
	int pos_x_text_ = margin + ((width-margin) - text_.length())/2;
	customAttribute->setPosionCursor(pos_x_text,pos_y+3);
	cout << text;
	customAttribute->setPosionCursor(pos_x_text_,pos_y+4);
	cout << text_;
	customAttribute->setBackgroundText(7,0); 
	customAttribute->setPosionCursor(0,0);
}
///=====================================================================================================================================
void EXAM::getDataExam(){
	listQuestion.clear();
	listAnswer.clear();
    listQuestion = api_GetListTest(listSubjectbundle->MAMH,exambundle->max_question);
    for(int i = 0;i < listQuestion.size() ; i++ ){
	    NodeANSWER newNode;
	    	newNode.Id = listQuestion[i].Id;
	    	newNode.chose = 0;
	    listAnswer.push_back(newNode);
	}
}
///=====================================================================================================================================
void EXAM::extractResultExam(int width){
	int correct_answer = 0;
    for(int i = 0 ; i < listQuestion.size() ; i++){
		if(listQuestion[i].ANSWER == listAnswer[i].chose) correct_answer = correct_answer + 1;	
		listAnswer[i].corect_chose = listQuestion[i].ANSWER;
	}
	exambundle->Score = 10 - static_cast<float>((exambundle->max_question - correct_answer)*10)/static_cast<float>(exambundle->max_question);
	ostringstream convert1,convert2,convert3;   
		convert1 << exambundle->Score;     
		convert2 << exambundle->time_exam;     
		convert3 << exambundle->max_question;   
	dataexam->InsertDatabase(listSubjectbundle->MAMH,loginbundle->maLop,loginbundle->maUser,convert1.str().substr(0,3),convert2.str(),convert3.str(),listAnswer);
	vector<variable> VARIABLE;
    string MALOP = loginbundle->maLop;
	string MASV = loginbundle->maUser;
	string MAMH = listSubjectbundle->MAMH;
	string DIEM = convert1.str();
	DIEM = DIEM.substr(0,3);
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"MAMH", MAMH};
	variable da4 = {"DIEM", DIEM};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	if(addScore(VARIABLE) == true)
	showAchievementExam(true,width);
	listAnswer.clear();
}
