/*
 * syscallbench_helper.c
 *
 *  Created on: Jul 27, 2016
 *      Author: vahldiek
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <cputimer.h>

unsigned long long run_syscall_bench(unsigned int sc, unsigned int count) {
	unsigned int i = 0;
	int ret = 0;
	unsigned long long start = rdtsc();

	for (i = 0; i < count; i++) {
		ret |= syscall(sc);
	}

	unsigned long long end = rdtsc();

	if(ret != 0) {
		printf("Syscall failed ret=%d\n", ret);
		perror("Syscall failed:");
	}

	return end - start;
}
