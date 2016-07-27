/*
 * cputimer.c
 *
 *  Created on: Jul 27, 2016
 *      Author: vahldiek
 */

unsigned long long rdtsc() {
	unsigned long long x;
	//rdtsc instruction
	__asm__ volatile (".byte 0x0f, 0x31" : "=A" (x) );
	return x;
}
