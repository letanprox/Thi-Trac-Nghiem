#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>   
#include <time.h> 

#include "CLASS.h"
#include "SUBJECT.h"
#include "QUESTION.h"

#ifndef APIGETDATA_H
#define APIGETDATA_H

using namespace std;

struct variable{
    string name;
    string value;
};
////LOAD DATABASE
bool LoadDatabase();
////LOAD CLASS
bool addClass(vector<variable> VARIABLE);
bool deleteClass(vector<variable> VARIABLE);
bool updateClass(vector<variable> VARIABLE);
vector<NodeCLASS> showAllClass();
////LOAD STUDENT
bool addStudent(vector<variable> VARIABLE);
bool deleteStudent(vector<variable> VARIABLE);
bool updateStudent(vector<variable> VARIABLE);
vector<NodeSTUDENT> showAllStudent(vector<variable> VARIABLE);
NodeSTUDENT* api_GetNodeStudent(string MALOP,string MASV);
/////LOAD SCORE
bool addScore(vector<variable> VARIABLE);
vector<NodeSCORE> showAllScore(vector<variable> VARIABLE);
NodeSCORE* api_GetFinalNodeScore(string MALOP,string MASV,string MAMH);
/////LOAD SUBJECT
bool addSubject(vector<variable> VARIABLE);
bool updateSubject(vector<variable> VARIABLE);
bool deleteSubject(vector<variable> VARIABLE);
vector<NodeSUBJECT> showAllSubject();
////LOAD QUESTION
bool addQuestion(vector<variable> VARIABLE);
bool deleteQuestion(vector<variable> VARIABLE);
bool updateQuestion(vector<variable> VARIABLE);
vector<NodeQUESTION> showAllQuestion(vector<variable> VARIABLE);
vector<NodeQUESTION> api_GetListTest(string MAMH,int limit);
int TotalQuestion(string MAMH);
NodeQUESTION api_GetNodeQuestion(int Id);

////LOAD EXTRA
vector<NodeSTUDENT> searchStudent(string MALOP,string text_search);
vector<NodeCLASS> searchClass(string text_search);

#endif
