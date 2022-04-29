#include <iostream>
#include <vector>

#include "CUSTOMATTRIBUTE.h"
#include "STUDENT.h"
#include "DRAWINPUT.h"
#include "DRAWINPUTSEARCH.h"
#include "DRAWBUTTON.h"
#include "DRAWSWITCHINPUT.h"
#include "LISTCLASS.h"

#ifndef LISTSTUDENT_H
#define LISTSTUDENT_H
      
    	struct ListStudentBundle{
    		bool is_in_student = false;     	
    		bool is_editstudent = false;
    		int chose_edit_elementstudent;
    		
			int chose;
		    int size;
		    int max_size;
		    int height;
		    int forward;
		    int margin;
		    int widthFrame;
		    int y_title;
		    char* text_search;
		    
		    string MASV;
		    string HOTEN;
		    string PHAI;
		    string PASSWORD;
		};
		
class LISTSTUDENT{
		//===========================================================================================
        private:
        LISTCLASS* ListClass;	
        ListClassBundle* listClassbundle;
        ListStudentBundle* listStudentbundle;
		DRAWINPUT* drawInput;
		DRAWBUTTON* drawbutton;
		DRAWINPUTSEARCH* drawInputSearch;
        DRAWSWITCHINPUT* drawswitchinput;
		FRAME* frame;
		CUSTOMATTRIBUTE* customAttribute;
		
    	DrawInput* input_edit_hoten;
    	DrawInput* input_edit_password;
    	DrawSwitchInput* switchinput_edit_phai;
    	DrawButton* button_edit_student;
    	
		DrawInputSearch* input_search_hoten;
		//===========================================================================================
        public:
    	LISTSTUDENT(ListStudentBundle* listStudentbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,DRAWINPUT* drawInput_,DRAWBUTTON* drawbutton_,
		LISTCLASS* ListClass_,ListClassBundle* listClassbundle_,DRAWSWITCHINPUT* drawswitchinput_,DRAWINPUTSEARCH* drawInputSearch_){
		    listStudentbundle = listStudentbundle_;
		    customAttribute = customAttribute_;
		    frame = frame_;
		    drawInput = drawInput_;
		    drawbutton = drawbutton_;
		    ListClass = ListClass_;
            listClassbundle = listClassbundle_;
            drawswitchinput = drawswitchinput_; 
            drawInputSearch = drawInputSearch_;
		};
		int status;
		vector<NodeSTUDENT> liststudent;

		void createElement(int width);
    	void keepElement(int width);
        void switchElement(int width,bool move);
        void deleteElement();
		void searchElement(int width,char c);
		void keepSearchElement(int width,char c);
		void switchSearchElement(char c);
		void excuteSearchElement(int width,char c);

        void createEditStudent(int width);
    	void keepEditStudent(int width);
    	void switchEditPhaiStudent(char c);
        void switchEditStudent(bool isMove,bool direct,char c);
        void excuteEditStudent(char c);
        void updateEditStudent();

        void clearBlankElement(int width);
        void clearBlankListElement(int width);
        void clearBlankEditElement(int width);
        void setListStudent(bool out,bool iscreate,int width);
        void moveElement(int width,bool move);
};

#endif
