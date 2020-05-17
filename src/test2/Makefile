CC = g++
CFLAGS = -std=c++14

LDFLAGS =
LDLIBS = -lncurses

OBJS = SnakeGame.o UIManager.o GameManager.o GameFlow.o kbhit.o

TARGET = SnakeGame

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

kbhit.o : kbhit.cpp kbhit.h
	$(CC) -c kbhit.cpp

GameFlow.o : GameFlow.cpp GameFlow.h kbhit.h
	$(CC) -c GameFlow.cpp

GameManager.o : GameManager.cpp GameManager.h
	$(CC) -c GameManager.cpp

UIManager.o : UIManager.cpp UIManager.h kbhit.h
	$(CC) -c UIManager.cpp

SnakeGame.o : SnakeGame.cpp UIManager.h GameManager.h NcursesSetting.h GameFlow.h
	$(CC) -c SnakeGame.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)