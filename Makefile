VolImage: driver.o volimage.o
	g++ -o VolImage driver.o volimage.o

driver.o: driver.cpp volimage.h
	g++ -c -o driver.o driver.cpp

volimage.o: volimage.cpp volimage.h
	g++ -c -o volimage.o volimage.cpp

run:
	./VolImage

clean:
	rm *.o VolImage

