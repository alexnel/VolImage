//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"
using namespace std;
namespace NLXALE001 {

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
		string filename = baseName + to_string(j) + ".raw";	//FIX!! conversion of j to string	
		ifstream file (filename, ios::binary);

		unsigned char ** arr;
		arr = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			arr[i] = new unsigned char[width];
			
			file.read(arr[i], width);
		}
		
		
		
	}//end for j
		
	}
	
	// compute difference map and write out;  define in .cpp
	void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)	{
	
		//(unsigned char)(abs((float)volume[i][r][c] - (float)volume[j][r][c])/2)	
	
	}

	// extract slice sliceId and write to output - define in .cpp
	void VolImage::extract(int sliceId, std::string output_prefix)	{
	
	}

	// number of bytes uses to store image data bytes
	//and pointers (ignore vector<> container, dims etc)
	int VolImage::volImageSize(void)	{	// define in .cpp
	
	}

}
