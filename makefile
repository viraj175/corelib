CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = corelib

SRCS = src/my_malloc.c src/my_string.c src/stack.c src/queue.c src/main.c
OBJS = $(SRCS:.c=.o)

run: $(TARGET)
	./$(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
	/run/current-system/sw/bin/rm -f $(OBJS) $(TARGET)

re: clean all

.PHONY: all clean re
