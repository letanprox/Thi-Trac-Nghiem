#include "MENU.h"

using namespace std;

void MENU::DisplayItemPart(bool checkMove,bool checkEnter,bool inMenu,int pos_y,int pos_x,int width_menu,string text){
	int colorText = 7;
	int colorBackground = 8;
	int reset_colorText = 7;
	int reset_colorBackground = 0;
     	if(checkMove == true){
     		customAttribute->setBackgroundText(colorText,colorBackground); 
    	    for(int i = pos_x ; i < pos_x + width_menu; i++){
    	    	customAttribute->setPosionCursor(i,pos_y);
			    cout << " ";
			}
    	    customAttribute->setPosionCursor(pos_x+3,pos_y);
	        cout << text;
	        customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
	    }else{
	    	customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
    	    for(int i = pos_x ; i < pos_x + width_menu; i++){
    	    	customAttribute->setPosionCursor(i,pos_y);
			    cout << " ";
			}
	        customAttribute->setPosionCursor(pos_x+3,pos_y);
	        cout << text;	
		}
		if(checkEnter == true){
			if(checkMove == true){
				if(inMenu == true){
					customAttribute->setBackgroundText(9,4); 
				}else{
					customAttribute->setBackgroundText(colorText,4); 
				}
			}else{
				customAttribute->setBackgroundText(colorText,4);
			} 
    	    for(int i = pos_x ; i < pos_x + width_menu; i++){
    	    	customAttribute->setPosionCursor(i,pos_y);
			    cout << " ";
			}
    	    customAttribute->setPosionCursor(pos_x+3,pos_y);
	        cout << text;
	        customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
		}
		customAttribute->setPosionCursor(0,0);
}

vector<string> ListText(){
    vector<string> listtext;
    listtext.push_back("In danh sach lop");
    listtext.push_back("Them lop");
    listtext.push_back("Them sinh vien");
    listtext.push_back("Them mon hoc");
    listtext.push_back("Thi trac nghiem");
	listtext.push_back("In cau hoi");
    return listtext;
}

void MENU::DisplayItem(int item,int itemEnter,bool inMenu){
	
	int limit = ListText().size();
    int pos_y = 11;
    int pos_x = 4;
    int width_menu = 21;
    
    vector<string> listtext = ListText();
    for(int i= 0;i<limit;i++){
	    if((item - 1) == i){
	    	if((itemEnter-1) == i){
			    DisplayItemPart(true,true,inMenu,pos_y,pos_x,width_menu,listtext[i]);
			}else{
				DisplayItemPart(true,false,inMenu,pos_y,pos_x,width_menu,listtext[i]);
			}
		}else{
			if((itemEnter-1) == i){
			    DisplayItemPart(false,true,inMenu,pos_y,pos_x, width_menu,listtext[i]);
			}else{
				DisplayItemPart(false,false,inMenu,pos_y,pos_x, width_menu,listtext[i]);
			}
		}
	    pos_y = pos_y + 2;
	}
}

int MENU::MoveBottomItem(int item,int itemEnter,bool inMenu){
	int limit = ListText().size();
	if(item == limit){
		DisplayItem(1,itemEnter,inMenu);
	    item = 1;		
	}else{
		DisplayItem(item+1,itemEnter,inMenu);
	    item = item+1;	
	}
	return item;
}

int MENU::MoveTopItem(int item,int itemEnter,bool inMenu){
	int limit = ListText().size();
	if(item == 1){
		DisplayItem(limit,itemEnter,inMenu);
	    item = limit;		
	}else{
		DisplayItem(item-1,itemEnter,inMenu);
	    item = item-1;	
	}
	return item;
}
