#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>

using namespace std;

#ifndef CONSOLELOG_H
#define CONSOLELOG_H

struct consoleLOG_bundle{
	int width_Frame = 40;
	int top = 0;
	string message;
};

class consoleLOG{
	private:
	consoleLOG_bundle* consolebundle;
	public:
    consoleLOG(consoleLOG_bundle* consolebundle_){
	    consolebundle = consolebundle_;
	}
	void RISE_CONSOLE();
};

#endif

