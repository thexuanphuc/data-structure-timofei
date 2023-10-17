# purpose : prerequisite
# 	action 1
# 	action 2
#the header file need to be created manually
all : main.exe
main.exe : main.o mylibrary.o #this is linking process
	g++ -o main.exe main.o mylibrary.o

main.o : main.cpp mylibrary.h
	g++ -c main.cpp

mylibrary.o : mylibrary.cpp mylibrary.h
	g++ -c mylibrary.cpp
clean:
	rm -f *.o main.exe
