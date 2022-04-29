#include "COUNTDOWN.h"

using namespace std;
//---------------------------------------------------------------------------
void COUNTDOWN::SETCLOCK(){
    if(countdownbundle->cur_pos_x != countdownbundle->pos_x || countdownbundle->cur_pos_y != countdownbundle->pos_y){
	    countdownbundle->pos_x = countdownbundle->cur_pos_x;
	    countdownbundle->pos_y = countdownbundle->cur_pos_y;
	        
	        int width_Frame = 8;
	        int height_Frame = 3;
	    
	    	////DRAW TOP LINE INPUT
		    for (int i = countdownbundle->pos_x ; i <= countdownbundle->pos_x + width_Frame ; i++) {
	            customAttribute->setPosionCursor(i,countdownbundle->pos_y);
	            if( i == countdownbundle->pos_x){
				    cout<< "\xDA";
				}else if( i == (countdownbundle->pos_x + width_Frame)){
					cout<< "\xBF";
				}else{
					cout<< "\xC4";
				}
            }
            ////DRAW TWO VERTICLE LINE FORM 
            for (int i = countdownbundle->pos_y ; i <  countdownbundle->pos_y + height_Frame; i++) {
	            customAttribute->setPosionCursor(countdownbundle->pos_x , i);
	            if( i ==  countdownbundle->pos_y ){
				    cout<< "\xDA";
				}else if( i == (countdownbundle->pos_y + height_Frame) - 1){
					cout<< "\xC0";
				}else{
					cout<< "\xB3";
				}
	            customAttribute->setPosionCursor(countdownbundle->pos_x + width_Frame, i);
	            if( i ==  countdownbundle->pos_y ){
				    cout<< "\xBF";
				}else if( i == (countdownbundle->pos_y + height_Frame) - 1){
					cout<< "\xD9";
				}else{
					cout<< "\xB3";
				}
            }
            ////DRAW BOTTOM LINE INPUT
            for (int i = countdownbundle->pos_x; i <= (countdownbundle->pos_x + width_Frame); i++) {
	            customAttribute->setPosionCursor(i,  countdownbundle->pos_y + height_Frame-1);
	            if( i == countdownbundle->pos_x){
				    cout<< "\xC0";
				}else if( i == (countdownbundle->pos_x + width_Frame)){
					cout<< "\xD9";
				}else{
					cout<< "\xC4";
				}
            }
            
            customAttribute->setPosionCursor( countdownbundle->pos_x + 2,  countdownbundle->pos_y+1);
            cout << "00:00";
            customAttribute->DisplayCursor(false);
	}
}
//---------------------------------------------------------------------------
void COUNTDOWN::RISETIME(){
    countdownbundle->start_clock = clock();
    customAttribute->setPosionCursor( countdownbundle->pos_x + 2,  countdownbundle->pos_y+1);
    if(countdownbundle->total_minute < 10) cout << "0" <<countdownbundle->total_minute<<":"<< "00";
    else cout << countdownbundle->total_minute<<":"<< "00";
    countdownbundle->is_rise = true;
}
//---------------------------------------------------------------------------
void COUNTDOWN::GETTIME(){
	clock_t end_t,pre_total,total_t;
	end_t = clock();
    pre_total = total_t;
   	total_t = (int)(end_t - countdownbundle->start_clock) / CLOCKS_PER_SEC;
   	
   	if(total_t != countdownbundle->cur_total_clock){
   		countdownbundle->cur_total_clock = total_t;
	    int second_remain = countdownbundle->total_minute*60 - total_t;
	    
	    int seconds_ = second_remain % 60;
	    int minutes_ = second_remain / 60;
	    
    	ostringstream convert1,convert2;   
    	convert1 << seconds_;      
    	string seconds = convert1.str(); 
    	convert2 << minutes_;      
    	string minutes = convert2.str();
	
	    if(seconds_ < 10) seconds = "0" + seconds;
	    if(minutes_ < 10) minutes = "0" + minutes;
        
        customAttribute->setPosionCursor( countdownbundle->pos_x + 2,  countdownbundle->pos_y+1);
	    cout << minutes <<":"<< seconds;
	    customAttribute->DisplayCursor(false);
	}
}
//---------------------------------------------------------------------------
bool COUNTDOWN::ISBREAK(){
    if((countdownbundle->total_minute*60 - countdownbundle->cur_total_clock) <= 0){
    	countdownbundle->is_stop = true;
	    return true;
	}
    else return false;
}
//---------------------------------------------------------------------------
void COUNTDOWN::clearCLOCK(){
		int width_Frame = 9;
	    int height_Frame = 4;
	for(int y = countdownbundle->cur_pos_y; y <= countdownbundle->cur_pos_y + height_Frame; y++)
    	for(int i = countdownbundle->cur_pos_x; i <= countdownbundle->cur_pos_x + width_Frame; i++){
    		customAttribute->setPosionCursor(i,y);
        	cout << " ";
        }
}
