#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "SUBJECT.h"

using namespace std;

bool SUBJECT::IsContain(string MAMH){
	int iscon = false;
    for (int i = 0; i < ListSUBJECT.size() ; i++){
	    if((ListSUBJECT[i].MAMH).compare(MAMH) == 0){
		    iscon = true;
		    break;
		}
	}
	return iscon;
}

int SUBJECT::getPos(string MAMH){
	int pos = 0;
    for (int i = 0; i < ListSUBJECT.size() ; i++){
	    if((ListSUBJECT[i].MAMH).compare(MAMH) == 0){
		    break;
		}else{
			pos = pos + 1;
		}
	}
	return pos;
}

bool SUBJECT::Insert(string MAMH,string TENMH,bool isLoad){
    bool same = false; 
    bool done = false;
    same = IsContain(MAMH);
        if(same == false){
				NodeSUBJECT newNode;
	            newNode.MAMH = MAMH;
	            newNode.TENMH = TENMH;
                ListSUBJECT.push_back(newNode);
                //add database
                if(isLoad == false){
				    vector<string> select_element;
                    select_element.push_back("MAMH="+MAMH);
                    select_element.push_back("TENMH="+TENMH);
                    insertOneElement("subject.txt",select_element);
				}
	            done = true;
		}
	return done;
}

bool SUBJECT::Delete(string MAMH){
	if( IsContain(MAMH) == true ){
	    ListSUBJECT.erase(ListSUBJECT.begin() + getPos(MAMH));
	    //add database
		vector<string> select_element;
        select_element.push_back("MAMH="+MAMH);
        removeManyElement("subject.txt",select_element);
        removeManyElement("question.txt",select_element);
        removeManyElement("score.txt",select_element);
    	return true;
	}
}

bool SUBJECT::Update(string MAMH,string EDITTENMH){
	if( IsContain(MAMH) == true ){
		ListSUBJECT[getPos(MAMH)].TENMH = EDITTENMH;
		//add database
		vector<string> select_element;
        select_element.push_back("MAMH="+MAMH);              
        vector<string> update_element;
        update_element.push_back("TENMH="+EDITTENMH);
        updateManyElement("subject.txt",select_element,update_element);
	    return true;
	}
}

vector<NodeSUBJECT> SUBJECT::GetList(){
	return ListSUBJECT;
} 

NodeSUBJECT SUBJECT::GetNode(string MAMH){
	NodeSUBJECT node = ListSUBJECT[getPos(MAMH)];
    return node;    
} 
