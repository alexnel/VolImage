//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"

namespace NLXALE001 {

using namespace std;

	VolImage::VolImage()	{	// default constructor - define in .cpp
	
	}
	VolImage::~VolImage()	{	// destructor - define in .cpp file
	
	}
	
	// populate the object with images in stack and
	//set member variables define in .cpp
	bool VolImage::readImages(std::string baseName)	{
	
	//open heqader and extract data
	string headerfile = baseName + ".data";
	ifstream infile;
	infile.open(headerfile.c_str());
	string line;
	int num;
	getline(infile, line);
	istringstream iss(line);
	iss >> width >> height >> num;

	
	for (int j = 0; j<num; j++)
	{
		stringstream ss;
    		ss << j;
		
   		string str;
    		ss >> str;
		
		string filename = baseName + str + ".raw";	
		ifstream file (filename.c_str(), ios::binary);

		unsigned char ** arr;
		arr = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			arr[i] = new unsigned char[width];
			
			file.read((char *)arr[i], width);
		}
		
		slices.push_back(arr);
		
	}//end for j
		
	}
	
	// compute difference map and write out;  define in .cpp
	void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)	{
	
		//(unsigned char)(abs((float)volume[i][r][c] - (float)volume[j][r][c])/2)	
	
	}

	// extract slice sliceId and write to output - define in .cpp
	void VolImage::extract(int sliceId, std::string output_prefix)	{
		string outname = output_prefix + ".raw";

		ofstream out;	
				
		for (int i = 0; i < height; ++i) {			
			out.write((char *)slices[sliceId][i], width);
		}	

	}

	// number of bytes uses to store image data bytes
	//and pointers (ignore vector<> container, dims etc)
	int VolImage::volImageSize(void)	{	// define in .cpp
	
	}

}
