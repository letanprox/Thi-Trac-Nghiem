#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "ACCESSFILE.h"

#ifndef QUESTION_H
#define QUESTION_H

using namespace std;

        struct NodeQUESTION{
		    int Id;
            string MAMH;
	        string NOIDUNG;
	        string A;
	        string B;
	        string C;
	        string D;
	        int ANSWER;
        };

	    struct Node{
	    	NodeQUESTION* nodeQuestion;
	    	string MAMH;
		   	int key; 
	        Node *left; 
	        Node *right; 
	        int height; 
		};
		
class QUESTION{ 
	public: 
	    Node *root;   
	    int count;
	    vector<int> preOrderList;
		
		Node* InsertNode(Node* node, int key,string MAMH,NodeQUESTION* newNode);
		Node* DeleteNode(Node* root, int key);
		Node* GetNodeTree(Node* node, int key);
		bool IshaveNode(Node* node, int key);
		void preOrder(Node* root,string MAMH); ///RETURN PREORDER LIST
		void countQuestionNode(Node* node,string MAMH);
		
	    bool Insert(NodeQUESTION* dataQuestion,bool isLoad);
        bool Update(NodeQUESTION* dataQuestion);
	    bool Delete(int Id);
	    int  countTotalQuestion(string MAMH);
	    NodeQUESTION GetNode(int Id);
	    vector<NodeQUESTION> GetList(string MAMH);
	    vector<NodeQUESTION> GetListTest(string MAMH,int limit);	    
};

#endif
