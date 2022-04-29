#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "ACCESSFILE.h"
#include "STUDENT.h"

using namespace std;
		struct NodeCLASS{
            string MALOP;
	        string TENLOP;
            STUDENT* list_STUDENT;
        };
        
class CLASS{
	public: 
	    vector<NodeCLASS> ListCLASS;
	    bool Insert(string MALOP,string TENLOP,bool isLoad);
	    bool Update(string MALOP,string EDITTENLOP);
	    bool Delete(string MALOP);
	    int  getPos(string MALOP);
	    bool IsContain(string MALOP);
	    NodeCLASS GetNode(string MASV); 
	    vector<NodeCLASS> GetList(); 
};
