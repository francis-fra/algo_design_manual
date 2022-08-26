CFLAGS = -I ../../lib -I include
LDFLAGS= -L ../../lib
LIBS = -lfra

main_union: main_union.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)