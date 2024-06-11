CC = gcc
# CFLAGS = -Wall -Wextra -O3 -Iinclude -MMD -MP
CFLAGS = -Wall -Wextra -O3 -Iinclude

# dirs
BINDIR = bin
OBJDIR = obj
LIBDIR = lib
SRCDIR = src
INCDIR = include

TARGETS = show-wifi-key submit

# default target
all: $(foreach T, $(TARGETS), $(BINDIR)/$(T))

# linking executable
$(BINDIR)/show-wifi-key: $(OBJDIR)/show-wifi-key.o $(OBJDIR)/readLine.o
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/submit: $(OBJDIR)/submit.o
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

.PHONY: all clean remake
