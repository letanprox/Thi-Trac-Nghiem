#include <iostream>
#include <string.h>
#include <string>

#include "CUSTOMATTRIBUTE.h"

using namespace std;

#ifndef FRAME_H
#define FRAME_H


class FRAME{
    private:
    CUSTOMATTRIBUTE* customAttribute_frame;
    public:
	FRAME(CUSTOMATTRIBUTE* customAttribute_){
        customAttribute_frame = customAttribute_;
    }
    void FrameTitle(int width,int color_Theme,string MS,string HOTEN);
    void FrameContent(int width,int height,int color_Theme);
    void LineContent(int width,string TEXT_TITLE);
    void ReDrawFrameContent(int current_height,int height,int width,int color_Theme);
    void ClearContent(int width,int height);
    void ClearPart(int first_x, int first_y , int back_x , int back_y);
    void frameLogin(int color_Theme,int width,int height);
    void ReframeLogin(int current_height,int height,int width,int color_Theme);
};

#endif
