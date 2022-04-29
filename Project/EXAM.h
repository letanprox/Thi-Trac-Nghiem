#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>


#include "APIGETDATA.h"
#include "FRAME.h"
#include "LISTNUMBER.h"
#include "EXAMQUESTION.h"
#include "DRAWBUTTON.h"
#include "DRAWINPUT.h"
#include "LOGIN.h"
#include "LISTSUBJECT.h"
#include "DATAEXAM.h"
#include "DATAEXAM.h"

using namespace std;

#ifndef EXAM_H
#define EXAM_H

struct ExamBundle{
	    bool is_in_condition_exam;
	    bool is_in_exam;
	    bool is_temp_finish;
	    bool is_finish_exam;
	    bool is_view_answer;
	    
        int height;
        int widthFrame;
        int margin;
        float Score;
        int max_question;
        int time_exam;
        
        int chose_condition_exam = 1;
        int chose_exam_element = 1;
        int temp_chose_number = 1;
        int chose_achieve_element = 1; 
    
        string MAMH;
        string TIME;
        string MASV;
        string TOTAL;
        string HOTEN;
        string DIEM;
};
class EXAM{
		//======================================================================================================
	    private:
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        ExamBundle* exambundle;
        LISTNUMBER* listnumber;
        ListNumberBundle* listnumberbundle;
        ExamQuestionBundle* examquestionbundle;
        EXAMQUESTION* examquestion;
        DRAWBUTTON* drawbutton;
        DRAWINPUT* drawInput;
        LoginBundle* loginbundle;
        ListSubjectBundle* listSubjectbundle;
        DATAEXAM* dataexam;
		//======================================================================================================
        public:
		EXAM(ListNumberBundle* listnumberbundle_,LISTNUMBER* listnumber_,ExamQuestionBundle* examquestionbundle_,EXAMQUESTION* examquestion_,ExamBundle* exambundle_,CUSTOMATTRIBUTE* customAttribute_,
		FRAME* frame_,DRAWBUTTON* drawbutton_,DRAWINPUT* drawInput_,LoginBundle* loginbundle_,ListSubjectBundle* listSubjectbundle_,DATAEXAM* dataexam_){
            customAttribute = customAttribute_;
            frame = frame_; 
            exambundle = exambundle_;
            listnumberbundle = listnumberbundle_;
            listnumber = listnumber_;
            examquestionbundle = examquestionbundle_;
            examquestion = examquestion_;
            drawbutton = drawbutton_;
            drawInput = drawInput_;
            loginbundle = loginbundle_;
            listSubjectbundle = listSubjectbundle_;
            dataexam = dataexam_;
        }
        ////DATA
        vector<NodeANSWER> listAnswer;
	    vector<NodeQUESTION> listQuestion;
		///ELEMENT
    	DrawInput* input_time_exam;
    	DrawInput* input_total_question;
    	DrawButton* button_Vaothi;	
    	//ELEMENT 2
    	DrawButton* buttonNopBai;
    	//ELEMENT 3
    	DrawButton* ButtonThoat;
    	//ELEMENT 4
		DrawButton* buttonExit;
		DrawButton* buttonViewExam;

        ////CONDITION
        void createConditionExam(int width);
        void keepConditionExam(int width);
        
        void switchConditionExam(bool isMove,bool direct,char c);
        void excuteConditionExam(char c);
        
        void clearBlankConditionExam(int width);  
        int getValueForExam();

        
        ////EXAM
    	void createExam(int width);
    	void keepExam(int width);
        void clearBlankExamBottom(int width,int y);
        
    	void switchExamElement(bool isMove,bool direct,int width);
    	
        void clearListQuestion(int width);  
        void switchListQuestion(bool isMove,bool direct,int width);
        void switchItemQuestion(bool isMove,bool direct,int width);
        void EnterChoseItem(int width);
        
        void switchListNumber(bool isMove,bool direct,int width);
        void EnterListNumber(int width);
        
        void notTimeout(int width);
        
        ///DATA
        void getDataExam();
        void extractResultExam(int width);
        
        
        ////RESULT
        void showAchievementExam(bool is_live,int width);
        void keepAchievementExam(bool is_live,int width);
        void switchElementAchievementExam(int width);
        
        
        ////ANSWER
        void createResulteExam(int width);
        void keepResulteExam(int width);
        
        void switchResultExamElement(bool isMove,bool direct,int width);
        void switchListAnswer(bool isMove,bool direct,int width);
        void EnterListNumberAnswers(int width);
};

#endif

