CC = g++
main: kit.o
	$(CC) -o kit kit.o
install: kit.o
	$(CC) -o kit kit.o
	if [ -d "~/.kit" ]; then mkdir ~/.kit; fi
	cp ./kitrc ~/.kit/kitrc
	sudo cp ./kit /usr/local/bin/kit
run: kit.o
	$(CC) -o kit kit.o
	./kit
