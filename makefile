CC=gcc

CFLAGS=-std=c11 -Wall -O2 -g

TARGET=parser

SOURCES=main.c stack.c queue.c rpn.c sy.c

OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c stack.h queue.h rpn.h sy.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean