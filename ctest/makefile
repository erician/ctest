.PHONY: clean 
default: ctest_main.o

SRCDIR = src
OBJDIR = obj
TESTDIR = test

INCLUDEDIR = include

# Define the tools we are going to use
CC= gcc
LD = gcc
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -ansi
CFLAGS += -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR)/internal
LIBS = -lm -lc -lpthread

# OBJS can deal with either .cc or .c 
OBJS = $(OBJDIR)/ctest_testsuit.o
OBJS += $(OBJDIR)/ctest_main.o

JUNK = *~ $(OBJDIR)/*.o $(OBJDIR)/*.a $(OBJDIR)/*_test 

$(OBJDIR)/ctest_main.o: $(SRCDIR)/ctest_main.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/ctest_testsuit.o: $(SRCDIR)/ctest_testsuit.c
	$(CC) $(CFLAGS) -c -o $@ $<

# the next is test
assert-test: $(OBJDIR)/ctest_assert_test
	./$(OBJDIR)/ctest_assert_test
$(OBJDIR)/ctest_assert_test: $(OBJDIR)/ctest_assert_test.o $(OBJS)
	$(LD) -o $@  $^  $(LIBS)
$(OBJDIR)/ctest_assert_test.o: $(TESTDIR)/ctest_assert_test.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(JUNK)