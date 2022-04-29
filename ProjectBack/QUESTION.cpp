#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "QUESTION.h"

using namespace std;

void PreOrder(Node *root) { 
	if(root != NULL) { 
		cout << root->key << " "; 
		PreOrder(root->left); 
		PreOrder(root->right); 
	} 
} 

bool QUESTION::Insert(NodeQUESTION* dataQuestion,bool isLoad){
    bool same = false;
    bool done = false;  
	    same = IshaveNode(root, dataQuestion->Id);
        if(same == false){
				NodeQUESTION newNode;
	            newNode.MAMH = dataQuestion->MAMH;
                newNode.Id = dataQuestion->Id;
	            newNode.NOIDUNG = dataQuestion->NOIDUNG;
                newNode.A = dataQuestion->A;
                newNode.B = dataQuestion->B;
                newNode.C = dataQuestion->C;
                newNode.D = dataQuestion->D;
                newNode.ANSWER = dataQuestion->ANSWER;
                ListQUESTION.push_back(newNode);
                //////////insert tree
                root = InsertNode(root,dataQuestion->Id);
           	    PreOrder(root);
           	    if(isLoad == false){
           	    	ostringstream ss1;
           	    	ostringstream ss2;
                    ss1 << dataQuestion->Id;
                    ss2 << dataQuestion->ANSWER;
                    string Id = ss1.str();
           	    	string ANSWER = ss2.str();
				    vector<string> select_element;
                    select_element.push_back("MAMH="+dataQuestion->MAMH);
                    select_element.push_back("Id="+Id);
                    select_element.push_back("NOIDUNG="+dataQuestion->NOIDUNG);
                    select_element.push_back("A="+dataQuestion->A);
                    select_element.push_back("B="+dataQuestion->B);
                    select_element.push_back("C="+dataQuestion->C);
                    select_element.push_back("D="+dataQuestion->D);
                    select_element.push_back("ANSWER="+ANSWER);
                    insertOneElement("question.txt",select_element);
				}
	            done = true;
		}
	return done;
}

int QUESTION::getPos(int Id){
	int pos = 0;
    for (int i = 0; i < ListQUESTION.size() ; i++){
	    if(ListQUESTION[i].Id == Id){
		    break;
		}else{
			pos = pos + 1;
		}
	}
	return pos;
}

bool QUESTION::Delete(int Id){
	if( IshaveNode(root, Id) == true ){
	    ListQUESTION.erase(ListQUESTION.begin() + getPos(Id));
        DeleteNode(root, Id);
        //add database
        ostringstream ss1;
        ss1 << Id;
        string Id_ = ss1.str();
		vector<string> select_element;
        select_element.push_back("Id="+Id_);
        removeManyElement("question.txt",select_element);
        return true;
	}
}

bool QUESTION::Update(NodeQUESTION* editQuestion){
	
	vector<string> select_element;
	vector<string> update_element;
    ostringstream ss1;
    ss1 << editQuestion->Id;
    string Id = ss1.str();
	
    if(!(editQuestion->NOIDUNG).empty()){
	    ListQUESTION[getPos(editQuestion->Id)].NOIDUNG = editQuestion->NOIDUNG ;
	    update_element.push_back("NOIDUNG="+editQuestion->NOIDUNG);
	} 
	if(!(editQuestion->A).empty()){
	    ListQUESTION[getPos(editQuestion->Id)].A = editQuestion->A;
	    update_element.push_back("A="+editQuestion->A);
	}
	if(!(editQuestion->B).empty()){
	    ListQUESTION[getPos(editQuestion->Id)].B = editQuestion->B;
	    update_element.push_back("B="+editQuestion->B);
	}
	if(!(editQuestion->C).empty()){
	    ListQUESTION[getPos(editQuestion->Id)].C = editQuestion->C;
	    update_element.push_back("C="+editQuestion->C);
	}
	if(!(editQuestion->D).empty()){
	    ListQUESTION[getPos(editQuestion->Id)].D =editQuestion->D;
	    update_element.push_back("D="+editQuestion->D);
	}
	if( editQuestion->ANSWER != ListQUESTION[getPos(editQuestion->Id)].ANSWER ){
	    ListQUESTION[getPos(editQuestion->Id)].ANSWER = editQuestion->ANSWER;
	    ostringstream ss2;
	    ss2 << editQuestion->ANSWER;
	    string ANSWER = ss2.str();
	    update_element.push_back("ANSWER="+ANSWER);
	}
    select_element.push_back("Id="+Id);
	updateManyElement("question.txt",select_element,update_element);
	return true;
}

bool QUESTION::IsSubjectContain(int Id,string MAMH){
    bool check = false;
    for (int i = 0; i < ListQUESTION.size() ; i++){
	    if(ListQUESTION[i].Id == Id){
	    	if((ListQUESTION[i].MAMH).compare(MAMH) == 0) check = true;
		    break;
		}
	}
	return check;
}

NodeQUESTION QUESTION::GetNode(int Id){
	NodeQUESTION node = ListQUESTION[getPos(Id)];
    return node;    
} 

vector<NodeQUESTION> QUESTION::GetListTest(string MAMH){
    preOrder(root); 
    vector<int> array = preOrderList;
    preOrderList.clear();
    vector<int> arr ;
    for(int i = 0; i < array.size() ; i++){
	    if(IsSubjectContain(array[i],MAMH) == true){
		    arr.push_back(array[i]);
		}
	}
	srand(time(NULL));
	int n = arr.size();
	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;
	int i = 0;
	while (i < n - 1){
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;
 	    int temp = arr[i];
	    arr[i] = arr[swapPosition];
	    arr[swapPosition] = temp;
		i++;
	}
	vector<NodeQUESTION> newlist;
	for (int i=0; i < arr.size() ; i++){
	    newlist.push_back(GetNode(arr[i]));
	}
	return newlist;
} 

