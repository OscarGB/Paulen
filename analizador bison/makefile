CC = gcc
BISON = bison
FLEX = flex

BIN = pruebaSintactico
CFLAGS = -Wall -ansi -pedantic
CYYFLAGS = -ansi -pedantic
FLEXFLAGS =
BISONFLAGS = -dyv

ZIPNAME = pautlen.zip
ZIPFILES = *.l *.y *.c *.h Makefile

all: ${BIN}

${BIN}:%: y.tab.o lex.yy.o %.o
	$(CC) -o $@ $^

lex.yy.o: lex.yy.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

y.tab.o: y.tab.c
	$(CC) ${CYYFLAGS} -c -o $@ $<

%.o: %.c
	$(CC) ${CFLAGS} -c -o $@ $<

y.tab.c: omicron.y
	$(BISON) $(BISONFLAGS) omicron.y

y.tab.h: omicron.y
	$(BISON) $(BISONFLAGS) omicron.y

lex.yy.c: omicron.l y.tab.h
	$(FLEX) $(FLEXFLAGS) omicron.l

clean:
	rm -rvf $(ZIPNAME) $(BIN) *.o lex.yy.c y.tab.h y.tab.c y.output

zip: clean zip $(ZIPNAME) $(ZIPFILES)