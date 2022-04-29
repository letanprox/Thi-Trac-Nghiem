#include <iostream>
using namespace std; 

class Node { 
	public: 
	    int key; 
	    Node *left; 
	    Node *right; 
	    int height; 
}; 

Node* ishaveNode(Node* node, int key);

Node* deleteNode(Node* root, int key);

Node* insertNode(Node* node, int key);

class Node{
	private:
		struct Node{
			int key; 
	        Node *left; 
	        Node *right; 
	        int height; 
		};
};


