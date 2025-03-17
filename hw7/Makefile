CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra -g # standard flags from previous Makefiles + -g for debugging
TARGET = main
TEST_TARGET = main_test
SOURCES = main.c
TEST_SOURCES = main_test.c main.c
OBJECTS = $(SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
HEADERS = main.h

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -o $(TEST_TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET) $(TEST_TARGET) 

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run test