//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	string baseName = string(argv[0]);
	
	if(string(argv[1])=="-d")	{	//-d flag, send to diffmap
		istringstream iss(argv[2]);
		int i;
		iss >> i;
		istringstream iss(argv[3]);
		int j;
		iss >> j;
		string out = string(arg[4]);
		
		diffmap(i, j, out);
	}
	else if(string(argv[1])=="-x")	{	//-x flag, send to extract
		istringstream iss(argv[2]);
		int i2;
		iss >> i2;
		string out2 = string(argv[3]);
		
		extract(i2, out2);
	}
	else				{	//no flag
		
	}
	
}
