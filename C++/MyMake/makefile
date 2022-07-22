all: hello
hello: hello.o hello2.o
	gcc -o hello hello.o hello2.o

hello.o: hello.c
	gcc -c hello.c

hello2.o: hello2.c
	gcc -c hello2.c

clean: 	
	rm hello.o hello2.o

