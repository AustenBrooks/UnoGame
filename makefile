CC = g++
CFLAG = -std=c++11 -Wall
test: main.o card.o gameManager.o
	$(CC) main.o card.o gameManager.o -o test

main.o: main.cpp card.h gameManager.h
	$(CC) -c main.cpp $(CFLAG)

card.o: card.cpp card.h gameManager.h
	$(CC) -c card.cpp $(CFLAG)

gameManager.o: gameManager.cpp gameManager.h
	$(CC) -c gameManager.cpp $(CFLAG)

clean:
	rm *.o test