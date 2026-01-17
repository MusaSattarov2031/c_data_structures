CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = list_test
SRCS = main.c linked_list.c

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)
clean:
	rm -f $(TARGET)