#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "CLASS.h"

using namespace std;

bool CLASS::IsContain(string MALOP){
	int iscon = false;
    for (int i = 0; i < ListCLASS.size() ; i++){
	    if((ListCLASS[i].MALOP).compare(MALOP) == 0){
		    iscon = true;
		    break;
		}
	}
	return iscon;
}

int CLASS::getPos(string MALOP){
	int pos = 0;
    for (int i = 0; i < ListCLASS.size() ; i++){
	    if((ListCLASS[i].MALOP).compare(MALOP) == 0){
		    break;
		}else{
			pos = pos + 1;
		}
	}
	return pos;
}

bool CLASS::Insert(string MALOP,string TENLOP,bool isLoad){
    bool same = false; 
    bool done = false;
    same = IsContain(MALOP);
        if(same == false){
				NodeCLASS newNode;
	            newNode.MALOP = MALOP;
	            newNode.TENLOP = TENLOP;
                newNode.list_STUDENT = new STUDENT(); 
                ListCLASS.push_back(newNode); 
                //add database
                if(isLoad == false){
                vector<string> select_element;
                select_element.push_back("MALOP="+MALOP);
                select_element.push_back("TENLOP="+TENLOP);
                insertOneElement("class.txt",select_element);
                }
	            done = true;
		}
	return done;
}

bool CLASS::Delete(string MALOP){
	if( IsContain(MALOP) == true ){
	    ListCLASS.erase(ListCLASS.begin() + getPos(MALOP));
	    //add database
		vector<string> select_element;
        select_element.push_back("MALOP="+MALOP);
        removeManyElement("class.txt",select_element);
        removeManyElement("student.txt",select_element);
        removeManyElement("score.txt",select_element);       
    	return true;
	}
}

bool CLASS::Update(string MALOP,string EDITTENLOP){
	if( IsContain(MALOP) == true ){
		ListCLASS[getPos(MALOP)].TENLOP = EDITTENLOP;
		//add database
		vector<string> select_element;
        select_element.push_back("MALOP="+MALOP); 
        vector<string> update_element;
        update_element.push_back("TENLOP="+EDITTENLOP);   
        updateManyElement("class.txt",select_element,update_element);         
	    return true;
	}
}

vector<NodeCLASS> CLASS::GetList(){
	return ListCLASS;
} 

NodeCLASS CLASS::GetNode(string MALOP){
	NodeCLASS node = ListCLASS[getPos(MALOP)];
    return node;    
} 
