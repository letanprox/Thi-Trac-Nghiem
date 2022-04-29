#include <iostream>
#include <windows.h>  
#include <conio.h>

#include "CUSTOMATTRIBUTE.h"
#include "ADDCLASS.h"
#include "ADDSUBJECT.h"
#include "LISTCLASS.h"
#include "LISTSTUDENT.h"
#include "MENU.h"
#include "FRAME.h"
#include "CONTROL.h"
#include "LOGIN.h"
#include "EXAM.h"
#include "LISTNUMBER.h"
#include "EXAMQUESTION.h"
#include "COUNTDOWN.h"
#include "DATAEXAM.h"
#include "SHOWSTUDENTSCORE.h"
#include "SHOWCLASSSCORE.h"

#include "APIGETDATA.h"

using namespace std;

int main() {
	///WINDOWS SIZE
	HWND console_ = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console_, &ConsoleRect); 
    MoveWindow(console_, ConsoleRect.left, ConsoleRect.top, 1070, 700, TRUE);
	////LOG
	consoleLOG_bundle* consolebundle = new consoleLOG_bundle();
	consoleLOG* console = new consoleLOG(consolebundle);
	////ATTRIBUTE
    CUSTOMATTRIBUTE* customAttribute = new CUSTOMATTRIBUTE();
    FRAME* frame = new FRAME(customAttribute);
    DRAWINPUTFORM* drawInputform = new DRAWINPUTFORM(frame,customAttribute);
    DRAWINPUT* drawInput = new DRAWINPUT(frame,customAttribute);
    DRAWINPUTSEARCH* drawInputSearch = new DRAWINPUTSEARCH(frame,customAttribute);
    DRAWBUTTON* drawbutton = new DRAWBUTTON(customAttribute);
    DRAWSWITCHINPUT* drawswitchinput = new DRAWSWITCHINPUT(customAttribute);
	////LOGIN
	LoginBundle* loginbundle = new LoginBundle();
    LOGIN* login = new LOGIN(loginbundle,customAttribute,drawInputform,drawbutton,frame,consolebundle);
    ///MENU
    MENU* menu = new MENU(customAttribute,loginbundle);
	////BOARD CONTROL
	DashBoard* dashboard = new DashBoard();
    ////LIST CLASS STUDENT
    ListClassBundle* listClassbundle = new ListClassBundle();
    ListStudentBundle* listStudentbundle = new ListStudentBundle(); 
    LISTCLASS* ListClass = new LISTCLASS(listClassbundle,customAttribute,frame,drawInput,drawbutton,drawInputSearch);
    LISTSTUDENT* ListStudent = new LISTSTUDENT(listStudentbundle,customAttribute,frame,drawInput,drawbutton,ListClass,listClassbundle,drawswitchinput,drawInputSearch);
    /////ADD CLASS STUDENT
	AddClassBundle* addClassbundle = new AddClassBundle();
    AddStudentBundle* addstudentbundle = new AddStudentBundle();
    ADDCLASS* AddClass = new ADDCLASS(addClassbundle,customAttribute,drawInput,drawbutton,frame);
    ADDSTUDENT* AddStudent = new ADDSTUDENT(addstudentbundle,customAttribute,drawInput,drawbutton,frame,drawswitchinput,listClassbundle);
    /////LIST SUBJECT QUESTION
    ListSubjectBundle* listSubjectbundle = new ListSubjectBundle();
    ListQuestionBundle* listQuestionbundle = new ListQuestionBundle(); 
    LISTSUBJECT* ListSubject= new LISTSUBJECT(listSubjectbundle,customAttribute,frame,drawInput,drawbutton);
    LISTQUESTION* ListQuestion = new LISTQUESTION(listQuestionbundle,customAttribute,frame,drawInputform,drawbutton,listSubjectbundle,drawswitchinput);
    /////ADD SUBJECT QUESTION
	AddSubjectBundle* addSubjectbundle = new AddSubjectBundle();   
    ADDSUBJECT* AddSubject = new ADDSUBJECT(addSubjectbundle,customAttribute,drawInput,drawbutton,frame);
    ////EXAM
    DATAEXAM* dataexam = new DATAEXAM();
    CountDownBundle* countdownbundle = new CountDownBundle();
    COUNTDOWN* countdown = new COUNTDOWN(countdownbundle,customAttribute,frame);
    ListNumberBundle* listnumberbundle = new ListNumberBundle();
    LISTNUMBER* listnumber = new LISTNUMBER(listnumberbundle,customAttribute,frame);
    ExamQuestionBundle* examquestionbundle = new ExamQuestionBundle();
    EXAMQUESTION* examquestion = new EXAMQUESTION(examquestionbundle,customAttribute,frame);
    ExamBundle* exambundle = new ExamBundle();
    EXAM* exam = new EXAM(listnumberbundle,listnumber,examquestionbundle,examquestion,exambundle,customAttribute,frame,drawbutton,drawInput,
	                    loginbundle,listSubjectbundle,dataexam);                 
	////SHOWSCORESTUDENT
	ShowStudentScoreBundle* showstudentscorebundle = new ShowStudentScoreBundle();
	SHOWSTUDENTSCORE* showstudentscore = new SHOWSTUDENTSCORE(showstudentscorebundle,customAttribute,frame,
	listClassbundle,listStudentbundle,exambundle,exam,dataexam);
	////SHOWSCORECLASS
	ShowClassScoreBundle* showclassscorebundle = new ShowClassScoreBundle();
	SHOWCLASSSCORE* showclassscore = new SHOWCLASSSCORE(showclassscorebundle,customAttribute,frame,listClassbundle,listSubjectbundle);          
	////CONTROLL PROGRAM
    CONTROL* control = new CONTROL(dashboard,AddClass,addClassbundle,customAttribute,frame,menu,login,loginbundle,console,
	consolebundle,ListClass,listClassbundle,ListStudent,listStudentbundle,addstudentbundle,AddStudent,ListSubject,listSubjectbundle,addSubjectbundle,AddSubject,
	listQuestionbundle,ListQuestion,exambundle,exam,countdown,dataexam,showstudentscore,showstudentscorebundle,showclassscore,showclassscorebundle);
    /////LOAD DATA
    LoadDatabase();
