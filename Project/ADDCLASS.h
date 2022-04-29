#include <iostream>

#include "APIGETDATA.h"
#include "DRAWINPUT.h"
#include "DRAWBUTTON.h"
#include "CUSTOMATTRIBUTE.h"

#ifndef ADDCLASS_H
#define ADDCLASS_H
      
    	struct AddClassBundle{
		    int chose;
		    int height;
		    int widthFrame;
		    int margin;
		};
		
class ADDCLASS{
		//=====================================================================================
        private:
    	AddClassBundle* addClassbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUT* drawInput;
		DRAWBUTTON* drawbutton;
		FRAME* frame;
		
    	DrawInput* input01;
    	DrawInput* input02;
    	DrawButton* buttonEnter;
		//=====================================================================================
		public:
    	ADDCLASS(AddClassBundle* addClassbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_,FRAME* frame_){
		    addClassbundle = addClassbundle_;
		    customAttribute = customAttribute_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		    frame = frame_;
		};
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(bool isMove,bool direct,char c);
        void executeElement(char c);
        bool addClass_();
};

#endif
