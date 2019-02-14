CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
OBJFILES = lab2.o
TARGET = lab2
ADDITIONAL = Star


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(ADDITIONAL).cpp $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
