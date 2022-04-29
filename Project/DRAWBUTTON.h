#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "FRAME.h"

#ifndef DRAWINGBUTTON_H
#define DRAWINGBUTTON_H

	struct DrawButton{ 
	    bool is_reset;
        int pos_y;
        int cur_pos_y;
		int pos_x;
		int width;
		int height;
		int background_color;
		char* text_button;
    };
    
class DRAWBUTTON{
		private:
	    CUSTOMATTRIBUTE* customAttribute;
	    public:
        DRAWBUTTON(CUSTOMATTRIBUTE* customAttribute_){
		    customAttribute = customAttribute_;
		};
		void DrawButtonFunction(DrawButton* buttonForm);
};

#endif
