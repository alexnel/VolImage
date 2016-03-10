//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"

using namespace std;
using namespace NLXALE001;

int main(int argc, char* argv[]) {
	
	string baseName = string(argv[1]);
	
	VolImage v;
	bool complete = v.readImages(baseName);
	if (complete == false) { 	return 0;	} //if something failed, exit

	
	if(string(argv[2])=="-d")	{	//-d flag, send to diffmap
		istringstream iss(argv[3]);
		int i;
		iss >> i;
		istringstream is(argv[4]);
		int j;
		is >> j;
		string out = string(argv[5]);
		
		v.diffmap(i, j, out);
	}
	else if(string(argv[2])=="-x")	{	//-x flag, send to extract
		istringstream iss1(argv[3]);
		int i2;
		iss1 >> i2;
		string out2 = string(argv[4]);
		
		v.extract(i2, out2);
	}
	else if(string(argv[2])=="-g")	{	//-x flag, send to extract
		istringstream iss2(argv[3]);
		int i1;
		iss2 >> i1;
		string out3 = string(argv[4]);
		
		v.extra(i1, out3);
	}
	else				{	//no flag
		v.volImageSize();
	}
	return 0;
}
