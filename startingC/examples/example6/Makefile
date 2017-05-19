
# This is a comment line

CC=gcc
OBJS=pointers.o
EXE=pointers.exe
CFLAGS=-Wall

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $^ -o $@

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXE)
