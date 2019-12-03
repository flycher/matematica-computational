CC = g++
CFLAGS1 = -c -m64 -O -fPIC -fexceptions -DNDEBUG -DIL_STD -DILOSTRICTPOD
CFLAGS2 =    -m64 -O -O0 -fPIC -fexceptions -DNDEBUG -DIL_STD -DILOSTRICTPOD -Wall
LIBS =  -lm 
INCLUDES = -I/home/flycher/ibm/cplex/cplex/include/ -I/home/flycher/ibm/cplex/concert/include/
OBJS = readFile.o bitMapGraph.o PL.o
SRCS = readFile.c bitMapGraph.c PL.cpp
LIBS = -L/home/flycher/ibm/cplex/cplex/lib/x86-64_linux/static_pic -lilocplex -lcplex -L/home/flycher/ibm/cplex/concert/lib/x86-64_linux/static_pic -lconcert -lm -lpthread -ldl
HDRS =  
EXEC = PL

compila: PL.cpp
#para compilar no lia no cplex versão 11
	${CC} ${CFLAGS1} ${INCLUDES} ${SRCS}
	${CC} ${CFLAGS2} ${INCLUDES} ${OBJS} -o ${EXEC} ${LIBS}

executa: compila
	./PL ../../instancia
