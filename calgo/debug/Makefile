CFLAGS = -I ../lib -I include
# CFLAGS = -I include
LDFLAGS= -lfra

main: main.o queue.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c
	gcc $(CFLAGS) -c $^

queue.o: queue.c
	gcc $(CFLAGS) -c $^

clean:
	rm *.o

# gcc -I ../lib -I include -c main.c
# gcc -I ../lib -I include -c queue.c
# gcc -o main main.o queue.o -lfra
# ./main