#include "EXAM.h"

using namespace std;

//===============================================================================================================================
void EXAM::createConditionExam(int width){
    exambundle->margin = 15;
    exambundle->widthFrame = 23;
    int top = 9;
    int pos_x = exambundle->margin + ((width-exambundle->margin) - exambundle->widthFrame)/2;
    
    customAttribute->setPosionCursor(pos_x + 2,top);
    cout << "MASV: " << loginbundle->maUser;
    
    customAttribute->setPosionCursor(pos_x + 2,top + 2);
    cout << "HOTEN: " << loginbundle->nameUser;
    
    customAttribute->setPosionCursor(pos_x + 2,top + 4);
    cout << "MON THI: " << listSubjectbundle->MAMH;

    input_time_exam = new DrawInput();
    input_time_exam -> text_input = (char*) calloc (50,sizeof(char));
	input_time_exam -> text_form = " Thoi gian ";
    input_time_exam -> width = width;
	input_time_exam -> pos_x = pos_x;
	input_time_exam -> cur_pos_y = top + 6; 
	input_time_exam -> margin_right = width - input_time_exam->pos_x - exambundle->widthFrame;
	input_time_exam -> is_reset = true; 
	drawInput->DrawInputFunction(input_time_exam,' ',true);	
	
	input_total_question = new DrawInput();
    input_total_question -> text_input = (char*) calloc (50,sizeof(char));
	input_total_question -> text_form = " So cau hoi "; 
    input_total_question -> width = width;
	input_total_question -> pos_x = input_time_exam -> pos_x;
	input_total_question -> cur_pos_y = input_time_exam -> cur_pos_y + 5; 
	input_total_question -> margin_right = input_time_exam -> margin_right ;
	input_total_question -> is_reset = true; 
	drawInput->DrawInputFunction(input_total_question,' ',true);	

    button_Vaothi = new DrawButton();
	button_Vaothi->cur_pos_y = input_total_question->cur_pos_y + 5;
	button_Vaothi->height = 1;
	button_Vaothi->width = 13;
	button_Vaothi->pos_x = exambundle->margin + ((width-exambundle->margin) - button_Vaothi->width)/2;
	button_Vaothi -> background_color = 8;
	button_Vaothi -> is_reset = true;
	button_Vaothi -> text_button = "Vao thi ";
	drawbutton->DrawButtonFunction(button_Vaothi);
	
	exambundle->height = button_Vaothi->cur_pos_y + 4;
}
//===============================================================================================================================
void EXAM::keepConditionExam(int width){
    int top = 9;
    int pos_x = exambundle->margin + ((width-exambundle->margin) - exambundle->widthFrame)/2;
    
    customAttribute->setPosionCursor(pos_x + 2,top);
    cout << "MASV: " << loginbundle->maUser;
    
    customAttribute->setPosionCursor(pos_x + 2,top + 2);
    cout << "HOTEN: " << loginbundle->nameUser;
    
    customAttribute->setPosionCursor(pos_x + 2,top + 4);
    cout << "MON THI: " << listSubjectbundle->MAMH;
    
    input_time_exam -> width = width;
	input_time_exam -> pos_x = pos_x;
	input_time_exam -> margin_right = width - input_time_exam->pos_x - exambundle->widthFrame;
	input_time_exam -> is_reset = true; 
	drawInput->DrawInputFunction(input_time_exam,' ',true);	
	
    input_total_question -> width = width;
	input_total_question -> pos_x = input_time_exam -> pos_x;
	input_total_question -> margin_right = input_time_exam -> margin_right ;
	input_total_question -> is_reset = true; 
	drawInput->DrawInputFunction(input_total_question,' ',true);	
    
	button_Vaothi->pos_x = exambundle->margin + ((width-exambundle->margin) - button_Vaothi->width)/2;
	button_Vaothi -> is_reset = true;
	drawbutton->DrawButtonFunction(button_Vaothi);
	
	exambundle->height = button_Vaothi->cur_pos_y + 3;
}
//===============================================================================================================================
void EXAM::switchConditionExam(bool isMove,bool direct,char c){
    	if(isMove == true){
	        if(direct == true) exambundle->chose_condition_exam = frame->direction(true,3,exambundle->chose_condition_exam);
	        else exambundle->chose_condition_exam = frame->direction(false,3,exambundle->chose_condition_exam);
	    }
	    if(exambundle->chose_condition_exam == 1){
			if(button_Vaothi -> background_color != 8){
	    	    button_Vaothi -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_Vaothi);
			}
		    drawInput->DrawInputFunction(input_time_exam,c,true);
		}
		if(exambundle->chose_condition_exam == 2){
			if(button_Vaothi -> background_color != 8){
	    	    button_Vaothi -> background_color = 8;
			    drawbutton->DrawButtonFunction(button_Vaothi);
			}
			drawInput->DrawInputFunction(input_total_question,c,true);	
		}
		if(exambundle->chose_condition_exam == 3){
			button_Vaothi -> background_color = 4;
			drawbutton->DrawButtonFunction(button_Vaothi);
		}
}
//===============================================================================================================================
void EXAM::excuteConditionExam(char c){
	    if(exambundle->chose_condition_exam == 1) drawInput->DrawInputFunction(input_time_exam,c,false);
		if(exambundle->chose_condition_exam == 2) drawInput->DrawInputFunction(input_total_question,c,false);	
}
//===============================================================================================================================
void EXAM::clearBlankConditionExam(int width){
        int pos_x = exambundle->margin + ((width-exambundle->margin) - exambundle->widthFrame)/2;
	    frame->ClearPart(pos_x,9,pos_x + exambundle->widthFrame,exambundle->height);
}
//===============================================================================================================================
int EXAM::getValueForExam(){
	string max_question__ = input_total_question->text_input;
	string time_exam__ = input_time_exam->text_input; 
	if(!max_question__.empty() && !time_exam__.empty()){
		int max_question_; istringstream(max_question__) >> max_question_;
		if(TotalQuestion(listSubjectbundle->MAMH) >= max_question_){
			exambundle->widthFrame = 70;
    		int time_exam_; istringstream(time_exam__) >> time_exam_;
    		exambundle->max_question = max_question_;
    		exambundle->time_exam = time_exam_;
    		getDataExam();
    		return 3;
    	}else return 2;
    }return 1;
}
