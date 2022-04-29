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
    	    customAttribute->setPosionCursor(pos_x+2,pos_y);
	        cout << text;
	        customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
	    }else{
	    	customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
    	    for(int i = pos_x ; i < pos_x + width_menu; i++){
    	    	customAttribute->setPosionCursor(i,pos_y);
			    cout << " ";
			}
	        customAttribute->setPosionCursor(pos_x+2,pos_y);
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
    	    customAttribute->setPosionCursor(pos_x+2,pos_y);
	        cout << text;
	        customAttribute->setBackgroundText(reset_colorText,reset_colorBackground); 
		}
		customAttribute->setPosionCursor(0,0);
		customAttribute->DisplayCursor(false);
}
//---------------------------------------------------------------------------
vector<string> MENU::ListText(){
    vector<string> listtext;
    if(loginbundle->maUser.compare("GV") == 0){
    	listtext.push_back("DANH SACH LOP");
    	listtext.push_back("THEM LOP");
    	listtext.push_back("THEM SINH VIEN");
    	listtext.push_back("DANH SACH MON HOC");
    	listtext.push_back("THEM MON HOC");
    	listtext.push_back("THEM CAU HOI");
		listtext.push_back("XEM BAI THI");
    	listtext.push_back("XEM BANG DIEM");
		listtext.push_back("DANG XUAT");
	}else{
		listtext.push_back("THI TRAC NGHIEM");
		listtext.push_back("XEM BAI THI");
    	listtext.push_back("XEM BANG DIEM");
		listtext.push_back("DANG XUAT");
	}
    return listtext;
}
//---------------------------------------------------------------------------
void MENU::DisplayItem(int item,int itemEnter,bool inMenu){	
	int margin_top = 3;
	int margin_left = 3;
    int width_menu = 22;
	width_menu = width_menu - 1;
	int limit = ListText().size();
    int pos_y = margin_top + 6;
    int pos_x = margin_left+1;
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
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
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
