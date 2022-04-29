#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "APIGETDATA.h"

using namespace std;

/////////////////////// get variable
string GetVariable(string outVariable,vector<variable> VARIABLE){
	string temp_var;
    for (int i = 0; i < VARIABLE.size(); i++) { 
        if((VARIABLE[i].name).compare(outVariable) == 0){
		    temp_var = VARIABLE[i].value;
		}
    }
    return temp_var;
}
/////////////////////// action 
CLASS* Class = new CLASS();
SUBJECT* Subject = new SUBJECT();
QUESTION* Question = new QUESTION();

//Load data from database
bool LoadDatabase(){
    //load class student
	vector<string> listclass =  selectAllElement("class.txt");
	
	for(int i=0; i<listclass.size() ; i++){	
	    vector<string> dotdataclass = hashData(listclass[i]);
	    Class->Insert(dotdataclass[0],dotdataclass[1],true); 
	    
	    NodeCLASS dataclass = Class->GetNode(dotdataclass[0]);
	    STUDENT* Student = dataclass.list_STUDENT;
		    vector<string> liststudent =  selectAllElement("student.txt");
			for(int i=0; i<liststudent.size() ; i++){
			    vector<string> dotdatastudent = hashData(liststudent[i]);
			    if(dotdatastudent[0].compare(dotdataclass[0]) == 0){
			      	bool PHAI;
	                istringstream(dotdatastudent[3]) >> PHAI;
				    Student->Insert(dotdatastudent[1],dotdatastudent[2], PHAI ,dotdatastudent[4],dotdatastudent[0],true);
				    
				    NodeSTUDENT* datascore = Student->GetNode(dotdatastudent[1]);
	                SCORE* Score = datascore->list_SCORE;
					vector<string> listscore =  selectAllElement("score.txt");
	                for(int i=0; i<listscore.size() ; i++){
					    vector<string> dotdatascore = hashData(listscore[i]);
					    if(dotdatascore[1].compare(dotdatastudent[1]) == 0){
					    	int DIEM;
					    	istringstream(dotdatascore[3]) >> DIEM;
						    Score->Insert(dotdatascore[0],dotdatascore[1],dotdatascore[2],DIEM,true);
						}
					}  
				}
			}
	}
	//load question
	vector<string> listquestion =  selectAllElement("question.txt");
	for(int i=0; i<listquestion.size() ; i++){
		vector<string> dotdataquestion = hashData(listquestion[i]);
		int Id;
	    istringstream(dotdataquestion[1]) >> Id;
	    int ANSWER;
	    istringstream(dotdataquestion[7]) >> ANSWER;
		NodeQUESTION* newNode = new NodeQUESTION();
		newNode->MAMH = dotdataquestion[0];
		newNode->NOIDUNG = dotdataquestion[2];
		newNode->Id = Id;
        newNode->A = dotdataquestion[3];
        newNode->B = dotdataquestion[4];
        newNode->C = dotdataquestion[5];
        newNode->D = dotdataquestion[6];
        newNode->ANSWER = ANSWER;
	    Question->Insert(newNode,true); 
	}
	//load subject
	vector<string> listsubject =  selectAllElement("subject.txt");
	for(int i=0; i<listsubject.size() ; i++){
	    vector<string> dotdatasubject = hashData(listsubject[i]);
	    Subject->Insert(dotdatasubject[0],dotdatasubject[1],true); 
	}
}

////////////////// CLASS
//add 
bool addClass(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string TENLOP = GetVariable("TENLOP",VARIABLE);
    return Class->Insert(MALOP,TENLOP,false); 
}
//delete
bool deleteClass(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);            
    return Class->Delete(MALOP);     
}
//update
bool updateClass(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string EDITTENLOP = GetVariable("EDITTENLOP",VARIABLE);
    return Class->Update(MALOP,EDITTENLOP);   
}
//show
vector<NodeCLASS> showAllClass(){
	return Class->GetList(); 
};
////////////////STUDENT
//add
bool addStudent(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string MASV = GetVariable("MASV",VARIABLE);
	string HOTEN = GetVariable("HOTEN",VARIABLE);
	string PHAI_ = GetVariable("PHAI",VARIABLE);
	string PASSWORD = GetVariable("PASSWORD",VARIABLE);
	bool PHAI;
	int x;
	istringstream(PHAI_) >> x;
	if(x == 1){
	    PHAI = true;
	}else{
		PHAI =false;
	}
	NodeCLASS data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
	return Student->Insert(MASV,HOTEN,PHAI,PASSWORD,MALOP,false);
}
//delete
bool deleteStudent(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string MASV  = GetVariable("MASV",VARIABLE);
	NodeCLASS data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
    return Student->Delete(MASV);    
}
//update
bool updateStudent(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string MASV = GetVariable("MASV",VARIABLE);
	string EDITHOTEN = GetVariable("EDITHOTEN",VARIABLE);
	string EDITPHAI_ = GetVariable("EDITPHAI",VARIABLE);
	string EDITPASSWORD = GetVariable("EDITPASSWORD",VARIABLE);
	bool EDITPHAI;
	int x;
	istringstream(EDITPHAI_) >> x;
	if(x == 1){
	    EDITPHAI = true;
	}else{
		EDITPHAI =false;
	}
	NodeCLASS  data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
    return Student->Update(MASV,EDITHOTEN,EDITPHAI,EDITPASSWORD);    
}
//show
vector<NodeSTUDENT> showAllStudent(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	NodeCLASS  data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
	return Student->GetList();  
};

