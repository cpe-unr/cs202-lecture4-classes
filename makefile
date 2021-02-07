cats: main.o cat.o
	g++ -std=c++11 -o cats main.o cat.o

main.o: main.cpp cat.h
	g++ -std=c++11 -c main.cpp

cat.o: cat.cpp cat.h
	g++ -std=c++11 -c cat.cpp

clean:
	rm *.o cats