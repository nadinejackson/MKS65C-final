#include "pipe_networking.h"
#include "game.c"
void play(char * buf, int vals[])
{
  strcat(buf, "yes, this is working.");
  int i;
  //for (i = 0; i < 81; i++)
  //printf("[%d]\n", vals[i]);
}

int main()
{
  int vals[81];
  int pid = getpid();
  int to_client;
  int from_client;
  char * buf = malloc(1024 * sizeof(char));
  from_client = server_handshake( &to_client );
  swap(vals);
  while(1)
    {
      if (getpid() - pid)
	{
	  if (read(from_client, buf, 1024 * sizeof(char)))
	    {
	      play(buf, vals);
	      write(to_client, buf, 1024 * sizeof(char));
	    }
	  else
	    exit(0);
	}
      else
	from_client = server_handshake( &to_client );
    }
}

