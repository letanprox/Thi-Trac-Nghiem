#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>

#include "SCORE.h"

using namespace std;

bool SCORE::Insert(string MALOP,string MASV,string MAMH,int DIEM,bool isLoad){
				NodeSCORE* newNode = new NodeSCORE();
	            newNode->MAMH = MAMH;
	            newNode->DIEM = DIEM;
	            if(head == NULL){
            	    head = newNode;
			    }else{
				    NodeSCORE* current = head;
			        while (current){
						if(current->next){
						    current = current->next;
						}else{
							break;
					 	}			
                    }
                    current->next = newNode;
				}
			if(isLoad == false){
                ostringstream ss;
                ss << DIEM;
                string DIEM_ = ss.str();
				vector<string> select_element;
                select_element.push_back("MALOP="+MALOP);
                select_element.push_back("MASV="+MASV);
                select_element.push_back("MAMH="+MAMH);
                select_element.push_back("DIEM="+DIEM_);
                insertOneElement("score.txt",select_element);
            }
	return true;
}

vector<NodeSCORE> SCORE::GetList(){
	    vector<NodeSCORE> ListScore;
		if(head != NULL){
			NodeSCORE* current = head;
			while (current){
				    NodeSCORE data = {current->MAMH, current->DIEM};
				    ListScore.push_back(data);
					if(current->next){
					    current = current->next;
					}else{
						break;
					}			    			
            }	    	
		}
		return ListScore;
}
