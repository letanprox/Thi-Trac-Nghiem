#include <iostream>
#include <windows.h>  
#include <conio.h>
#include "ADDCLASS.h"
#include "MENU.h"
#include "FRAME.h"
#include "LOGIN.h"

using namespace std;

#ifndef CONTROL_H
#define CONTROL_H


struct DashBoard{
	bool isLogin = false;
	bool isLoadLogin = true;
	bool FirstProgram = true;
    int color_Theme = 9; 
	int width = 0;
	int current_width = 0;
	int height = 0;
	int current_height = 0;
	bool inMenu = true;
	int item = 1;
	int itemEnter = 1;
    bool x = true;
};

class CONTROL{
	    private:
		DashBoard* dashboard;
        AddClassBundle* addClassbundle;
        ADDCLASS* AddClass;
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        MENU* menu;
        LOGIN* login;
        LoginBundle* loginbundle;
        public:
		CONTROL(DashBoard* dashboard_,ADDCLASS* AddClass_,AddClassBundle* addClassbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,MENU* menu_,LOGIN* login_,LoginBundle* loginbundle_){
            dashboard = dashboard_;
            AddClass = AddClass_;
            addClassbundle = addClassbundle_;
            customAttribute = customAttribute_;
            frame = frame_;
            menu = menu_;
            login = login_;
            loginbundle = loginbundle_;
        }
		
		void RESET_CONTROL();
		void MENU_CONTROL(char c);
		void ADDCLASS_CONTROL(char c);
		void OTHER_CONTROL(char c);
		void LOGIN_CONTROL(char c);
};

#endif



