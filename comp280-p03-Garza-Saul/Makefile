CC = gcc
CFLAGS = -g -Wall -Werror
LDFLAGS = -lm

TARGET = stats rotate-test

all: $(TARGET)

stats: stats.c readfile.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

readfile.o: readfile.c readfile.h
	$(CC) $(CFLAGS) -c $<

rotate-test: rotate-test.c rotate.s 
	$(CC) $(CFLAGS) -o $@ $^

comp280-p03-%.tar.gz: stats.c readfile.h readfile.c rotate.s rotate-test.c Makefile project03.txt
	tar -czf $@ $^

clean:
	$(RM) $(TARGET) *.o *.tar.gz
