/*
 * syscallbench_helper.c
 *
 *  Created on: Jul 27, 2016
 *      Author: vahldiek
 */

#include <unistd.h>
#include <sys/syscall.h>
#include <cputimer.h>

unsigned long long run_syscall_bench(unsigned int sc, unsigned int count) {
	unsigned int i = 0;
	unsigned long long start = rdtsc();

	for (i = 0; i < count; i++) {
		syscall(sc);
	}

	unsigned long long end = rdtsc();

	return end - start;
}
