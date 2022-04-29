#include "DRAWSWITCHINPUT.h"

using namespace std;

	void DRAWSWITCHINPUT::DrawSwitchInputFunction(DrawSwitchInput* drawswitchinput){
		customAttribute->DisplayCursor(false);
	    if( drawswitchinput->is_reset == true ||  drawswitchinput->cur_pos_y != drawswitchinput->pos_y){
		    drawswitchinput-> pos_y = drawswitchinput->cur_pos_y;
			int l = drawswitchinput->text.length();
			
			int text_form_width = drawswitchinput->text_form.size();
			customAttribute->setPosionCursor(drawswitchinput->pos_x,drawswitchinput->pos_y);
			cout << drawswitchinput->text_form;
			
			customAttribute->setBackgroundText(7,drawswitchinput->background_color); 
		  	for(int x = 0 ; x < drawswitchinput->width ; x ++ ){
			    customAttribute->setPosionCursor(drawswitchinput->pos_x + x + text_form_width,drawswitchinput->pos_y);
                    cout << " ";
			}
			customAttribute->setBackgroundText(7,0); 
			string pre_ = " < ";
			string next_ = " > ";
			    customAttribute->setBackgroundText(7,drawswitchinput->background_color); 
				int k = 0;
		    	for(int x = 0 ; x < drawswitchinput->width ; x ++ ){
				    customAttribute->setPosionCursor(drawswitchinput->pos_x + x + text_form_width,drawswitchinput->pos_y);
				    if(x >= (drawswitchinput->width - l ) / 2 && x < ((drawswitchinput->width - l ) / 2 + l) ){  
                        cout << (drawswitchinput->text)[k];
                        k = k + 1;
					}
				}
				customAttribute->setBackgroundText(7,0);
				
				customAttribute->setBackgroundText(7,drawswitchinput->background_color); 
			    customAttribute->setPosionCursor(drawswitchinput->pos_x + text_form_width,drawswitchinput->pos_y);
			    cout << pre_;
			    customAttribute->setPosionCursor(drawswitchinput->pos_x + drawswitchinput->width - 3 + text_form_width,drawswitchinput->pos_y);
			    cout << next_;
			    customAttribute->setBackgroundText(7,0); 
			    
			  	if(drawswitchinput->is_rise_event == true){
					if(drawswitchinput->is_next == true){
					    customAttribute->setBackgroundText(7,drawswitchinput->background_color_switch); 
				        customAttribute->setPosionCursor(drawswitchinput->pos_x + drawswitchinput->width - 3 + text_form_width,drawswitchinput->pos_y);
				        cout << next_;
				        customAttribute->setBackgroundText(7,0); 	
				        Sleep(200);
				        customAttribute->setBackgroundText(7,drawswitchinput->background_color); 
				        customAttribute->setPosionCursor(drawswitchinput->pos_x + drawswitchinput->width - 3 + text_form_width,drawswitchinput->pos_y);
				        cout << next_;
				        customAttribute->setBackgroundText(7,0); 	
					}else{
						customAttribute->setBackgroundText(7,drawswitchinput->background_color_switch); 
				        customAttribute->setPosionCursor(drawswitchinput->pos_x + text_form_width,drawswitchinput->pos_y);
				        cout << pre_;
				        customAttribute->setBackgroundText(7,0); 	
				        Sleep(200);
				        customAttribute->setBackgroundText(7,drawswitchinput->background_color); 
				        customAttribute->setPosionCursor(drawswitchinput->pos_x + text_form_width,drawswitchinput->pos_y);
				        cout << pre_;
				        customAttribute->setBackgroundText(7,0); 	
					}
				}
		}
	}
