CC = g++
CFLAGS =

LDFLAGS =
LDLIBS = -lncurses

OBJS = input.o game.o gameLoader.o main.o

TARGET = project

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

input.o : input.cpp input.h
	$(CC) -c input.cpp


gameLoader.o : gameLoader.cpp gameLoader.h
	$(CC) -c gameLoader.cpp

main.o : main.cpp gameLoader.h
	$(CC) -c main.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)
test :
	$(CC) -o test test.cpp $(LDLIBS)
	./test
	rm test
