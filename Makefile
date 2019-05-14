CXX=g++
CXXFLAGS=-O2 -Wall -pedantic -std=c++14
LIBS=

program05:	main.o	funkcje.o
		$(CXX) -o program05 main.o funkcje.o $(CXXFLAGS) $(LIBS)
main.o:	main.cpp funkcje.hpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
funkcje.o:	funkcje.cpp funkcje.hpp
		$(CXX) -o funkcje.o -c funkcje.cpp $(CXXFLAGS)
clean:
		rm *.o
