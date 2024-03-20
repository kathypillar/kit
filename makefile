CC = g++
main: kit.o
	$(CC) -o kit kit.o
install: kit.o
	$(CC) -o kit kit.o
run: kit.o
	$(CC) -o kit kit.o
	./kit
