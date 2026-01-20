CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = stack_test
SRCS = main.c stack.c

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

rerun: clean all run