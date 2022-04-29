#include "DRAWINPUT.h"

using namespace std;

	void DRAWINPUT::DrawInputFunction(DrawInput* input,char c,bool isCodeKey){
	
	customAttribute->DisplayCursor(true);
//--------------------------------------------------------------------------------------------------------------------------		
    input->width_text = input->width - input->pos_x - input->margin_right - 4;
    if( input->is_reset == true ||  input->cur_pos_y != input->pos_y){
    	    ///SET REQUIRE
		    input->is_reset = false;
			input->pos_y = input->cur_pos_y;
			////DRAW TOP LINE INPUT
		    for (int i = input->pos_x ; i < input->width - input->margin_right ; i++) {
	            customAttribute->setPosionCursor(i,input->pos_y);
	            if( i == input->pos_x){
				    cout<< "\xDA";
				}else if( i == (input->width - input->margin_right) - 1){
					cout<< "\xBF";
				}else{
					cout<< "\xC4";
				}
            }
            ////DRAW TWO VERTICLE LINE FORM 
            for (int i = input->pos_y; i <  input->pos_y + 4; i++) {
	            customAttribute->setPosionCursor(input->pos_x , i);
	            if( i ==  input->pos_y ){
				    cout<< "\xDA";
				}else if( i == (input->pos_y + 3)){
					cout<< "\xC0";
				}else{
					cout<< "\xB3";
				}
	            customAttribute->setPosionCursor(input->pos_x + input->width_text + 3 , i);
	            if( i ==  input->pos_y ){
				    cout<< "\xBF";
				}else if( i == (input->pos_y + 3)){
					cout<< "\xD9";
				}else{
					cout<< "\xB3";
				}
            }
            ////DRAW BOTTOM LINE INPUT
            for (int i = input->pos_x; i < (input->width - input->margin_right); i++) {
	            customAttribute->setPosionCursor(i, input->pos_y + 3);
	            if( i == input->pos_x){
				    cout<< "\xC0";
				}else if( i == (input->width - input->margin_right) - 1){
					cout<< "\xD9";
				}else{
					cout<< "\xC4";
				}
            }
            ///PRINT TITLE TEXT FORM
            customAttribute->setPosionCursor(input->pos_x + 1 , input->pos_y);
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
				    input->cursor_x =input->pos_x + 2;	
				    input->cursor_last_x =input->pos_x + 2;	
			}else{
			        for(int k = 0; k < input->text_length ; k++){	
				        customAttribute->setPosionCursor(k + input->pos_x + 2,input->pos_y + 2);
				        cout <<  input->text_input[k];
				        input->cursor_x = k + input->pos_x + 3;	
				        input->cursor_last_x = k + input->pos_x + 3;	
				    }
			}
			input->point_text = input->text_length;
			////SET CURSOR
            customAttribute->setPosionCursor(input->cursor_x, input->pos_y+2);    
	}else{

		if(isCodeKey == true){
			    switch((int)c){
				    case 75 :{
				    	    if(input->point_text > 0){
					            input->cursor_x = input->cursor_x - 1;
                                input->point_text = input->point_text - 1;
					            customAttribute->setPosionCursor(input->cursor_x , input->pos_y+2);
				            }
			                break;	
					}
					case 77 : {
						    if(input->point_text < input->text_length ){
							    input->cursor_x = input->cursor_x + 1;
                                input->point_text = input->point_text + 1;
					            customAttribute->setPosionCursor(input->cursor_x , input->pos_y+2);
					        }
					        break;
					}
				}
	    }else{
				if(c == '\b'){	
						    	
	                if(input->point_text > 0){
	                	////CLEAR LINE TEXT
	                	for(int k = 0; k < input->text_length ; k++){
				            customAttribute->setPosionCursor(k + input->pos_x + 2,input->pos_y + 2);
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
	                    customAttribute->setPosionCursor(input->pos_x + 2,input->pos_y + 2);
			            for(int k = 0; k < input->text_length ; k++){
				            customAttribute->setPosionCursor(k + input->pos_x + 2,input->pos_y + 2);
				            cout <<  input->text_input[k];	
				        }
				        ////SET CURSOR
				        input->cursor_x = input->cursor_x - 1;	
				        input->cursor_last_x = input->cursor_last_x - 1;
                        customAttribute->setPosionCursor(input->cursor_x, input->pos_y+2);
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
					    ////// REWRITE TEXT
			            for(int k = 0; k < input->text_length ; k++){
				            customAttribute->setPosionCursor(k + input->pos_x + 2,input->pos_y + 2);
				            cout <<  input->text_input[k];	
				        }
				        ////SET CURSOR
				        input->cursor_x = input->cursor_x + 1;	
				        input->cursor_last_x = input->cursor_last_x + 1;
                        customAttribute->setPosionCursor(input->cursor_x, input->pos_y+2);  
				    }  
					      	
				}
						
		}
		/////SET CURSOR FINAL
		customAttribute->setPosionCursor(input->cursor_x , input->pos_y+2);
	}
}
