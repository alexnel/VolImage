//Author: NLXALE001
//Project: C++ Assignment 2

#include "volimage.h"
#include <math.h>

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
	cout << headerfile;
	ifstream infile (headerfile.c_str());
	string line;
	if(!infile.is_open()){
		cout << "Error, file not found" << endl;
		return false;
	}
	if(infile.is_open()){
	
		infile >> width;
		infile >> height;
		infile >> num;
	
	}

	
	for (int j = 0; j<num; j++)
	{
		stringstream ss;
    		ss << j;
		
   		string str;
    		ss >> str;
		
		string filename = baseName + str + ".raw";	
		ifstream file (filename.c_str(), ios::binary);
		
		if(!file.is_open()){
			cout << "Error, file not found" << endl;
			return false;
		}

		unsigned char ** arr;
		arr = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			arr[i] = new unsigned char[width];
			
			file.read((char *)arr[i], width);
		}
		
		slices.push_back(arr);
		
	}//end for j
		return true;
	}
	
	// compute difference map and write out;  define in .cpp
	void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)	{
		
		string outname = output_prefix + ".raw";

		ofstream out(outname.c_str());	
		
		unsigned char ** array;
		array = new unsigned char*[height];

		for (int i = 0; i < height; ++i) {
			array[i] = new unsigned char[width];
			
			for (int j = 0; j < width; j++) {
				array[i][j] = (unsigned char)(fabs((float)slices[sliceI][i][j] - (float)slices[sliceJ][i][j])/2);
			}
			
			out.write((char *)array[i], width);
		}
		
		out.close();
	}

	// extract slice sliceId and write to output - define in .cpp
	void VolImage::extract(int sliceId, std::string output_prefix)	{
		string outname = output_prefix + ".raw";

		ofstream out(outname.c_str());	
				
		for (int i = 0; i < height; ++i) {			
			out.write((char *)slices[sliceId][i], width);
		}
		
		out.close();
	}

	// number of bytes uses to store image data bytes
	//and pointers (ignore vector<> container, dims etc)
	void VolImage::volImageSize(void)	{	// define in .cpp
	
		int bytes = width*height*num*1 + height*num*8 + num*8; //arraysize*charsize + pointers + double pointers
		cout << "Number of images: " << num << endl;
		cout << "Number of bytes required: " << bytes << endl;
		
	}

}
