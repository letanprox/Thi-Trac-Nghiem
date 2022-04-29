#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

#ifndef ACCESSFILE_H
#define ACCESSFILE_H

vector<string> selectAllElement(char* fileName);
//file name

vector<string> hashData(string dataline);
//hash dataline

vector<string> selectManyElement(char* fileName,vector<string> select_title_element,vector<string> select_element);
// example :[ * , "tuoi >= 13" , "gioi tinh = nam]
// example :[ ten , "gioi tinh = nam"]

void insertOneElement(char* fileName,vector<string> select_element);
// example :[ "ten = tan" , "gioi tinh = nam"]

void removeManyElement(char* fileName,vector<string> select_element);
// example :[ "tuoi >= 13" , "gioi tinh = nam"]

void updateManyElement(char* fileName,vector<string> select_element,vector<string> update_element);
// example :[ "tuoi >= 13" ,"gioi tinh = nam"] ["diem = 9"]


#endif
