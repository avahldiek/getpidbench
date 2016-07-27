CFLAGS=-I .

all: syscallbench

syscallbench: cputimer.o  syscallbench_helper.o 

clean:
	rm *.o
	rm syscallbench
	
.phony: clean