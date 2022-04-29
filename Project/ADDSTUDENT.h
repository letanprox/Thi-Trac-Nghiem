#include <iostream>

#include "APIGETDATA.h"
#include "CUSTOMATTRIBUTE.h"
#include "DRAWINPUT.h"
#include "DRAWBUTTON.h"
#include "DRAWSWITCHINPUT.h"
#include "LISTCLASS.h"

#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H
      
    	struct AddStudentBundle{
    		bool is_addstudent = false;
		    int chose;
		    int height;
		    int widthFrame;
		    int margin;
		};
		
class ADDSTUDENT{
		//=================================================================================
        private:
    	AddStudentBundle* addstudentbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUT* drawInput;
		DRAWBUTTON* drawbutton;
		FRAME* frame;
        DRAWSWITCHINPUT* drawswitchinput;
        ListClassBundle* listClassbundle;
        
    	DrawInput* input_masv;
    	DrawInput* input_hoten;
    	DrawInput* input_password;
    	DrawSwitchInput* switchinput_phai;
    	DrawButton* button_add_student;
    	//=================================================================================
		public:
    	ADDSTUDENT(AddStudentBundle* addstudentbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_,
		FRAME* frame_,DRAWSWITCHINPUT* drawswitchinput_,ListClassBundle* listClassbundle_){
		    addstudentbundle = addstudentbundle_;
		    customAttribute = customAttribute_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		    frame = frame_;
		    drawswitchinput = drawswitchinput_;
		    listClassbundle = listClassbundle_;
		};
	
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(bool isMove,bool direct,char c);
        void executeElement(char c);
        bool addStudent_();
        
        void clearBlankAddStudent(int width);
        void switchPhaiStudent(char c);
};

#endif
