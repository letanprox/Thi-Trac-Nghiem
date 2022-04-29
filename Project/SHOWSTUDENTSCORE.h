#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <sstream>

#include "APIGETDATA.h"
#include "LISTCLASS.h"
#include "QUESTION.h"
#include "LISTSTUDENT.h"
#include "FRAME.h"
#include "EXAM.h"
#include "DATAEXAM.h"

using namespace std;

#ifndef SHOWSTUDENTSCORE_H
#define SHOWSTUDENTSCORE_H

struct ShowStudentScoreBundle{
    int chose_element = 1;

	string MAMH;
	string MALOP;
	string MASV;
	string HOTEN;
	string TIME;
	string TOTAL;
	string DIEM;
	int LANTHI;
	
	int chose;
	int size;
	int max_size;
	int height;
	int forward;
	int margin;
	int widthFrame;
	int y_title;
};

class SHOWSTUDENTSCORE{
		//==============================================================================================================
	    private:
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        ShowStudentScoreBundle* showstudentscorebundle;
        ListClassBundle* listClassbundle;
        ListStudentBundle* listStudentbundle;
        ExamBundle* exambundle;
        EXAM* exam;
        DATAEXAM* dataexam;
        
        vector<NodeSCORE> listscore;
        //==============================================================================================================
        public:
		SHOWSTUDENTSCORE(ShowStudentScoreBundle* showstudentscorebundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,ListClassBundle* listClassbundle_,
		ListStudentBundle* listStudentbundle_,ExamBundle* exambundle_,EXAM* exam_,DATAEXAM* dataexam_){
            customAttribute = customAttribute_;
            frame = frame_; 
            showstudentscorebundle = showstudentscorebundle_;
            listClassbundle = listClassbundle_;
            listStudentbundle = listStudentbundle_;
            exambundle = exambundle_;
            exam = exam_;
            dataexam = dataexam_;
        }
        void getDataListScore(bool is_login);
        void setListStudentScore(bool out,bool iscreate,int width);
        void createListScoreElement(int width,bool is_login);
        void keepListScoreElement(int width);
        void switchListScoreElement(int width,bool move);
        void moveListScoreElement(int width,bool move);
        void getdataForResultExam();
        void getdataForArchieveExam();
};

#endif
