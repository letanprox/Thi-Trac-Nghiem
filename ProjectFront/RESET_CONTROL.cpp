#include "CONTROL.h"

using namespace std;

void CONTROL::RESET_CONTROL(){
			system("cls");
			dashboard->width  = dashboard->current_width;
			
		if(dashboard->isLogin == false){
            
            if(dashboard->isLoadLogin == true){
				login->createElement(dashboard->width);
				dashboard->isLoadLogin = false;
			}else{
				login->keepElement(dashboard->width);
			}
			dashboard->height = loginbundle->height;
			frame->frameLogin(9,dashboard->width,dashboard->height);
			
			loginbundle->chose = 1;
			login->switchElement(false,true,' ');

			
		}else {
		//-------------------------------------------------------------------------------------------------	
        	frame->FrameTitle(dashboard->width,dashboard->color_Theme,"GV01","LE QUOC TAN");
        	menu->DisplayItem(dashboard->item,dashboard->itemEnter,dashboard->inMenu);
        	
        	if(dashboard->FirstProgram == true){
        		dashboard->FirstProgram = false;
        		
        		dashboard->current_height = 25;
                dashboard->height = dashboard->current_height;
                
                frame->LineContent(dashboard->width,"");
                frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
                
            }else if(dashboard->itemEnter == 2){

        	    AddClass->keepElement(dashboard->width);
                dashboard->current_height = addClassbundle->height;
                dashboard->height = dashboard->current_height;
        	    frame->LineContent(dashboard->width," THEM LOP ");
        	    frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
                AddClass->switchElement(' ');
                
		    }else{
		    	
		    	frame->LineContent(dashboard->width,"  ");
		        frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
		        
			}
		//-------------------------------------------------------------------------------------------------
		}
}



