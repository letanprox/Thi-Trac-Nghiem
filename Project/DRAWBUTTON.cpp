#include "DRAWBUTTON.h"

using namespace std;

	void DRAWBUTTON::DrawButtonFunction(DrawButton* buttonForm){
		if( buttonForm->is_reset == true ||  buttonForm->cur_pos_y != buttonForm->pos_y){
			buttonForm-> pos_y = buttonForm->cur_pos_y;
			///GET LENGHT TEXT IN BUTTON
			int l = 0;
            while ((buttonForm->text_button)[l]){
			    l=l+1;
			}
			//SET BUTTON
			customAttribute->setBackgroundText(7,buttonForm->background_color); 
		    for(int i = 0; i < buttonForm->height ; i ++){
		    	int k = 0;
		    	for(int x = 0 ; x < buttonForm->width ; x ++ ){
				    customAttribute->setPosionCursor(buttonForm->pos_x + x,buttonForm->pos_y + i);
				    if(x > (buttonForm->width - l)/2){ 
					    if(k < l){
					    	cout << (buttonForm->text_button)[k];
						    k++;
						}else{
							cout << " ";
						}
					}else{
						cout << " ";
					}
				}
			}
			customAttribute->setBackgroundText(7,0); 
		}
		customAttribute->DisplayCursor(false);
	}
