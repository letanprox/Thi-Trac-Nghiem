#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "FRAME.h"

#ifndef DRAWINPUT_H
#define DRAWINPUT_H

	struct DrawInput{
        bool is_reset;
		char* text_form; 
        
        int pos_y;
        int cur_pos_y;
		int pos_x;
		int width;
		int margin_right;

		int width_text;
		int point_text;
		int cursor_x;
		int cursor_last_x;
		
		int text_length; 
		char* text_input; 
    };
    

class DRAWINPUT{
		private:
	    CUSTOMATTRIBUTE* customAttribute;
	    FRAME* frame;
	    public:
        DRAWINPUT(FRAME* frame_,CUSTOMATTRIBUTE* customAttribute_){
		    frame = frame_;
		    customAttribute = customAttribute_;
		};
		void DrawInputFunction(DrawInput* input, char c,bool isCodeKey);
};   
#endif

