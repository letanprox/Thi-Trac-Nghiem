#include <windows.h>
#include <conio.h>  
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include <string>

#include "FRAME.h"

#ifndef COUNTDOWN_H
#define COUNTDOWN_H

struct CountDownBundle{
	clock_t start_clock,cur_total_clock;
	int pos_x;
	int pos_y;
	int cur_pos_x;
	int cur_pos_y;
	int total_minute;
	bool is_rise;
	bool is_stop;
};

class COUNTDOWN{
	private:
		CountDownBundle* countdownbundle;
        CUSTOMATTRIBUTE* customAttribute;
        FRAME* frame;
    public:
    	COUNTDOWN(CountDownBundle* countdownbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_){
		    countdownbundle = countdownbundle_;
		    customAttribute = customAttribute_;
		    frame = frame_;
		}
        void SETCLOCK();
        void RISETIME();
        void GETTIME();
        bool ISBREAK();
        void clearCLOCK();
};

#endif
