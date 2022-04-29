#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>

#include "ACCESSFILE.h"

using namespace std;
//return title chain database
vector<string> TitleChain(char* fileName){
	string title_database;	     
	    fstream readFile;
        readFile.open(fileName,ios::in | fstream::app); 
        if (readFile.is_open()){   
            string word;
            while(getline(readFile, title_database)){ 
            break;}
            readFile.close();
        }
    vector<string> title;
		string temp_titles;
        for (int i = 0; i < title_database.size(); i++){
    	    if(title_database[i] == '#'){
		        title.push_back(temp_titles);
		        temp_titles = "";
		    }else {
		        temp_titles = temp_titles + title_database[i] ;
	 	    }	
        }
	return title;    
}
// return value chain database user input
string* AbsrtractChain(char* fileName,vector<string> select_element,vector<string> title){
    string temp_title[select_element.size()];
    string temp_value[select_element.size()];
    for (int i = 0; i < select_element.size(); i++){
        bool check = false;
	    for (int k = 0; k<select_element[i].length() ; k++ ){
		    if(select_element[i][k] == '='){
		        check = true;
		    }else {
		        if(check == true){
		    	    temp_value[i] = temp_value[i] + select_element[i][k];
		        }else{
		    	    temp_title[i] = temp_title[i] + select_element[i][k];
			    }
		    }	
	    }
	}
    string* checkChain = new string[title.size()];
	for (int i = 0; i<select_element.size(); i++ ){
	    for (int k = 0 ; k<title.size() ; k++ ){
	        if(temp_title[i].compare(title[k]) == 0){
			      checkChain[k] = temp_value[i];			
			}
		}
	}
	return checkChain;
}
//return title chain user input 
string* AbsrtractElement(char* fileName,vector<string> select_element,vector<string> title){
    string* checkChain = new string[title.size()];
	for (int i = 0; i<select_element.size(); i++ ){
	    for (int k = 0 ; k<title.size() ; k++ ){
	        if(select_element[i].compare(title[k]) == 0){
			      checkChain[k] = select_element[i];			
			}
		}
	}
	return checkChain;
}

//return element after ,
vector<string> hashData(string dataline){
                vector<string> data_dot;
		        string temp_data_dot;
                for (int i = 0; i < dataline.size(); i++){
    	            if(dataline[i] == '#'){
		                data_dot.push_back(temp_data_dot);
		                temp_data_dot = "";
		            }else {
		                temp_data_dot = temp_data_dot + dataline[i];
	 	            }	
                }     
    return data_dot;           
}

//return chain value chose
bool checkCondition(string dataline,string* checkChain){
                vector<string> data_dot =  hashData(dataline);
                bool check = true;
				for (int i = 0; i < data_dot.size(); i++){
					if(!checkChain[i].empty()){	
					    if(checkChain[i][0] == '<'){
                            string temp = checkChain[i];
                            temp.erase(0, 1);
                            int x,y;
					        istringstream(data_dot[i]) >> x;
					        istringstream(temp) >> y;
						    if(x < y ){}else{
							    check = false;
						    }
					    }else if(checkChain[i][0] == '>'){
						    string temp = checkChain[i];
                            temp.erase(0, 1);
                            int x,y;
					        istringstream(data_dot[i]) >> x;
					        istringstream(temp) >> y;
					        if(x > y ){}else{
							    check = false;
						    } 
					    }else if(data_dot[i].compare(checkChain[i]) != 0){
					        check = false;
				        }
					}
				}
        return check;        
}
//////////////////////////////////action funtion
int countElement(char* fileName,vector<string> select_element){
	int count = 0;
    vector<string> title = TitleChain(fileName);
	string* checkChain  = AbsrtractChain(fileName,select_element,title);
	fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){
    string dataline;
    bool first_line = true;
    while(getline(readFile, dataline)){ 
        if(first_line == false){
		    if(!dataline.empty()){  
		        vector<string> data_dot =  hashData(dataline);	
                bool check = checkCondition(dataline,checkChain);
		        if(check == true) count = count + 1;
	        }
		}else first_line = false;
	}
	readFile.close();
	}
	return count;
}
//////////////////////////////////action funtion
void insertOneElement(char* fileName,vector<string> select_element){
        vector<string> title = TitleChain(fileName);
	    string* checkChain = AbsrtractChain(fileName,select_element,title);
	    fstream writeFile;
        writeFile.open (fileName, fstream::out | fstream::app);
        writeFile<<endl;
	    for (int i = 0; i<title.size(); i++ ){
	        writeFile<<checkChain[i]<<"#";
	    }
        writeFile.close();     
}

