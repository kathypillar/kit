CC = g++
main: kit.o
	$(CC) -o kit kit.o
install: kit.o
	$(CC) -o kit kit.o
	if [ -d "/usr/share/kit" ]; then echo; else sudo mkdir /usr/share/kit; fi
	sudo cp ./kitrc /usr/share/kit/kitrc
	sudo cp ./kit /usr/local/bin/kit
run: kit.o
	$(CC) -o kit kit.o
	./kit
