CC = g++
CFLAGS =

LDFLAGS =
LDLIBS = -lncurses

OBJS =

TARGET = project

all : $(TARGET)

$(TARGET) : test.cpp
	$(CC) -o $@ $^ $(LDLIBS)

clean :
	rm -rf $(TARGET)
run :
	./$(TARGET)