////////////////////////////// SCORE
//add
bool addScore(vector<variable> VARIABLE){
	string MALOP = GetVariable("MALOP",VARIABLE);
	string MASV = GetVariable("MASV",VARIABLE);
	string MAMH = GetVariable("MAMH",VARIABLE);
	string DIEM_ = GetVariable("DIEM",VARIABLE);
	int DIEM;
	istringstream(DIEM_) >> DIEM;
	NodeCLASS  data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
	NodeSTUDENT* data_ = Student->GetNode(MASV);
	SCORE* NodeScore = data_->list_SCORE;
	return NodeScore->Insert(MALOP,MASV,MAMH,DIEM,false);
}
//show
vector<NodeSCORE> showAllScore(vector<variable> VARIABLE){
    string MALOP = GetVariable("MALOP",VARIABLE);
	string MASV = GetVariable("MASV",VARIABLE);
	NodeCLASS  data = Class->GetNode(MALOP);
	STUDENT* Student = data.list_STUDENT;
	NodeSTUDENT* data_ = Student->GetNode(MASV);
	SCORE* NodeScore = data_->list_SCORE;
	return NodeScore->GetList(); 
}

///////////////////////// SUBJECT
//add
bool addSubject(vector<variable> VARIABLE){
	string MAMH = GetVariable("MAMH",VARIABLE);
	string TENMH = GetVariable("TENMH",VARIABLE);
    return Subject->Insert(MAMH,TENMH,false); 
}
//update
bool updateSubject(vector<variable> VARIABLE){
	string MAMH = GetVariable("MAMH",VARIABLE);
	string EDITTENMH = GetVariable("EDITTENMH",VARIABLE);
    return Subject->Update(MAMH,EDITTENMH); 
}
//delete
bool deleteSubject(vector<variable> VARIABLE){
	string MAMH = GetVariable("MAMH",VARIABLE);
    return Subject->Delete(MAMH);    
}
//show
vector<NodeSUBJECT> showAllSubject(){
    return Subject->GetList(); 
}

////////////////////////QUESTION
//add
bool addQuestion(vector<variable> VARIABLE){
	string MAMH = GetVariable("MAMH",VARIABLE);
	string NOIDUNG = GetVariable("NOIDUNG",VARIABLE);
	string A = GetVariable("A",VARIABLE);
	string B = GetVariable("B",VARIABLE);
	string C = GetVariable("C",VARIABLE);
	string D = GetVariable("D",VARIABLE);
	string ANSWER_ = GetVariable("ANSWER",VARIABLE);
	int ANSWER;
	istringstream(ANSWER_) >> ANSWER;
	srand (time(NULL));
	int Id = rand() % 100 + 1;
	while(Question->IshaveNode(Question->root, Id) == true){
	    Id = rand() % 100 + 1;
	}
    NodeQUESTION* newNode = new NodeQUESTION();
    newNode->A = A;
    newNode->B = B;
    newNode->C = C;
    newNode->D = D;
    newNode->ANSWER = ANSWER;
    newNode->MAMH = MAMH;
    newNode->NOIDUNG = NOIDUNG;
    newNode->Id = Id;
    return Question->Insert(newNode,false);
}
//show
vector<NodeQUESTION> showAllQuestion(vector<variable> VARIABLE){
    string MAMH = GetVariable("MAMH",VARIABLE);
    return Question->GetListTest(MAMH);
}
//delete
bool deleteQuestion(vector<variable> VARIABLE){
    string Id_ = GetVariable("Id",VARIABLE);
    int Id;
	istringstream(Id_) >> Id;
    return Question->Delete(Id);
}
//update
bool updateQuestion(vector<variable> VARIABLE){
	string MAMH = GetVariable("MAMH",VARIABLE);
	string NOIDUNG = GetVariable("NOIDUNG",VARIABLE);
	string A = GetVariable("A",VARIABLE);
	string B = GetVariable("B",VARIABLE);
	string C = GetVariable("C",VARIABLE);
	string D = GetVariable("D",VARIABLE);
	string ANSWER_ = GetVariable("ANSWER",VARIABLE);
	string Id_ = GetVariable("Id",VARIABLE);
	int Id;
	istringstream(Id_) >> Id;
	int ANSWER;
	istringstream(ANSWER_) >> ANSWER;
	NodeQUESTION* newNode = new NodeQUESTION();
    newNode->A = A;
    newNode->B = B;
    newNode->C = C;
    newNode->D = D;
    newNode->ANSWER = ANSWER;
    newNode->NOIDUNG = NOIDUNG;
    newNode->Id = Id;
    return Question->Update(newNode); 
}
