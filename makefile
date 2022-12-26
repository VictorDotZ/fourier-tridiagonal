CC=g++
FLAGS=-std=c++2a 

all: tridiagonal.out fourie.out

fourie.out: fourie.o main.o eigenvalues.o
	$(CC) $(FLAGS) -o fourie.out fourie.o main.o eigenvalues.o

tridiagonal.out: tridiagonal.o main.o eigenvalues.o
	$(CC) $(FLAGS) -o tridiagonal.out tridiagonal.o main.o eigenvalues.o


main.o: main.cpp eigenvalues.hpp
	$(CC) $(FLAGS) -c main.cpp

fourie.o: fourie.cpp solve.hpp eigenvalues.hpp
	$(CC) $(FLAGS) -c fourie.cpp

tridiagonal.o: tridiagonal.cpp solve.hpp
	$(CC) $(FLAGS) -c tridiagonal.cpp

eigenvalues.o: eigenvalues.cpp eigenvalues.hpp
	$(CC) $(FLAGS) -c eigenvalues.cpp

clean:
	rm -rf *.o *.out *.a