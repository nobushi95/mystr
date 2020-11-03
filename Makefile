all:
	clang++ -Wall -O2 main.cpp
	./a.out

clean:
	rm -f a.out *~