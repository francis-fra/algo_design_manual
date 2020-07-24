CPP = g++
.SUFFIXES : .o .cpp .c
OFLAG = -o
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<
.c.o :
	$(CPP) $(CPPFLAGS) -c $<

sort_test: sort_test.cpp
	$(CPP) $(OFLAG) sort_test sort_test.cpp