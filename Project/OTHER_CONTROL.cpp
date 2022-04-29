#include "CONTROL.h"

using namespace std;

void CONTROL::OTHER_CONTROL(char c){
	///ESC
	if((int)c == 27){
        menu->MoveBottomItem(dashboard->item-1,dashboard->itemEnter,true);
		dashboard->inMenu = true;
	}	
}

