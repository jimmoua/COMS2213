all: yes

yes: expression.o in2post.o
	g++ expression.o in2post.o -std=c++11 -Wall

expression.o:
	g++ -c expression.cpp -Wall -std=c++11

in2post.o:
	g++ -c in2post.cpp -Wall -std=c++11


rm:
	rm *.out *.o
