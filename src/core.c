#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "fnv.h"
#include "hashtable.h"
#include "core.h"

void* event_loop(void* args);

int main(int argc, char *argv[]) {
  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s [port]\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  pthread_t thread_sv;
  pthread_t thread_db;

  s_options options;
  printf("%s",argv[1]);
  strncpy(&options.port,argv[1],6);

  if (pthread_create(&thread_db,NULL,event_loop,(void *)NULL) != 0) {
    fprintf(stderr,"db pthread err.\n");
    exit (EXIT_FAILURE);
  }

  if (pthread_create(&thread_sv,NULL,sock_boot,(void *)&options) != 0) {
    fprintf(stderr,"sv pthread err.\n");
    exit (EXIT_FAILURE);
  }

  pthread_join( thread_db, NULL );
  pthread_join( thread_sv, NULL );

  return 0;
}

void* event_loop(void* args) {
  while (1) {
  char command[256];
    sprintf( command, "grep VmSize /proc/%d/status", getpid() );
//      system( command );
    sleep(1);
  }
}
