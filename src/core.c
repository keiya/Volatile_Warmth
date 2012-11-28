#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char *argv[]) {
  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s [port]\n", argv[0]);
      exit (EXIT_FAILURE);
    }


  sock_boot(argv[1]);

  return 0;
}
