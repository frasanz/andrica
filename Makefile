WARNINGS=-Wall -Wextra
OPTS=-O3 -g  -pedantic -static
EXE=gapdrica_l64

LIB=-lgmp

all: ${EXE}

${EXE} : gapdrica.c
	${CC} -o ${EXE} gapdrica.c ${LIB}
clean:
		rm -f *.o
		rm ${EXE}
