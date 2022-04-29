#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

#include "LISTNUMBER.h"

using namespace std;

void LISTNUMBER::createList(int width){
	int line = listnumberbundle->y_Frame;
	int x_move = listnumberbundle->x_Frame-1;
	int mount_width = 0;
	int line_final = listnumberbundle->y_Frame;
	int final_mount_width = 0;
	
	for(int i = 1; i <= listnumberbundle->max_number; i++){
		if(listnumberbundle->width_Frame-3 < mount_width){
			mount_width = 0;
			line_final = line_final + 2;
		}
	    if(i < 10){
		    mount_width = mount_width + 4;
		}else{
			mount_width = mount_width + 5;
		}
	}
	int x_final = listnumberbundle->x_Frame - 3 + (listnumberbundle->width_Frame - mount_width)/2;
	mount_width = 0;
	bool is_check_final = false;
	for(int i = 1; i <= listnumberbundle->max_number; i++){
		if(listnumberbundle->width_Frame-3 < mount_width){
			mount_width = 0;
		    line = line + 2;
		    x_move = listnumberbundle->x_Frame-2;
		}
		if(line == line_final){
			if(is_check_final == false){
			    x_move = x_final;
			    is_check_final = true;
			}
		}
		if(i < 10){
	    	x_move = x_move + 4;
	    	///////MAKE BACKGROUND
	    	if(listnumberbundle->chose == listnumberbundle->temp_chose)
	    		if(listnumberbundle->chose == i) customAttribute->setBackgroundText(9,10);
				else customAttribute->setBackgroundText(7,8);   
			else 
			    if(listnumberbundle->chose == i) customAttribute->setBackgroundText(7,10);
				else if(listnumberbundle->temp_chose == i) customAttribute->setBackgroundText(7,9);   
				else customAttribute->setBackgroundText(7,8);   
				
			for(int p = -1;p < 2;p++){
			    customAttribute->setPosionCursor(x_move+p,line);
			    cout <<" ";
			    }
			customAttribute->setPosionCursor(x_move,line);
				cout << i;
			customAttribute->setBackgroundText(7,0); 
			mount_width = mount_width + 4;
		}else{
			if(i == 10) x_move = x_move -1;
	    	x_move = x_move + 5;
	    	///////MAKE BACKGROUND
	    	if(listnumberbundle->chose == listnumberbundle->temp_chose)
	    		if(listnumberbundle->chose == i) customAttribute->setBackgroundText(9,10);
				else customAttribute->setBackgroundText(7,8);   
			else 
			    if(listnumberbundle->chose == i) customAttribute->setBackgroundText(7,10);
				else if(listnumberbundle->temp_chose == i) customAttribute->setBackgroundText(7,9);   
				else customAttribute->setBackgroundText(7,8);  
			    for(int p = -1;p < 3;p++){
			    	customAttribute->setPosionCursor(x_move+p,line);
			        cout <<" ";
			    }
			customAttribute->setPosionCursor(x_move,line);
				cout << i;
			customAttribute->setBackgroundText(7,0); 
			mount_width = mount_width + 5;
		}
	}
	listnumberbundle->height = line_final + 2 - listnumberbundle->y_Frame;
}
