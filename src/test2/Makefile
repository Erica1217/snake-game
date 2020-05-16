CC = g++
CFLAGS = -std=c++14

LDFLAGS =
LDLIBS = -lncurses

OBJS = SnakeGame.o WindowManager.o

TARGET = SnakeGame

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

input.o : input.cpp input.h
	$(CC) -c input.cpp


WindowManager.o : WindowManager.cpp WindowManager.h
	$(CC) -c WindowManager.cpp

SnakeGame.o : SnakeGame.cpp WindowManager.h NcursesSetting.h
	$(CC) -c SnakeGame.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)
test :
	$(CC) -o test test.cpp $(LDLIBS)
	./test
	rm test
