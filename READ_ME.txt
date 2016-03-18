NLXALE001
Alex Nel

To build file:
Run 'make' from terminal in given directory

To run file:
To extract file:
			./VolImage <imageBase> -x slideID output_file_name
To diffmap file:
			./VolImage <imageBase> -d sliceIDi sliceIDj output_file_name
To extract imgage along rows for all slices:
			./VolImage <imageBase> -g rowID
To determine the number of bytes used and number of images:
			./VolImage <imageBase>


where 	<imageBase> is  the  the prefix for the file sequence
	output_file_name is the file that the results will be written to
	sliceID is th enumber of the slice you wish to extract
	sliceIdi and sliceIDj are the number of the images to be compared
	rowID is the row you wish to extract



Files must be placed in the root directory, not in a different file.

My program is made up of three files: driver.cpp, volimage.cpp and volimage.h
