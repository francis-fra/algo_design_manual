# ------------------------------------------------------------
# old
# ------------------------------------------------------------
# VPATH    = include
# CPPFLAGS = -I include

# main_graph: main_graph.o  graph.o
# queue.o : queue.h 
# graph.o: graph.h

# ------------------------------------------------------------
CFLAGS = -I ../lib -I include
LDFLAGS= -L ../lib
LIBS = -lfra

main_backtrack: main_backtrack.o search.o 
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

main_backtrack.o: main_backtrack.c
	gcc $(CFLAGS) -c $^

search.o: search.c 
	gcc $(CFLAGS) -c $^

clean:
	rm *.o


# ------------------------------------------------------------
# gcc -I include -c queue.c
# gcc -I include -c graph.c
# gcc -I ../../lib -I include -c main_graph.c
# gcc -o main_graph main_graph.o graph.o queue.o -L ../../lib -lfra
# ./main_graph < fig5.9.txt