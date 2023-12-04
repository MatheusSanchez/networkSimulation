CC=g++

all:
	$(CC) *.cpp -o main

run: all
	./main

clean:
	rm main
