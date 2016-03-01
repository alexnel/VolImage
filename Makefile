driver: driver.o volimage.o
	g++ -o driver driver.o volimage.o

driver.o: driver.cpp volimage.h
	g++ -c -o volimage.o driver.cpp

database.o: volimage.cpp volimage.h
	g++ -c -o volimage.o volimage.cpp

run:
	./driver

clean:
	rm *.o driver

