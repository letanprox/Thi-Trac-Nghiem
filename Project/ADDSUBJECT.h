#include <iostream>

#include "APIGETDATA.h"
#include "DRAWINPUT.h"
#include "DRAWBUTTON.h"
#include "CUSTOMATTRIBUTE.h"

#ifndef ADDSUBJECT_H
#define ADDSUBJECT_H
      
    	struct AddSubjectBundle{
		    int chose;
		    int height;
		    int widthFrame;
		    int margin;
		};
		
class ADDSUBJECT{
		//==============================================================================================================
        private:
    	AddSubjectBundle* addSubjectbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUT* drawInput;
		DRAWBUTTON* drawbutton;
		FRAME* frame;
		
    	DrawInput* input01_subject;
    	DrawInput* input02_subject;
    	DrawButton* buttonEnter_subject;	
		//==============================================================================================================
		public:
    	ADDSUBJECT(AddSubjectBundle* addSubjectbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_,FRAME* frame_){
		    addSubjectbundle = addSubjectbundle_;
		    customAttribute = customAttribute_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		    frame = frame_;
		};
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(bool isMove,bool direct,char c);
        void executeElement(char c);
        bool addSubject_();
};

#endif
