CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++11
OBJFILES = program1.o
TARGET = program1
STAR = Star
PLANET = Planet
VECTOR = Vector
LIST = List
VALGRIND = valgrind --leak-check=yes

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(STAR).cpp $(PLANET).cpp $(VECTOR).cpp $(LIST).cpp $(LDFLAGS)

memcheck: $(VALGRIND) $(TARGET)
	

clean:
	rm -f $(OBJFILES) $(TARGET) *~
