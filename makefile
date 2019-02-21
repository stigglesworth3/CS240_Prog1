CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
OBJFILES = program1.o
TARGET = program1
ADDITIONAL = Star


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(ADDITIONAL).cpp $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
