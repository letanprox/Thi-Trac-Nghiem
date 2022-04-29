#include "DATAEXAM.h"

using namespace std;

bool DATAEXAM::InsertDatabase(string MAMH,string MALOP,string MASV,string SCORE,string TIME,string TOTAL,vector<NodeANSWER> listAnswer){
	string EXAM;
    for(int i = 0; i < listAnswer.size() ; i++){
		ostringstream convert1,convert2,convert3;   
    	convert1 << listAnswer[i].Id;     
		convert2 << listAnswer[i].chose;     
		convert3 << listAnswer[i].corect_chose;    
		EXAM = EXAM + "-" + convert1.str() + "," + convert2.str() + "," + convert3.str();	
	}
	vector<string> element_check_count;
	element_check_count.push_back("MAMH="+MAMH);
	element_check_count.push_back("MASV="+MASV);
	int LANTHI_ = countElement("DATAEXAM.txt",element_check_count) + 1;
    ostringstream ss;
    ss << LANTHI_;
    string LANTHI = ss.str();
	vector<string> select_element;
	select_element.push_back("MAMH="+MAMH);
	select_element.push_back("MALOP="+MALOP);
	select_element.push_back("MASV="+MASV);
	select_element.push_back("SCORE="+SCORE);
	select_element.push_back("TIME="+TIME);
	select_element.push_back("TOTAL="+TOTAL);
	select_element.push_back("LANTHI="+LANTHI);
	select_element.push_back("EXAM="+EXAM);
	insertOneElement("DATAEXAM.txt",select_element);
}

vector<NodeANSWER> DATAEXAM::getDatabase(string MAMH,string MASV,string LANTHI){
	vector<string> select_title_element,select_element;
	select_title_element.push_back("EXAM");
	select_element.push_back("MASV="+MASV);
	select_element.push_back("MAMH="+MAMH);
	select_element.push_back("LANTHI="+LANTHI);
    vector<string> data = selectManyElement("DATAEXAM.txt",select_title_element,select_element);
    vector<NodeANSWER> dataAnswers;
    if(!data.empty()){
        int count = 0;	
        string Id;
        string chose;
        string correct_chose;
        for(int i = 0 ; i < data[0].size(); i++){
        if((data[0][i]) != ('#')){
	    	if((data[0][i]) != ('-')){	
		    	if((data[0][i]) != (',')){
		    		if(count == 1){
		        		Id = Id + data[0][i];
		        	}else if(count == 2){
					    chose = chose + data[0][i];
					}else if(count == 3){
					    correct_chose = correct_chose + data[0][i];
					} 
		        }else{
		        	count = count + 1;
				}
			}else{	
			    if(count > 0){
			        int Id_,chose_,correct_chose_;
			        
			        stringstream str1num(Id);str1num >> Id_; 
			        stringstream str2num(chose);str2num >> chose_; 
			        stringstream str3num(correct_chose);str3num >> correct_chose_; 
			        
		        	NodeANSWER node;
		        	node.Id = Id_;
		        	node.chose = chose_;
		        	node.corect_chose = correct_chose_;
		        	dataAnswers.push_back(node);
		        	
			        Id = "";
			        chose = "";
			        correct_chose = "";
				    count = 1;
				}else{
					count = 1;
				}
			}
	 	}else{
			int Id_,chose_,correct_chose_;
			stringstream str1num(Id);str1num >> Id_; 
			stringstream str2num(chose);str2num >> chose_; 
			stringstream str3num(correct_chose);str3num >> correct_chose_; 
			        
		    NodeANSWER node;
		    node.Id = Id_;
		    node.chose = chose_;
		    node.corect_chose = correct_chose_;
		    dataAnswers.push_back(node);
		        
			Id = "";
			chose = "";
			correct_chose = "";
			count = 1;	
		}
	    }
	}
	return dataAnswers;
}
