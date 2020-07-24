CPP = g++
.SUFFIXES : .o .cpp .c
OFLAG = -o
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<
.c.o :
	$(CPP) $(CPPFLAGS) -c $<

linked_list_tpl_test: linked_list_tpl_test.cpp 
	$(CPP) $(OFLAG) linked_list_tpl_test linked_list_tpl_test.cpp