all:
	g++ -Wall -O2 main.cpp
	./a.out

clean:
	rm -f a.out *~