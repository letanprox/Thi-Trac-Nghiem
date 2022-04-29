#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>

#include "FRAME.h"

using namespace std;

#ifndef EXAMQUESTION_H
#define EXAMQUESTION_H

struct ExamQuestionBundle{
    int chose;
    int temp_chose;
    int corect_chose;
    
    int width_Frame;
    int y_Frame;
    int x_Frame;
    int height;
    int number_question;
       
    string NOIDUNG;
    string A;
    string B;
    string C;
    string D;
};

class EXAMQUESTION{
		//=====================================================================================================
	    private:
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        ExamQuestionBundle* examquestionbundle;
		//=====================================================================================================
        public:
		EXAMQUESTION(ExamQuestionBundle* examquestionbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_){
            customAttribute = customAttribute_;
            frame = frame_; 
            examquestionbundle = examquestionbundle_;
        }
        void createExamquestion(int width);
        void NOIDUNG(int width);
        void E(string E,string content,bool is_temp_chose,bool is_chose,bool is_correct,int width);
        void showExamanswers(int width);
};

#endif