//-----------------------------------------------------------------------------------------------------	

while(true){
	///REFRAME PROGRAM -------------------------------------------------------------------------------
    dashboard->current_width = customAttribute->getWidthScreen();
    if(dashboard->current_width != dashboard->width || loginbundle->isGotoProgram == true || dashboard->isReset == true) control->RESET_CONTROL();   
	///MAKE CLOCK  -----------------------------------------------------------------------------------
	if(exambundle->is_in_exam == true && exambundle->is_finish_exam == false){
		countdownbundle->total_minute = exambundle->time_exam;
		countdownbundle->cur_pos_x = (dashboard->width - exambundle->widthFrame)/2 + exambundle->widthFrame;
	    countdownbundle->cur_pos_y = 8;
	    ///SET WATCH
	    countdown->SETCLOCK();
	    ///START COUNT TIME
		if(countdownbundle->is_rise == false) countdown->RISETIME();
		///GET TIME FOR WATCH
		if(countdownbundle->is_stop == false) countdown->GETTIME();
		/////CHECK ZERO
		if(countdown->ISBREAK() == true){
			///RESET CLOCK
			countdownbundle->cur_total_clock = 0;
			countdownbundle->start_clock = 0;
			countdownbundle->total_minute = 0;
			countdownbundle->is_rise = false;
			countdownbundle->is_stop = false;
			countdownbundle->pos_x = 0;
		    ////CONDITION
			exambundle->is_temp_finish = true;
			exambundle->is_finish_exam = true;
			///NOTIFICATION
            exam->notTimeout(dashboard->width);
		}   
	}
	///TYPE KEY -------------------------------------------------------------------------------------
	if(kbhit()){
		bool x = false;
	    char c = getch();
	    if(dashboard->isLogin_ed == false){
	        control->LOGIN_CONTROL(c);
		}else{
			int item;
        	///TRANSLATE-----------------------------------
        	if(loginbundle->maUser.compare("GV") == 0){
					 if(dashboard->item == 7) item = 8;			
				else if(dashboard->item == 8) item = 9;
				else if(dashboard->item == 9) item = 10;	
				   else item = dashboard->item;	
			}else{
					 if(dashboard->item == 1) item = 7;
				else if(dashboard->item == 2) item = 8;
				else if(dashboard->item == 3) item = 9;	
				else if(dashboard->item == 4) item = 10;
			}
			///ACTION WHEN TYPE CONTROL IN MENU
	        if(dashboard->inMenu == true && x == false){
                control->MENU_CONTROL(c);
                x = true;
            }
            if((item) == 1 && x == false){
            	if(listStudentbundle->is_in_student == false)control->LISTCLASS_CONTROL(c);
            	else control->LISTSTUDENT_CONTROL(c);
			    x = true;
			}
			if((item) == 2 && x == false){
				control->ADDCLASS_CONTROL(c);
				x = true;
			}
			if((item) == 3 && x == false){
				control->ADDSTUDENT_CONTROL(c);
				x = true;
			}
			if((item) == 4 && x == false){
				if(listQuestionbundle->is_in_question == false)control->LISTSUBJECT_CONTROL(c);
            	else control->LISTQUESTION_CONTROL(c);
				x = true;
			}
			if((item) == 5 && x == false){
				control->ADDSUBJECT_CONTROL(c);
				x = true;
			}
			if((item) == 6 && x == false){
				control->ADDQUESTION_CONTROL(c);
				x = true;
			}
			if((item) == 7 && x == false){
				if(exambundle->is_in_exam == false) control->EXAM_CONTROL(c);
				else{
				    if(exambundle->is_finish_exam == false) control->IN_EXAM_CONTROL(c);
				    else{
				    	////RESET
				    	countdownbundle->pos_x = 0;
						countdownbundle->cur_total_clock = 0;
						countdownbundle->start_clock = 0;
						countdownbundle->total_minute = 0;
						countdownbundle->is_rise = false;
						countdownbundle->is_stop = false;
					    control->FINISH_EXAM_CONTROL(c);
					}
				}
				x = true;
			}
			if((item) == 8 && x == false){
				control->SHOWSTUDENTSCORE_CONTROL(c);
				x = true;
			}
			if((item) == 9 && x == false){
				control->SHOWCLASSSCORE_CONTROL(c);
				x = true;
			}
			if(x == false){
			    control->OTHER_CONTROL(c);
			    x = true;
			} 
		} 
    }
//Sleep(0);
}	
return 0;
}
