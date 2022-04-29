#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>

#include "ACCESSFILE.h"

#ifndef SCORE_H
#define SCORE_H

using namespace std;
		struct NodeSCORE{
            string MAMH;
            string MALOP;
            string MASV;
            int LANTHI;
	        string DIEM;
            NodeSCORE* next;
        };
class SCORE{
	public: 
		NodeSCORE* head;    
    	SCORE(){head = NULL;}

	    bool Insert(string MALOP,string MASV,string MAMH,string DIEM,bool isLoad);
		int countexamTimes(string MAMH);
		NodeSCORE* GetFinal(string MAMH); 
		vector<NodeSCORE> GetList(); 	    
};

#endif
