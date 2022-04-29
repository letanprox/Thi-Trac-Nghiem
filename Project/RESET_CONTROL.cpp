#include "CONTROL.h"

using namespace std;

void CONTROL::RESET_CONTROL(){ system("cls");
	///CONDITON ========================================================================================
	///CHANGE WIDTH TO NOT CHANGE
	dashboard->width  = dashboard->current_width;
	///CHANGE RESET TO NOT RESET
	dashboard->isReset = false;
	///CHANGE FROM LOGIN TO PROGRAM
    if(loginbundle->isGotoProgram == true){
    	loginbundle->isGotoProgram = false;
		    dashboard->isLogin_ed = true;}
		////IMPLEMENT CONDITION	=========================================================================
		if(dashboard->isLogin_ed == false){
			///create login element-----------------------
            if(dashboard->isLoadingLogin == true){
				login->createElement(dashboard->width);
				dashboard->isLoadingLogin = false;
				loginbundle->chose = 1;
			}else login->keepElement(dashboard->width);
				///get height-----------------------------
				dashboard->height = loginbundle->height;
				dashboard->current_height = dashboard->height;
				frame->frameLogin(9,dashboard->width,dashboard->height);
				login->switchElement(false,true,' ');
		}else{
			//create title theme and menu-----------------
          	frame->FrameTitle(dashboard->width,dashboard->color_Theme,loginbundle->maUser,loginbundle->nameUser);
        	menu->DisplayItem(dashboard->item,dashboard->itemEnter,dashboard->inMenu);
        	//translate menu------------------------------
        	int item;
       		if(loginbundle->maUser.compare("GV") == 0){
			 		if(dashboard->itemEnter == 7) item = 8;			
				else if(dashboard->itemEnter == 8) item = 9;
				else if(dashboard->itemEnter == 9) item = 10;	
			   	  else item = dashboard->itemEnter;
			}else{
			 		 if(dashboard->itemEnter == 1) item = 7;
				else if(dashboard->itemEnter == 2) item = 8;
				else if(dashboard->itemEnter == 3) item = 9;	
				else if(dashboard->itemEnter == 4) item = 10;
			}
        	//start program--------------------------------	
        	if(dashboard->isLoadingProgram == true){
        		dashboard->isLoadingProgram = false;
                dashboard->height = 29;
                frame->LineContent(dashboard->width,"",35);
                frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
            //---------------------------------------------------------------------------------------------------------------
            }else if(item == 1){
				////DRAW FRAME
        	    frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);     
				///DRAW ELEMENT 
				if(listStudentbundle -> is_in_student == false){
					////IN CLASS LIST
					int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
				    if( listClassbundle->is_editclass == false){
				    	///NON EDIT
	        	        ListClass->keepElement(dashboard->width);
	        	        frame->LineContent(dashboard->width," DANH SACH LOP ",x);
	        	        frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   TYPE:TIMKIEM   ENTER");
                    }else{
                    	///EDIT
        	    	    ListClass->keepEditClass(dashboard->width);
                        frame->LineContent(dashboard->width," DANH SACH LOP ",x);
                        frame->LineGuide(dashboard->height,"ESC   ENTER");
                        ListClass->switchEditClass(' ');
				    }
				}else{
					////IN STUDENT
					int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;	
				    if(listStudentbundle->is_editstudent == false){
				    	////NON EDIT
	        	        ListStudent->keepElement(dashboard->width);
	                    frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
	                    frame->LineGuide(dashboard->height,"ESC   F4:XOA   TYPE:TIMKIEM   ENTER:SUA");
        	        }else{
        	        	////EDIT
        	    	    ListStudent->keepEditStudent(dashboard->width);
                        frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
                        frame->LineGuide(dashboard->height,"ESC   ENTER");
                        ListStudent->switchEditStudent(false,false,' ');
				    }
				}     	
            ////-------------------------------------------------------------------------------------------------------          
		    }else if(item == 2){
                /////KEEP ADDCLASS
        	    AddClass->keepElement(dashboard->width);
        	    ////DRAW TITLE LINE
        	    int x = addClassbundle->margin + ((dashboard->width-addClassbundle->margin) - addClassbundle->widthFrame)/2;
        	    frame->LineContent(dashboard->width," THEM LOP ",x);
        	    ////DRAW LAST LINE
    	        frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
                ///GUIDE LINE
                frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
        	    /////CURSOR ELEMENT
                AddClass->switchElement(false,false,' '); 	
			////-------------------------------------------------------------------------------------------------------      
			}else if(item == 3){
			    if(addstudentbundle->is_addstudent == false){
			    	//////KEEP LISTCLASS
				    ListClass->keepElement(dashboard->width);
			        //////TITLE
		    	    int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    	    frame->LineContent(dashboard->width," DANH SACH LOP ",x);
		    	    /////LINE
		    	    frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
            		///GUIDE LINE
            		frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}else{
					AddStudent->keepElement(dashboard->width);
		            //////TITLE
                    int x =  addstudentbundle->margin + ((dashboard->width-addstudentbundle->margin) - addstudentbundle->widthFrame)/2;
                    frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
                    /////CREATE FRAME
					frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
					////GUIDE LINE
		    		frame->LineGuide(dashboard->height,"ESC   ENTER");
		            ////RE DRAW
					AddStudent->keepElement(dashboard->width);
					////CURSOR ELEMENT
		            AddStudent->switchElement(false,false,' ');
				}
	        ////-------------------------------------------------------------------------------------------------------     	
			}else if(item == 4){
				if(listQuestionbundle->is_in_question == false){
    				////DRAW FRAME
        	    	frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);       	
					////IN SUBJECT LIST
					int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
					if( listSubjectbundle->is_editsubject == false){
				    	///NON EDIT
	        	    	ListSubject->keepElement(dashboard->width);
	        	    	frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            			////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC:MENU   F4:XOA   F3:SUA   ENTER");
                	}else{
                 		///EDIT
        	   	    	ListSubject->keepEditSubject(dashboard->width);
                    	frame->LineContent(dashboard->width," MON HOC: "+listSubjectbundle->MAMH+" ",x);
						////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC   ENTER");
                    	ListSubject->switchEditSubject(' ');    
			    	}
			    }else{
                	////DRAW FRAME
        	    	frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);       	
					////IN QUESTION LIST
					int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
					if( listQuestionbundle->is_editquestion == false){
				    	///NON EDIT
	        	    	ListQuestion->keepElement(dashboard->width);
	        	    	frame->LineContent(dashboard->width," DANH SACH CAU HOI ",x);
            			////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC   F4:XOA   ENTER");
                	}else{
                 		///EDIT
        	   	    	ListQuestion->keepEditQuestion(dashboard->width);
                    	frame->LineContent(dashboard->width," Id Cau hoi: "+listQuestionbundle->Id+" ",x);
            			////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
                    	ListQuestion->switchEditQuestion(false,false,' ');    
			    	}
				}
            ////-------------------------------------------------------------------------------------------------------          
		    }else if(item == 5){
                /////KEEP ADDSUBJECT
        	    AddSubject->keepElement(dashboard->width);
        	    ////DRAW TITLE LINE
        	    int x = addSubjectbundle->margin + ((dashboard->width-addSubjectbundle->margin) - addSubjectbundle->widthFrame)/2;
        	    frame->LineContent(dashboard->width," THEM MON HOC ",x);
        	    ////DRAW LAST LINE
    	        frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
				////GUIDE LINE
				frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
        	    /////CURSOR ELEMENT
                AddSubject->switchElement(false,false,' '); 	
			////-------------------------------------------------------------------------------------------------------      
			}else if(item == 6){
    			//DRAW FRAME
                frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);      
	        	if( listQuestionbundle->is_editquestion == false){
					////IN SUBJECT LIST
					int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
					frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
				    ///NON EDIT
	        	    ListSubject->keepElement(dashboard->width);
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}else{
            		int x = listQuestionbundle->margin + ((dashboard->width-listQuestionbundle->margin) - listQuestionbundle->widthFrame)/2;
            		frame->LineContent(dashboard->width," THEM CAU HOI CHO MON " + listSubjectbundle->MAMH + " " ,x);
        	   	    ListQuestion->keepEditQuestion(dashboard->width);
            		////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
                    ListQuestion->switchEditQuestion(false,false,' ');    
				}
            ////-------------------------------------------------------------------------------------------------------          
		    }else if(item == 7){
                if(exambundle->is_in_condition_exam == false){
				   	exam->clearBlankConditionExam(dashboard->width);
					ListSubject->keepElement(dashboard->width);
					////FRAME CONTENT
					frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
            		////CHANGE TITLE CLASS
		    		int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    		frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}else{
					if(exambundle->is_in_exam == false){
	        			////SHOW ELEMENT
						exam->keepConditionExam(dashboard->width);
						////TITLE
            			string title = " NHAP CAU HOI CHO BAI THI ";
	    				int x = exambundle->margin + ((dashboard->width-exambundle->margin) - exambundle->widthFrame)/2 - 1;
	    				frame->LineContent(dashboard->width,title,x);
						////FRAME CONTENT
						dashboard->current_height = exambundle->height;
						frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
						////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC   ENTER");
		    			////CURSOR ELEMENT
						exam->switchConditionExam(false,false,' ');
					}else{
						if(exambundle->is_finish_exam == false){
							string title = " MON THI " + listSubjectbundle->MAMH + " ";
	    					int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
                    		frame->LineContent(dashboard->width,title,x);
            				////FRAME CONTENT
							frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
            				////GUIDE LINE
							frame->LineGuide(dashboard->height,"TOP BOTTOM LEFT RIGHT  ENTER");
			            	////SHOW EXAM
            				exam->keepExam(dashboard->width);  
            			}else{
            				if(exambundle->is_view_answer == false){
	    						exam->keepAchievementExam(false,dashboard->width);				
								string title = " THANH TICH ";
	    						int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length())/2;
	    						frame->LineContent(dashboard->width,title,x);
            					////FRAME CONTENT
								frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
								////GUIDE LINE
								frame->LineGuide(dashboard->height,"ENTER");
							}else{
								exam->keepResulteExam(dashboard->width);
								////TITLE
                				string title = " MON THI " + listSubjectbundle->MAMH + " ";
	    						int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
                				frame->LineContent(dashboard->width,title,x);
            					///REDRAW FRAME CONTENT
								frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);		
            					////GUIDE LINE
								frame->LineGuide(dashboard->height,"TOP BOTTOM LEFT RIGHT  ENTER");
							}
						}
					}
				}
            ////-------------------------------------------------------------------------------------------------------          
		    }else if(item == 8){
			    if(showstudentscorebundle->chose_element == 1){
	        	        ListClass->keepElement(dashboard->width);
	        	        int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
	        	        frame->LineContent(dashboard->width," DANH SACH LOP ",x);
	        	        ////DRAW FRAME
        	    		frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme); 
						////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}else if(showstudentscorebundle->chose_element == 2){
	        	        ListStudent->keepElement(dashboard->width);
	        	        ///	TITLE
            			int x = listStudentbundle->margin + ((dashboard->width-listStudentbundle->margin) - listStudentbundle->widthFrame)/2;	
            			frame->LineContent(dashboard->width," LOP: "+listClassbundle->MALOP+" ",x);
	        	        ////DRAW FRAME
        	    		frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme); 
						////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC   ENTER");
				}else if(showstudentscorebundle->chose_element == 3){
            			showstudentscore->keepListScoreElement(dashboard->width);
            			///TITLE
            			int x = showstudentscorebundle->margin + ((dashboard->width-showstudentscorebundle->margin) - showstudentscorebundle->widthFrame)/2;	
            			frame->LineContent(dashboard->width," MASV: "+showstudentscorebundle->MASV+" ",x);
	        	        ////DRAW FRAME
        	    		frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme); 
        	    		///GUIDE LINE 
						if(loginbundle->maUser.compare("GV") == 0) frame->LineGuide(dashboard->height,"ESC   ENTER");
						else frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}else if(showstudentscorebundle->chose_element == 4){
	    				exam->keepAchievementExam(false,dashboard->width);	
						///TITLE			
						string title = " THANH TICH ";
	    				int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length())/2;
	    				frame->LineContent(dashboard->width,title,x);
            			////FRAME CONTENT
						frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
						////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC   ENTER");
				}else if(showstudentscorebundle->chose_element == 5){
						exam->keepResulteExam(dashboard->width);
						////TITLE
                		string title = " MON THI " + showstudentscorebundle->MAMH + " ";
	    				int x = exambundle->margin + ((dashboard->width-exambundle->margin) - title.length() + 2)/2 - 1;
                		frame->LineContent(dashboard->width,title,x);
            			///FRAME CONTENT
						frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);	
            			////GUIDE LINE
						frame->LineGuide(dashboard->height,"ESC  TOP BOTTOM LEFT RIGHT  ENTER");
				}		
			}else if(item == 9){
				if(showclassscorebundle->chose_element == 1){
		    		////CREATE LISTCLASS
					ListClass->keepElement(dashboard->width);
            		////CHANGE TITLE CLASS
					int x = listClassbundle->margin + ((dashboard->width-listClassbundle->margin) - listClassbundle->widthFrame)/2;
		    		frame->LineContent(dashboard->width," DANH SACH LOP ",x);
            		///REDRAW FRAME CONTENT
					frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);	
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC:MENU   ENTER");
				}
				if(showclassscorebundle->chose_element == 2){
					////CREATE LISTSUBJECT
					ListSubject->keepElement(dashboard->width);
            		////CHANGE TITLE CLASS
		    		int x = listSubjectbundle->margin + ((dashboard->width-listSubjectbundle->margin) - listSubjectbundle->widthFrame)/2;
		    		frame->LineContent(dashboard->width," DANH SACH MON HOC ",x);
            		///REDRAW FRAME CONTENT
					frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);	
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC   ENTER");
				}
				if(showclassscorebundle->chose_element == 3){
					showclassscore->keepListScoreElement(dashboard->width);
					////CHANGE TITLE CLASS
					string title = " DANH SACH DIEM LOP: " + listClassbundle->MALOP + " ";
		    		int i = showclassscorebundle->margin + ((dashboard->width-showclassscorebundle->margin) - showclassscorebundle->widthFrame)/2;
		    		frame->LineContent(dashboard->width,title,i);
            		///REDRAW FRAME CONTENT
					frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);	
					////GUIDE LINE
					frame->LineGuide(dashboard->height,"ESC   <- RIGHT   LEFT ->");
				}
			}else{
		    	///temp
		    	frame->LineContent(dashboard->width,"",35);
		        frame->FrameContent(dashboard->width,dashboard->height,dashboard->color_Theme);
			}
		//-------------------------------------------------------------------------------------------------
		}
}