//////////////////////////////////action funtion
vector<string> selectManyElement(char* fileName,vector<string> select_title_element,vector<string> select_element){
    vector<string> title = TitleChain(fileName);
	string* title_chose = AbsrtractElement(fileName,select_title_element,title);
	string* checkChain  = AbsrtractChain(fileName,select_element,title);
	vector<string> getData;
	fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){   
        string dataline;
        bool first_line = true;
        while(getline(readFile, dataline)){ 
        if(first_line == false){
            if(!dataline.empty()){     	
			    vector<string> data_dot =  hashData(dataline);	
                bool check = checkCondition(dataline,checkChain);	
		        string temp;
				if(check == true){
				    for(int j = 0 ; j<data_dot.size() ; j++ ){
					    if(!title_chose[j].empty()){
						    temp = temp + data_dot[j] + "#";
						}
					}
				}
				if(!temp.empty()){
				getData.push_back(temp);
				}
			}
        }else{
           	  first_line = false;
		}
        }
        readFile.close();
    }
	return getData;    
}
//////////////////////////////////action funtion
vector<string> selectAllElement(char* fileName){
	vector<string> getData;        
	fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){   
        string dataline;
        bool first_line = true;
        while(getline(readFile, dataline)){ 
        if(first_line == false){
            if(!dataline.empty()){     
			    getData.push_back(dataline);
			}
        }else{
           	  first_line = false;
		}
        }
        readFile.close();
    }
	return getData;    
}

//////////////////////////////////action funtion
void removeManyElement(char* fileName,vector<string> select_element){
    vector<string> title = TitleChain(fileName);
	string* checkChain  = AbsrtractChain(fileName,select_element,title);
    fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){
    	char* temp_filename = new char;
    	temp_filename = "temp_filename.txt";
		fstream writeFile;
        writeFile.open (temp_filename, fstream::out | fstream::app);
        string dataline;
        bool first_line = true;
        while(getline(readFile, dataline)){ 
        if(first_line == false){
		    if(!dataline.empty()){  
		        vector<string> data_dot =  hashData(dataline);	
                bool check = checkCondition(dataline,checkChain);
		        if(check == false){
				    writeFile << endl << dataline;
				}
	        }
		}else{
			writeFile << dataline;
			first_line = false;
		}
		}
		writeFile.close();
		readFile.close();
		remove( fileName );
		rename( temp_filename , fileName );
	}
}

//////////////////////////////////action funtion
void updateManyElement(char* fileName,vector<string> select_element,vector<string> update_element){
    vector<string> title = TitleChain(fileName);
	string* checkChain  = AbsrtractChain(fileName,select_element,title);
	string* updateChain  = AbsrtractChain(fileName,update_element,title);
    fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){
    	char* temp_filename = new char;
    	temp_filename = "temp_filename.txt";
		fstream writeFile;
        writeFile.open (temp_filename, fstream::out | fstream::app);
        string dataline;
        bool first_line = true;
        while(getline(readFile, dataline)){ 
        if(first_line == false){
		    if(!dataline.empty()){  
		        vector<string> data_dot =  hashData(dataline);	
                bool check = checkCondition(dataline,checkChain);
		        if(check == false){		  
				    writeFile << endl << dataline; 
				}else{
				    writeFile<<endl;
	                for (int i = 0; i<title.size(); i++ ){
	                	if(updateChain[i].empty()){
						    writeFile<<data_dot[i]<<"#";   
						}else{
							writeFile<<updateChain[i]<<"#";
						}
	                }	
				}	
	        }
		}else{
			writeFile << dataline;
			first_line = false;
		}
		}
		writeFile.close();
		readFile.close();
		remove( fileName );
		rename( temp_filename , fileName );
	}
}
//////////////////////////////////action funtion
vector<string> searchManyElement(char* fileName,vector<string> select_element,vector<string> conditon_element,vector<string> search_element,string search_text){
    vector<string> title = TitleChain(fileName);
	string* element_chose = AbsrtractElement(fileName,select_element,title);
	string* element_search = AbsrtractElement(fileName,search_element,title);
	string* checkChain;
	if(!conditon_element.empty()) checkChain  = AbsrtractChain(fileName,conditon_element,title);
	vector<string> getData;
	fstream readFile;
    readFile.open(fileName,ios::in | fstream::app ); 
    if (readFile.is_open()){   
        string dataline;
        bool first_line = true;
        bool check = false;
        size_t found;
        string temp;
        while(getline(readFile, dataline)){ 
        if(first_line == false){
            if(!dataline.empty()){   
			    vector<string> data_dot =  hashData(dataline);	
				if(conditon_element.empty() || checkCondition(dataline,checkChain) == true){
					for (int i = 0; i < data_dot.size(); i++){
						if(!element_search[i].empty()){	
							found = data_dot[i].find(search_text);
							if(found!=string::npos) check = true;
						}
					}
				}
				if(check == true){
					check = false;
				    for(int j = 0 ; j<data_dot.size() ; j++ ){
					    if(!element_chose[j].empty()){
						    temp = temp + data_dot[j];
						}
					}
				}
				if(!temp.empty()){
					getData.push_back(temp);
					temp = "";
				}
			}
        }else{
           	  first_line = false;
		}
        }
        readFile.close();
    }
	return getData;    
}
