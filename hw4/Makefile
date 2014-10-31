CC=g++
CFLAGS= -ansi -O2 

TARGET=main
HEADERS=element.h word.h dict.h
SOURCES=main.cpp word.cpp dict.cpp 

all:	$(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

