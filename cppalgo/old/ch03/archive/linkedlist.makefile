CPP = g++
.SUFFIXES : .o .cpp .c
OFLAG = -o
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<
.c.o :
	$(CPP) $(CPPFLAGS) -c $<

linkedlist: linked_list.cpp linked_list_test.cpp
	$(CPP) $(OFLAG) linkedlist linked_list.cpp linked_list_test.cpp