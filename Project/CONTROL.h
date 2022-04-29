#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ADDCLASS.h"
#include "ADDSTUDENT.h"
#include "LISTSTUDENT.h"
#include "LISTSUBJECT.h"
#include "LISTQUESTION.h"
#include "ADDSUBJECT.h"
#include "MENU.h"
#include "FRAME.h"
#include "LOGIN.h"
#include "EXAM.h"
#include "COUNTDOWN.h"
#include "DATAEXAM.h"
#include "SHOWSTUDENTSCORE.h"
#include "SHOWCLASSSCORE.h"

using namespace std;

#ifndef CONTROL_H
#define CONTROL_H

struct DashBoard{
	//reset whole program
	bool isReset = false;
	
	//chose interface
	bool isLogin_ed = false;
	//create interface login
	bool isLoadingLogin = true;
	//create interface program
	bool isLoadingProgram = true;
	
	//element
    int color_Theme = 9; 
	int width = 0;
	int current_width = 0;
	int height = 0;
	int current_height = 0;
	bool inMenu = true;
	int item = 1;
	int itemEnter = 0;
    bool x = true;
    int pre_Enter;
};

class CONTROL{
		//=========================================================================
	    private:
		DashBoard* dashboard;
        AddClassBundle* addClassbundle;
        ADDCLASS* AddClass;
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        MENU* menu;
        LOGIN* login;
        LoginBundle* loginbundle;
        consoleLOG_bundle* consolebundle;
        consoleLOG* console;
        LISTCLASS* ListClass;
        ListClassBundle* listClassbundle;
        LISTSTUDENT* ListStudent;
		ListStudentBundle* listStudentbundle;
		AddStudentBundle* addstudentbundle;
		ADDSTUDENT* AddStudent;
		ListSubjectBundle* listSubjectbundle;
		LISTSUBJECT* ListSubject;
	    AddSubjectBundle* addSubjectbundle;
	    ADDSUBJECT* AddSubject;
	    ListQuestionBundle* listQuestionbundle ;
        LISTQUESTION* ListQuestion;
        ExamBundle* exambundle;
        EXAM* exam;
        COUNTDOWN* countdown ;
        DATAEXAM* dataexam;
		ShowStudentScoreBundle* showstudentscorebundle;
		SHOWSTUDENTSCORE* showstudentscore;
		ShowClassScoreBundle* showclassscorebundle;
		SHOWCLASSSCORE* showclassscore;
        //=========================================================================
        public:
		CONTROL(DashBoard* dashboard_,ADDCLASS* AddClass_,AddClassBundle* addClassbundle_,
		        CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,MENU* menu_,
				LOGIN* login_,LoginBundle* loginbundle_,consoleLOG* console_,consoleLOG_bundle* consolebundle_,
				LISTCLASS* ListClass_,ListClassBundle* listClassbundle_,LISTSTUDENT* ListStudent_,ListStudentBundle* listStudentbundle_,
				AddStudentBundle* addstudentbundle_,ADDSTUDENT* AddStudent_,LISTSUBJECT* ListSubject_,ListSubjectBundle* listSubjectbundle_,
				AddSubjectBundle* addSubjectbundle_,ADDSUBJECT* AddSubject_,ListQuestionBundle* listQuestionbundle_,LISTQUESTION* ListQuestion_,
				ExamBundle* exambundle_,EXAM* exam_,COUNTDOWN* countdown_,DATAEXAM* dataexam_,
				SHOWSTUDENTSCORE* showstudentscore_,ShowStudentScoreBundle* showstudentscorebundle_,
				SHOWCLASSSCORE* showclassscore_,ShowClassScoreBundle* showclassscorebundle_){
					
            dashboard = dashboard_;
            AddClass = AddClass_;
            addClassbundle = addClassbundle_;
            customAttribute = customAttribute_;
            frame = frame_;
            menu = menu_;
            login = login_;
            loginbundle = loginbundle_;
            console = console_;
            consolebundle = consolebundle_;          
            ListClass = ListClass_;
            listClassbundle = listClassbundle_;
            addstudentbundle = addstudentbundle_;
            AddStudent = AddStudent_;
		    ListStudent = ListStudent_;
            listStudentbundle = listStudentbundle_;
            listSubjectbundle = listSubjectbundle_;
            ListSubject = ListSubject_;
            addSubjectbundle = addSubjectbundle_;
            AddSubject = AddSubject_;
            listQuestionbundle = listQuestionbundle_;
            ListQuestion = ListQuestion_;
            exambundle = exambundle_;
            exam = exam_;
            countdown = countdown_;
            dataexam = dataexam_;
            showstudentscore = showstudentscore_;
            showstudentscorebundle = showstudentscorebundle_;
            showclassscore = showclassscore_;
            showclassscorebundle = showclassscorebundle_;
        }
		
		void RESET_CONTROL();
		void MENU_CONTROL(char c);
		void ADDCLASS_CONTROL(char c);
		void OTHER_CONTROL(char c);
		void LOGIN_CONTROL(char c);
		void LISTCLASS_CONTROL(char c);
		void LISTSTUDENT_CONTROL(char c);
        void ADDSTUDENT_CONTROL(char c);
        void LISTSUBJECT_CONTROL(char c);
        void LISTQUESTION_CONTROL(char c);
        void ADDSUBJECT_CONTROL(char c);
        void ADDQUESTION_CONTROL(char c);
        void EXAM_CONTROL(char c);
        void IN_EXAM_CONTROL(char c);
        void FINISH_EXAM_CONTROL(char c);
        void SHOWSTUDENTSCORE_CONTROL(char c);
        void SHOWCLASSSCORE_CONTROL(char c);
};

#endif
