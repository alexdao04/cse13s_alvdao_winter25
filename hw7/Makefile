CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

# makefile from hw6 was used as a reference for this makefile.

all: main_test main

main: main.o
	$(CC) main.o -o main

main_test: main.o main_test.o
	$(CC) main.o main_test.o -o main_test

main_test.o: main_test.c
	$(CC) $(CFLAGS) -c main_test.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.quit

clean:
	rm -f main.o main_test.o main main_test

format:
	clang-format -i -style=file *.[ch]
