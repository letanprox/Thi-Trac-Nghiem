#include "DRAWINPUTSEARCH.h"

using namespace std;

void DRAWINPUTSEARCH::DrawInputSearchFunction(DrawInputSearch* input,char c,bool isCodeKey){
	
	customAttribute->DisplayCursor(true);
//--------------------------------------------------------------------------------------------------------------------------		
    if( input->is_reset == true){
    	    ///SET REQUIRE
		    input->is_reset = false;
            ///PRINT TITLE TEXT FORM
            customAttribute->setPosionCursor(input->pos_x,input->pos_y);
                cout<< input->text_form;
            ////GET TEXT LENGTH INPUT
            int x=0;
            while ((input->text_input)[x]){
            	if(input->width_text > x){
			    	x=x+1;
			    }
			}
            input->text_length = x;
			///WRITE TEXT
            if(input->text_length == 0 ){
				    input->cursor_x = input->pos_x + input->text_form.length();	
				    input->cursor_last_x = input->pos_x + input->text_form.length();	
			}else{
			    for(int k = 0; k < input->text_length ; k++){	
				    customAttribute->setPosionCursor(k + input->pos_x + input->text_form.length(),input->pos_y);
				    cout <<  input->text_input[k];
				    input->cursor_x = k + input->pos_x + input->text_form.length()+1;	
				    input->cursor_last_x = k + input->pos_x + input->text_form.length()+1;	
				}
			}
			input->point_text = input->text_length;
			////SET CURSOR
            customAttribute->setPosionCursor(input->cursor_x, input->pos_y);    
	}else{
		if(isCodeKey == true){
			    switch((int)c){
				    case 75 :{
				    	    if(input->point_text > 0){
					            input->cursor_x = input->cursor_x - 1;
                                input->point_text = input->point_text - 1;
					            customAttribute->setPosionCursor(input->cursor_x , input->pos_y);
				            }
			                break;	
					}
					case 77 : {
						    if(input->point_text < input->text_length ){
							    input->cursor_x = input->cursor_x + 1;
                                input->point_text = input->point_text + 1;
					            customAttribute->setPosionCursor(input->cursor_x , input->pos_y);
					        }
					        break;
					}
				}
	    }else{
				if(c == '\b'){				    	
	                if(input->point_text > 0){
	                	////CLEAR LINE TEXT
	                	for(int k = 0; k < input->text_length ; k++){
				            customAttribute->setPosionCursor(k + input->pos_x + input->text_form.length(),input->pos_y);
                            cout << " ";
				        }
				        ////SET NEW TEXT
	     				input->text_length = input->text_length - 1;
				        input->point_text = input->point_text - 1;
				        for(int x = 0; x < input->text_length ; x++){
					        if(x >= input->point_text){
						        	input->text_input[x] = input->text_input[x+1];
	                        }
	                    }
	                    input->text_input[input->text_length] = '\0';
	                    /////REWRITE TEXT
	                    customAttribute->setPosionCursor(input->pos_x + input->text_form.length(),input->pos_y);
			    		for(int k = 0; k < input->text_length ; k++){	
				    		customAttribute->setPosionCursor(k + input->pos_x + input->text_form.length(),input->pos_y);
				    		cout <<  input->text_input[k];
				        }
				        ////SET CURSOR
				        input->cursor_x = input->cursor_x - 1;	
				        input->cursor_last_x = input->cursor_last_x - 1;
                        customAttribute->setPosionCursor(input->cursor_x, input->pos_y);
				    }
				}else{
					if(input->width_text > input->text_length){
				        ////SET NEW TEXT
						input->text_length = input->text_length + 1;
				        input->point_text = input->point_text + 1;
				        for(int x = input->text_length-1; x > input->point_text-1 ; x--){
					        input->text_input[x] = input->text_input[x-1];
				        }	
				        input->text_input[input->point_text-1] = c;
	                    /////REWRITE TEXT
	                    customAttribute->setPosionCursor(input->pos_x + input->text_form.length(),input->pos_y);
			    		for(int k = 0; k < input->text_length ; k++){	
				    		customAttribute->setPosionCursor(k + input->pos_x + input->text_form.length(),input->pos_y);
				    		cout <<  input->text_input[k];
				        }
				        ////SET CURSOR
				        input->cursor_x = input->cursor_x + 1;	
				        input->cursor_last_x = input->cursor_last_x + 1;
                        customAttribute->setPosionCursor(input->cursor_x, input->pos_y);
				    }        	
				}
		}
	customAttribute->setPosionCursor(input->cursor_x, input->pos_y);
	}
}
