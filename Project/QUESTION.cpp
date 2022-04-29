#include "QUESTION.h"

using namespace std;
//-------------------------------------------------------------------------------------------------
bool QUESTION::Insert(NodeQUESTION* dataQuestion,bool isLoad){
    bool same = false;
    bool done = false;  
	    same = IshaveNode(root, dataQuestion->Id);
        if(same == false){
				NodeQUESTION* newNode = new NodeQUESTION();
	            newNode->MAMH = dataQuestion->MAMH;
                newNode->Id = dataQuestion->Id;
	            newNode->NOIDUNG = dataQuestion->NOIDUNG;
                newNode->A = dataQuestion->A;
                newNode->B = dataQuestion->B;
                newNode->C = dataQuestion->C;
                newNode->D = dataQuestion->D;
                newNode->ANSWER = dataQuestion->ANSWER;
                //insert tree
                root = InsertNode(root,dataQuestion->Id,dataQuestion->MAMH,newNode);
				//add database
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
//-------------------------------------------------------------------------------------------------
bool QUESTION::Delete(int Id){
	if(IshaveNode(root, Id) == true ){
        DeleteNode(root, Id);
        //add database
        ostringstream ss1;
        ss1 << Id;
        string Id_ = ss1.str();
		vector<string> select_element;
        select_element.push_back("Id="+Id_);
        removeManyElement("question.txt",select_element);
        return true;
	}else return false;
}
//-------------------------------------------------------------------------------------------------
bool QUESTION::Update(NodeQUESTION* editQuestion){
	vector<string> select_element;
	vector<string> update_element;
    ostringstream ss1;
    ss1 << editQuestion->Id;
    string Id = ss1.str();
    NodeQUESTION* data = GetNodeTree(root,editQuestion->Id)->nodeQuestion;
    if(!(editQuestion->NOIDUNG).empty()){
    	data->NOIDUNG = editQuestion->NOIDUNG;
	    update_element.push_back("NOIDUNG="+editQuestion->NOIDUNG);
	} 
	if(!(editQuestion->A).empty()){
	    data->A = editQuestion->A;
	    update_element.push_back("A="+editQuestion->A);
	}
	if(!(editQuestion->B).empty()){
	    data->B = editQuestion->B;
	    update_element.push_back("B="+editQuestion->B);
	}
	if(!(editQuestion->C).empty()){
	    data->C = editQuestion->C;
	    update_element.push_back("C="+editQuestion->C);
	}
	if(!(editQuestion->D).empty()){
	    data->D = editQuestion->D;
	    update_element.push_back("D="+editQuestion->D);
	}
	if(editQuestion->ANSWER != data->ANSWER){
	    data->ANSWER = editQuestion->ANSWER;
	    ostringstream ss2;
	    ss2 << editQuestion->ANSWER;
	    string ANSWER = ss2.str();
	    update_element.push_back("ANSWER="+ANSWER);
	}
	//add database
    select_element.push_back("Id="+Id);
	updateManyElement("question.txt",select_element,update_element);
	return true;
}
//-------------------------------------------------------------------------------------------------
int QUESTION::countTotalQuestion(string MAMH){
	count = 0;
	if(root != NULL) countQuestionNode(root,MAMH); 
	return count;
}
//-------------------------------------------------------------------------------------------------
NodeQUESTION QUESTION::GetNode(int Id){
	NodeQUESTION* data = GetNodeTree(root,Id)->nodeQuestion;
	NodeQUESTION return_data;
	return_data.MAMH = data->MAMH;
    return_data.Id = data->Id;
	return_data.NOIDUNG = data->NOIDUNG;
    return_data.A = data->A;
    return_data.B = data->B;
    return_data.C = data->C;
    return_data.D = data->D;
    return_data.ANSWER = data->ANSWER;
    return return_data;
} 
//-------------------------------------------------------------------------------------------------
vector<NodeQUESTION> QUESTION::GetList(string MAMH){
   	preOrder(root,MAMH); 
    vector<int> array = preOrderList;
    preOrderList.clear();
	vector<NodeQUESTION> newlist;
	for (int i=0; i < array.size() ; i++)
	    newlist.push_back(GetNode(array[i]));
	
	return newlist;
}
//-------------------------------------------------------------------------------------------------
vector<NodeQUESTION> QUESTION::GetListTest(string MAMH,int limit){
   	preOrder(root,MAMH); 
    vector<int> array = preOrderList;
    preOrderList.clear();
	srand(time(NULL));
	int n = array.size();
	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;
	int i = 0;
	while (i < n - 1){
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;
 	    int temp = array[i];
	    array[i] = array[swapPosition];
	    array[swapPosition] = temp;
		i++;
	}
	vector<NodeQUESTION> newlist;
	if(limit == 0){
		for (int i=0; i < array.size() ; i++){
	    	newlist.push_back(GetNode(array[i]));
		}	
	}else{
		for (int i=0; i < limit ; i++){
	    	newlist.push_back(GetNode(array[i]));
		}
	}
	return newlist;
} 
