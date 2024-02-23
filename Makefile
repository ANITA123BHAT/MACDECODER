# make file for compilation in one short
#compiler
CXX=g++

#compiler flag
CXXFLAG=-Wall

all:target

target: main.o mac_decoder.o
	$(CXX) $(CXXFLAG) main.cpp mac_decoder.cpp -o target

main.o:main.cpp
	$(CXX) $(CXXFLAG) -c  main.cpp -o main.o

mac_decoder.o : mac_decoder.cpp
	$(CXX) $(CXXFLAG) -c mac_decoder.cpp -o mac_decoder.o

clean:
	rm -rf *o target
