WARNINGS=-Wall -Wextra
OPTS=-O4 -static
EXE=gapdrica_l64

LIB=-lgmp

##Libraries BOINC
BOINC_HOME= ${HOME}/boinc/boinc_build/boinc_7.7.0_l64
BOINC      = -lboinc_api -lboinc
INCLUDES   = -I$(BOINC_HOME)/lib -I$(BOINC_HOME)/api
LIBRARIES  = -L$(BOINC_HOME)/lib -L$(BOINC_HOME)/api


all: ${EXE}

${EXE} : gapdrica.c
	${CXX} -o ${EXE} gapdrica.c ${INCLUDES} ${LIBRARIES} ${BOINC} ${LIB} ${OPTS}  libstdc++.a -pthread
clean:
		rm -f *.o
		rm ${EXE}
