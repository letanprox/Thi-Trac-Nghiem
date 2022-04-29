#include <iostream>
#include <windows.h>
#include <conio.h>

#include "FRAME.h"

using namespace std;

#ifndef LISTNUMBER_H
#define LISTNUMBER_H

struct ListNumberBundle{
    int max_number;
    int chose;
    int temp_chose;
    int width_Frame;
    int y_Frame;
    int x_Frame;
    int height;
};

class LISTNUMBER{
		//=====================================================================
	    private:
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
        ListNumberBundle* listnumberbundle;
		//=====================================================================
        public:
		LISTNUMBER(ListNumberBundle* listnumberbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_){
            customAttribute = customAttribute_;
            frame = frame_; 
            listnumberbundle = listnumberbundle_;
        }
        void createList(int width);
};

#endif
