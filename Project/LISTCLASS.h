#include <iostream>
#include <vector>

#include "APIGETDATA.h"
#include "CUSTOMATTRIBUTE.h"
#include "DRAWINPUT.h"
#include "DRAWBUTTON.h"
#include "DRAWINPUTSEARCH.h"

#ifndef LISTCLASS_H
#define LISTCLASS_H
      	
    	struct ListClassBundle{
    		bool is_editclass = false;
    		int chose_editclass;
		    
			int chose;
		    int size;
		    int height;
		    int forward;
		    int margin;
		    int widthFrame;
		    int y_title;
		    int max_size;
		    
		    string MALOP;
		    string TENLOP;
		};
		
class LISTCLASS{
		//============================================================================================  
        private:
    	ListClassBundle* listClassbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUT* drawInput;
		FRAME* frame;	
		DRAWBUTTON* drawbutton;
		DRAWINPUTSEARCH* drawInputSearch;
		
		vector<NodeCLASS> listclass;
		DrawInput* input_editclass; 
		DrawButton* button_editclass;
		
		DrawInputSearch* input_search_tenlop;
      	//============================================================================================  
        public:
    	LISTCLASS(ListClassBundle* listClassbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_,DRAWINPUTSEARCH* drawInputSearch_){
		    listClassbundle = listClassbundle_;
		    customAttribute = customAttribute_;
		    frame = frame_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		    drawInputSearch = drawInputSearch_;
		};
		int status;
		
		void createElement(int width);
    	void keepElement(int width);
        void switchElement(int width,bool move);
        void deleteElement();
		void searchElement(int width,char c);
		void keepSearchElement(int width,char c);
		void switchSearchElement(char c);
		void excuteSearchElement(int width,char c);
        
        void createEditClass(int width);
    	void keepEditClass(int width);
        void switchEditClass(char c);
        void excuteEditClass(char c);
        void updateEditClass();
        
        void setListClass(bool out,bool iscreate,int width);
        void moveElement(int width,bool move);
        void clearBlankElement(int width);
		void clearBlankListElement(int width);
};

#endif
