CFLAGS = -Wall -Werror -Wvla -g
LDFLAGS = -lm

.PHONY: all clean run test debug bench

all: main
	
run: main
	./main
	
debug: main
	gdb ./main
	
memcheck: main
	valgrind ./main
	
bench: main
	hyperfine -S=sh -w=10 -p='sync; echo 3 | sudo tee /proc/sys/vm/drop_mains' -P file 1 5 './main < testes/grande{file}.in'

main: main.o methods.o
	gcc $(CFLAGS) main.o methods.o -o main $(LDFLAGS)

main.o: main.c methods.h
	gcc $(CFLAGS) -c main.c $(LDFLAGS) 

methods.o: methods.c methods.h basics.h
	gcc $(CFLAGS) -c methods.c $(LDFLAGS) 
	
clean:
	rm -f main *.o
