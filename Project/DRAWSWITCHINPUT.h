#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "FRAME.h"

#ifndef DRAWSWITCHINPUT_H
#define DRAWSWITCHINPUT_H

	struct DrawSwitchInput{ 
	    bool is_reset;
        int pos_y;
        int cur_pos_y;
		int pos_x;
		int width;
		int height;
		int background_color;
		int background_color_switch;
		bool is_rise_event;
		bool is_next;
		string text;
		string text_form;
    };
    
class DRAWSWITCHINPUT{
		private:
	    CUSTOMATTRIBUTE* customAttribute;
	    public:
        DRAWSWITCHINPUT(CUSTOMATTRIBUTE* customAttribute_){
		    customAttribute = customAttribute_;
		};
		void DrawSwitchInputFunction(DrawSwitchInput* drawswitchinput);
};

#endif
