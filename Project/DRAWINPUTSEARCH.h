#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "FRAME.h"

#ifndef DRAWINPUTSEARCH_H
#define DRAWINPUTSEARCH_H

struct DrawInputSearch{
    bool is_reset;
	string text_form;
        
    int pos_y;
	int pos_x;
	int width;
		
	int width_text;
	int point_text;
	int cursor_x;
	int cursor_last_x;
		
	int text_length;
	char* text_input;
};
    
class DRAWINPUTSEARCH{
		private:
	    CUSTOMATTRIBUTE* customAttribute;
	    FRAME* frame;
	    public:
        DRAWINPUTSEARCH(FRAME* frame_,CUSTOMATTRIBUTE* customAttribute_){
		    frame = frame_;
		    customAttribute = customAttribute_;
		};
		void DrawInputSearchFunction(DrawInputSearch* input, char c,bool isCodeKey);
};   
#endif
