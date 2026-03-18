CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address
LSAN_OPTIONS = detect_leaks=0

# final binary
TARGET = corelib

# all .c files
SRCS = main.c my_malloc.c stack.c queue.c my_string.c

# automatically generate .o names from .c names
OBJS = $(SRCS:.c=.o)

# Run the program
run: $(TARGET)
	LSAN_OPTIONS=detect_leaks=0 ./$(TARGET)

# default target — runs when you just type 'make'
all: $(TARGET)

# link all object files into final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean build artifacts
clean:
	/run/current-system/sw/bin/rm -f $(OBJS) $(TARGET)

# rebuild from scratch
re: clean all

.PHONY: all clean re run
