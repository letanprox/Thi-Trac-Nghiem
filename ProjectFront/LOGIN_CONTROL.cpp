#include "CONTROL.h"

using namespace std;

void CONTROL::LOGIN_CONTROL(char c){
	
	bool x = false;
	
	if((int)c == -32){
	    c = getch();
	    ///TOP
	    if(c == 72 && x == false){
            login->switchElement(true,false,c);
		    x = true;
	    }
	    ///BOTTOM	
	    if(c == 80  && x == false){
            login->switchElement(true,true,c);
		    x = true;
	    }
	    x = true;
	}
	

	///ENTER
	if(c=='\r' && x == false){          	
        
	    x = true;
	}
	
	///TYPE CHARACTER
	if(x == false){
        login->executeElement(c);
        dashboard->current_height = loginbundle->height;
        frame-> ReframeLogin(dashboard->current_height,dashboard->height,dashboard->width,9);
        dashboard->height = dashboard->current_height;
        login->switchElement(false,true,c);
        x = true;
	}
}

