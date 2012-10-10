CC = /opt/cilk/bin/gcc -O2

all: libgraphicsscreen.a libStopWatch.a 
# libstack.a

libgraphicsscreen.a: graphicsScreen.o
	ar rsv libgraphicsScreen.a graphicsScreen.o

graphicsScreen.o: graphicsScreen.c
	$(CC) $(INC) -c graphicsScreen.c

libStopWatch.a: StopWatch.o
	ar rsv libStopWatch.a StopWatch.o

StopWatch.o: StopWatch.c
	$(CC) $(INC) -c StopWatch.c

# libstack.a: stack.o
# 	ar rsv libstack.a stack.o

# stack.o: stack.c
# 	$(CC) $(INC) -c stack.c

clean:
	rm -f *.o *~ *.a
