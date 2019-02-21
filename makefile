CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
TARGET = program1
ADDITIONAL = Star


all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
