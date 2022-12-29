CC=g++
FLAGS=-std=c++2a 

all: tridiagonal.out fourier.out

fourie.out: fourie.o main.o eigenvalues.o
	$(CC) $(FLAGS) -o fourier.out fourier.o main.o eigenvalues.o

tridiagonal.out: tridiagonal.o main.o eigenvalues.o
	$(CC) $(FLAGS) -o tridiagonal.out tridiagonal.o main.o eigenvalues.o


main.o: main.cpp eigenvalues.hpp
	$(CC) $(FLAGS) -c main.cpp

fourier.o: fourier.cpp solve.hpp eigenvalues.hpp
	$(CC) $(FLAGS) -c fourier.cpp

tridiagonal.o: tridiagonal.cpp solve.hpp
	$(CC) $(FLAGS) -c tridiagonal.cpp

eigenvalues.o: eigenvalues.cpp eigenvalues.hpp
	$(CC) $(FLAGS) -c eigenvalues.cpp

clean:
	rm -rf *.o *.out *.a
