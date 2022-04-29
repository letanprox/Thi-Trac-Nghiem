#include <iostream>

#include "DRAWINPUTFORM.h"
#include "DRAWBUTTON.h"
#include "CUSTOMATTRIBUTE.h"

#ifndef LOGIN_H
#define LOGIN_H
      
    	struct LoginBundle{
		    int chose;
		    int height;
		};
		
class LOGIN{
        private:
    	LoginBundle* loginbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUTFORM* drawInputform;
		DRAWBUTTON* drawbutton;
		public:
    	LOGIN(LoginBundle* loginbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUTFORM* drawInputform_,DRAWBUTTON* drawbutton_){
		    loginbundle = loginbundle_;
		    customAttribute = customAttribute_;
		    drawInputform = drawInputform_;
		    drawbutton = drawbutton_;
		};
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(bool isMove,bool direct,char c);
        void executeElement(char c);
        void emplementLogin();
};

#endif
