#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "ACCESSFILE.h"

#ifndef SUBJECT_H
#define SUBJECT_H

using namespace std;
		struct NodeSUBJECT{
            string MAMH;
	        string TENMH;
        };
        
class SUBJECT{
	public: 
	    vector<NodeSUBJECT> ListSUBJECT;
	    
	    bool IsContain(string MAMH);
	    int  getPos(string MAMH);
	    bool Insert(string MAMH,string TENMH,bool isLoad);
	    bool Update(string MAMH,string EDITTENMH);
	    bool Delete(string MAMH);
	    NodeSUBJECT GetNode(string MASV); 
	    vector<NodeSUBJECT> GetList(); 
};

#endif
