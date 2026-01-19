CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = doubly_list_test
SRCS = main.c doubly_linked_list.c

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

rerun:clean all run