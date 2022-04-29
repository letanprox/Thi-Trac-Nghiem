#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "STUDENT.h"

#ifndef CLASS_H
#define CLASS_H

using namespace std;
		struct NodeCLASS{
            string MALOP;
	        string TENLOP;
            STUDENT* list_STUDENT;
        };
        
class CLASS{
	public: 
	    vector<NodeCLASS> ListCLASS;
	    
	    bool IsContain(string MALOP);
	    int  getPos(string MALOP);
	    bool Insert(string MALOP,string TENLOP,bool isLoad);
	    bool Update(string MALOP,string EDITTENLOP);
	    bool Delete(string MALOP);
	    NodeCLASS GetNode(string MASV); 
	    vector<NodeCLASS> GetList(); 
};

#endif
