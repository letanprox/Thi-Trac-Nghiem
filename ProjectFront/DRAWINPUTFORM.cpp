#include "DRAWINPUTFORM.h"

using namespace std;

	void DRAWINPUTFORM::DrawInputFormFunction(DrawInputForm* inputForm,char c,bool isCodeKey,int bottom_height_frame){
//--------------------------------------------------------------------------------------------------------------------------		
		inputForm->width_text = inputForm->width - inputForm->pos_x - inputForm->margin_right - 4;
        if( inputForm->ischangeWidth == true ||  inputForm->cur_pos_y != inputForm->pos_y){
            inputForm->ischangeWidth = false;
        	inputForm->pos_y = inputForm->cur_pos_y;
        	
        	////DRAW TOP LINE INPUT
		    for (int i = inputForm->pos_x ; i < inputForm->width - inputForm->margin_right ; i++) {
	            customAttribute->setPosionCursor(i,inputForm->pos_y);
	            if( i == inputForm->pos_x){
				    cout<< "\xC9";
				}else if( i == (inputForm->width - inputForm->margin_right) - 1){
					cout<< "\xBB";
				}else{
					cout<< "\xCD";
				}
            }
            
            ///PRINT TITLE TEXT FORM
            customAttribute->setPosionCursor(inputForm->pos_x + 2 , inputForm->pos_y);
                cout<< inputForm->text_form;
                
            ////GET TEXT LENGTH INPUT
            int x=0;
            while ((inputForm->text_input)[x]){
			    x=x+1;
			}
			////DEFINE HEIGHT TEXT INPUT
			if(inputForm->text_length == 0 ){
			    inputForm->height_text = 1;
			}else{
                inputForm->height_text  =  inputForm->text_length/inputForm->width_text;
                if( (inputForm->width_text)*(inputForm->height_text) < inputForm->text_length ){
			        inputForm->height_text = inputForm->height_text + 1;
			    }else{
				    inputForm->height_text = inputForm->height_text;
			    }
			}
			
			////DRAW TWO VERTICLE LINE FORM 
            for (int i = inputForm->pos_y + 1; i <  inputForm->pos_y + inputForm->height_text + 3; i++) {
	            customAttribute->setPosionCursor(inputForm->pos_x , i);
	            if( i ==  inputForm->pos_y ){
				    cout<< "\xC9";
				}else if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					cout<< "\xC8";
				}else{
					cout<< "\xBA";
				}
	            customAttribute->setPosionCursor(inputForm->pos_x + inputForm->width_text + 3 , i);
	            if( i ==  inputForm->pos_y ){
				    cout<< "\xBB";
				}else if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					cout<< "\xBC";
				}else{
					cout<< "\xBA";
				}
            }
            
            ////DRAW BOTTOM LINE INPUT
            for (int i = inputForm->pos_x; i < (inputForm->width - inputForm->margin_right); i++) {
	            customAttribute->setPosionCursor(i, inputForm->pos_y + inputForm->height_text + 2);
	            if( i == inputForm->pos_x){
				    cout<< "\xC8";
				}else if( i == (inputForm->width - inputForm->margin_right) - 1){
					cout<< "\xBC";
				}else{
					cout<< "\xCD";
				}
            }
            
            ///SET CURSOR LINE INPUT
            if(inputForm->text_length == 0 ){
				    inputForm->position_cursor_x =inputForm->pos_x + 2;	
				    inputForm->position_cursor_y = inputForm->pos_y + 2;
				    inputForm->position_cursor_last_line_x = inputForm->pos_x + 2;
				    inputForm->position_cursor_last_line_y = inputForm->pos_y + 2;
			}else{
                int p = 0;
			    for(int i=0; i < inputForm->height_text ; i++){
			        for(int k = 0; k < inputForm->width_text ; k++){
			    	    if(p < inputForm->text_length){
				        customAttribute->setPosionCursor(k + inputForm->pos_x + 2,i + inputForm->pos_y + 2);
				        cout <<  inputForm->text_input[p];
				        inputForm->position_cursor_x = k + inputForm->pos_x + 3;	
				        inputForm->position_cursor_y = i + inputForm->pos_y + 2;
				        inputForm->position_cursor_last_line_x = k + inputForm->pos_x + 3;
				        inputForm->position_cursor_last_line_y = i + inputForm->pos_y + 2;
				        }
				    p++;
				    }
			    }
			}
			inputForm->point_text = inputForm->text_length;
            customAttribute->setPosionCursor(inputForm->position_cursor_x, inputForm->position_cursor_y);
