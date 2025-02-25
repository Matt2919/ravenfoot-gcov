# Makefile
CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -g -00 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address

a.out: main.o Vector.o VectorGPT.o VectorSTD.o
	$(CC) -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-parameter -std=c++17 -g -O2 -fmax-errors=1 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address main.cc Vector.cc VectorGPT.cc VectorSTD.cc

main.o: main.cc
	$(CC) -c main.cc

Vector.o: Vector.cc
	$(CC) -c Vector.cc

VectorGPT.o: VectorGPT.cc
	$(CC) -c VectorGPT.cc

VectorSTD.o: VectorSTD.cc
	$(CC) -c VectorSTD.cc

clean:
	rm -f a.out core *.o
