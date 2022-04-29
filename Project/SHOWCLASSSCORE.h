#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

#include "APIGETDATA.h"
#include "QUESTION.h"
#include "LISTSTUDENT.h"
#include "LISTSUBJECT.h"
#include "FRAME.h"
#include "EXAM.h"
#include "DATAEXAM.h"

using namespace std;

#ifndef SHOWCLASSSCORE_H
#define SHOWCLASSSCORE_H

struct ShowClassScoreBundle{
    int chose_element = 1;

	string MAMH;
	string MALOP;
	string MASV;
	string HOTEN;
	string DIEM;
	int LANTHI;
	
	int page;
	int choseTable;
	int max_line;
	int height;
	int margin;
	int widthFrame;
	int y_title;
};

struct NodeClassScore{
    string HOTEN;
    string MASV;
    string DIEM;
};

class SHOWCLASSSCORE{
		//=============================================================================================
	    private:
	    ShowClassScoreBundle* showclassscorebundle;
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        ListClassBundle* listClassbundle;
        ListSubjectBundle* listSubjectbundle;
        //=============================================================================================
        public:
		SHOWCLASSSCORE(ShowClassScoreBundle* showclassscorebundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,
		ListClassBundle* listClassbundle_,ListSubjectBundle* listSubjectbundle_){
            customAttribute = customAttribute_;
            frame = frame_; 
            listClassbundle = listClassbundle_;
            listSubjectbundle = listSubjectbundle_;
            showclassscorebundle = showclassscorebundle_;
        }
        vector<NodeClassScore> listClassScore;
        vector<NodeSTUDENT> liststudent;
        void getDataForStudent();
        void ClassscoreTable(int width);
        void createListScoreElement(int width);
        void switchListScoreElement(bool isMove,bool direct,int width);
        void clearBlankElement(int width);
        void clearBlankElement_(int width);
        void keepListScoreElement(int width);
};

#endif
