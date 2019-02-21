CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
OBJFILES = program1.o
TARGET = program1
STAR = Star
PLANET = Planet
VECTOR = Vector
LIST = List


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(STAR).cpp $(PLANET).cpp $(VECTOR).cpp $(LIST).cpp $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
