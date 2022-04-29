#include <iostream>

#include "CUSTOMATTRIBUTE.h"
#include "DRAWINPUTFORM.h"
#include "DRAWBUTTON.h"
#include "DRAWSWITCHINPUT.h"
#include "LISTSUBJECT.h"

#ifndef LISTQUESTION_H
#define LISTQUESTION_H
      
    	struct ListQuestionBundle{
    		bool is_in_question = false;     	
    		bool is_editquestion = false;
    		int chose_edit_elementquestion;
    		
			int chose;
		    int size;
		    int max_size;
		    int height;
		    int forward;
		    int margin;
		    int widthFrame;
		    int y_title;
		    int chose_answer;
		    
		    string Id;
		    string NOIDUNG;
		    string A;
		    string B;
		    string C;
		    string D;
		    int ANSWER;
		};
		
class LISTQUESTION{
		//====================================================================================
        private:
        LISTSUBJECT* ListQuestion;	
        ListQuestionBundle* listQuestionbundle;

		DRAWINPUTFORM* drawInputform;
		DRAWBUTTON* drawbutton;
        DRAWSWITCHINPUT* drawswitchinput;
		FRAME* frame;
		CUSTOMATTRIBUTE* customAttribute;
		ListSubjectBundle* listSubjectbundle;
		
		vector<NodeQUESTION> listquestion;
		DrawInputForm* input_edit_NOIDUNG;
    	DrawInputForm* input_edit_A;
    	DrawInputForm* input_edit_B;
    	DrawInputForm* input_edit_C;
    	DrawInputForm* input_edit_D;
    	DrawSwitchInput* switchinput_edit_ANSWER;
    	DrawButton* button_edit_QUESTION;
		//====================================================================================
        public:
    	LISTQUESTION(ListQuestionBundle* listQuestionbundle_,CUSTOMATTRIBUTE* customAttribute_,FRAME* frame_,DRAWINPUTFORM* drawInputform_,
		DRAWBUTTON* drawbutton_,ListSubjectBundle* listSubjectbundle_,DRAWSWITCHINPUT* drawswitchinput_){
		    listQuestionbundle = listQuestionbundle_;
		    customAttribute = customAttribute_;
		    frame = frame_;
		    drawbutton = drawbutton_;
            listSubjectbundle = listSubjectbundle_;
            drawswitchinput = drawswitchinput_;
            drawInputform = drawInputform_;
            
		};
		void createElement(int width);
    	void keepElement(int width);
        void switchElement(int width,bool move);
        bool deleteElement();
        
        void createEditQuestion(bool is_add,int width);
    	void keepEditQuestion(int width);
    	void switchEditAnswerQuestion(char c);
        void switchEditQuestion(bool isMove,bool direct,char c);
        void excuteEditQuestion(char c);
        bool updateEditQuestion();
        bool addQuestion_();
        
        void clearBlankElement(int width);
        void clearBlankEditElement(int width);
        void setListQuestion(bool out,bool iscreate,int width);
        void moveElement(int width,bool move);
        void checkElement();
};

#endif
