CC = gcc
OPENMP	 = -fopenmp 
CFLAGS   = -Wall -O3 -std=c99 

TARGETS  = pi_seq pi_omp
all: $(TARGETS) 

pi_seq: pi_seq.c
	$(CC) $(CFLAGS) $< -o $@

pi_omp: pi_omp.c
	$(CC) $(CFLAGS) $(OPENMP) $< -o $@

clean:
	rm -rf $(TARGETS)

ultraclean:
	rm -rf TRACE*.mpit $(TARGETS) *.prv *.pcf *.row set-0 *.mpits *.sym *.o* *.e* time-* *.ps *.pdf *.fig *.txt
