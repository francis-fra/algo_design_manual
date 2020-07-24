CPP = g++
.SUFFIXES : .o .cpp .c
OFLAG = -o
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<
.c.o :
	$(CPP) $(CPPFLAGS) -c $<

binary_tree_test: binary_tree_test.cpp
	$(CPP) $(OFLAG) binary_tree_test binary_tree_test.cpp