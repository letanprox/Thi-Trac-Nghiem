#include <iostream>
#include <vector>
#include <string.h>
#include <string>

#include "CLASS.h"
#include "SUBJECT.h"
#include "QUESTION.h"
#include "ACCESSFILE.h"

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
/////LOAD SCORE
bool addScore(vector<variable> VARIABLE);
vector<NodeSCORE> showAllScore(vector<variable> VARIABLE);
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

#endif