//--------------------------------------------------------------------------------------------------------------------------			
        }else{
//--------------------------------------------------------------------------------------------------------------------------        	      
			        if(isCodeKey == true){
				        switch((int)c){
				        	////SET CURSOR WHEN MOVE LEFT
			                case 75 :{	  	
								if(inputForm->position_cursor_x <= inputForm->pos_x + 2){	  		
	                                if((inputForm->position_cursor_y - inputForm->pos_y - 1) > 1){
                		                inputForm->position_cursor_x = inputForm->pos_x + inputForm->width_text + 1;
					                    inputForm->position_cursor_y = inputForm->position_cursor_y - 1;	
							            inputForm->point_text = (inputForm->position_cursor_x - inputForm->pos_x - 2) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                    customAttribute->setPosionCursor(inputForm->position_cursor_x,inputForm->position_cursor_y);
					                }
				                }else{
					                inputForm->position_cursor_x = inputForm->position_cursor_x - 1;
				                    if((inputForm->position_cursor_y - inputForm->pos_y - 1) <= 1){
					 	                inputForm->point_text = inputForm->position_cursor_x - inputForm->pos_x - 2 ; 
					                }else{
						                inputForm->point_text =(inputForm->position_cursor_x - inputForm->pos_x - 2) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                }
					                customAttribute->setPosionCursor(inputForm->position_cursor_x , inputForm->position_cursor_y);
				                }
			                break;		
			                } 
			                ////SET CURSOR WHEN MOVE RIGHT
			                case 77 : {
			                    if(inputForm->point_text < inputForm->text_length){
					                if(inputForm->position_cursor_x >= inputForm->pos_x + inputForm->width_text + 1){		  		
	                                    inputForm->position_cursor_x = inputForm->pos_x + 2;
					                    inputForm->position_cursor_y = inputForm->position_cursor_y + 1;	
							            inputForm->point_text = (inputForm->position_cursor_x - inputForm->pos_x - 1) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                    customAttribute->setPosionCursor(inputForm->position_cursor_x,inputForm->position_cursor_y);
					                }else{
				                        if((inputForm->position_cursor_y - inputForm->pos_y - 1) <= 1){
						                    inputForm->point_text = inputForm->position_cursor_x - inputForm->pos_x - 1 ; 
					                    }else{
						                    inputForm->point_text =(inputForm->position_cursor_x - inputForm->pos_x - 1) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                    }
				                        inputForm->position_cursor_x = inputForm->position_cursor_x + 1;
					                    customAttribute->setPosionCursor(inputForm->position_cursor_x , inputForm->position_cursor_y);
				                    }
				                }
			                break;
							}
		                }
		            } else {
		            	////SET FORM WHEN DELETE TEXT
			            if(c == '\b'){
	                        if(inputForm->point_text > 0){  	
	                            
	                            ////SET CURSOR
			  	                if(inputForm->position_cursor_x <= inputForm->pos_x + 2){		  		
	                                if((inputForm->position_cursor_y - inputForm->pos_y - 1) > 1){
                		                inputForm->position_cursor_x = inputForm->pos_x + inputForm->width_text + 1;
					                    inputForm->position_cursor_y = inputForm->position_cursor_y - 1;
							            inputForm->point_text = (inputForm->position_cursor_x - inputForm->pos_x - 2) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                }
				                }else{
				                    inputForm->position_cursor_x = inputForm->position_cursor_x - 1;
					                if((inputForm->position_cursor_y - inputForm->pos_y - 1) <= 1){
						                inputForm->point_text = inputForm->position_cursor_x - inputForm->pos_x - 2 ; 
					                }else{
						                inputForm->point_text =(inputForm->position_cursor_x - inputForm->pos_x - 2) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					                }
				                }
				                
				                ////SET LASTLINE CURSOR
				                if(inputForm->position_cursor_last_line_x <= inputForm->pos_x + 2){
				                    if(inputForm->height_text > 1){
				    	                inputForm->position_cursor_last_line_x = inputForm->pos_x + inputForm->width_text + 1;
					                    inputForm->position_cursor_last_line_y = inputForm->position_cursor_last_line_y - 1;
					                    inputForm->height_text = inputForm->height_text - 1;
					                    
					                    frame->ClearPart(inputForm->pos_x, inputForm->pos_y + inputForm->height_text + 3, inputForm->width - inputForm->margin_right , bottom_height_frame );	
				                        
										for (int i = inputForm->pos_x; i < inputForm->width - inputForm->margin_right; i++) {
	                                        customAttribute->setPosionCursor(i, inputForm->pos_y + inputForm->height_text + 2);
	                                        if( i == inputForm->pos_x){
				                                cout<< "\xC8";
				                            }else if( i == (inputForm->width - inputForm->margin_right) - 1){
					                            cout<< "\xBC";
				                            }else{
					                            cout<< "\xCD";
				                            }
                                        }
			                            for (int i = inputForm->pos_y; i < inputForm->pos_y + inputForm->height_text + 3; i++) {
	                                        customAttribute->setPosionCursor(inputForm->pos_x , i);
                                            if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					                            cout<< "\xC8";
				                            }else if(i > inputForm->pos_y){
					                            cout<< "\xBA";
				                            }
	                                        customAttribute->setPosionCursor(inputForm->pos_x + inputForm->width_text + 3 , i);
	                                        if( i ==  inputForm->pos_y){
				                                cout<< "\xBB";
				                            }else if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					                            cout<< "\xBC";
				                            }else{
					                            cout<< "\xBA";
				                            }
                                        }
					                }
				                }else{
					                inputForm->position_cursor_last_line_x = inputForm->position_cursor_last_line_x - 1;
					                for (int i = inputForm->position_cursor_last_line_x; i < inputForm->width - inputForm->margin_right-1; i++) {
	                                    customAttribute->setPosionCursor(i, inputForm->pos_y + inputForm->height_text +1 );
	                                    cout<< " ";
                                    }///should delete for
				                }
				                
				                ////REWRITE TEXT INPUT
				                inputForm->text_length = inputForm->text_length - 1;
				                for(int x=0; x < inputForm->text_length ; x++){
					                if(x >= inputForm->point_text){
					                inputForm->text_input[x] = inputForm->text_input[x+1];
	                                }
				                }
				                int p = 0;
			                    for(int i=0; i < inputForm->height_text ; i++){
			                        for(int k = 0; k < inputForm->width_text ; k++){
			    	                    if(p < inputForm->text_length){
			    	                        customAttribute->setPosionCursor(k + inputForm->pos_x + 2,i + inputForm->pos_y + 2);	
				                            cout <<  inputForm->text_input[p];
				                            p++;
				                        }
				                    }
			                    }
			                    
			                    ///SET DEFAULT ERROR
								customAttribute->setPosionCursor(inputForm->pos_x + inputForm->width_text + 1,inputForm->pos_y+inputForm->height_text + 1);	
				                cout <<  " ";
				                
				                ///SET CURRENT CURSOR 
		     	                customAttribute->setPosionCursor(inputForm->position_cursor_x, inputForm->position_cursor_y);
		               	    }
			
			            }else if(c=='\r'){}
						////SET FORM TYPE TEXT
						else{
							
							////SET CURSOR INPUT
				            if(inputForm->position_cursor_x >= inputForm->pos_x + inputForm->width_text + 1){
		  		                inputForm->position_cursor_x = inputForm->pos_x + 2;
					            inputForm->position_cursor_y = inputForm->position_cursor_y + 1;	
							    inputForm->point_text = (inputForm->position_cursor_x - inputForm->pos_x - 2) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
	                        }else{
				                if((inputForm->position_cursor_y - inputForm->pos_y - 1) <= 1){
						            inputForm->point_text = inputForm->position_cursor_x - inputForm->pos_x - 1 ; 
					            }else{
						            inputForm->point_text =(inputForm->position_cursor_x - inputForm->pos_x - 1) + (inputForm->width_text*((inputForm->position_cursor_y - inputForm->pos_y - 1) - 1)); 
					            }
				                inputForm->position_cursor_x = inputForm->position_cursor_x + 1;
				            }
				            
				            ////SET LASTLINE CURSOR
		  	                if(inputForm->position_cursor_last_line_x >= inputForm->pos_x + inputForm->width_text + 1){
				    	        inputForm->position_cursor_last_line_x = inputForm->pos_x + 2;
					            inputForm->position_cursor_last_line_y = inputForm->position_cursor_last_line_y + 1;
					            inputForm->height_text = inputForm->height_text + 1;
					            
					            frame->ClearPart(inputForm->pos_x, inputForm->pos_y + inputForm->height_text + 1, inputForm->width - inputForm->margin_right , bottom_height_frame );	
				                
				                ///CLEAR PRE_LAST_LINE
                                for (int i = inputForm->pos_x; i < inputForm->width - inputForm->margin_right; i++) {
	                                customAttribute->setPosionCursor(i, inputForm->pos_y + inputForm->height_text + 1);
	                                cout<< " ";
                                }
				                
				                ////DRAW LAST LINE INPUT FORM
								for (int i = inputForm->pos_x; i < inputForm->width - inputForm->margin_right; i++) {
	                                customAttribute->setPosionCursor(i, inputForm->pos_y + inputForm->height_text + 2);
	                                if( i == inputForm->pos_x){
				                        cout<< "\xC8";
				                    }else if( i == (inputForm->width - inputForm->margin_right) - 1){
					                    cout<< "\xBC";
				                    }else{
					                    cout<< "\xCD";
				                    }
                                }
                                
                                ////DRAW TWO VERTICLE LINE
                                for (int i = inputForm->pos_y; i < inputForm->pos_y + inputForm->height_text + 3; i++) {
	                                customAttribute->setPosionCursor(inputForm->pos_x , i);
                                    if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					                    cout<< "\xC8";
				                    }else if(i > inputForm->pos_y){
					                    cout<< "\xBA";
				                    }
	                                customAttribute->setPosionCursor(inputForm->pos_x + inputForm->width_text + 3 , i);
	                                if( i ==  inputForm->pos_y){
				                        cout<< "\xBB";
				                    }else if( i == (inputForm->pos_y + inputForm->height_text + 3) - 1){
					                    cout<< "\xBC";
				                    }else{
					                    cout<< "\xBA";
				                    }
                                }
                                
                            }else{
					            inputForm->position_cursor_last_line_x = inputForm->position_cursor_last_line_x + 1;
					    	}
					    	
					    	/////REWIRE TEXT INPUT FORM
				            inputForm->text_length = inputForm->text_length + 1;
				            for(int x = inputForm->text_length-1; x > inputForm->point_text-1 ; x--){
					            inputForm->text_input[x] = inputForm->text_input[x-1];
				            }	
					        inputForm->text_input[inputForm->point_text-1] = c;
				            int p = 0;
			                for(int i=0; i < inputForm->height_text; i++){
			                    for(int k = 0; k < inputForm->width_text ; k++){
			    	                if(p < inputForm->text_length){
			    	                customAttribute->setPosionCursor(k + inputForm->pos_x + 2,i + inputForm->pos_y + 2);	
				                    cout <<  inputForm->text_input[p];
				                    p++;
				                    }
				                }
			                }
			                
							////SET CURRENT CURSOR	
                            customAttribute->setPosionCursor(inputForm->position_cursor_x , inputForm->position_cursor_y);
			            }
			        }
		}
//--------------------------------------------------------------------------------------------------------------------------    		
    }
