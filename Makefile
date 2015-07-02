all: example 

CXXFLAGS=	-c -g -O0 -fPIC
CC=gcc

LIBS_SERVER=    -lpthread


.c.o:
	$(CC) $(CXXFLAGS) $<



clean:
	rm -f *.o
	rm -f example


	

