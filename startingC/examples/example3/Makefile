
CC=gcc
OBJS=flow.o
EXE=flow.exe
CFLAGS=-Wall

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $^ -o $@

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXE)
