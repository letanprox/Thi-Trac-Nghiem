#include <iostream>
#include <string.h>
#include <string>

#include "CUSTOMATTRIBUTE.h"

using namespace std;

#ifndef FRAME_H
#define FRAME_H

class FRAME{
	//===============================================================================
    private:
    CUSTOMATTRIBUTE* customAttribute_frame;
	int margin_top = 2;
	int margin_left = 3;
	int width_menu = 22;
	//===============================================================================
    public:
	FRAME(CUSTOMATTRIBUTE* customAttribute_){
        customAttribute_frame = customAttribute_;
    }
    void FrameTitle(int width,int color_Theme,string MS,string HOTEN);
    void FrameContent(int width,int height,int color_Theme);
    void LineContent(int width,string TEXT_TITLE,int pos_x_title_content);
    void LineGuide(int height,string TEXT_LINE);
    void ReDrawFrameContent(int current_height,int height,int width,int color_Theme);
    void ClearContent(int width,int height);
    void ClearPart(int first_x, int first_y , int back_x , int back_y);
    void frameLogin(int color_Theme,int width,int height);
    void ReframeLogin(int current_height,int height,int width,int color_Theme);
    int  direction(bool direct,int max,int cur);
    string RemoveSpaceString(string chain);
};

#endif
