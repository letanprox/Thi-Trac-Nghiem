#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "ACCESSFILE.h"
#include "SCORE.h"

using namespace std;
		struct NodeSTUDENT{
            string MASV;
	        string HOTEN;
	        bool PHAI;
	        string PASSWORD;
            NodeSTUDENT* next;
            SCORE* list_SCORE;
        };
class STUDENT{
	public: 
		NodeSTUDENT* head;    
    	STUDENT(){
		    head = NULL;
		}
	    bool Insert(string MASV,string HOTEN,bool PHAI,string PASSWORD,string MALOP,bool isLoad);
	    bool Update(string MASV,string EDITHOTEN,bool EDITPHAI,string EDITPASSWORD);
	    bool Delete(string MASV);
	    bool IsContain(string MASV);
	    NodeSTUDENT* LastNode();
	    NodeSTUDENT* GetNode(string MASV); 
	    vector<NodeSTUDENT> GetList(); 
};
