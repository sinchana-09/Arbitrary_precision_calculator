CC = gcc
CFLAGS = -Wall
TARGET = apc

SRCS = main.c add.c sub.c mul.c div.c apc.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)