#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "ACCESSFILE.h"
#include "QUESTION.h"

using namespace std;

#ifndef DATAEXAM_H
#define DATAEXAM_H

	struct NodeANSWER{
        int Id;
        int chose = 0;
        int corect_chose;
	};

class DATAEXAM{ 
	public: 
        bool InsertDatabase(string MAMH,string MALOP,string MASV,string SCORE,string TIME,string TOTAL,vector<NodeANSWER> listAnswer);
        vector<NodeANSWER> getDatabase(string MAMH,string MASV,string LANTHI);
};

#endif
