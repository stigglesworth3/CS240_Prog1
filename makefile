CC = g++
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++11
OBJFILES = lab4.o
TARGET = lab4
VALGRIND = valgrind --leak-check=yes

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LDFLAGS)

memcheck: 
	valgrind -—leak-check=yes ./lab4
	

clean:
	rm -f $(OBJFILES) $(TARGET) *~

run:
	./$(TARGET)