#include <iostream>
#include <vector>
#include <conio.h>
#include <string.h>
#include <string>

#include "APIGETDATA.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
void inputClass(){
	vector<variable> VARIABLE;
    string MALOP;
    string TENLOP;
    
    cout << "nhap MALOP: ";
	getline (cin,MALOP);
	
    cout << "nhap TENLOP: ";
	getline (cin,TENLOP);
    
    variable da1 = {"MALOP", MALOP};
    variable da2 = {"TENLOP", TENLOP};
    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    
    if(addClass(VARIABLE) == true){
	   cout << "da them thanh cong" << endl;
	}
	
	VARIABLE.clear();
}

void showlistClass(){
    
    vector<NodeCLASS> getdata ;
    
    getdata = showAllClass();
    
    for(int i=0; i < getdata.size(); i++){
	    cout << "MALOP: " << getdata[i].MALOP ;
	    cout << "\t" << "TENLOP: " << getdata[i].TENLOP << endl;
	}
	
	getdata.clear();

}

void updateOneClass(){
	
	
    vector<variable> VARIABLE;
    string MALOP,EDITMALOP,EDITTENLOP;
    
	cout << "nhap MALOP can sua: ";
	getline (cin,MALOP);
	
	cout << "sua TENLOP : ";
	getline (cin,EDITTENLOP);
	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"EDITTENLOP", EDITTENLOP};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	
	if(updateClass(VARIABLE) == true){
	   cout << "da sua thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};

}

void  deleteOneClass(){
    
    vector<variable> VARIABLE;
    string MALOP;
    
	cout << "nhap MALOP: ";
	getline (cin,MALOP);
	
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	
	if(deleteClass(VARIABLE) == true){
	   cout << "da xoa thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};
}

///////////////////////////////////////////////////////////

void insertStudent(){
	
    vector<variable> VARIABLE;
    string MALOP,MASV,HOTEN,PHAI,PASSWORD;
    
	cout << "nhap MALOP: ";
	getline (cin,MALOP);
	
	cout << "nhap MASV: ";
	getline (cin,MASV);
	
	cout << "nhap HOTEN: ";
	getline (cin,HOTEN);
	
	cout << "nhap PHAI: ";
	getline (cin,PHAI);
	
	cout << "nhap PASSWORD: ";
	getline (cin,PASSWORD);
	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"HOTEN", HOTEN};
	variable da4 = {"PHAI", PHAI};
	variable da5 = {"PASSWORD", PASSWORD};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	VARIABLE.push_back(da5);
	
	if(addStudent(VARIABLE) == true){
	    cout << "da them sv";
	};
	
}

void showlistStudent(){
	vector<variable> VARIABLE;
    string MALOP;
    
	cout << "nhap MALOP: ";
	getline (cin,MALOP);
	
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);

    vector<NodeSTUDENT> getdata ;
    
    getdata = showAllStudent(VARIABLE);
    
    for(int i=0; i < getdata.size(); i++){
	    cout << "MASV: " << getdata[i].MASV;
	    cout << "\t" << "HOTEN: " << getdata[i].HOTEN << endl;
	    cout << "\t" << "PASS: " << getdata[i].PASSWORD << endl;
	}
}

void deleteOneStudent(){
    vector<variable> VARIABLE;
    string MALOP,MASV;
    
	cout << "nhap MALOP: ";
	getline (cin,MALOP);
	cout << "nhap MASV: ";
	getline (cin,MASV);
	
	variable da1 = {"MALOP", MALOP};
	VARIABLE.push_back(da1);
	variable da2 = {"MASV", MASV};
	VARIABLE.push_back(da2);
	
	if(deleteStudent(VARIABLE) == true){
	    cout<< "da xoa sv";
	}else{
		cout << "fail";
	}

}





void updateOneStudent(){
	
	
    vector<variable> VARIABLE;
    string MALOP,MASV,EDITHOTEN,EDITPHAI,EDITPASSWORD;
    
	cout << "nhap MALOP : ";
	getline (cin,MALOP);
	
	cout << "nhap MASV can sua: ";
	getline (cin,MASV);
	
	cout << "sua HOTEN : ";
	getline (cin,EDITHOTEN);

	cout << "sua PHAI : ";
	getline (cin,EDITPHAI);
	
	cout << "sua PASS : ";
	getline (cin,EDITPASSWORD);
	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"EDITHOTEN", EDITHOTEN};
	variable da4 = {"EDITPHAI", EDITPHAI};
	variable da5 = {"EDITPASSWORD", EDITPASSWORD};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	VARIABLE.push_back(da5);
	
	if(updateStudent(VARIABLE) == true){
	   cout << "da sua SV thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};

}



