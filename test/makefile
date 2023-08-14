all: main.exe run

main.exe: main.c ../sorting.c
	@clang -Wall -o main.exe main.c ../sorting.c

run: main.exe
	@./main.exe
