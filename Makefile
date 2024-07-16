CC = gcc
# CFLAGS = -Wall -Wextra -O3 -Iinclude -MMD -MP
OPT = -O2
CFLAGS = -Wall -Wextra -g -Iinclude $(OPT)

# dirs
BINDIR = bin
OBJDIR = obj
LIBDIR = lib
SRCDIR = src
INCDIR = include
TESTDIR = test

TARGETS = show-wifi-key submit score-histogram nameList mklib

# default target
all: $(foreach T, $(TARGETS), $(BINDIR)/$(T))

# linking executable
$(BINDIR)/show-wifi-key: $(OBJDIR)/show-wifi-key.o $(OBJDIR)/readLine.o
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/submit: $(OBJDIR)/submit.o $(OBJDIR)/readLine.o
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/score-histogram: $(OBJDIR)/score-histogram.o $(OBJDIR)/readLine.o
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/nameList: $(OBJDIR)/nameList.o $(OBJDIR)/readLine.o $(OBJDIR)/store.o
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/mklib: $(OBJDIR)/mklib.o
	$(CC) $(CFLAGS) -o $@ $^

# compiling source
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# compiling library
$(OBJDIR)/%.o: $(LIBDIR)/%.c $(INCDIR)/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

# clean binary
clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*

# remake
remake: clean all

# unit test
test: $(BINDIR)/test
	@bin/test

$(BINDIR)/test: $(OBJDIR)/main.o $(OBJDIR)/sort.o $(OBJDIR)/sort_test.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean remake test
