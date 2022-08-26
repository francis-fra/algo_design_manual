# ------------------------------------------------------------
# old
# ------------------------------------------------------------
# VPATH    = include
# CPPFLAGS = -I include

# main_graph: main_graph.o  graph.o
# queue.o : queue.h 
# graph.o: graph.h

# ------------------------------------------------------------
CFLAGS = -I ../../lib -I include
LDFLAGS= -L ../../lib
LIBS = -lfra

main_graph: main_graph.o graph.o queue.o weighted_graph.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

main_graph.o: main_graph.c
	gcc $(CFLAGS) -c $^

queue.o: queue.c
	gcc $(CFLAGS) -c $^

graph.o: graph.c
	gcc $(CFLAGS) -c $^

weighted_graph.o: weighted_graph.c
	gcc $(CFLAGS) -c $^ $(LDFLAGS) $(LIBS)

clean:
	rm *.o


# ------------------------------------------------------------
# gcc -I include -c queue.c
# gcc -I include -c graph.c
# gcc -I ../../lib -I include -c main_graph.c
# gcc -o main_graph main_graph.o graph.o queue.o -L ../../lib -lfra
# ./main_graph < fig5.9.txt