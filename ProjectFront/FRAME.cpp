#include "FRAME.h"

using namespace std;

void FRAME::FrameTitle(int width,int color_Theme,string MS,string HOTEN){
    
	////TITLE APP	    
    for (int i = 0; i < width ; i++) {
	    customAttribute_frame->setPosionCursor(i,0);
	    cout<< " ";
    }
    customAttribute_frame->setPosionCursor(width*2/5,0);
    cout << "THI TRAC NGHIEM";
    
    ////DRAW FIRST LINE
    customAttribute_frame->setBackgroundText(10,color_Theme); 
    for (int i = 3; i < width-3 ; i++) {
        customAttribute_frame->setPosionCursor(i,3);
        cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
	
	////DRAW TWO VERTICLE LINE IN FIRST 
	customAttribute_frame->setBackgroundText(10,color_Theme); 
	for (int i = 3; i < 7 ; i++) {
	    customAttribute_frame->setPosionCursor(3,i);
        cout<< " ";
        customAttribute_frame->setPosionCursor(width-4,i);
        cout<< " ";
	}
	customAttribute_frame->setBackgroundText(7,0);
	
	////DRAW SECOND LINE
	customAttribute_frame->setBackgroundText(10,color_Theme); 
    for (int i = 3; i < width-3 ; i++) {
	    customAttribute_frame->setPosionCursor(i,7);
	    cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
	
	////INFO 
	customAttribute_frame->setPosionCursor(8,5);
	if(MS.compare("GV") == 0){
		cout << "MAGV: " << MS ;
	}else {
	    cout << "MSSV: "<< MS ;
	}
	customAttribute_frame->setPosionCursor(30,5);
	cout << "HOTEN: " << HOTEN;
	    
}

void FRAME::LineContent(int width,string TEXT_TITLE){
	////DRAW LINE 
    for (int i = 3; i < width-3 ; i++) {
    	if(i != 3 && i != 25 &&  i!= width-4){
	    customAttribute_frame->setPosionCursor(i,9);
	    cout<< "\xC4";
	    }
    }
    
	customAttribute_frame->setPosionCursor(10,9);
	cout << " MENU ";
	
	customAttribute_frame->setPosionCursor(35,9);
	cout << TEXT_TITLE;

}

void FRAME::FrameContent(int width,int height,int color_Theme){
	///DRAW THREE HORIZON LINE
	customAttribute_frame->setBackgroundText(10,color_Theme); 
    for (int i = 7; i < height ; i++) {
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
    for (int i = 3; i < width-3 ; i++){
	    customAttribute_frame->setPosionCursor(i,height);
	    cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
}

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

void FRAME::ClearContent(int width,int height){
	////CLEAR CONTENT
     	customAttribute_frame->setBackgroundText(7,0); 
     	for(int x = 10; x < height-3 ; x++){
            for (int i = 35; i < width-5 ; i++) {
	            customAttribute_frame->setPosionCursor(i,x);
	            cout<< " ";
            } 
        }
        customAttribute_frame->setBackgroundText(7,0);
}


void FRAME::ClearPart(int first_x, int first_y , int back_x , int back_y){
	//CLEAR PART
	for(int i=0 ; i< (back_y - first_y ); i++){
		for (int k=0 ; k<(back_x - first_x ); k++){
		    customAttribute_frame->setPosionCursor(first_x+k,first_y+i);
			cout << " ";
	    }
	}
}

void FRAME::frameLogin(int color_Theme,int width,int height){
	
	char* Title = " THI TRAC NGHIEM ";
	
	int l = 0;
    while (Title[l]){
		l=l+1;
	}
	
	int margin_text = ((width - 30) - l)/2; 
	
    ////DRAW FIRST LINE
    customAttribute_frame->setBackgroundText(15,color_Theme); 
    for (int i = 15; i <= width-15 ; i++) {
        customAttribute_frame->setPosionCursor(i,4);
        cout<< " ";
    }
	customAttribute_frame->setBackgroundText(7,0); 
	
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

