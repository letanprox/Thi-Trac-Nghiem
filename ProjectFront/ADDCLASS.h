#include <iostream>

#include "DRAWINPUTFORM.h"
#include "CUSTOMATTRIBUTE.h"

#ifndef ADDCLASS_H
#define ADDCLASS_H
      
    	struct AddClassBundle{
		    int chose;
		    int height;
		};
		
class ADDCLASS{
        private:
    	AddClassBundle* addClassbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUTFORM* drawInputform;
		public:
    	ADDCLASS(AddClassBundle* addClassbundle_,CUSTOMATTRIBUTE* customAttribute_,DRAWINPUTFORM* drawInputform_){
		    addClassbundle = addClassbundle_;
		    customAttribute = customAttribute_;
		    drawInputform = drawInputform_;
		};
    	void createElement(int width);
    	void keepElement(int width);
        void switchElement(char c);
        void executeElement(char c);
};

#endif
