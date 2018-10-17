executable: Main.o DataType.o SortedLinkedList.o
	g++ Main.o DataType.o SortedLinkedList.o -o main

run: main
	./main test.txt

Main.o: Main.cpp
	g++ -c Main.cpp

DataType.o: DataType.cpp
	g++ -c DataType.cpp

SortedLinkedList.o: SortedLinkedList.cpp
	g++ -c SortedLinkedList.cpp

clean:
	rm *.o main