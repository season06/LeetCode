CC = g++
CFLAGS = -c -Wall -std=c++11 

SOURCES = main.cpp
TARGET = main
OBJECTS = $(SOURCES:.cpp=.o)

# define the build target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
