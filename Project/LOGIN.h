#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "DRAWINPUTFORM.h"
#include "DRAWBUTTON.h"

#include "consoleLOG.h"

#ifndef LOGIN_H
#define LOGIN_H
      
struct LoginBundle{
		int chose;
		int height;
		bool isGotoProgram;
		    
		string nameUser;
	    string maUser;
	    string maLop;
};
		
class LOGIN{
		///----------------------------------------------------------------
        private:
    	LoginBundle* loginbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUTFORM* drawInputform;
		DRAWBUTTON* drawbutton;
		FRAME* frame_login;
		consoleLOG_bundle* consolebundle ;

    	DrawInputForm* inputForm_login_1;
    	DrawInputForm* inputForm_login_2;
    	DrawButton* buttonForn_login_1;
		///-----------------------------------------------------------------
		public:
    	LOGIN(LoginBundle* loginbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUTFORM* drawInputform_,DRAWBUTTON* drawbutton_,FRAME* frame_,consoleLOG_bundle* consolebundle_){
		    loginbundle = loginbundle_;
		    customAttribute = customAttribute_;
		    drawInputform = drawInputform_;
		    drawbutton = drawbutton_;
		    frame_login = frame_;
		    consolebundle = consolebundle_;
		};
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(bool isMove,bool direct,char c);
        void executeElement(char c);
        void implementLogin();
};

#endif
