#include <iostream>
#include <windows.h>  
#include <conio.h>
#include "CUSTOMATTRIBUTE.h"
#include "ADDCLASS.h"
#include "MENU.h"
#include "FRAME.h"
#include "CONTROL.h"
#include "LOGIN.h"

using namespace std;

int main() {
	
	LoginBundle* loginbundle = new LoginBundle();
	DashBoard* dashboard = new DashBoard();
    AddClassBundle* addClassbundle = new AddClassBundle();
    CUSTOMATTRIBUTE* customAttribute = new CUSTOMATTRIBUTE();
    MENU* menu = new MENU(customAttribute);
    FRAME* frame = new FRAME(customAttribute);
    DRAWINPUTFORM* drawInputform = new DRAWINPUTFORM(frame,customAttribute);
    DRAWBUTTON* drawbutton = new DRAWBUTTON(customAttribute);
    LOGIN* login = new LOGIN(loginbundle,customAttribute,drawInputform,drawbutton);
    ADDCLASS* AddClass = new ADDCLASS(addClassbundle,customAttribute,drawInputform);
    CONTROL* control = new CONTROL(dashboard,AddClass,addClassbundle,customAttribute,frame,menu,login,loginbundle);
	
//-----------------------------------------------------------------------------------------------------	
while(1){
    dashboard->current_width = customAttribute->getWidthScreen();
    if(dashboard->current_width != dashboard->width){
        control->RESET_CONTROL();
	}

	if(kbhit()){
		bool x = false;
	    char c = getch();
	    
	    
	    if(dashboard->isLogin == false){
	        control->LOGIN_CONTROL(c);
		}else{
			
			///ACTION WHEN TYPE CONTROL IN MENU
	        if(dashboard->inMenu == true && x == false){
                control->MENU_CONTROL(c);
                x = true;
            }
               
			if((dashboard->itemEnter) == 2 && x == false){
				control->ADDCLASS_CONTROL(c);
				x = true;
			}
			
			if(x == false){
			    control->OTHER_CONTROL(c);
			    x = true;
			} 
			
		} 
    }
}
	
  return 0;
}
