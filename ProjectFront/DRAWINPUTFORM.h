#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "FRAME.h"

#ifndef DRAWINPUTFORM_H
#define DRAWINPUTFORM_H

	struct DrawInputForm{
		char* text_form; 
		
        bool ischangeWidth;
        
        int pos_y;
		int cur_pos_y; 
		int pos_x;
		
		int width;
		int margin_right;
		
		int height_text;
		int width_text;
		
		int position_cursor_y;
		int position_cursor_x;
		int position_cursor_last_line_x;
		int position_cursor_last_line_y;
			
		int text_length; 
		char* text_input; 
		
		int point_text;
    };
    


class DRAWINPUTFORM{
		private:
	    CUSTOMATTRIBUTE* customAttribute;
	    FRAME* frame;
	    public:
        DRAWINPUTFORM(FRAME* frame_,CUSTOMATTRIBUTE* customAttribute_){
		    frame = frame_;
		    customAttribute = customAttribute_;
		};
		void DrawInputFormFunction(DrawInputForm* inputForm, char c,bool isCodeKey,int bottom_height_frame);
};

#endif
