#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "STUDENT.h"

using namespace std;

bool STUDENT::IsContain(string MASV){
    if(head != NULL){
		NodeSTUDENT* current = head;
		while (current){
			if((current->MASV).compare(MASV) == 0){
				return true;
			    break;
		    }
		    current = current->next;
		}
	}else{
		return false;
	}
}

NodeSTUDENT* STUDENT::LastNode(){
    if(head != NULL){
	    NodeSTUDENT* current = head;
		while (current){
			if(current->next){
				current = current->next;
			}else{
				break;
			}			
        }
        return current;
    }else{
    	return NULL;
	}     
}

bool STUDENT::Insert(string MASV,string HOTEN,bool PHAI,string PASSWORD,string MALOP,bool isLoad){
    bool same = false; 
    bool done = false;
    same = IsContain(MASV);
        if(same == false){
				NodeSTUDENT* newNode = new NodeSTUDENT();
	            newNode->MASV = MASV;
	            newNode->HOTEN = HOTEN;
	            newNode->PHAI = PHAI;
	            newNode->PASSWORD = PASSWORD;
                newNode->list_SCORE = new SCORE(); 
	            if(head == NULL)	{
            	    head = newNode;
			    }else{
                    LastNode()->next = newNode;
				}
				//add database
				if(isLoad == false){
					string PHAI_;
					if(PHAI == true){
					    PHAI_ = "1";
					}else{
						PHAI_ = "0";
					}
					vector<string> select_element;
                    select_element.push_back("MALOP="+MALOP);
                    select_element.push_back("MASV="+MASV);
                    select_element.push_back("HOTEN="+HOTEN);
                    select_element.push_back("PHAI="+PHAI_);
                    select_element.push_back("PASSWORD="+PASSWORD);
                    insertOneElement("student.txt",select_element);
				}	
	        done = true;
		}
	return done;
}

NodeSTUDENT* STUDENT::GetNode(string MASV){
    if(head != NULL){
	    NodeSTUDENT* current = head;
		while ((current->MASV).compare(MASV) != 0){
			if(current->next){
				current = current->next;
			}else{
				break;
			}			
        }
        if((current->MASV).compare(MASV) == 0){
            return current;
		}else{
			return NULL;
		}	
    }else{
    	return NULL;
	}     
}


bool STUDENT::Delete(string MASV){
                bool done = false;
    	        if(head != NULL){
    	        	if((head->MASV).compare(MASV) == 0){
					    head = head->next;
					    done = true;
					}else{
				        NodeSTUDENT* current = head;
				        NodeSTUDENT* prev = NULL;
			            while ((current->MASV).compare(MASV) != 0){
						    if(current->next){		
							    prev = current;
						        current = current->next; 
						    }else{
							    break;
					 	    }			
                        } 
                        if((current->MASV).compare(MASV) == 0){	
                    	    if(current->next){
						        prev->next= current->next;
						        done = true;
						    }else{
							    prev->next = NULL;
						        done = true;	
						    }	    
					    }
					}
				}
				//add database
				vector<string> select_element;
                select_element.push_back("MASV="+MASV);
                removeManyElement("student.txt",select_element);
                removeManyElement("score.txt",select_element);    
	            return done;
}

bool STUDENT::Update(string MASV,string EDITHOTEN,bool EDITPHAI,string EDITPASSWORD){
                    bool done = false;
                    NodeSTUDENT* current = GetNode(MASV);
                    //add database
		            vector<string> select_element;
                    select_element.push_back("MASV="+MASV);
                    vector<string> update_element;
					if((current->MASV).compare(MASV) == 0){
						if(!EDITHOTEN.empty()){
						    current-> HOTEN = EDITHOTEN;
						    update_element.push_back("HOTEN="+EDITHOTEN);
						}
						if(current-> PHAI != EDITPHAI){
						    current-> PHAI = EDITPHAI;
						    update_element.push_back("PHAI="+EDITPHAI);
						}
						if(!EDITPASSWORD.empty()){
						    current-> PASSWORD = EDITPASSWORD;
						    update_element.push_back("PASSWORD="+EDITPASSWORD);
						}
                        updateManyElement("student.txt",select_element,update_element);
			       		done = true;	
					}
            		return done;
}

vector<NodeSTUDENT> STUDENT::GetList(){
	    vector<NodeSTUDENT> ListStudent;
		if(head == NULL){
		}else{
			NodeSTUDENT* current = head;
			while (current){
				    NodeSTUDENT node = {current->MASV , current->HOTEN , current->PHAI , current->PASSWORD};
				    ListStudent.push_back(node);
					if(current->next){
					    current = current->next;
					}else{
						break;
					}			    			
            }	    	
		}
		return ListStudent;
}
