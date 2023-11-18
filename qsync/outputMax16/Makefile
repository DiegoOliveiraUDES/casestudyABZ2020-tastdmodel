TARGET = a1
CC = g++
CFLAGS = -std=c++11 -g -Wall -O1

.PHONY: default all clean
default: $(TARGET)
all: default

HEADERS = *.h
OBJECTS = a1.o

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< 

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean: 
	-del /F /Q *.o 2>nul
	-del /F /Q *.h 2>nul
	-del /F /Q *.hpp 2>nul
	-del /F /Q *.cpp 2>nul
	-del /F /Q $(TARGET).exe 2>nul