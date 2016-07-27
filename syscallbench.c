/*
 * GetPid syscall benchmark using rdtsc for timing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>


int main(int argc, char **argv) {
	if (argc < 3) {
		unsigned int count = 0;
		for (count = 1; count < 10000000; count = count * 2) {
			unsigned long long cycles = run_syscall_bench(SYS_getpid, count);
			printf("# iterations: %d, total cycles spend: %llu, cycles per sys call: %llu\n", count, cycles, (cycles)/count);
		}

	} else {
		unsigned int syscall = atoi(argv[1]);
		unsigned int count = atoi(argv[2]);
		unsigned long long cycles = run_syscall_bench(syscall, count);
		printf("# iterations: %d, total cycles spend: %llu, cycles per sys call: %llu\n", count, cycles, (cycles)/count);
	}
}
