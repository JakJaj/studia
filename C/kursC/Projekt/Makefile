PROG = projekt
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`


${PROG}: ${PROG}.c
	${CC} ${CFLAGS} ${PROG}.c  ${LIBS} -o ${PROG}

clean:
	rm ${PROG}