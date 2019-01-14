#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>

#define KEY 0xFADEDDAB
			
int write_line(int * place, int * locations, int p)
{
  int got = shmget(KEY, sizeof(int), 0644 | IPC_CREAT); //shared memory
  int *ptr = shmat(got, 0, 0); //shared memory pointer
  int c = 15;
  if(*place - *(ptr+15) > 0)
    {
      while(c--)
	*(ptr + c) = *(locations + c);
      ptr[15] = *place;

      if (p)
	ptr[15 + p]++;
      return 0;
    }
  
  while(c--)
    *(locations + c) = *(ptr + c);
  *place = ptr[15]; 

  return ptr[15];
}
