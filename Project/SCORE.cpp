#include "SCORE.h"

using namespace std;

bool SCORE::Insert(string MALOP,string MASV,string MAMH,string DIEM,bool isLoad){
	    	int times = countexamTimes(MAMH);          
			NodeSCORE* newNode = new NodeSCORE();
	        newNode->MAMH = MAMH;
	        newNode->DIEM = DIEM;
	        newNode->MALOP = MALOP;
	        newNode->MASV = MASV;
	        newNode->LANTHI = times;
	            
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
			///DATA BASE
			if(isLoad == false){
                ostringstream ss2;
                ss2 << times;
                string LANTHI_ = ss2.str();
                
				vector<string> select_element;
                select_element.push_back("MALOP="+MALOP);
                select_element.push_back("MASV="+MASV);
                select_element.push_back("MAMH="+MAMH);
                select_element.push_back("LANTHI="+LANTHI_);
                select_element.push_back("DIEM="+DIEM);
                insertOneElement("score.txt",select_element);
            }
	return true;
}

int SCORE::countexamTimes(string MAMH){
	int count = 1;
        NodeSCORE* current = head;
            while (current){
				if((current->MAMH).compare(MAMH) == 0)	{count = count + 1;};
				current = current->next; 			
            } 
    return count;
}

NodeSCORE* SCORE::GetFinal(string MAMH){
	NodeSCORE* current = head;
	NodeSCORE* nodeNeed = NULL;
        while (current){
			if((current->MAMH).compare(MAMH) == 0){nodeNeed = current;}
			current = current->next; 			
        } 
    return nodeNeed;
}

vector<NodeSCORE> SCORE::GetList(){
	vector<NodeSCORE> ListScore;
		if(head != NULL){
			NodeSCORE* current = head;
			while (current){
				    NodeSCORE data = {current->MAMH,current->MALOP,current->MASV,current->LANTHI,current->DIEM};
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
