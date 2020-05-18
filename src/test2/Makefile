CC = g++
CFLAGS = -std=c++14

LDFLAGS =
LDLIBS = -lncursesw

OBJS = SnakeGame.o UIManager.o GameManager.o GameFlow.o Game.o kbhit.o

TARGET = SnakeGame

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

kbhit.o : kbhit.cpp kbhit.h
	$(CC) -c kbhit.cpp

Game.o : Game.cpp Game.h
	$(CC) -c Game.cpp

GameFlow.o : GameFlow.cpp GameFlow.h kbhit.h
	$(CC) -c GameFlow.cpp

GameManager.o : GameManager.cpp GameManager.h Game.h MapInfo.h
	$(CC) -c GameManager.cpp

UIManager.o : UIManager.cpp UIManager.h kbhit.h Game.h
	$(CC) -c UIManager.cpp

SnakeGame.o : SnakeGame.cpp UIManager.h GameManager.h NcursesSetting.h GameFlow.h
	$(CC) -c SnakeGame.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)