void insertOneScore(){
	
	vector<variable> VARIABLE;
    string MALOP,MASV,MAMH,DIEM;
    
	cout << "nhap MALOP : ";
	getline (cin,MALOP);
	
	cout << "nhap MASV : ";
	getline (cin,MASV);
	
	cout << "nhap MAMH : ";
	getline (cin,MAMH);

	cout << "nhap DIEM : ";
	getline (cin,DIEM);

	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	variable da3 = {"MAMH", MAMH};
	variable da4 = {"DIEM", DIEM};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	VARIABLE.push_back(da3);
	VARIABLE.push_back(da4);
	
	if(addScore(VARIABLE) == true){
	   cout << "da them diem thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};
}

void showlistdiem(){
	vector<variable> VARIABLE;
	string MALOP,MASV;
    
	cout << "nhap MALOP : ";
	getline (cin,MALOP);
	
	cout << "nhap MASV : ";
	getline (cin,MASV);
	
	variable da1 = {"MALOP", MALOP};
	variable da2 = {"MASV", MASV};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	
	vector<NodeSCORE> getdata ;
    
    getdata = showAllScore(VARIABLE);
    
    for(int i=0; i < getdata.size(); i++){
	    cout << "MAMH: " << getdata[i].MAMH;
	    cout << "\t" << "DIEM: " << getdata[i].DIEM << endl;
	}
}

void insertsubject(){
	vector<variable> VARIABLE;
    string MAMH;
    string TENMH;
    
    cout << "nhap MAMH: ";
	getline (cin,MAMH);
	
    cout << "nhap TENMH: ";
	getline (cin,TENMH);
    
    variable da1 = {"MAMH", MAMH};
    variable da2 = {"TENMH", TENMH};
    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    
    if(addSubject(VARIABLE) == true){
	   cout << "da them thanh cong" << endl;
	}
	
	VARIABLE.clear();
}

void showlistsubject(){
    vector<NodeSUBJECT> getdata ;
    
    getdata = showAllSubject();
    
    for(int i=0; i < getdata.size(); i++){
	    cout << "MAMH: " << getdata[i].MAMH ;
	    cout << "\t" << "TENMH: " << getdata[i].TENMH << endl;
	}
	
	getdata.clear();
}

void updatesubject(){
    vector<variable> VARIABLE;
    string MAMH,EDITTENMH;
    
	cout << "nhap MAMH can sua: ";
	getline (cin,MAMH);
	
	cout << "sua TENMH : ";
	getline (cin,EDITTENMH);
	
	variable da1 = {"MAMH", MAMH};
	variable da2 = {"EDITTENMH", EDITTENMH};
	VARIABLE.push_back(da1);
	VARIABLE.push_back(da2);
	
	if(updateSubject(VARIABLE) == true){
	   cout << "da sua thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};
}


void  deletesubject(){
    
    vector<variable> VARIABLE;
    string MAMH;
    
	cout << "MAMH : ";
	getline (cin,MAMH);
	
	variable da1 = {"MAMH", MAMH};
	VARIABLE.push_back(da1);
	
	if(deleteSubject(VARIABLE) == true){
	   cout << "da xoa thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};
}

void insertquestion(){
	vector<variable> VARIABLE;
	
    string MAMH;
    string NOIDUNG;
    string A;
    string B;
    string C;
    string D;
    string ANSWER;
    
    cout << "nhap MAMH: ";
	getline (cin,MAMH);
	
	cout << "nhap NOIDUNG: ";
	getline (cin,NOIDUNG);
	
	cout << "nhap A: ";
	getline (cin,A);
	
	cout << "nhap B: ";
	getline (cin,B);
	
	cout << "nhap C: ";
	getline (cin,C);
	
	cout << "nhap D: ";
	getline (cin,D);
	
	cout << "nhap ANSWER: ";
	getline (cin,ANSWER);
	
    
    variable da1 = {"MAMH",MAMH };
        variable da2 = {"NOIDUNG", NOIDUNG};
            variable da3 = {"A", A};
                variable da4 = {"B", B};
                    variable da5 = {"C", C};
                        variable da6 = {"D", D};
                        variable da7 = {"ANSWER", ANSWER};

    VARIABLE.push_back(da1);
    VARIABLE.push_back(da2);
    VARIABLE.push_back(da3);
    VARIABLE.push_back(da4);
    VARIABLE.push_back(da5);
    VARIABLE.push_back(da6);
    VARIABLE.push_back(da7);
    
    if(addQuestion(VARIABLE) == true){
	   cout << "da them thanh cong" << endl;
	}
	
	VARIABLE.clear();
}

void showlistquestion(){
    vector<NodeQUESTION> getdata ;
    vector<variable> VARIABLE;
	
    string MAMH;
    
        cout << "nhap MAMH: ";
	getline (cin,MAMH);
    variable da1 = {"MAMH",MAMH };
    VARIABLE.push_back(da1);
    
    getdata = showAllQuestion(VARIABLE);
    
    for(int i=0; i < getdata.size(); i++){
	    cout << "Id: " << getdata[i].Id ;
	    cout << "\t" << "NOIDUNG: " << getdata[i].NOIDUNG << endl;
	}
	
	getdata.clear();
}

void deletequestion(){
    vector<variable> VARIABLE;
    string Id;
    cout << "nhap Id: ";
	getline (cin,Id);
	
	variable da1 = {"Id",Id };
    VARIABLE.push_back(da1);
	
	if(deleteQuestion(VARIABLE) == true){
	    cout<< "da xoa cau hoi";
	}else{
		cout << "fail";
	}
	
	VARIABLE.clear();
}

void updatequestion(){
    vector<variable> VARIABLE;
    string MAMH;
    string NOIDUNG;
    string A;
    string B;
    string C;
    string D;
    string ANSWER;
    string Id;
    
    cout << "nhap Id: ";
	getline (cin,Id);
    
	
	cout << "nhap NOIDUNG: ";
	getline (cin,NOIDUNG);
	
	cout << "nhap A: ";
	getline (cin,A);
	
	cout << "nhap B: ";
	getline (cin,B);
	
	cout << "nhap C: ";
	getline (cin,C);
	
	cout << "nhap D: ";
	getline (cin,D);
	
	cout << "nhap ANSWER: ";
	getline (cin,ANSWER);
	

        variable da2 = {"NOIDUNG", NOIDUNG};
            variable da3 = {"A", A};
                variable da4 = {"B", B};
                    variable da5 = {"C", C};
                        variable da6 = {"D", D};
                        variable da7 = {"ANSWER", ANSWER};
                        variable da8 = {"Id", Id};
           

    VARIABLE.push_back(da2);
    VARIABLE.push_back(da3);
    VARIABLE.push_back(da4);
    VARIABLE.push_back(da5);
    VARIABLE.push_back(da6);
    VARIABLE.push_back(da7);       
	VARIABLE.push_back(da8);       
	
	if(updateQuestion(VARIABLE) == true){
	   cout << "da sua cau hoi thanh cong " <<endl;
	}else{
		cout << "fail" << endl;
	};
}






void chosework(){
    cout << endl <<" 1.them lop" << endl << " 2.in danh sach lop" << endl << " 3.xoa mot lop" << endl << " 4.chinh sua mot lop" << endl << " 5.them sv" << endl << " 6.in danh sach sv" << endl  << " 7.xoa sv" << endl
	<< " 8.sua sv" << endl << " 9.them diem" << endl << " a.danh sach diem" << endl  << " b.them mon hoc" << endl << " c.ds mon hoc" << endl
	<< " d.them cau hoi" << endl << " e.ds cau hoi" << endl << " f.xoa cau hoi" << endl << " j.sua cau hoi" << endl
	<< " h.sua mon hc" << endl << " l.xoa mon hc" << endl << "ban chon: " ;
}


int main() {
	
	
	LoadDatabase();
    
	
    cout << "\t" <<"CHUONG TRINH" << endl;
    chosework();

    while(true){
    	
    	char c = getch();
    	if(c == '1'){
    		
    		cout << endl << endl;

    		
    		inputClass();
    		chosework();

		}else if(c == '2'){
			
    		cout << endl <<endl;
    		
    		showlistClass();
            chosework();
            
		}else if(c == '3'){
		     
		    cout << endl <<endl;
		    
		    deleteOneClass();
            chosework();
		    
		}else if(c == '4'){
			cout << endl <<endl;
		    
		    updateOneClass();
		    
            chosework();
		}else if(c == '5'){
			cout << endl <<endl;
		    
		    insertStudent();
		    
            chosework();
		}else if(c == '6'){
			cout << endl <<endl;
		    
		    showlistStudent();
		    
            chosework();
		}else if(c == '7'){
			cout << endl <<endl;
		    
		    deleteOneStudent();
		    
            chosework();
		}else if(c == '8'){
			cout << endl <<endl;
		    
		    updateOneStudent();
		    
            chosework();
		}
		else if(c == '9'){
			cout << endl <<endl;

		    insertOneScore();
		    
            chosework();
		}else if(c == 'a'){
			cout << endl <<endl;
		    
		    showlistdiem();
		    
            chosework();
		}else if(c == 'b'){
			cout << endl <<endl;
		    
		    insertsubject();
		    
            chosework();
		}else if(c == 'c'){
			cout << endl <<endl;
		    
		    showlistsubject();
		    
            chosework();
		}else if(c == 'd'){
			cout << endl <<endl;
		    
		    insertquestion();
		    
            chosework();
		}else if(c == 'e'){
			cout << endl <<endl;
		    
		    showlistquestion();
		    
            chosework();
		}else if(c == 'f'){
			cout << endl <<endl;
		    
		    deletequestion();
		    
            chosework();
		}else if(c == 'j'){
			cout << endl <<endl;
		    
		    updatequestion();
		    
            chosework();
		}else if(c == 'h'){
			cout << endl <<endl;
		    
		    updatesubject();
		    
            chosework();
		}else if(c == 'l'){
			cout << endl <<endl;
		    
		    deletesubject();
		    
            chosework();
		}
	}
    
   
  
  return 0;
}


