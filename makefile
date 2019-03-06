CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++11
OBJFILES = program1.o
TARGET = program1
VECTOR = Vector
STARVECTOR = StarVector
STAR = Star
PLANET = Planet
LIST = List

VALGRIND = valgrind --leak-check=yes

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(STAR).cpp $(PLANET).cpp $(LIST).cpp $(VECTOR).cpp $(LDFLAGS)

memcheck:
	valgrind -—leak-check=yes ./lab4


clean:
	rm -f $(OBJFILES) $(TARGET) *~

run:
	./$(TARGET)
