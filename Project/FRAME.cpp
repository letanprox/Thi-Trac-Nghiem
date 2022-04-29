#include "FRAME.h"

using namespace std;

void FRAME::FrameTitle(int width,int color_Theme,string MS,string HOTEN){
	////TITLE APP	    
    for (int i = 0; i < width ; i++) {
	    customAttribute_frame->setPosionCursor(i,0);
	    cout<< " ";
    }
    string title_app = "THI TRAC NGHIEM";
    customAttribute_frame->setPosionCursor((width - title_app.length())/2,0);
    cout << title_app;
    ////DRAW FIRST LINE
    customAttribute_frame->setBackgroundText(10,color_Theme); 
    for(int j = margin_top;j < margin_top+3 ; j++){
        for (int i = margin_left; i < width-margin_left ; i++) {
        	customAttribute_frame->setPosionCursor(i,j);
        	cout<< " ";
    	}
    }
	customAttribute_frame->setBackgroundText(7,0); 
	////INFO 
	customAttribute_frame->setBackgroundText(0,9); 
	customAttribute_frame->setPosionCursor(9,margin_top+1);
	if(MS.compare("GV") == 0){
		cout << "MAGV: " << MS ;
	}else {
	    cout << "MSSV: "<< MS ;
	}
	customAttribute_frame->setPosionCursor(35,margin_top+1);
	cout << "HOTEN: " << HOTEN;
	customAttribute_frame->setBackgroundText(7,0); 
}
//-------------------------------------------------------------------------------
void FRAME::LineContent(int width,string TEXT_TITLE,int pos_x_title_content){
	////DRAW LINE 
    for (int i = margin_left; i < width-margin_left ; i++) {
    	if(i != margin_left && i != width_menu+margin_left &&  i!= width-margin_left-1){
	    customAttribute_frame->setPosionCursor(i,margin_top+4);
	    cout<< "\xC4";
	    }
    }
	customAttribute_frame->setPosionCursor((width_menu+margin_left*2- 6)/2,margin_top+4);
	cout << " MENU ";
	customAttribute_frame->setPosionCursor(pos_x_title_content,margin_top+4);
	cout << TEXT_TITLE;
    customAttribute_frame->DisplayCursor(false);
}
//-------------------------------------------------------------------------------
void FRAME::LineGuide(int height,string TEXT_LINE){
	int color_Theme = 14;
	int reset_color_Theme = 9;
	int left = 26;
	int width_line = 57;
	////DRAW GUIDELINE    
    for (int i = left; i < left + width_line ; i++){
    	if(i < TEXT_LINE.length() + left + 6){
    		customAttribute_frame->setBackgroundText(0,color_Theme); 
	    	customAttribute_frame->setPosionCursor(i,height);
	    	cout<< " ";
	    }else{
	    	customAttribute_frame->setBackgroundText(0,reset_color_Theme); 
	    	customAttribute_frame->setPosionCursor(i,height);
	    	cout<< " ";
		}
    }
    customAttribute_frame->setBackgroundText(0,color_Theme); 
    customAttribute_frame->setPosionCursor(left + 3,height);
    cout << TEXT_LINE;
    customAttribute_frame->setBackgroundText(7,0);
}
//-------------------------------------------------------------------------------
void FRAME::FrameContent(int width,int height,int color_Theme){
	///DRAW THREE HORIZON LINE
	customAttribute_frame->setBackgroundText(7,color_Theme); 
    for (int i = margin_top+3; i < height ; i++) {
	    customAttribute_frame->setPosionCursor(3,i);
	    cout<< " ";
	    customAttribute_frame->setPosionCursor(25,i);
	    cout<< " ";
	    customAttribute_frame->setPosionCursor(width-4,i);
	    cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
	////DRAW LAST LINE    
	customAttribute_frame->setBackgroundText(10,color_Theme); 
    for (int i = margin_left; i < width-margin_left ; i++){
	    customAttribute_frame->setPosionCursor(i,height);
	    cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
}
//-------------------------------------------------------------------------------
void FRAME::ReDrawFrameContent(int current_height,int height,int width,int color_Theme){
	if(current_height != height){
		customAttribute_frame->setBackgroundText(7,0); 
		///CLEAR THREE VERTICLE LINE
		if(current_height < height){
        	for (int i = current_height; i <= height ; i++) {
	        	customAttribute_frame->setPosionCursor(3,i);
	        	cout<< " ";
	        	customAttribute_frame->setPosionCursor(25,i);
	        	cout<< " ";
	        	customAttribute_frame->setPosionCursor(width-4,i);
	        	cout<< " ";
        	}
		}
		////CLEAR LAST LINE    
    	for (int i = 3; i < width-3 ; i++){
	    	customAttribute_frame->setPosionCursor(i,height);
	    	cout<< " ";
    	}
		customAttribute_frame->setBackgroundText(7,0); 
		customAttribute_frame->setBackgroundText(7,color_Theme); 
		///DRAW THREE VERTICLE LINE
		if(current_height > height){
			for (int i = height; i <= current_height ; i++) {
	        	customAttribute_frame->setPosionCursor(3,i);
	        	cout<< " ";
	        	customAttribute_frame->setPosionCursor(25,i);
	        	cout<< " ";
	        	customAttribute_frame->setPosionCursor(width-4,i);
	        	cout<< " ";
        	}
    	}
    	////DRAWLAST LINE    
    	for (int i = 3; i < width-3 ; i++){
	    	customAttribute_frame->setPosionCursor(i,current_height);
	    	cout<< " ";
    	}
		customAttribute_frame->setBackgroundText(7,0); 
    }
}
//-------------------------------------------------------------------------------
void FRAME::ClearContent(int width,int height){
	////CLEAR CONTENT
     	customAttribute_frame->setBackgroundText(7,0); 
     	for(int x = margin_top + 6; x < height-2 ; x++){
            for (int i = margin_left + width_menu + 2; i < width-5 ; i++) {
	            customAttribute_frame->setPosionCursor(i,x);
	            cout<< " ";
            } 
        }
        customAttribute_frame->setBackgroundText(7,0);
}
//-------------------------------------------------------------------------------
void FRAME::ClearPart(int first_x, int first_y , int back_x , int back_y){
	//CLEAR PART
	for(int i=0 ; i< (back_y - first_y ); i++){
		for (int k=0 ; k<(back_x - first_x ); k++){
		    customAttribute_frame->setPosionCursor(first_x+k,first_y+i);
			cout << " ";
	    }
	}
}
//-------------------------------------------------------------------------------
void FRAME::frameLogin(int color_Theme,int width,int height){
	char* Title = " THI TRAC NGHIEM ";
	int l = 0;while (Title[l]){l=l+1;}
	int margin_text = ((width - 30) - l)/2; 
    ////DRAW FIRST LINE
    customAttribute_frame->setBackgroundText(15,color_Theme); 
    for (int i = 15; i <= width-15 ; i++) {
        customAttribute_frame->setPosionCursor(i,4);
        cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
    ///DRAW TITLE	
	customAttribute_frame->setBackgroundText(9,0); 
	customAttribute_frame->setPosionCursor(15 + margin_text,4);
	cout << Title;
	customAttribute_frame->setBackgroundText(7,0); 
	////DRAW TWO VERTICLE LINE IN FIRST 
	customAttribute_frame->setBackgroundText(15,color_Theme); 
	for (int i = 4; i < height ; i++) {
	    customAttribute_frame->setPosionCursor(15,i);
        cout<< " ";
        customAttribute_frame->setPosionCursor(width-15,i);
        cout<< " ";
	}
	customAttribute_frame->setBackgroundText(7,0);
	////DRAW LAST LINE
    customAttribute_frame->setBackgroundText(15,color_Theme); 
    for (int i = 15; i <= width-15 ; i++) {
        customAttribute_frame->setPosionCursor(i,height);
        cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
}
//-------------------------------------------------------------------------------
void FRAME::ReframeLogin(int current_height,int height,int width,int color_Theme){
if(current_height != height){
	customAttribute_frame->setBackgroundText(7,0); 
	///CLEAR THREE VERTICLE LINE
	if(current_height < height){
        for (int i = current_height; i <= height ; i++) {
	    	customAttribute_frame->setPosionCursor(15,i);
        	cout<< " ";
        	customAttribute_frame->setPosionCursor(width-15,i);
        	cout<< " ";
        }
	}
	////CLEAR LAST LINE    
    for (int i = 15; i < width-15 ; i++){
	    customAttribute_frame->setPosionCursor(i,height);
	    cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
	customAttribute_frame->setBackgroundText(15,color_Theme); 
	///DRAW TWO VERTICLE LINE
	if(current_height > height){
		for (int i = height; i <= current_height ; i++) {
	    customAttribute_frame->setPosionCursor(15,i);
        cout<< " ";
        customAttribute_frame->setPosionCursor(width-15,i);
        cout<< " ";
        }
    }
    ////DRAW LAST LINE    
    for (int i = 15; i <= width-15 ; i++) {
        customAttribute_frame->setPosionCursor(i,current_height);
        cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
}
}
//-------------------------------------------------------------------------------
int FRAME::direction(bool direct,int max,int cur){
        if(direct == true){
		    if(max == cur) return 1;
		    else return cur+1;
		}else{
		    if(cur == 1) return max;
		    else return cur-1;		
		}
}
//-------------------------------------------------------------------------------
string FRAME::RemoveSpaceString(string chain){
    string returnChain = "";
    for(int i = 0; i < chain.length() ; i++){
    	if(chain[i] != ' '){
		    returnChain = returnChain + chain[i];
		}
	}	
	return returnChain;
}
