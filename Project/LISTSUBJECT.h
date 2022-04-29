#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "DRAWINPUT.h"
#include "DRAWBUTTON.h"
#include "APIGETDATA.h"

#ifndef LISTSUBJECT_H
#define LISTSUBJECT_H
      	
    	struct ListSubjectBundle{
    		bool is_editsubject = false;
    		int chose_editsubject;
		    
			int chose;
		    int size;
		    int height;
		    int forward;
		    int margin;
		    int widthFrame;
		    int y_title;
		    int max_size;
		    
		    string MAMH;
		    string TENMH;
		};
		
class LISTSUBJECT{
		//==================================================================================
        private:
    	ListSubjectBundle* listSubjectbundle;
		CUSTOMATTRIBUTE* customAttribute;
		DRAWINPUT* drawInput;
		FRAME* frame;	
		DRAWBUTTON* drawbutton;
		
		vector<NodeSUBJECT> listsubject;
		DrawInput* input_editsubject; 
		DrawButton* button_editsubject;
        //==================================================================================
        public:
    	LISTSUBJECT(ListSubjectBundle* listSubjectbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_){
		    listSubjectbundle = listSubjectbundle_;
		    customAttribute = customAttribute_;
		    frame = frame_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		};
		void createElement(int width);
    	void keepElement(int width);
        void switchElement(int width,bool move);
        void deleteElement();
        
        void createEditSubject(int width);
    	void keepEditSubject(int width);
        void switchEditSubject(char c);
        void excuteEditSubject(char c);
        void updateEditSubject();
        
        void setListSubject(bool out,bool iscreate,int width);
        void moveElement(int width,bool move);
        void clearBlankElement(int width);
};

#endif
