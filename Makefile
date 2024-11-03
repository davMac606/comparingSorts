CFLAGS = -Wall -Werror -Wvla -g
LDFLAGS = -lm

.PHONY: all clean run test debug bench gen_all

sorts = SELECTION INSERTION BUBBLE QUICK MERGE HEAP
sizes = 100 1000 10000 50000 100000

out = main

all: main

run: main
	./main
	
debug: main
	gdb ./main
	
test: main gen_array
	./gen_array $(SIZE) | ./main

memcheck: main
	valgrind ./main
	
bench: gen_array
	hyperfine -S=sh -L sort $(sorts) -L size $(sizes) './gen_array {size} | ./{sort}'

main: main.o methods.o
	gcc $(CFLAGS) main.o methods.o -D $(SORT) -o $(out) $(LDFLAGS)

gen_all:
	for sort in $(sorts); do \
		make -B main SORT=$$sort out=$$sort; \
	done

main.o: main.c methods.h
	gcc $(CFLAGS) -c main.c -D $(SORT) $(LDFLAGS) 

gen_array: gen_array.c
	gcc $(CFLAGS) gen_array.c -o gen_array $(LDFLAGS)

methods.o: methods.c methods.h basics.h
	gcc $(CFLAGS) -c methods.c  -D $(SORT) $(LDFLAGS) 
	
clean:
	rm -f main *.o $(sorts)
