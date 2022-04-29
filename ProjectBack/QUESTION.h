#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "ACCESSFILE.h"

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
		   	int key; 
	        Node *left; 
	        Node *right; 
	        int height; 
		};
		
class QUESTION{ 
	public: 
	    vector<NodeQUESTION> ListQUESTION;
	    Node *root;   
		
		Node* InsertNode(Node* node, int key);
		Node* DeleteNode(Node* root, int key);
		Node* GetNodeTree(Node* node, int key);
		bool IshaveNode(Node* node, int key);
		vector<int> preOrderList;
		void preOrder(Node* root); 
		
	    bool Insert(NodeQUESTION* dataQuestion,bool isLoad);
        bool Update(NodeQUESTION* dataQuestion);
	    bool Delete(int Id);
	    int  getPos(int Id);
	    bool IsSubjectContain(int Id,string MAMH);
	    vector<NodeQUESTION> GetListTest(string MAMH);
	    NodeQUESTION GetNode(int Id);	    
};
