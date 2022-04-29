#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "ACCESSFILE.h"

using namespace std;
		struct NodeSCORE{
            string MAMH;
	        int DIEM;
            NodeSCORE* next;
        };
class SCORE{
	public: 
		NodeSCORE* head;    
    	SCORE(){
		    head = NULL;
		}
	    bool Insert(string MALOP,string MASV,string MAMH,int DIEM,bool isLoad);
	    vector<NodeSCORE> GetList(); 	    
};
