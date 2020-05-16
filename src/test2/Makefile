CC = g++
CFLAGS = -std=c++14

LDFLAGS =
LDLIBS = -lncurses

OBJS = SnakeGame.o UIManager.o GameManager.o

TARGET = SnakeGame

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS) $(CFLAGS)

GameManager.o : GameManager.cpp GameManager.h
	$(CC) -c GameManager.cpp

UIManager.o : UIManager.cpp UIManager.h
	$(CC) -c UIManager.cpp

SnakeGame.o : SnakeGame.cpp UIManager.h NcursesSetting.h
	$(CC) -c SnakeGame.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET)
test :
	$(CC) -o test test.cpp $(LDLIBS)
	./test
	rm test
