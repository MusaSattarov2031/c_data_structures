# Makefile for C_Data_Structures
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = vector_test
SRCS = main.c vector.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)