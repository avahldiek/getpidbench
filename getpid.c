/*
 * GetPid syscall benchmark using rdtsc for timing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
  unsigned long long x;
  //CPUID to serailize; Not required 
  //__asm__ volatile (".byte 0x0f, 0xa2");
  //rdtsc instruction
  __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x) );
  return x; 
}

void run_getpid_bench(unsigned int count) {
  unsigned int i = 0;
  unsigned long long start = rdtsc();

  for (i = 0; i < count; i++) {
    syscall(SYS_getpid);
  }

  unsigned long long end = rdtsc();

  printf("# iterations: %d, total cycles spend: %llu, cycles per sys call: %llu\n", count, end-start, (end-start)/count);
}


int main(int argc,char **argv)
{
  int count=0, i=0;

  if (argc < 2) {

    for(i=1;i < 10000000; i=i*2) {
      run_getpid_bench(i);
    }

  } else {
    count = atoi(argv[1]);
    run_getpid_bench(count);
  }
}
