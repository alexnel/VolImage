//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"

using namespace std;
using namespace NLXALE001;

int main(int argc, char* argv[]) {
	
	string baseName = string(argv[0]);
	
	VolImage v;
	v.readImages(baseName);
	
	if(string(argv[1])=="-d")	{	//-d flag, send to diffmap
		istringstream iss(argv[2]);
		int i;
		iss >> i;
		istringstream is(argv[3]);
		int j;
		is >> j;
		string out = string(argv[4]);
		
		v.diffmap(i, j, out);
	}
	else if(string(argv[1])=="-x")	{	//-x flag, send to extract
		istringstream iss1(argv[2]);
		int i2;
		iss1 >> i2;
		string out2 = string(argv[3]);
		
		v.extract(i2, out2);
	}
	else				{	//no flag
		
	}
	
}
